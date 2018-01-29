//
//  Learn_5_2.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2018/1/2.
//  Copyright © 2018年 蔡欣东. All rights reserved.
//

#include "Learn_5_2.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

void Learn_5_2::learn() {
    Mat srcImg = imread("dnf.jpg");
    Mat mask = imread("logo.jpg");

    //Rect设置ROI 
    Mat imgROI = srcImg(Rect(20,20,mask.cols,mask
                             .rows));
    
    mask.copyTo(imgROI, mask);
    
    imshow("windows", srcImg);
    
    waitKey(0);
}
