#include "Writer.h"
/*
Write the keypoints of one img
*/
bool WriteKeyPoints
( string & imgname, vector<KeyPoint>& key_points, Mat & descriptor, vector<Vec3b> colors)
{
	string fileName = ".\\KeyPoints\\" + parseName(imgname) ;

	FileStorage fs(fileName, FileStorage::WRITE);

	if (!fs.isOpened()) {
		fs.release();
		return false;
	}

	fs << "Key Points" << "[";
	for (int i = 0; i < key_points.size(); i++) {
		fs << key_points[i];
	}
	fs << "]";

	fs << "Descriptor"<< descriptor;

	fs << "Colors" << "[";
	for (int i = 0; i < colors.size(); i++ ) {
		fs << colors[i];
	}
	fs << "]";

	fs.release();

	return true;
}
/*
Write the keypoints of all imgs
*/
bool WriteKeyPointsForAll
( vector<string>& imgnames,vector<vector<KeyPoint>>& key_points_for_all, vector<Mat>& descriptor_for_all, vector<vector<Vec3b>>& colors_for_all)
{
	int N = imgnames.size();

	for (int i= 0; i < N; i++) {
		if (WriteKeyPoints(imgnames[i], key_points_for_all[i], descriptor_for_all[i], colors_for_all[i]))
			cout << imgnames[i] << "write in successful!"<<endl;
		else
			cout << imgnames[i] << "write in false."<<endl;
	}
	return true;
}
