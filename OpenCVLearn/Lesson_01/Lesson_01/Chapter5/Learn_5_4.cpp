//
//  Learn_5_4.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2018/1/3.
//  Copyright © 2018年 蔡欣东. All rights reserved.
//

#include "Learn_5_4.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

bool MultiChannelBlending();
void ShowHelpText();

void Learn_5_4::learn() {
    system("color 9F");
    if (MultiChannelBlending()) {
        cout<<endl<<"\n运行成功！";
    }
    waitKey(0);
}

bool MultiChannelBlending() {
    Mat srcImage;
    Mat logoImage;
    vector<Mat> channels;
    Mat imageBlueChannel;
    
    logoImage = imread("logo.jpg",0);
    srcImage = imread("dnf.jpg");
    
    if (!logoImage.data) {
        cout<<"load logo fail!"<<endl;
    }
    
    if (!srcImage.data) {
        cout<<"load src fail"<<endl;
    }
    
    split(srcImage, channels);
    
    imageBlueChannel = channels.at(0);
    addWeighted(imageBlueChannel(Rect(20,20,logoImage.cols,logoImage.rows)), 1.0, logoImage, 0.5, 0, imageBlueChannel(Rect(20,20,logoImage.cols,logoImage.rows)));
    
    merge(channels, srcImage);
    
    imshow("效果图", srcImage);
    
    return true;
}
