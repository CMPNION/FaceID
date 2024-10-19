

//
// Created by Дмитрий Норкин on 20.10.2024.
//

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#endif //FUNCTIONS_HPP
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;

class Functions
{
  private:
    string hrc_directory = "../haarcascades/";
    string faces_directory = "../faces/";
  public:

  int loadCascade(CascadeClassifier& cascade_classifier, const string &fname) const {
      if (!cascade_classifier.load(hrc_directory + fname)) {
        cout << "Error loading face cascade\n";
        return -1;
      }
      return 0;
    }

};