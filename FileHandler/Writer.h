#pragma once
#include <opencv2/imgproc/imgproc.hpp>  
#include <iostream>
#include "parseName.h"

using namespace cv;
using namespace std;


bool WriteKeyPoints
(
	string& imgname,
	vector<KeyPoint>& key_points,
	Mat& descriptor,
	vector<Vec3b> colors
);