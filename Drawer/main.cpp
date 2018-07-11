//#include <opencv2/highgui/highgui.hpp>  
//
//#include <opencv2/imgproc/imgproc.hpp>  
//
//#include <opencv2/core/core.hpp>  
//
//#include <iostream>
//
//#include <time.h>
//
//#include "PointCloud.h"
//
//
//using namespace cv;
//using namespace std;
//
///*
//string static getTime()
//{
//	time_t timep;
//	time(&timep);
//	char tmp[64];
//	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
//	return tmp;
//}*/
//
//int main()
//
//{
//	double PI = 4*atan(1);
//	//line3D* l = new line3D(p1,p2);
//	Point3d p1, p2, p3, p4, p5,ball, ball1, ball2;
//	//Ball = new Point3d[1000000];
//	/*Ball2 = new Point3d[1000000];
//	Ball1 = new Point3d[1000000];*/
//	DrawPoint *cloud;
//
//	cloud = new DrawPoint[10000];
//
//	p1.x = 0;
//	p1.y = 0;
//	p1.z = 0;
//	p2.x = 1;
//	p2.y = 0;
//	p2.z = 0;
//	p3.x = 100;
//	p3.z = 10;
//	p3.y = 100;
//	p4.x = 0;
//	p4.y = 1;
//	p4.z = 0;
//	p5.x = 0;
//	p5.y = 0;
//	p5.z = 1;
//	
//	ball.x = 20;
//	ball.y = 0;
//	ball.z = 0;
//
//	ball1.x = 10;
//	ball1.y = 0;
//	ball1.z = 0;
//
//	ball2.x = 10;
//	ball2.y = 0;
//	ball2.z = 0;
//	
//
//	double A = 0.0;
//	
//		double a, b, C, h;
//		h = 0.01;
//
//		for (int i = 1; i < 3333; i++) {
//			a = 15.0;
//			b = 35.0;
//			C = 2.5;
//
//			ball.x = ball.x + h*a*(ball.y - ball.x);
//			ball.y = ball.y + h*(ball.x*(b - ball.z) - ball.y);
//			ball.z = ball.z + 0.01*(ball.x*ball.y - ball.z*C);
//			a = 15.0;
//			b = 25.0;
//			C = 8.0 / 3.0;
//
//			ball1.x = ball1.x + h*a*(ball1.y - ball1.x);
//			ball1.y = ball1.y + h*(ball1.x*(b - ball1.z) - ball1.y);
//			ball1.z = ball1.z + 0.01*(ball1.x*ball1.y - ball1.z*C);
//
//			a = 15.0;
//			b = 30.0;
//			C = 4;
//
//			ball2.x = ball2.x + h*a*(ball2.y - ball2.x);
//			ball2.y = ball2.y + h*(ball2.x*(b - ball2.z) - ball2.y);
//			ball2.z = ball2.z + 0.01*(ball2.x*ball2.y - ball2.z*C);
//
//			cloud[3*i].P = ball;
//			cloud[3 * i].R = 255;
//
//			cloud[3*i+1].P = ball1;
//			cloud[3 * i+1].G = 255;
//
//			cloud[3*i+2].P = ball2;
//			cloud[3 * i+2].B = 255;
//		}
//
//		PointCloud* PC = new PointCloud();
//
//		PC->SetCloud(cloud, 10000);
//
//		PC->SetCamera(p3, 0, PI / 4);
//
//		PC->Show();
//		/*
//		for (int i = 0; i < 100; i++) {
//			for (int j = 0; j < 100; j++) {
//				b = 2.0 * PI*(double)i / 99.0;
//				a = 4.0 * PI*(double)j / 99.0;
//				ball.x = 10 * cos(a)*cos(b);
//				ball.y = 10 * sin(a)*cos(b);
//				ball.z = 10 * (sin(b)+a);
//				Ball[i * 100 + j] = ball;
//			}
//		}*/
//		//莫比乌斯
//		/*
//		for (int i = 0; i < 1000; i++) {
//			for (int j = 0; j < 1000; j++) {
//				b = 2.0 * PI*(double)i / 99.0;
//				a = -1 + 2 * (double)j / 99.0;
//				ball.x = 20*(1.0 + (a / 2)*cos(b / 2))*cos(b);
//				ball.y = 20 * (1.0 + (a / 2)*cos(b / 2))*sin(b);
//				ball.z = 20 * (a / 2)*sin(b / 2);
//				Ball[i * 100 + j] = ball;
//			}
//		}
//		*/
//		/*for (int i = 0; i < 100; i++) {
//			for (int j = 0; j < 100; j++) {
//				b = 6.0 * PI*(double)i / 99.0;
//				a = 6.0 * PI*(double)j / 99.0;
//				ball.x = 20*cos(a)*sin(b/a);
//				ball.y = 20*sin(a)*cos(a/b);
//				ball.z = 20*(sin(a + b)+ cos(a * b));
//				Ball[i * 100 + j] = ball;
//			}
//		}*/
//
//		/*for (int i = 0; i < 10000; i++) {
//				ball.x += 2 * ((double)rand() / RAND_MAX - 0.5);
//				ball.y += 2 * ((double)rand() / RAND_MAX - 0.5);
//				ball.z += 2 * ((double)rand() / RAND_MAX - 0.5);
//				Ball[i] = ball;
//		}*/
//
//		/*line3D *l1, *l2, *l3,  *DLT[6];
//		l1 = new line3D(p1, p2, true, false);
//		l2 = new line3D(p1, p4, true, false);
//		l3 = new line3D(p1, p5, true, false);*/
//
//
//}

