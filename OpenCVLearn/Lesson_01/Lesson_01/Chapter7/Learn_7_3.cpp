//
//  Learn_7_3.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2018/3/26.
//  Copyright © 2018年 蔡欣东. All rights reserved.
//

#include "Learn_7_3.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

void Learn_7_3::learn() {
    Mat img = imread("lena.jpeg",1);
    GaussianBlur(img, img, Size(3,3), 0,0,BORDER_DEFAULT);
    Mat gray;
    cvtColor(img, gray, CV_BGR2GRAY);
    Mat dst;
    Laplacian(gray, dst, CV_16S,3,1,0,BORDER_DEFAULT);
    Mat abs_dst;
    convertScaleAbs(dst, abs_dst);
    imshow("效果图", abs_dst);
    waitKey(0);
    
}
