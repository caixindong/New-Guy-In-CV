//
//  Learn_3_1.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2017/12/13.
//  Copyright © 2017年 蔡欣东. All rights reserved.
//

#include "Learn_3_1.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

void Learn_3_1::learn() {
    //>0，表示返回一个三通道的彩色图
    Mat image = imread("dnf.jpg",1);
    Mat logo = imread("logo.jpg");
    
    namedWindow("原画图");
    imshow("原画图", image);
    
    namedWindow("logo图");
    imshow("logo图", logo);

    //定义image的感兴趣区域
    Mat imageROI;
    imageROI = image(Rect(10,10, logo.cols, logo.rows));
    //将logo添加到imageROI的区域
    addWeighted(imageROI, 0.5, logo, 0.3, 0, imageROI);

    namedWindow("原图+logo");
    imshow("原图+logo", image);

    imwrite("合成图.jpg", image);
    
    waitKey();
}
