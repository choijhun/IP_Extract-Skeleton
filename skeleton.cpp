#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include <opencv2/core.hpp>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
using namespace cv;
using namespace std;

#ifdef _DEBUG
#pragma comment(lib,"opencv_world490d.lib")
#else
#pragma comment(lib,"opencv_world490.lib")
#endif


int main(void)
{
    // Load the original image
    Mat src = imread("C:/Users/choij/Desktop/sk1.png", IMREAD_GRAYSCALE);
    Mat element = getStructuringElement(MORPH_CROSS, Size(3, 3), Point(1, 1));

    Mat inverted;
    bitwise_not(src, inverted); // Èæ¹é ÀüÈ¯

    Mat X, Y;

    Mat Difference;
    Mat S = Mat::zeros(inverted.size(), inverted.type());
    Mat previous_S, D0;
    erode(inverted, X, element);
    dilate(X, Y, element);
    subtract(inverted, Y, D0); // X¸¦ inverted·Î ¹Ù²ã¾ßÇÔ
    bitwise_or(S, D0, S);


    while (true) {

        erode(inverted, X, element);

        erode(X, Y, element);
        dilate(Y, Y, element);

        subtract(X, Y, Difference);
        previous_S = S.clone();
        bitwise_or(S, Difference, S);
        if (countNonZero(previous_S != S) == 0) {
            break;
        }
        inverted = X.clone();


    }
    
    imshow("original image", src);


   
    imshow("Skeleton", S);

    waitKey(0);
    return 0;

}
