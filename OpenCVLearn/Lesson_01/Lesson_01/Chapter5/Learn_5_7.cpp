//
//  Learn_5_7.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2018/1/15.
//  Copyright © 2018年 蔡欣东. All rights reserved.
//

#include "Learn_5_7.hpp"
#include <opencv2/opencv.hpp>
#include <time.h>
using namespace cv;

void Learn_5_7::learn() {
    FileStorage fs("test.yaml",FileStorage::WRITE);
    
    fs<<"frameCount"<<5;
    time_t rawtime;
    //得到机器的日历时间
    time(&rawtime);
    fs<<"calibrationDate"<<asctime(localtime(&rawtime));
    Mat cameraMatrix = (Mat_<double>(3,3)<<1000,0,320,0,1000,240,0,0,1);
    Mat distCoeffs = (Mat_<double>(5,1)<<0.1,0.01,-0.001,0,0);
    fs<<"cameraMatrix"<<cameraMatrix<<"distCoeffs"<<distCoeffs;
    fs<<"features"<<"[";
    for (int i = 0; i<3; i++) {
        int x = rand() % 640;
        int y = rand() % 480;
        uchar lbp = rand() % 256;
        
        fs << "{:" << "x" << x << "y" << y << "lbp" <<"[:";
        for (int j = 0; j < 8; j++)
            fs<<((lbp>>j) & 1);
        fs<<"]"<<"}";
    }
    fs<<"]";
    fs.release();
    
    printf("写入完毕");
    
    getchar();
    
}
