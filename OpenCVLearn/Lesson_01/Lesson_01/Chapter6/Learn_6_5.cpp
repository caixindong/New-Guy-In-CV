//
//  Learn_6_5.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2018/1/30.
//  Copyright © 2018年 蔡欣东. All rights reserved.
//

#include "Learn_6_5.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

void Learn_6_5::learn() {
    Mat img = imread("ganda.jpg",1);
    imshow("原图", img);
    waitKey();
    Rect rect;
    //漫水填充，有mask参数，就不会填充mask里面的像素
    floodFill(img, Point(100,100), Scalar(155,255,55),&rect,Scalar(20,20,20),Scalar(20,20,20));
    imshow("效果图", img);
    waitKey();
    
}
