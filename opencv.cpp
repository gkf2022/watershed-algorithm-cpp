#include<opencv2/opencv.hpp>
#include<opencv2/core/utils/logger.hpp>

#include<iostream>
using namespace std;
using namespace cv;
int main() {
    cv::utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_SILENT);

    //Read in image and display attributes
    Mat image;
    image = imread("beans.png", IMREAD_GRAYSCALE);  
    
    int w = image.rows;
    int h = image.cols;
    int c = image.channels();

    cout << w << " x " << h << " :: " << c << " channels " << endl;

    //Define matrix with threshold RGB value
    //All pixels falling below this value will be converted to black
    Mat mat_threshold(w, h, CV_8U,220);
    Mat mat_res = image - mat_threshold;
    mat_res *= 255;

    //Invert the previous result (black to white and vice-versa)
    Mat mat_inv(w, h, CV_8U, 255);
    mat_res = mat_inv - mat_res;

    //Show the image result in a window
    imshow("I;m thinkin bout thos Beans", mat_res);
    waitKey(0);

    return 0;
}