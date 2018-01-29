//
//  Learn_5_5.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2018/1/4.
//  Copyright © 2018年 蔡欣东. All rights reserved.
//

#include "Learn_5_5.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;

static void on_ContrastAndBright(int,void*);

int g_nContrastValue;
int g_nBrightValue;
Mat g_srcImg,g_disImg;

void Learn_5_5::learn() {
    g_srcImg = imread("lena.jpeg");
    g_disImg = Mat::zeros(g_srcImg.rows, g_srcImg.cols, g_srcImg.type());
    
    g_nBrightValue = 80;
    g_nContrastValue = 80;
    
    namedWindow("效果",0);
    
    createTrackbar("对比度", "效果", &g_nContrastValue, 300, on_ContrastAndBright);
//    createTrackbar("亮度", "效果", &g_nBrightValue, 200, on_ContrastAndBright);
    
    on_ContrastAndBright(g_nContrastValue, 0);
    on_ContrastAndBright(g_nBrightValue, 0);
    
    while (char(waitKey(1)) != 'q') {
        
    }
}

static void on_ContrastAndBright(int,void*) {
    for (int i = 0; i < g_srcImg.rows; i++) {
        for (int j = 0; j < g_srcImg.cols; j++) {
            for (int z = 0; z < 3; z++) {
                g_disImg.at<Vec3b>(i,j)[z] = saturate_cast<uchar>((g_nContrastValue*0.01)*g_srcImg.at<Vec3b>(i,j)[z] + g_nBrightValue);
            }
        }
    }
    imshow("效果", g_disImg);
}
