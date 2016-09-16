#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cout << "Cannot open the video cam" << endl;
        return -1;
    }
    double dWidth  = cap.get(CV_CAP_PROP_FRAME_WIDTH);
    double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    cout << "Frame size:" << dWidth << " x " << dHeight << endl;
    namedWindow("MyVideo",CV_WINDOW_AUTOSIZE);
    while(1) {
        Mat frame;
        bool bSuccess = cap.read(frame);
        if (!bSuccess) {
            cout << "Cannot read a frame from video stream" << endl;
            break;
        }
        imshow("MyVideo",frame);
        if (waitKey(30) == 27) {
            cout << "esc key is pressed by user" << endl;
            break;
        }
    }
    return 0;
}
