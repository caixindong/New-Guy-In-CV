//
//  Learn_facedetect.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2018/3/22.
//  Copyright © 2018年 蔡欣东. All rights reserved.
//

#include "Learn_facedetect.hpp"
#include <opencv2/opencv.hpp>
#include <string>
#include <iostream>
using namespace cv;
using namespace std;

void Pic2Gray(Mat camerFrame,Mat &gray)
{
    //普通台式机3通道BGR,移动设备为4通道
    if (camerFrame.channels() == 3)
    {
        cvtColor(camerFrame, gray, CV_BGR2GRAY);
    }
    else if (camerFrame.channels() == 4)
    {
        cvtColor(camerFrame, gray, CV_BGRA2GRAY);
    }
    else
        gray = camerFrame;
}

void LearnFace::learn(){
    CascadeClassifier faceDetector;
    string faceCascadeFilename = "haarcascade_frontalface_default.xml";
    
    try {
        faceDetector.load(faceCascadeFilename);
    } catch (Exception e) {
        
    }
    if (faceDetector.empty()) {
        cerr<<"脸部检测器不能加载(";
        cerr<<faceCascadeFilename<<")!"<<endl;
        exit(1);
    }
    
    VideoCapture camera(0);
    while (true) {
        Mat cameraframe;
        camera>>cameraframe;
        if (cameraframe.empty()) {
            cerr<<"无法获取摄像头图像"<<endl;
            getchar();
            exit(1);
        }
        Mat displayFrame(cameraframe.size(),CV_8UC3);
        
        //人脸检测只试用于灰度图像
        Mat gray;
        Pic2Gray(cameraframe, gray);
        
        //直方图均匀化(改善图像的对比度和亮度)
        Mat equalizedImg;
        equalizeHist(gray, equalizedImg);
        
        
        //只检测脸最大的人
        int flags = CASCADE_FIND_BIGGEST_OBJECT|CASCADE_DO_ROUGH_SEARCH;
        Size minFeatureSize(30, 30);
        float searchScaleFactor = 1.1f;
        int minNeighbors = 4;
        
        vector<Rect> faces;
        faceDetector.detectMultiScale(cameraframe, faces,searchScaleFactor,minNeighbors,flags,minFeatureSize);
    
        Mat face;
        Point text_lb;
        for (size_t i = 0; i < faces.size(); i++) {
            if (faces[i].height > 0 && faces[i].width > 0) {
                face = gray(faces[i]);
                text_lb = Point(faces[i].x,faces[i].y);
                rectangle(cameraframe, faces[i], cv::Scalar(255, 0, 0), 1, 8, 0);
            }
        }
        
        imshow("face", cameraframe);
        waitKey(30);
    }
    

    
}
