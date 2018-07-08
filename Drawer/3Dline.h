#pragma once
//Create by ZH
//a line in 3D space
#include <iostream>

#include <opencv2/highgui/highgui.hpp>  

#include <opencv2/imgproc/imgproc.hpp>  

#include <opencv2/core/core.hpp>  

#include <math.h>
using namespace cv;

using namespace std;

class line3D
{
public:

	line3D();

	//第一个点，第二个点,默认直线
	line3D(Point3d p1, Point3d p2);

	//第一个点，第二个点，是否截断p1,p2
	line3D(Point3d p1, Point3d p2,bool end1,bool end2);

	//判断是否在线上,true判断是否包含
	bool hasPoint(Point3d p,bool mode);

	//长度
	double length();

	//SET:
	bool setPoint1(Point3d p1);

	bool setPoint2(Point3d p2);

	void closePoint1();

	void closePoint2();

	void openPoint1();

	void openPoint2();

	//GET

	Point3d Point1();

	Point3d Point2();

	//向量
	double Vx;

	double Vy;

	double Vz;

	bool end1;

	bool end2;
private:
	Point3d p1;

	Point3d p2;

};
