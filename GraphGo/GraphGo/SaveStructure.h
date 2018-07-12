#include <opencv2\xfeatures2d\nonfree.hpp>
#include <opencv2\features2d\features2d.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\calib3d\calib3d.hpp>
#include <iostream>
#include "GetPoints.h"
#include "Transform.h"

using namespace cv;
using namespace std;

int init_structure(Mat K, vector<vector<KeyPoint>>& key_points_for_all, vector<vector<Vec3b>>& colors_for_all, vector<vector<DMatch>>& matches_for_all, vector<Point3f>& structure, vector<vector<int>>& correspond_struct_idx, vector<Vec3b>& colors, vector<Mat>& rotations, vector<Mat>& motions, vector<int>& match_idx, int idx);

void reconstruct(Mat& K, Mat& R1, Mat& T1, Mat& R2, Mat& T2, vector<Point2f>& p1, vector<Point2f>& p2, vector<Point3f>& structure);

void fusion_structure(vector<DMatch>& matches, vector<int>& struct_indices, vector<int>& next_struct_indices, vector<Point3f>& structure, vector<Point3f>& next_structure, vector<Vec3b>& colors, vector<Vec3b>& next_colors);

void save_structure(string file_name, vector<Mat>& rotations, vector<Mat>& motions, vector<Point3f>& structure, vector<Vec3b>& colors);

