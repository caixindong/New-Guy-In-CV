//
//  Learn_6_3.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2018/1/29.
//  Copyright © 2018年 蔡欣东. All rights reserved.
//

#include "Learn_6_3.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

void Learn_6_3::learn() {
    Mat img = imread("lena.jpeg",1);
    
    Mat element = getStructuringElement(MORPH_RECT, Size(15,15));
    Mat out;
    //腐蚀
    erode(img, out, element);
    
    imshow("效果图", out);
    
    waitKey();
}
