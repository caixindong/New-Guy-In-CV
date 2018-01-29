//
//  Learn_4_1.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2017/12/25.
//  Copyright © 2017年 蔡欣东. All rights reserved.
//

#include "Learn_4_1.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void Learn_4_1::learn() {
    Mat m1(2, 2, CV_8UC3, Scalar(0,0,255));
    cout<<"M1 = "<<endl<<" "<<m1<<endl<<endl;
    
    Mat m2;
    //不能设置初始值，如果指定的参数与之前的参数相同则不进行是指的内存申请操作，如果参数不同，则重新申请内容
    m2.create(4, 4, CV_8UC(2));
    cout<<"M2 = "<<endl<<m2<<endl<<endl;
    
    Mat e = Mat::eye(4, 4, CV_64F);
    cout<<"E = "<<endl<<e<<endl<<endl;
    Mat o = Mat::ones(2, 2, CV_32F);
    cout<<"O = "<<endl<<o<<endl<<endl;
    Mat z = Mat::zeros(3, 3, CV_8UC1);
    cout<<"Z = "<<endl<<z<<endl<<endl;
    
    Mat c = (Mat_<double>(3,3) << 0,-1,0,-1,5,-1,0,-1,0);
    cout<<"C = "<<endl<<c<<endl<<endl;
    
    Mat rowClone = c.row(1).clone();
    cout<<"rowClone = "<<endl<<rowClone<<endl<<endl;
    
    //点表示
    Point point(1,2);
    cout<<"p = "<<point<<endl;
    //颜色表示 rgba
    Scalar color(122,123,122);
    //尺寸 width, height
    Size s(11,5);

    Mat img = imread("lena.jpeg");
    cvtColor(img, img, COLOR_BGR2Lab);
    imshow("效果图", img);
    waitKey(0);
    

}
