//
//  Learn_2.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2017/12/11.
//  Copyright © 2017年 蔡欣东. All rights reserved.
//

#include "Learn_2.hpp"
#include <opencv2/opencv.hpp>

using namespace cv;

void Learn_2::learn() {
    Mat srcImage = imread("lena.jpeg");
    imshow("原始图", srcImage);
    Mat dstImage;
    blur(srcImage, dstImage, Size(7,7));
    imshow("均值滤波效果图", dstImage);
    waitKey(0);
}
