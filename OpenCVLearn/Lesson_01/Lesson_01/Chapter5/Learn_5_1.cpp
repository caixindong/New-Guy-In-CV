//
//  Learn_5_1.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2017/12/28.
//  Copyright © 2017年 蔡欣东. All rights reserved.
//

#include "Learn_5_1.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void colorReduce(Mat &input, Mat &output, int div);
void colorReduce_02(Mat &input, Mat &output, int div);
void colorReduce_03(Mat &input, Mat &output, int div);


void Learn_5_1::learn() {
    Mat srcImage = imread("lena.jpeg");
    imshow("原始图像", srcImage);
    waitKey(0);

    Mat dstImage;
    dstImage.create(srcImage.rows, srcImage.cols, srcImage.type());
    //记录起始的时钟周期数
    double time0 = static_cast<double>(getTickCount());
    //颜色空间缩减函数
    colorReduce_03(srcImage,dstImage,32);
    //getTickFrequency CPU一秒钟所走的时钟周期数
    time0 = ((double)getTickCount() - time0)/getTickFrequency();
    
    cout<<"运行时间为"<<time0<<"秒"<<endl;
    
    imshow("效果图", dstImage);
    
    waitKey(0);
}

void colorReduce(Mat &input, Mat &output, int div) {
    output = input.clone();
    int row = output.rows;
    int col = output.cols * output.channels();
    
    for (int i = 0; i < row; i++) {
        //ptr可以获取第i行的首地址
        uchar *data = output.ptr<uchar>(i);
        for (int j = 0; j < col; j++) {
            data[j] = data[j]/div * div + div/2;
        }
    }
}

void colorReduce_02(Mat &input, Mat &output, int div) {
    output = input.clone();
    Mat_<Vec3b>::iterator it = output.begin<Vec3b>();
    Mat_<Vec3b>::iterator itend = output.end<Vec3b>();
    
    for (; it != itend; it++) {
        (*it)[0] = (*it)[0]/div * div + div/2;
        (*it)[1] = (*it)[1]/div * div + div/2;
        (*it)[2] = (*it)[2]/div * div + div/2;

    }
}

void colorReduce_03(Mat &input, Mat &output, int div) {
    output = input.clone();
    int row = output.rows;
    int col = output.cols;
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            output.at<Vec3b>(i,j)[0] = output.at<Vec3b>(i,j)[0]/div * div + div/2;
            output.at<Vec3b>(i,j)[1] = output.at<Vec3b>(i,j)[1]/div * div + div/2;
            output.at<Vec3b>(i,j)[2] = output.at<Vec3b>(i,j)[2]/div * div + div/2;
        }
    }
}
