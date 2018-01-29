//
//  Learn_5_8.cpp
//  Lesson_01
//
//  Created by 蔡欣东 on 2018/1/15.
//  Copyright © 2018年 蔡欣东. All rights reserved.
//

#include "Learn_5_8.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void Learn_5_8::learn() {
    system("color 6F");
    
    FileStorage fs("test.yaml",FileStorage::READ);
    
    int framecount = (int)fs["frameCount"];
    
    std::string date;
    fs["calibrationDate"]>>date;
    
    Mat cameraMatrix,distCoeffs;
    fs["cameraMatrix"]>>cameraMatrix;
    fs["distCoeffs"]>>distCoeffs;
    
    cout<<"frameCount:"<<framecount<<endl
    <<"calibrationDate:"<<date<<endl
    <<"camera matrix:"<<cameraMatrix<<endl
    <<"distortion coeffs:"<<distCoeffs<<endl;
    
    FileNode features = fs["features"];
    FileNodeIterator it = features.begin(),it_end = features.end();
    int idx = 0;
    std::vector<uchar> lbpval;
    for (; it != it_end; ++it,idx++) {
        cout<<"feature #"<<idx<<":";
        cout<<"x="<<(int)(*it)["x"]<<",y="<<(int)(*it)["y"]<<",lbp:(";
        (*it)["lbp"]>>lbpval;
        for (int i = 0; i < (int)lbpval.size(); i++)
            cout<<" "<<(int)lbpval[i];
        cout<<")"<<endl;
    }
    
    fs.release();
    
    printf("\n结束了");
    getchar();
}
