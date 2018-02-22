//
//  Learn_7_1.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2018/2/7.
//  Copyright © 2018年 蔡欣东. All rights reserved.
//

#include "Learn_7_1.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

void Learn_7_1::learn() {
    Mat src = imread("lena.jpeg",1);
    Mat src1 = src.clone();
    imshow("原图", src);
    waitKey();
//    //直接用canny，在opencv3失效了
//    Canny(src, src, 150, 100, 3);
//    imshow("效果图1", src);
//    waitKey();
    
    //转成灰度图，降噪，再用canny,最后将得到的边缘作为掩码拷贝原图到效果图上，得到彩色边缘图
    Mat dst,edge,gray;
    dst.create(src1.size(), src1.type());
    cvtColor(src1, gray, COLOR_BGR2GRAY);
    blur(gray, edge, Size(3,3));
    Canny(edge, edge, 150, 100,3);
    
    dst = Scalar::all(0);
    src1.copyTo(dst, edge);
    imshow("效果图2", dst);
    waitKey();
    
    
}
