//
//  Learn_7_6.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2018/4/10.
//  Copyright © 2018年 蔡欣东. All rights reserved.
//

#include "Learn_7_6.hpp"
#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

void Learn_7_6::learn() {
    Mat img = imread("backetball.jpeg");
    Mat mid;
    //灰度并平滑图像
    imshow("原始图", img);
    waitKey(0);
    cvtColor(img, mid, COLOR_BGR2GRAY);
    GaussianBlur(mid, mid, Size(9,9), 2,2);
    //圆的圆心(x,y)和半径r
    vector<Vec3f> circles;
    HoughCircles(mid, circles, HOUGH_GRADIENT, 1.5, 10, 200, 100, 0,0);
    for (size_t i = 0; i < circles.size(); i++) {
        Point center(cvRound(circles[i][0]),cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        //画圆心
        circle(img, center, 3, Scalar(0,0,255), -1, 8, 0);
        //画圆轮廓
        circle(img, center, radius, Scalar(155,50,255), 3, 8, 0);
    }
    imshow("效果", img);
    waitKey(0);
}

