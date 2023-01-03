#include <iostream>
#include <vector>
#include <ctime>
#include<stdlib.h>
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace std;
using namespace cv;

Mat input;
Mat output;
Mat boundary;
Mat temp;

void mouseAction(int event, int x, int y, int flags, void* param) {
    if (event == EVENT_LBUTTONDOWN) {
        Mat se = getStructuringElement(MORPH_CROSS, Size(3, 3));
        Mat rf = input;
        Mat rb;
        bitwise_not(boundary, rb);
        rf = rf.zeros(rf.rows, rf.cols, CV_8UC1);
        rf.at<uchar>(y, x) = 255;

        imshow("output", rf);
        while (1)
        {
            dilate(rf, rf, se);
            bitwise_and(rf, rb, rf);
            waitKey(1);
            imshow("output", rf);
        }
    }
}

int main() {
    Mat se = getStructuringElement(MORPH_RECT, Size(3, 3));
    input = imread("C:\\Users\\user\\Desktop\\Profile.png", 0);
    erode(input, temp, se);
    boundary = input - temp;

    namedWindow("output");
    setMouseCallback("output", mouseAction);
    imshow("input", input);
    imshow("output", boundary);

    waitKey();
    return 0;
}