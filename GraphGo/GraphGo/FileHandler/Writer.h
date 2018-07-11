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

bool WriteKeyPointsForAll
(
	vector<string>& imgnames,
	vector<vector<KeyPoint>>& key_points_for_all,
	vector<Mat>& descriptor_for_all,
	vector<vector<Vec3b>>& colors_for_all
);