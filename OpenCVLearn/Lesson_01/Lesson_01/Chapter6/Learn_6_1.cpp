//
//  Learn_6_1.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2018/1/25.
//  Copyright © 2018年 蔡欣东. All rights reserved.
//

#include "Learn_6_1.hpp"
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

Mat srcImg,dstImg1,dstImg2,dstImg3,dstImg4,dstImg5;
int boxfilterValue = 3;
int blurfilterValue = 3;
int gaussianBlurValue = 3;
int medianBlurValue = 10;
int bilateralValue = 10;

static void on_boxfilter(int, void*);
static void on_blurfilter(int, void*);
static void on_gaussianBlur(int, void*);
static void on_medianBlur(int, void*);
static void on_bilateralFilter(int, void*);

void Learn_6_1::learn() {
    srcImg = imread("lena.jpeg",1);
    
    dstImg1 = srcImg.clone();
    dstImg2 = srcImg.clone();
    dstImg3 = srcImg.clone();
    dstImg4 = srcImg.clone();
    dstImg5 = srcImg.clone();
    
    namedWindow("原图",1);
    imshow("原图", srcImg);
    
    waitKey();
    
//    namedWindow("方框滤波");
//    createTrackbar("内核值：", "方框滤波", &boxfilterValue, 40,on_boxfilter);
//    on_boxfilter(boxfilterValue, 0);
//
//    waitKey();

    
//    namedWindow("均值滤波");
//    createTrackbar("内核值：", "均值滤波", &blurfilterValue, 40,on_blurfilter);
//    on_blurfilter(blurfilterValue, 0);
//    
//    waitKey();

    
//    namedWindow("高斯滤波");
//    createTrackbar("内核值：", "高斯滤波", &gaussianBlurValue, 40,on_gaussianBlur);
//    on_gaussianBlur(gaussianBlurValue, 0);
//
//    waitKey();
    
    namedWindow("中值滤波");
    createTrackbar("内核值：", "中值滤波", &medianBlurValue, 40,on_medianBlur);
    on_medianBlur(medianBlurValue, 0);

    waitKey();
    
    
//    namedWindow("双边滤波");
//    createTrackbar("内核值：", "双边滤波", &bilateralValue, 40,on_bilateralFilter);
//    on_bilateralFilter(bilateralValue, 0);
//
//    waitKey();
    

}

static void on_boxfilter(int, void*) {
    boxFilter(srcImg, dstImg1, -1, Size(boxfilterValue+1,boxfilterValue+1));
    imshow("方框滤波", dstImg1);
}

static void on_blurfilter(int, void*) {
    blur(srcImg, dstImg2, Size(blurfilterValue+1,blurfilterValue+1),Point(-1,-1));
    imshow("均值滤波", dstImg2);
}

static void on_gaussianBlur(int, void*) {
    GaussianBlur(srcImg, dstImg3, Size(gaussianBlurValue*2+1,gaussianBlurValue*2+1), 0,0);
    imshow("高斯滤波", dstImg3);
}

static void on_medianBlur(int, void*) {
    medianBlur(srcImg, dstImg4, medianBlurValue*2+1);
    imshow("中值滤波", dstImg4);
}

static void on_bilateralFilter(int, void*) {
    bilateralFilter(srcImg, dstImg5, bilateralValue, bilateralValue*2, bilateralValue/2);
    imshow("双边滤波", dstImg5);
}

