
//
//  Learn_7_5.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2018/3/27.
//  Copyright © 2018年 蔡欣东. All rights reserved.
//

#include "Learn_7_5.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void Learn_7_5::learn() {
    Mat img = imread("ganda.jpg");
    Mat dst;
    img.copyTo(dst);
    Mat mid;
    Canny(img, mid, 50, 200,3);
    vector<Vec4i> lines;
    HoughLinesP(mid, lines, 1, CV_PI/180, 80,10,10);
    for (size_t i = 0; i < lines.size(); i++) {
        Vec4i l = lines[i];
        line(dst, Point(l[0],l[1]), Point(l[2],l[3]), Scalar(0,0,255));
    }
    
    imshow("原图", img);
    waitKey(0);
    imshow("效果", dst);
    waitKey(0);

}
