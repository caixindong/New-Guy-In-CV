//
//  Learn_6_4.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2018/1/30.
//  Copyright © 2018年 蔡欣东. All rights reserved.
//

#include "Learn_6_4.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

void Learn_6_4::learn() {
    Mat img = imread("ganda.jpg",1);
    
    Mat dst;
    
    imshow("原图", img);
    
    waitKey();
    //开运算、闭运算、形态学梯度、顶帽运算、黑猫运算
    Mat element = getStructuringElement(MORPH_RECT, Size(15,15));
    //MORPH_OPEN MORPH_CLOSE MORPH_GRADIENT MORPH_TOPHAT MORPH_BLACKHAT
    morphologyEx(img, dst, MORPH_BLACKHAT, element);
    
    imshow("效果图", dst);
    
    waitKey();
}
