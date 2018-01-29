//
//  Learn_1.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2017/12/11.
//  Copyright © 2017年 蔡欣东. All rights reserved.
//

#include "Learn_1.hpp"
using namespace std;
using namespace cv;

void Learn_1::learn() {
    Mat srcImage = imread("dnf.jpg");
    imshow("原始图", srcImage);
    waitKey(0);
    //指定性质和尺寸的结构元素
    Mat element = getStructuringElement(MORPH_ELLIPSE, Size(15, 15));
    Mat dstImage;
    //腐蚀操作
    erode(srcImage, dstImage, element);
    imshow("腐蚀效果图", dstImage);
    waitKey(0);
}
