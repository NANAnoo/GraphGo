#include "ESController.h"

void Display()
{
	vector<string> img_names = { "0001.png","0002.png","0003.png" };

	//内参矩阵
	Mat K(Matx33d(
		1000, 0, 2016,
		0, 1000, 1512,
		0, 0, 1));

	vector<vector<KeyPoint>> key_points_for_all;
	vector<Mat> descriptor_for_all;
	vector<vector<Vec3b>> colors_for_all;
	vector<vector<DMatch>> matches_for_all;
	//提取所有图像的特征
	extract_features(img_names, key_points_for_all, descriptor_for_all, colors_for_all);

	//每个图像的匹配图像的索引
	vector<int> match_idx;
	//对所有图像进行顺次的特征匹配
	match_features_for_all(descriptor_for_all, matches_for_all, match_idx);

	vector<Point3f> structure;
	vector<vector<int>> correspond_struct_idx; //保存第i副图像中第j个特征点对应的structure中点的索引
	vector<Vec3b> colors;
	vector<Mat> rotations;
	vector<Mat> motions;


	//初始化结构（三维点云）
	int i = 0;
	for (; i < matches_for_all.size(); ++i) {
		if (init_structure(K, key_points_for_all, colors_for_all, matches_for_all, structure, correspond_struct_idx, colors, rotations, motions, match_idx, i) == 1) {
			i++;
			break;
		}
	}

	//增量方式重建剩余的图像
	for (; i < matches_for_all.size(); ++i)
	{
		vector<Point3f> object_points;
		vector<Point2f> image_points;
		Mat r, R, T;
		//Mat mask;

		//获取第i幅图像中匹配点对应的三维点，以及在与之对应的图像中的像素点
		if (get_objpoints_and_imgpoints(matches_for_all[i], correspond_struct_idx[i], structure, key_points_for_all[match_idx[i]], object_points, image_points) == 0)
			continue;

		//求解变换矩阵
		solvePnPRansac(object_points, image_points, K, noArray(), r, T);
		//将旋转向量转换为旋转矩阵
		Rodrigues(r, R);
		//保存变换矩阵
		rotations.push_back(R);
		motions.push_back(T);

		vector<Point2f> p1, p2;
		vector<Vec3b> c1, c2;
		get_matched_points(key_points_for_all[i], key_points_for_all[match_idx[i]], matches_for_all[i], p1, p2);
		get_matched_colors(colors_for_all[i], colors_for_all[match_idx[i]], matches_for_all[i], c1, c2);

		//根据之前求得的R，T进行三维重建
		vector<Point3f> next_structure;
		reconstruct(K, rotations[i], motions[i], R, T, p1, p2, next_structure);

		//将新的重建结果与之前的融合
		fusion_structure(
			matches_for_all[i],
			correspond_struct_idx[i],
			correspond_struct_idx[i + 1],
			structure,
			next_structure,
			colors,
			c1
		);
	}

	//保存
	if (structure.size() != 0)
		save_structure(".\\structure.yml", rotations, motions, structure, colors);
}