//
//  Learn_7_2.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2018/3/22.
//  Copyright © 2018年 蔡欣东. All rights reserved.
//

#include "Learn_7_2.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

void Learn_7_2::learn(){
    Mat x,y,absx,absy;
    Mat img = imread("lena.jpeg");
    imshow("原始图", img);
    waitKey(0);

    //Sobel算子依然是一种过滤器，只是其是带有方向的,也用于边缘检测，Sobel算子结合了高斯平滑和微分求导,更多的抗噪性
    //Sobel函数求完导数后会有负值，还有会大于255的值。而原图像是uint8，即8位无符号数，所以Sobel建立的图像位数不够，会有截断。因此要使用16位有符号的数据类型
    Sobel(img, x, CV_16S, 1, 0,3,1,1,BORDER_DEFAULT);
    //在经过处理后，别忘了用convertScaleAbs()函数将其转回原来的uint8形式。否则将无法显示图像
    convertScaleAbs(x, absx);
    imshow("x求导", absx);
    waitKey(0);

    Sobel(img, y, CV_16S, 0, 1,3,1,1,BORDER_DEFAULT);
    convertScaleAbs(y, absy);
    imshow("y求导", absy);
    waitKey(0);
}
