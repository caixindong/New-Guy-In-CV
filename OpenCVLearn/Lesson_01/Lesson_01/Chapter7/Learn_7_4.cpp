//
//  Learn_7_4.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2018/3/26.
//  Copyright © 2018年 蔡欣东. All rights reserved.
//

#include "Learn_7_4.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;

void Learn_7_4::learn() {
    Mat img = imread("ganda.jpg",1);
    Mat mid,dst;
    Canny(img, mid, 50, 200,3);
    vector<Vec2f> lines;
    //输入是经过边缘检测的图
    HoughLines(mid, lines, 1, CV_PI/180, 150,0,0);
    
//    cvtColor(mid, dst, CV_GRAY2BGR);
    img.copyTo(dst);

    for (size_t i = 0; i < lines.size(); i++) {
        float rho = lines[i][0],theta = lines[i][1];
        Point p1,p2;
        double a = cos(theta),b = sin(theta);
        double x0 = a*rho,y0 = b*rho;
        p1.x = cvRound(x0+(-b)*1000);
        p1.y = cvRound(y0+(a)*1000);
        p2.x = cvRound(x0-(-b)*1000);
        p2.y = cvRound(y0-(a)*1000);
        
        line(dst, p1, p2, Scalar(0,0,255),1,LINE_AA);
    }
    
    imshow("原图", img);
    waitKey(0);
    imshow("效果图1", mid);
    waitKey(0);
    imshow("效果图2", dst);
    waitKey(0);
    

    
}
