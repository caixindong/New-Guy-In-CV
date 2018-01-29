//
//  Learn_3_3.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2017/12/19.
//  Copyright © 2017年 蔡欣东. All rights reserved.
//

#include "Learn_3_3.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

#define WINDOW_NAME "窗口"

void on_MouseHandle(int event, int x, int y, int flags, void *param);
void DrawRectangle(Mat &img, Rect box);
void ShowHelpText();

Rect g_rectangle;
bool g_bDrawingBox = false;
//生成随机数
RNG g_rng(12345);

void Learn_3_3::learn() {
    g_rectangle = Rect(-1, -1, 0, 0);
    Mat srcImage(300,400,CV_8UC3), tempImage;
    srcImage.copyTo(tempImage);
    srcImage = Scalar::all(0);
    
    namedWindow(WINDOW_NAME);
    setMouseCallback(WINDOW_NAME, on_MouseHandle,(void *)&srcImage);
    g_bDrawingBox = true;
    srcImage.copyTo(tempImage);
    if (g_bDrawingBox) {
        DrawRectangle(tempImage, g_rectangle);
    }
    waitKey(0);
}

void on_MouseHandle(int event, int x, int y, int flags, void *param) {
    Mat &image = *(Mat *)param;
    switch (event) {
        case EVENT_MOUSEMOVE:{
            if (g_bDrawingBox) {
                g_rectangle.width = x - g_rectangle.x;
                g_rectangle.height = y - g_rectangle.y;
            }
        }
        break;
        case EVENT_LBUTTONDOWN: {
            g_bDrawingBox = true;
            g_rectangle = Rect(x, y, 0, 0);
        }
        break;
        case EVENT_LBUTTONUP: {
            g_bDrawingBox = false;
            if (g_rectangle.width < 0) {
                g_rectangle.x += g_rectangle.width;
                g_rectangle.width *= -1;
            }
            if(g_rectangle.height < 0) {
                g_rectangle.y += g_rectangle.height;
                g_rectangle.height *= -1;
            }
            
            DrawRectangle(image, g_rectangle);
        }
        break;
        default:
        break;
    }
}

void DrawRectangle(Mat &img, Rect box) {
    rectangle(img, box.tl(), box.br(), Scalar(g_rng.uniform(0, 255),g_rng.uniform(0, 255),g_rng.uniform(0, 255)));
    imshow(WINDOW_NAME, img);

}

