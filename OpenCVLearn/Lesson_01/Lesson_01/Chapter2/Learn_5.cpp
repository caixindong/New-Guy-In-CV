//
//  Learn_5.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2017/12/13.
//  Copyright © 2017年 蔡欣东. All rights reserved.
//

#include "Learn_5.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

void Learn_5::learn() {
    VideoCapture capture(0);
    Mat edges;
    while (1) {
        Mat frame;
        capture>>frame;
        
        cvtColor(frame, edges, COLOR_BGR2GRAY);
        
        blur(edges, edges, Size(7,7));
        
        Canny(edges, edges, 0, 30, 3);
        
        imshow("显示", edges);
        if (waitKey(30) >= 0) {
            break;
        }
    }
}

