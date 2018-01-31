//
//  Learn_6_6.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2018/1/31.
//  Copyright © 2018年 蔡欣东. All rights reserved.
//

#include "Learn_6_6.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

void Learn_6_6::learn() {
    Mat srcImg = imread("ganda.jpg",1);
    imshow("原图", srcImg);
    waitKey();
    Mat dst;
    resize(srcImg, dst, Size(200,200));
    imshow("效果图", dst);
    waitKey();
    
    Mat srcImg2 = imread("lena.jpeg",1);
    imshow("原图2", srcImg2);
    waitKey();
    Mat dst2;
    pyrUp(srcImg2, dst2);
    //默认长宽扩大两倍，新增的行列用0填充，再用内核卷积
    imshow("效果图2", dst2);
    waitKey();
    
    Mat dst3;
    pyrDown(srcImg2, dst3);
    imshow("效果图3", dst3);
    waitKey();

}
