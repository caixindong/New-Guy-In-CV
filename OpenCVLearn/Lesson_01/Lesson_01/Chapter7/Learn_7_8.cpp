//
//  Learn_7_8.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2018/4/17.
//  Copyright © 2018年 蔡欣东. All rights reserved.
//

#include "Learn_7_8.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

void Learn_7_8::learn() {
    Mat img = imread("lena.jpeg");
    Mat dst, dst_rot;
    dst = Mat::zeros(img.rows, img.cols, img.type());
    dst_rot = Mat::zeros(img.rows, img.cols, img.type());
    
    
    Point2f srcT[3];
    Point2f dstT[3];
    
    srcT[0] = Point2f(0,0);
    srcT[1] = Point2f(static_cast<float>(img.cols-1),1);
    srcT[2] = Point2f(0,static_cast<float>(img.rows-1));
    
    dstT[0] = Point2f(static_cast<float>(0.0*img.cols), static_cast<float>(img.rows*0.33));
    dstT[1] = Point2f(static_cast<float>(0.65*img.cols), static_cast<float>(img.rows*0.35));
    dstT[2] = Point2f(static_cast<float>(0.15*img.cols), static_cast<float>(img.rows*0.6));

    Mat warpM(2,3,CV_32FC1);
    Mat rotM(2,3,CV_32FC1);
    
    warpM = getAffineTransform(srcT, dstT);
    warpAffine(img, dst, warpM, dst.size());
    
    Point center = Point(dst.cols/2, dst.rows/2);
    //顺时针
    double angle = -30.0;
    double scale = 0.8;
    rotM = getRotationMatrix2D(center, angle, scale);
    warpAffine(dst, dst_rot, rotM, dst_rot.size());
    
    imshow("原图", img);
    waitKey(0);
    imshow("仿射", dst);
    waitKey(0);
    imshow("旋转", dst_rot);
    waitKey(0);
}
