#include "Extract.h"

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
	//Ptr<Feature2D> sift = xfeatures2d::SIFT::create(0, 3, 0.04, 10);
	Ptr<Feature2D> sift = xfeatures2d::SURF::create();

	if (ReadAllKeyPoints(image_names, key_points_for_all, descriptor_for_all, colors_for_all))
		return;
	for (auto it = image_names.begin(); it != image_names.end(); ++it)
	{
		image = imread(".\\images\\" + *it);
		if (image.empty()) continue;

		cout << "Extracing features: " << *it << endl;

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

		WriteKeyPoints(*it, key_points, descriptor, colors);
	}
}