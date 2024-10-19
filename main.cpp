#include <opencv2/opencv.hpp>           //Для газеринга основных методов св
#include <opencv2/objdetect.hpp>        //Для детекта обьектов
#include "includes/errorHandler.hpp"    //Чтобы ошибки обраатываь
#include "includes/functions.hpp"       //Тут основные функции. Читать хедер, там тоже комменты
#include <filesystem>                   //для нахуй фалов отрыть делать
#include <vector>                       //динамический массив

using namespace cv;
using namespace std;


//Инициализируем глобально всю хуйню
Mat               frame;
ErrorHandler      eh;
Functions         functions;
VideoCapture      cap(0);
CascadeClassifier face_cascade;
vector<Rect>      faces_detected;


int main(){

    eh.checkCamera(cap); //чекаем камеру
    functions.loadCascade(face_cascade, "haarcascade_frontalface_default.xml"); //подгружаем обученный каскад фронтового лица




    while(true)
    {
        cap >> frame;
        eh.isEmptyFrame(frame);


        //Обнаружение и отрисовка прямоугольна лиц



        // Обнаружение лиц
        face_cascade.detectMultiScale(frame, faces_detected);

        // Рисуем прямоугольники вокруг обнаруженных лиц
        for(size_t i = 0; i < faces_detected.size(); i++) {
            rectangle(frame, faces_detected[i], Scalar(255, 0, 0), 2);
        }



        //showing frame
        imshow("frame", frame);

        //waiting escape
        if(waitKey(30) == 27) {
            break;
        }


    }

    cap.release();
    destroyAllWindows();

    return 0;
}
