//
//  Learn_7_9.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2018/5/3.
//  Copyright © 2018年 蔡欣东. All rights reserved.
//

#include "Learn_7_9.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

void Learn_7_9::learn() {
    Mat img = imread("lena.jpeg");
    Mat grayImg;
    cvtColor(img, grayImg, COLOR_BGR2GRAY);
    imshow("灰度图", grayImg);
    waitKey(0);
    Mat dst;
    equalizeHist(grayImg, dst);
    imshow("直方图均衡化", dst);
    waitKey(0);
}
