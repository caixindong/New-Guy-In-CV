//
//  Learn_5_6.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2018/1/10.
//  Copyright © 2018年 蔡欣东. All rights reserved.
//

#include "Learn_5_6.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

void Learn_5_6::learn() {
    Mat srcImg = imread("lena.jpeg",0);
    
    //最佳尺寸
    int m = getOptimalDFTSize(srcImg.rows);
    int n = getOptimalDFTSize(srcImg.cols);
    //填充像素
    Mat padded;
    copyMakeBorder(srcImg, padded, 0, m - srcImg.rows, 0, n - srcImg.cols, BORDER_CONSTANT, Scalar::all(0));
    
    //为傅里叶变换的结果实部和虚部分配存储空间
    Mat planes[] = {Mat_<float>(padded),Mat::zeros(padded.size(), CV_32F)};
    Mat complexI;
    merge(planes, 2, complexI);
    
    dft(complexI, complexI);
    
    //将复数转换为幅度F,planes[0]为实部re，plane[1]为虚部im, F = √（re²+im²）
    split(complexI, planes);
    magnitude(planes[0], planes[1], planes[0]);
    
    Mat magnitudeImage = planes[0];
    
    //幅度太大不适合显示在屏幕上，对数尺度缩放 M = log(M+1)
    magnitudeImage += Scalar::all(1);
    log(magnitudeImage, magnitudeImage);
    
    //x & -2 取不大于x 的最大偶数
    magnitudeImage = magnitudeImage(Rect(0,0,magnitudeImage.cols & -2,magnitudeImage.rows & -2));
    
    int cx = magnitudeImage.cols/2;
    int cy = magnitudeImage.rows/2;
    Mat q0(magnitudeImage,Rect(0,0,cx,cy));
    Mat q1(magnitudeImage,Rect(cx,0,cx,cy));
    Mat q2(magnitudeImage,Rect(0,cy,cx,cy));
    Mat q3(magnitudeImage,Rect(cx,cy,cx,cy));
    
    Mat tmp;
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);
    
    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);

    //归一化
    normalize(magnitudeImage, magnitudeImage,0,1,NORM_MINMAX);
    
    imshow("效果图", magnitudeImage);
    waitKey();
}
