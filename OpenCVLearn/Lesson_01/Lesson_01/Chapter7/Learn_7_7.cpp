//
//  Learn_7_7.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2018/4/12.
//  Copyright © 2018年 蔡欣东. All rights reserved.
//

#include "Learn_7_7.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

void Learn_7_7::learn() {
    Mat img,dst,map_x,map_y,dst2;
    img = imread("lena.jpeg");
    dst.create(img.size(),img.type());
    dst2.create(img.size(),img.type());

    map_x.create(img.size(), CV_32FC1);
    map_y.create(img.size(), CV_32FC1);
    //h(x,y) = (img.cols-x,y)，会按x轴翻转
    //map_x相当于img.cols-x
    //map_y相当于y
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            map_x.at<float>(i,j) = static_cast<float>(img.cols - j);
            map_y.at<float>(i,j) = static_cast<float>(img.rows - i);
        }
    }
    
    remap(img, dst, map_x, map_y, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0,0,0));
    imshow("origin", img);
    waitKey(0);
    imshow("show", dst);
    waitKey(0);
    
    for (int i = 0; i< img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            if (i>img.rows*0.25&&i<img.rows*0.75&&j>img.cols*0.25&&j<img.cols*0.75) {
                map_x.at<float>(i,j) = 2*(j - img.cols*0.25) + 0.5;
                map_y.at<float>(i,j) = 2*(i - img.rows*0.25) + 0.5;
            } else {
                map_x.at<float>(i,j) = 0;
                map_y.at<float>(i,j) = 0;
            }
        }
    }
    remap(img, dst2, map_x, map_y, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0,0,0));
    imshow("show2", dst2);
    waitKey(0);
}
