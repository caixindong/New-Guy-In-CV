//
//  Learn_6_7.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2018/2/4.
//  Copyright © 2018年 蔡欣东. All rights reserved.
//

#include "Learn_6_7.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

void Learn_6_7::learn() {
    Mat src = imread("lena.jpeg");
    Mat grayImg;
    cvtColor(src, grayImg, COLOR_BGR2GRAY);
    imshow("灰度图", grayImg);
    waitKey();
    Mat dst;
    //二进制阈值
    threshold(grayImg, dst, 100, 255, THRESH_BINARY);
    imshow("效果图", dst);
    waitKey();
    Mat dst2;
    //二进制阈值反转
    threshold(grayImg, dst2, 100, 255, THRESH_BINARY_INV);
    imshow("效果图", dst2);
    waitKey();
    Mat dst3;
    //截断阈值
    threshold(grayImg, dst3, 100, 255, THRESH_TRUNC);
    imshow("效果图", dst3);
    waitKey();
    Mat dst4;
    //阈值为0
    threshold(grayImg, dst4, 100, 255, THRESH_TOZERO);
    imshow("效果图", dst4);
    waitKey();
}
