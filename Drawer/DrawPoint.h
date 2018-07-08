#pragma once
#include <iostream>

#include <opencv2/highgui/highgui.hpp>  

#include <opencv2/imgproc/imgproc.hpp>  

#include <opencv2/core/core.hpp>  

using namespace cv;

class DrawPoint
{
public:
	DrawPoint(Point3d p,int r,int g,int b);
	DrawPoint();
	Point3d P;
	int R;
	int G;
	int B;
};