#include <opencv2\xfeatures2d\nonfree.hpp>
#include <opencv2\features2d\features2d.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\calib3d\calib3d.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void extract_features(
	vector<string>& image_names,
	vector<vector<KeyPoint>>& key_points_for_all,
	vector<Mat>& descriptor_for_all,
	vector<vector<Vec3b>>& colors_for_all
)
{
	key_points_for_all.clear();
	descriptor_for_all.clear();
	Mat image;

	//读取图像，获取图像特征点，并保存
	Ptr<Feature2D> sift = xfeatures2d::SIFT::create(0, 3, 0.04, 10);
	for (auto it = image_names.begin(); it != image_names.end(); ++it)
	{
		image = imread(*it);
		if (image.empty()) continue;

		vector<KeyPoint> key_points;
		Mat descriptor;
		//偶尔出现内存分配失败的错误
		sift->detectAndCompute(image, noArray(), key_points, descriptor);

		//特征点过少，则排除该图像
		if (key_points.size() <= 10) continue;

		key_points_for_all.push_back(key_points);
		descriptor_for_all.push_back(descriptor);

		vector<Vec3b> colors(key_points.size());
		for (int i = 0; i < key_points.size(); ++i)
		{
			Point2f& p = key_points[i].pt;
			colors[i] = image.at<Vec3b>(p.y, p.x);
		}
		colors_for_all.push_back(colors);
	}
}

void match_features(Mat& query, Mat& train, vector<DMatch>& matches)
{
	vector<vector<DMatch>> knn_matches;
	BFMatcher matcher(NORM_L2);
	matcher.knnMatch(query, train, knn_matches, 2);

	//获取满足Ratio Test的最小匹配的距离
	float min_dist = FLT_MAX;
	for (int r = 0; r < knn_matches.size(); ++r)
	{
		//Ratio Test
		if (knn_matches[r][0].distance > 0.6*knn_matches[r][1].distance)
			continue;

		float dist = knn_matches[r][0].distance;
		if (dist < min_dist) min_dist = dist;
	}

	matches.clear();
	for (size_t r = 0; r < knn_matches.size(); ++r)
	{
		//排除不满足Ratio Test的点和匹配距离过大的点
		if (
			knn_matches[r][0].distance > 0.6*knn_matches[r][1].distance ||
			knn_matches[r][0].distance > 5 * max(min_dist, 10.0f)
			)
			continue;

		//保存匹配点
		matches.push_back(knn_matches[r][0]);
	}
}

bool find_transform(Mat& K, vector<Point2f>& p1, vector<Point2f>& p2, Mat& R, Mat& T, Mat& mask)
{
	//根据内参矩阵获取相机的焦距和光心坐标（主点坐标）
	double focal_length = 0.5*(K.at<double>(0) + K.at<double>(4));
	Point2d principle_point(K.at<double>(2), K.at<double>(5));

	//根据匹配点求取本征矩阵，使用RANSAC，进一步排除失配点
	Mat E = findEssentialMat(p1, p2, focal_length, principle_point, RANSAC, 0.999, 1.0, mask);
	if (E.empty()) return false;

	double feasible_count = countNonZero(mask);
	cout << (int)feasible_count << " -in- " << p1.size() << endl;
	//对于RANSAC而言，outlier数量大于50%时，结果是不可靠的
	if (feasible_count <= 15 || (feasible_count / p1.size()) < 0.6)
		return false;

	//分解本征矩阵，获取相对变换
	int pass_count = recoverPose(E, p1, p2, R, T, focal_length, principle_point, mask);

	//同时位于两个相机前方的点的数量要足够大
	if (((double)pass_count) / feasible_count < 0.7)
		return false;

	return true;
}

void get_matched_points(
	vector<KeyPoint>& p1,
	vector<KeyPoint>& p2,
	vector<DMatch> matches,
	vector<Point2f>& out_p1,
	vector<Point2f>& out_p2
)
{
	out_p1.clear();
	out_p2.clear();
	for (int i = 0; i < matches.size(); ++i)
	{
		out_p1.push_back(p1[matches[i].queryIdx].pt);
		out_p2.push_back(p2[matches[i].trainIdx].pt);
	}
}

