#include "Extract.h"

void extract_features(vector<string>& image_names,vector<vector<KeyPoint>>& key_points_for_all,vector<Mat>& descriptor_for_all,vector<vector<Vec3b>>& colors_for_all)
{
	key_points_for_all.clear();
	descriptor_for_all.clear();
	Mat image;

	//��ȡͼ�񣬻�ȡͼ�������㣬������
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
		//ż�������ڴ����ʧ�ܵĴ���
		sift->detectAndCompute(image, noArray(), key_points, descriptor);

		//��������٣����ų���ͼ��
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

int match_features(Mat& query, Mat& train, vector<DMatch>& matches)
{
	vector<vector<DMatch>> knn_matches;
	vector<DMatch> temp_matches;
	BFMatcher matcher(NORM_L2);
	matcher.knnMatch(query, train, knn_matches, 2);

	//��ȡ����Ratio Test����Сƥ��ľ���
	float min_dist = FLT_MAX;
	for (int r = 0; r < knn_matches.size(); ++r)
	{
		//Ratio Test
		if (knn_matches[r][0].distance > 0.6*knn_matches[r][1].distance)
			continue;

		float dist = knn_matches[r][0].distance;
		if (dist < min_dist) min_dist = dist;
	}

	for (size_t r = 0; r < knn_matches.size(); ++r)
	{
		//�ų�������Ratio Test�ĵ��ƥ��������ĵ�
		if (
			knn_matches[r][0].distance > 0.6*knn_matches[r][1].distance ||
			knn_matches[r][0].distance > 5 * max(min_dist, 10.0f)
			)
			continue;

		//����ƥ���
		temp_matches.push_back(knn_matches[r][0]);
	}

	//��ƥ�䵽��ͼ����Ŀ��ͼ���ƥ��
	if (temp_matches.size() > matches.size()) {
		matches.clear();
		matches.swap(temp_matches);
		return 0;
	}

	return 1;
}

void match_features_for_all(vector<Mat>& descriptor_for_all, vector<vector<DMatch>>& matches_for_all, vector<int>& match_idx)
{
	matches_for_all.clear();

	vector<DMatch> matches;
	// n��ͼ��ÿһ��ͼ��������δ�ܳɹ�ƥ���ͼ�����һ��ƥ��
	for (int i = 0; i < descriptor_for_all.size() - 1; ++i)
	{
		match_idx.push_back(0);
		for (int j = i + 1; j < descriptor_for_all.size(); ++j)
		{
			if (match_features(descriptor_for_all[i], descriptor_for_all[j], matches) == 0)
				match_idx[i] = j;

		}

		cout << "Matched images " << i << " - " << match_idx[i] << endl;
		matches_for_all.push_back(matches);
		matches.clear();
	}
}