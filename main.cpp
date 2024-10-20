#include "includes/ocvManager.hpp"



using namespace std;




Mat               frame;
VideoCapture      cap(0);
CascadeClassifier face_cascade;
vector<Rect>      faces_detected;


int main(){

    eh.checkCamera(cap);

    functions.loadCascade(face_cascade, "haarcascade_frontalface_default.xml");

    while(true)
    {

        face_recognition.detectFace(frame, cap, faces_detected, face_cascade);\

        eh.isEmptyFrame(frame);

        imshow("frame", frame);

        if (waitKey(40) == 27) break;

    }

    cap.release();

    destroyAllWindows();

    return 0;
}