void get_matched_colors(
	vector<Vec3b>& c1,
	vector<Vec3b>& c2,
	vector<DMatch> matches,
	vector<Vec3b>& out_c1,
	vector<Vec3b>& out_c2
)
{
	out_c1.clear();
	out_c2.clear();
	for (int i = 0; i < matches.size(); ++i)
	{
		out_c1.push_back(c1[matches[i].queryIdx]);
		out_c2.push_back(c2[matches[i].trainIdx]);
	}
}

void reconstruct(Mat& K, Mat& R, Mat& T, vector<Point2f>& p1, vector<Point2f>& p2, Mat& structure)
{
	//两个相机的投影矩阵[R T]，triangulatePoints只支持float型
	Mat proj1(3, 4, CV_32FC1);
	Mat proj2(3, 4, CV_32FC1);

	proj1(Range(0, 3), Range(0, 3)) = Mat::eye(3, 3, CV_32FC1);
	proj1.col(3) = Mat::zeros(3, 1, CV_32FC1);

	R.convertTo(proj2(Range(0, 3), Range(0, 3)), CV_32FC1);
	T.convertTo(proj2.col(3), CV_32FC1);

	Mat fK;
	K.convertTo(fK, CV_32FC1);
	proj1 = fK * proj1;
	proj2 = fK * proj2;

	//三角重建
	triangulatePoints(proj1, proj2, p1, p2, structure);
}

void maskout_points(vector<Point2f>& p1, Mat& mask)
{
	vector<Point2f> p1_copy = p1;
	p1.clear();

	for (int i = 0; i < mask.rows; ++i)
	{
		if (mask.at<uchar>(i) > 0)
			p1.push_back(p1_copy[i]);
	}
}

void maskout_colors(vector<Vec3b>& p1, Mat& mask)
{
	vector<Vec3b> p1_copy = p1;
	p1.clear();

	for (int i = 0; i < mask.rows; ++i)
	{
		if (mask.at<uchar>(i) > 0)
			p1.push_back(p1_copy[i]);
	}
}

void save_structure(string file_name, vector<Mat>& rotations, vector<Mat>& motions, Mat& structure, vector<Vec3b>& colors)
{
	int n = (int)rotations.size();

	FileStorage fs(file_name, FileStorage::WRITE);
	fs << "Camera Count" << n;
	fs << "Point Count" << structure.cols;

	fs << "Rotations" << "[";
	for (size_t i = 0; i < n; ++i)
	{
		fs << rotations[i];
	}
	fs << "]";

	fs << "Motions" << "[";
	for (size_t i = 0; i < n; ++i)
	{
		fs << motions[i];
	}
	fs << "]";

	fs << "Points" << "[";
	for (size_t i = 0; i < structure.cols; ++i)
	{
		Mat_<float> c = structure.col(i);
		c /= c(3);	//齐次坐标，需要除以最后一个元素才是真正的坐标值
		fs << Point3f(c(0), c(1), c(2));
	}
	fs << "]";

	fs << "Colors" << "[";
	for (size_t i = 0; i < colors.size(); ++i)
	{
		fs << colors[i];
	}
	fs << "]";

	fs.release();
}

void main()
{
	string img1 = "F:\\实训\\GraphGo\\GraphGo\\0004.png";
	string img2 = "F:\\实训\\GraphGo\\GraphGo\\0006.png";
	vector<string> img_names = { img1, img2 };

	vector<vector<KeyPoint>> key_points_for_all;
	vector<Mat> descriptor_for_all;
	vector<vector<Vec3b>> colors_for_all;
	vector<DMatch> matches;

	//本征矩阵
	Mat K(Matx33d(
		2759.48, 0, 1520.69,
		0, 2764.16, 1006.81,
		0, 0, 1));

	//提取特征
	extract_features(img_names, key_points_for_all, descriptor_for_all, colors_for_all);
	//特征匹配
	match_features(descriptor_for_all[0], descriptor_for_all[1], matches);

	//计算变换矩阵
	vector<Point2f> p1, p2;
	vector<Vec3b> c1, c2;
	Mat R, T;	//旋转矩阵和平移向量
	Mat mask;	//mask中大于零的点代表匹配点，等于零代表失配点
	get_matched_points(key_points_for_all[0], key_points_for_all[1], matches, p1, p2);
	get_matched_colors(colors_for_all[0], colors_for_all[1], matches, c1, c2);
	find_transform(K, p1, p2, R, T, mask);

	//三维重建
	Mat structure;	//4行N列的矩阵，每一列代表空间中的一个点（齐次坐标）
	maskout_points(p1, mask);
	maskout_points(p2, mask);
	reconstruct(K, R, T, p1, p2, structure);

	//保存并显示
	vector<Mat> rotations = { Mat::eye(3, 3, CV_64FC1), R };
	vector<Mat> motions = { Mat::zeros(3, 1, CV_64FC1), T };
	maskout_colors(c1, mask);
	save_structure("F:\\实训\\GraphGo\\GraphGo\\structure.yml", rotations, motions, structure, c1);

	//system(".\\Viewer\\SfMViewer.exe");
}
