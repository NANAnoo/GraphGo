#include "ESController.h"

void Display()
{
	vector<string> img_names = { "0001.png","0002.png","0003.png" };

	//�ڲξ���
	Mat K(Matx33d(
		1000, 0, 2016,
		0, 1000, 1512,
		0, 0, 1));

	vector<vector<KeyPoint>> key_points_for_all;
	vector<Mat> descriptor_for_all;
	vector<vector<Vec3b>> colors_for_all;
	vector<vector<DMatch>> matches_for_all;
	//��ȡ����ͼ�������
	extract_features(img_names, key_points_for_all, descriptor_for_all, colors_for_all);

	//ÿ��ͼ���ƥ��ͼ�������
	vector<int> match_idx;
	//������ͼ�����˳�ε�����ƥ��
	match_features_for_all(descriptor_for_all, matches_for_all, match_idx);

	vector<Point3f> structure;
	vector<vector<int>> correspond_struct_idx; //�����i��ͼ���е�j���������Ӧ��structure�е������
	vector<Vec3b> colors;
	vector<Mat> rotations;
	vector<Mat> motions;


	//��ʼ���ṹ����ά���ƣ�
	int i = 0;
	for (; i < matches_for_all.size(); ++i) {
		if (init_structure(K, key_points_for_all, colors_for_all, matches_for_all, structure, correspond_struct_idx, colors, rotations, motions, match_idx, i) == 1) {
			i++;
			break;
		}
	}

	//������ʽ�ؽ�ʣ���ͼ��
	for (; i < matches_for_all.size(); ++i)
	{
		vector<Point3f> object_points;
		vector<Point2f> image_points;
		Mat r, R, T;
		//Mat mask;

		//��ȡ��i��ͼ����ƥ����Ӧ����ά�㣬�Լ�����֮��Ӧ��ͼ���е����ص�
		if (get_objpoints_and_imgpoints(matches_for_all[i], correspond_struct_idx[i], structure, key_points_for_all[match_idx[i]], object_points, image_points) == 0)
			continue;

		//���任����
		solvePnPRansac(object_points, image_points, K, noArray(), r, T);
		//����ת����ת��Ϊ��ת����
		Rodrigues(r, R);
		//����任����
		rotations.push_back(R);
		motions.push_back(T);

		vector<Point2f> p1, p2;
		vector<Vec3b> c1, c2;
		get_matched_points(key_points_for_all[i], key_points_for_all[match_idx[i]], matches_for_all[i], p1, p2);
		get_matched_colors(colors_for_all[i], colors_for_all[match_idx[i]], matches_for_all[i], c1, c2);

		//����֮ǰ��õ�R��T������ά�ؽ�
		vector<Point3f> next_structure;
		reconstruct(K, rotations[i], motions[i], R, T, p1, p2, next_structure);

		//���µ��ؽ������֮ǰ���ں�
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

	//����
	if (structure.size() != 0)
		save_structure(".\\structure.yml", rotations, motions, structure, colors);
}