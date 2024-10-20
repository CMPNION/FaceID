#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <filesystem>
#include <vector>
#include <sstream>


#ifndef ERRORHANDLER_HPP
#define ERRORHANDLER_HPP

#endif //ERRORHANDLER_HPP


using namespace std;
using namespace cv;

class ErrorHandler {
    public:
    int checkCamera(VideoCapture& cap)
    {
        if (!cap.isOpened())
        {
            cout << "Error: Could not open the camera." << endl;
            return -1;
        }
        cout << "Opened the camera." << endl;
        return 0;
    }

    void isEmptyFrame(Mat& frame){
        if (frame.empty())
        {
            cout << "Error: Blank frame grabbed." << endl;
        }

    }


};



