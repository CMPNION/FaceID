//
// Created by Дмитрий Норкин on 20.10.2024.
//

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#endif //FUNCTIONS_HPP
#include <opencv2/opencv.hpp>
#include <filesystem>

#include <iostream>


class ErrorHandler;
using namespace std;
using namespace cv;
namespace fs = std::filesystem;



class Functions
{
  private:
    string hrc_directory = "../haarcascades/";
  public:

  //Эту функцию нет смысла переносить в эрроры потому что я так сказал
  int loadCascade(CascadeClassifier& cascade_classifier, const string &fname) const {
      if (!cascade_classifier.load(hrc_directory + fname)) {
        cout << "Error loading face cascade\n";
        return -1;
      }
      return 0;
    }

  void collectFaceSamples(VideoCapture& capture, CascadeClassifier& face_cascade, const string& savePath, const string sample_name) {

      loadCascade(face_cascade, "haarcascade_frontalface_default.xml");

        if (!fs::exists(savePath + sample_name)) {
            fs::create_directories(savePath + sample_name);
            cout << "Создана директория: " << savePath << endl;
        }

        int sampleCount = 0;
        Mat frame, gray;

        while (sampleCount < 20) {  // Собираем 20 изображений
            capture >> frame;

            cvtColor(frame, gray, COLOR_BGR2GRAY);  // Преобразуем в черно-белый формат
            vector<Rect> faces;

            // Детектируем лица на кадре
            face_cascade.detectMultiScale(gray, faces, 1.1, 3, 0, Size(100, 100));

            for (size_t i = 0; i < faces.size(); i++) {
                Mat faceROI = gray(faces[i]);

                // Формируем путь к файлу
                string fileName = savePath + sample_name + "/" + to_string(sampleCount) + ".jpg";
                cout << "Путь файла: " << fileName << endl;

                // Сохраняем изображение
                bool isSuccess = imwrite(fileName, faceROI);
                if (isSuccess) {
                    cout << "Сохранено: " << fileName << endl;
                } else {
                    cerr << "Ошибка: не удалось сохранить файл " << fileName << endl;
                }

                // Показываем прямоугольник вокруг лица
                rectangle(frame, faces[i], Scalar(255, 0, 0), 2);
                sampleCount++;
            }

            imshow("Collecting Face Data", frame);

        }
    }

};