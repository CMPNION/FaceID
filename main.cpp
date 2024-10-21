
#include "includes/ocvManager.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <filesystem>
#include <iostream>

using namespace std;
using namespace cv;
namespace fs = std::filesystem;


Mat               frame;
VideoCapture      cap(0);
CascadeClassifier face_cascade;
vector<Rect>      faces_detected;
string             sample_name;


int main(){

    eh.checkCamera(cap);

    functions.loadCascade(face_cascade, "haarcascade_frontalface_default.xml");

    while(true)
    {

        //face_recognition.detectFace(frame, cap, faces_detected, face_cascade); //тут детект лица
        functions.collectFaceSamples(cap, face_cascade,"../faces/"  ,sample_name ); //тут сбор семплов
        eh.isEmptyFrame(frame); //чек на пустой кадр
        cin >> sample_name;
        imshow("frame", frame);

        if (waitKey(40) == 27) break; //ескейп чтобы не кушало ресурсы

    }

    cap.release();
    destroyAllWindows();

    return 0;
}


//лучше тестировать на монотонном фоне для исключения погрешностей