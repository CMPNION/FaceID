#include <opencv2/opencv.hpp>           //чтобы видеть нахуй
#include <opencv2/objdetect.hpp>        //чтобы видел нахуй
#include "includes/errorHandler.hpp"    //Чтобы ошибки обраатываьб
#include <iostream>                     //сиауты сам аутист
#include <filesystem>                   //для нахуй фалов отрыть делать
#include <vector>                       //чтобы массивы ебащить
#include <sstream>                      //чтобы я хз зочем

using namespace cv;
using namespace std;


//структура для директорий
struct Links {
public:
    string faces = "/Users/cmpnion/CLionProjects/untitled/faces";
    string haarascascades = "/Users/cmpnion/CLionProjects/untitled/haarcascades";
};

//Инициализируем глобально всю хуйню
Mat             frame;             // картинка с камеры далбаеб
ErrorHandler    eh;                // катчер ошибок
VideoCapture    cap(0);      //  индекс 0 - дефолт камера устройства

int main(){
    eh.checkCamera(cap);                                        //чек на далбаебааааа

    while(true)
    {
        cap >> frame;                                              //Тут передаем изображение с камеры на цею хуню
        eh.isEmptyFrame(frame);                                 //чекаем фрейм если камера короче пусто там если




        imshow("frame", frame);                       //вывели фрейм
        if(waitKey(30) == 27)
        {
            break;
        }                           // эскейп чтобы выйти


    }

    cap.release(); //вывели камеру
    destroyAllWindows(); // Закрыли все окна опенсв

    return 0;
}
