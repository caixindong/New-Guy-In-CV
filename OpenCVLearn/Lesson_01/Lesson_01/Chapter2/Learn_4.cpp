//
//  Learn_4.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2017/12/13.
//  Copyright © 2017年 蔡欣东. All rights reserved.
//

#include "Learn_4.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;
void Learn_4::learn() {
    VideoCapture capture("runninglife.mp4");
    while (1) {
        Mat frame;
        capture>>frame;
        imshow("读取视频", frame);
        //30ms
        waitKey(5);
    }
}
