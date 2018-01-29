//
//  Learn_4_2.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2017/12/27.
//  Copyright © 2017年 蔡欣东. All rights reserved.
//

#include "Learn_4_2.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

#define WINDOW_WIDTH 600
//画椭圆
void DrawEllipse(Mat img, double angle) {
    int thickness = 2;
    int lineType = 8;
    ellipse(img, Point(WINDOW_WIDTH/2,WINDOW_WIDTH/2), Size(WINDOW_WIDTH/4,WINDOW_WIDTH/16), angle, 0, 360, Scalar(255,129,0),thickness,lineType);
}
//画实心圆
void DrawFilledCircle(Mat img, Point center) {
    int thickness = -1;
    int lineType = 8;
    circle(img, center, WINDOW_WIDTH/32, Scalar(0, 0, 255), thickness, lineType);
}
//画多边形
void DrawPolygon(Mat img) {
    int lineType = 8;
    Point rookPoints[1][20];
    rookPoints[0][0] = Point(WINDOW_WIDTH/4, 7*WINDOW_WIDTH/8);
    rookPoints[0][1] = Point(3*WINDOW_WIDTH/4, 7*WINDOW_WIDTH/8);
    rookPoints[0][2] = Point(3*WINDOW_WIDTH/4, 13*WINDOW_WIDTH/16);
    rookPoints[0][3] = Point(11*WINDOW_WIDTH/16, 13*WINDOW_WIDTH/16);
    rookPoints[0][4] = Point(19*WINDOW_WIDTH/32, 3*WINDOW_WIDTH/8);
    rookPoints[0][5] = Point(3*WINDOW_WIDTH/4, 3*WINDOW_WIDTH/8);
    rookPoints[0][6] = Point(3*WINDOW_WIDTH/4, WINDOW_WIDTH/8);
    rookPoints[0][7] = Point(26*WINDOW_WIDTH/40, WINDOW_WIDTH/8);
    rookPoints[0][8] = Point(26*WINDOW_WIDTH/40, WINDOW_WIDTH/4);
    rookPoints[0][9] = Point(22*WINDOW_WIDTH/40, WINDOW_WIDTH/4);
    rookPoints[0][10] = Point(22*WINDOW_WIDTH/40, WINDOW_WIDTH/8);
    rookPoints[0][11] = Point(18*WINDOW_WIDTH/40, WINDOW_WIDTH/8);
    rookPoints[0][12] = Point(18*WINDOW_WIDTH/40, WINDOW_WIDTH/4);
    rookPoints[0][13] = Point(14*WINDOW_WIDTH/40, WINDOW_WIDTH/4);
    rookPoints[0][14] = Point(14*WINDOW_WIDTH/40, WINDOW_WIDTH/8);
    rookPoints[0][15] = Point(WINDOW_WIDTH/4, WINDOW_WIDTH/8);
    rookPoints[0][16] = Point(WINDOW_WIDTH/4, 3*WINDOW_WIDTH/8);
    
    rookPoints[0][17] = Point(13*WINDOW_WIDTH/32, 3*WINDOW_WIDTH/8);
    rookPoints[0][18] = Point(5*WINDOW_WIDTH/16, 13*WINDOW_WIDTH/16);
    rookPoints[0][19] = Point(WINDOW_WIDTH/4, 13*WINDOW_WIDTH/16);
    
    const Point *ppt[1] = {rookPoints[0]};
    int npt[] = {20};
    
    fillPoly(img, ppt, npt, 1, Scalar(255,255,255),lineType);
}

void DrawLine(Mat img, Point start, Point end) {
    int thickness = 2;
    int lineType = 8;
    line(img, start, end, Scalar(0,0,0),thickness, lineType);
}

void Learn_4_2::learn() {
    Mat atomImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);
    DrawEllipse(atomImage, 90);
    DrawEllipse(atomImage, 0);
    DrawEllipse(atomImage, 45);
    DrawEllipse(atomImage, -45);
    DrawFilledCircle(atomImage, Point(WINDOW_WIDTH/2,WINDOW_WIDTH/2));
    
    Mat rockImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);
    DrawPolygon(rockImage);
    rectangle(rockImage, Point(0, 7*WINDOW_WIDTH/8), Point(WINDOW_WIDTH,WINDOW_WIDTH), Scalar(0,255,255),-1, 8);
    
    DrawLine(rockImage, Point(0,15*WINDOW_WIDTH/16), Point(WINDOW_WIDTH,15*WINDOW_WIDTH/16));
    DrawLine(rockImage, Point(WINDOW_WIDTH/4,7*WINDOW_WIDTH/8), Point(WINDOW_WIDTH/4,WINDOW_WIDTH));
    DrawLine(rockImage, Point(WINDOW_WIDTH/2,7*WINDOW_WIDTH/8), Point(WINDOW_WIDTH/2,WINDOW_WIDTH));
    DrawLine(rockImage, Point(3*WINDOW_WIDTH/4,7*WINDOW_WIDTH/8), Point(3*WINDOW_WIDTH/4,WINDOW_WIDTH));

    
    imshow("atom", atomImage);
    
//    imshow("rock", rockImage);
    
    
    
    waitKey(0);
}
