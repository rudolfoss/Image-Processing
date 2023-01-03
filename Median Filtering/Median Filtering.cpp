//201821054 미디어학과 하태선 1차과제

#include<iostream>
#include<array>
#include<vector>
#include <opencv2/highgui.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;


void myMedianFilter(InputArray input, OutputArray output, int windowSize) {
    vector<uchar> vec;
    const Mat& img = input.getMat();
    output.create(img.size(), img.type());
    Mat dst = output.getMat();
    int window = (windowSize-1)/2;
    for (auto y = 0; y < img.rows; y++) 
        for (auto x = 0; x < img.cols; x++) {
            vec.clear();
            for (auto t = -window; t <= window; t++)
                for (auto s = -window; s <= window; s++) {
                    vec.push_back(img.at<uchar>(min(img.rows - 1, max(0, y + t)), min(img.cols - 1, max(0, x + s))));
        }
           sort(vec.begin(),vec.end());
           dst.at<uchar>(y, x) = vec[vec.size()/2];
    }
}
int main()
{
    Mat image = imread("C:\\Users\\user\\Desktop\\MedianFilterInput.png",0);    
    Mat out;
    myMedianFilter(image, out, 5);
    imshow("image", image);
    imshow("median", out);
    waitKey();
    return 0;
}
