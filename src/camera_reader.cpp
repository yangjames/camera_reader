#include <ros/ros.h>
#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char **argv) {
    ros::init(argc, argv, "camera_reader");
    ros::NodeHandle n;
    ros::Rate loop_rate(100);
    cv::VideoCapture cap(0);

    if (!cap.isOpened()) {
        std::cout << "Cannot open the video cam" << std::endl;
        return -1;
    }
    double dWidth  = cap.get(CV_CAP_PROP_FRAME_WIDTH);
    double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    std::cout << "Frame size:" << dWidth << " x " << dHeight << std::endl;

    cv::namedWindow("MyVideo",CV_WINDOW_AUTOSIZE);

    while(ros::ok()) {
        cv::Mat frame;
        bool bSuccess = cap.read(frame);
        if (!bSuccess) {
            std::cout << "Cannot read a frame from video stream" << std::endl;
            break;
        }
        cv::imshow("MyVideo",frame);
        cv::waitKey(1);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
