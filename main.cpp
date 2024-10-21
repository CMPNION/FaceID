#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // Загрузка каскада Хаара для обнаружения лиц
    CascadeClassifier face_cascade;
    if (!face_cascade.load(cv::samples::findFile("haarcascade_frontalface_default.xml"))) {
        cout << "Ошибка: Не удалось загрузить каскад Хаара" << endl;
        return -1;
    }

    // Захват видеопотока с веб-камеры
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cout << "Ошибка: Не удалось открыть видеопоток" << endl;
        return -1;
    }

    // Максимальное количество лиц, которое мы хотим обнаружить
    const int MAX_FACES = 10;
    Rect faces[MAX_FACES];  // Массив для хранения прямоугольников лиц
    int faces_detected;

    Mat frame, gray_frame;

    while (true) {
        // Считывание текущего кадра
        cap >> frame;
        if (frame.empty()) {
            cout << "Ошибка: Не удалось получить кадр" << endl;
            break;
        }

        // Преобразование кадра в градации серого
        cvtColor(frame, gray_frame, COLOR_BGR2GRAY);
        equalizeHist(gray_frame, gray_frame);  // Уравнивание гистограммы для лучшего обнаружения

        // Обнаружение лиц
        faces_detected = 0;  // Счетчик обнаруженных лиц
        face_cascade.detectMultiScale(gray_frame, faces, MAX_FACES, faces_detected, 1.1, 5, 0, Size(30, 30));

        // Отрисовка прямоугольников вокруг обнаруженных лиц
        for (int i = 0; i < faces_detected; i++) {
            rectangle(frame, faces[i], Scalar(255, 0, 0), 2);
        }

        // Отображение текущего кадра с обнаруженными лицами
        imshow("Face Detection", frame);

        //  'q' для выхода
        if (waitKey(10) == 'q') {
            break;
        }
    }

    // Освобождение ресурсов
    cap.release();
    destroyAllWindows();

    return 0;
}
