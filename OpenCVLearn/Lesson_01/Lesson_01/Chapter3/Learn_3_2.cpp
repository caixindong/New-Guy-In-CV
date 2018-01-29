//
//  Learn_3_2.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2017/12/18.
//  Copyright © 2017年 蔡欣东. All rights reserved.
//

#include "Learn_3_2.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

#define WINDOW_NAME "实例"

const int max_alphaValue = 100;
int alpha_slider;
double alphaValue;
double betaValue;

Mat srcImage1;
Mat srcImage2;
Mat dstImage;
//pos是轨迹位置，userdata是用户数据
void trackbar(int pos, void* userdata) {
    printf("pos : %d",pos);
    alphaValue = (double) alpha_slider / max_alphaValue;
    betaValue = (1 - alphaValue);
    
    addWeighted(srcImage1, alphaValue, srcImage2, betaValue, 0.0, dstImage);
    
    imshow(WINDOW_NAME, dstImage);
}

void Learn_3_2::learn() {
    srcImage1 = imread("anim1.jpg");
    srcImage2 = imread("anim2.jpg");
    
    alpha_slider = 70;
    
    namedWindow(WINDOW_NAME,1);
    
    char trackBarName[50];
    sprintf(trackBarName, "透明值 %d", max_alphaValue);
    //bar的名字、window的名字、bar初始值、bar最大值、回调函数
    createTrackbar(trackBarName, WINDOW_NAME, &alpha_slider, max_alphaValue, trackbar);
    
    trackbar(alpha_slider, 0);
    
    waitKey(0);
}
