//
//  Learn_3.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2017/12/13.
//  Copyright © 2017年 蔡欣东. All rights reserved.
//

#include "Learn_3.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
void Learn_3::learn(){
    Mat srcImage = imread("lena.jpeg");
    imshow("原始图", srcImage);
    Mat dstImage,edge,grayImage;
    dstImage.create(srcImage.size(), srcImage.type());
    //转为灰度图
    cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);
    //模糊化
    blur(grayImage, edge, Size(3,3));
    //边缘检测
    Canny(edge, edge, 3, 9.3);
    
    imshow("边缘检测图", edge);
    
    waitKey(0);
}
