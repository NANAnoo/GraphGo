#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	Mat image = imread("C:\\Users\\CYX\\Desktop\\1.jpg");  //����Լ�ͼ���·�� 
	imshow("��ʾͼ��", image);
	waitKey(0);
	return 0;
}