#pragma once
#include <opencv2/imgproc/imgproc.hpp>  
#include <iostream>
#include "parseName.h"

using namespace cv;
using namespace std;


/*
Read the structure file
*/
bool ReadPointCloud(string filename, vector<Mat>&rotations, vector<Mat>&motions, vector<Point3f>&points, vector<Vec3b>&colors);

/*
Read the keypoints file of a picture
*/
bool ReadKeyPoints(string& imgname,vector<KeyPoint>&key_points,Mat& descriptor, vector<Vec3b>& colors);
