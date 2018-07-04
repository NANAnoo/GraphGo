#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	Mat image = imread("C:\\Users\\CYX\\Desktop\\1.jpg");  //存放自己图像的路径 
	imshow("显示图像", image);
	waitKey(0);
	return 0;
}