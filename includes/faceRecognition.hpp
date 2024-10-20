//
// Created by Дмитрий Норкин on 21.10.2024.
//

#ifndef FACERECOGNITION_HPP
#define FACERECOGNITION_HPP

#endif //FACERECOGNITION_HPP

#include <opencv2/opencv.hpp>           //Для газеринга основных методов св
#include <opencv2/objdetect.hpp>        //Для детекта обьектов
#include <opencv2/highgui/highgui.hpp>  //для норм гиюай
#include <opencv2/imgproc/imgproc.hpp>  // для да
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/face.hpp>
#include <filesystem>                   //для нахуй фалов отрыть делать
#include <vector>  //динамический массив

using namespace std;
using namespace cv;
using namespace cv::face;


class FaceRecognition{
  private:
  public:
    void detectFace(Mat& frame, VideoCapture& cap, vector<Rect>& faces_detected, CascadeClassifier& face_cascade){
      cap >> frame;
      face_cascade.detectMultiScale(frame, faces_detected);

      for(size_t i = 0; i < faces_detected.size(); i++) {
        rectangle(frame, faces_detected[i], Scalar(255, 0, 0), 2);
      }


    }


};