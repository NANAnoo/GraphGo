#include <opencv2\xfeatures2d\nonfree.hpp>
#include <opencv2\features2d\features2d.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\calib3d\calib3d.hpp>
#include <iostream>
#include "FileHandler/FileController.h"

using namespace cv;
using namespace std;

void extract_features(vector<string>& image_names,vector<vector<KeyPoint>>& key_points_for_all,vector<Mat>& descriptor_for_all,vector<vector<Vec3b>>& colors_for_all);

int match_features(Mat& query, Mat& train, vector<DMatch>& matches);

void match_features_for_all(vector<Mat>& descriptor_for_all, vector<vector<DMatch>>& matches_for_all, vector<int>& match_idx);