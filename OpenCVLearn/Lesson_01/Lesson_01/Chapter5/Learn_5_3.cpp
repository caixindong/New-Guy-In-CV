//
//  Learn_5_3.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2018/1/2.
//  Copyright © 2018年 蔡欣东. All rights reserved.
//

#include "Learn_5_3.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

void Learn_5_3::learn() {
    double alpha = 0.5;
    double beta = 1 - alpha;
    Mat src1,src2,dst;
    src1 = imread("anim1.jpg");
    src2 = imread("anim2.jpg");
    
    addWeighted(src1, alpha, src2, beta, 0, dst);
    
    imshow("效果图", dst);
    
    waitKey(0);
}
