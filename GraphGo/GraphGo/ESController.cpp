#include "ESController.h"
#include "GetCameraMat.h"

void read_images(vector<string>& img_names)
{
	//vector<string> img_names = { "0001.png","0002.png","0003.png" };
	vector<string> img_names = { "01.jpg","02.jpg","03.jpg","04.jpg","05.jpg","06.jpg","07.jpg" };
	vector<string> camera_names = { ".//Camera//1.jpg",".//Camera//2.jpg",".//Camera//3.jpg",".//Camera//4.jpg",".//Camera//5.jpg" };
	string file_name = "camera.txt";

	//�ڲξ���
	Mat K(Matx33d(get_camera_mat(camera_names, file_name)));

	/*Mat K(Matx33d(
	0, 0, 0,
	0, 0, 0,
	0, 0, 0));
	Mat ans = get_camera_mat(camera_names);

	for (int i = 0; i < 3; ++i) {
	for (int j = 0; j < 3; ++j) {
	K.at<double>(i, j) = ans.at<double>(i, j);
	cout << K.at<double>(i, j);
	}
	}*/
	//Mat K(Matx33d(
	//	2759.48, 0, 1520.69,
	//	0, 2764.16, 1006.81,
	//	0, 0, 1));

	vector<vector<KeyPoint>> key_points_for_all;
	vector<Mat> descriptor_for_all;
	vector<vector<Vec3b>> colors_for_all;
	vector<vector<DMatch>> matches_for_all;
	//��ȡ����ͼ�������
	extract_features(img_names, key_points_for_all, descriptor_for_all, colors_for_all);

	//ÿ��ͼ���ƥ��ͼ�������
	vector<int> match_idx(key_points_for_all.size());
	//������ƥ������
	vector<int> sort_matches;
	//������ͼ�����˳�ε�����ƥ��
	match_features_for_all(descriptor_for_all, matches_for_all, match_idx);
	sort(match_idx, sort_matches);

	vector<Point3f> structure;
	vector<vector<int>> correspond_struct_idx; //�����i��ͼ���е�j���������Ӧ��structure�е������
	vector<Vec3b> colors;
	vector<Mat> rotations;
	vector<Mat> motions;




	//��ʼ���ṹ����ά���ƣ�
	int idx;
	int i = 0;
	for (; i < sort_matches.size() - 1; ++i) {
		idx = sort_matches[i];
		if (init_structure(K, key_points_for_all, colors_for_all, matches_for_all, structure, correspond_struct_idx, colors, rotations, motions, match_idx, idx) == 1) {
			i++;
			break;
		}
	}

	//������ʽ�ؽ�ʣ���ͼ��
	for (; i < sort_matches.size() - 1; ++i)
	{
		idx = sort_matches[i];

		vector<Point3f> object_points;
		vector<Point2f> image_points;
		Mat r, R, T;
		//Mat mask;

		//��ȡ��i��ͼ����ƥ����Ӧ����ά�㣬�Լ�����֮��Ӧ��ͼ���е����ص�
		if (get_objpoints_and_imgpoints(matches_for_all[idx], correspond_struct_idx[idx], structure, key_points_for_all[match_idx[idx]], object_points, image_points) == 0) {
			cout << "image " << idx << " and image " << match_idx[idx] << " is not matched " << endl;
			continue;
		}

		//���任����
		solvePnPRansac(object_points, image_points, K, noArray(), r, T);
		//����ת����ת��Ϊ��ת����
		Rodrigues(r, R);
		//����任����
		rotations.push_back(R);
		motions.push_back(T);

		vector<Point2f> p1, p2;
		vector<Vec3b> c1, c2;
		get_matched_points(key_points_for_all[idx], key_points_for_all[match_idx[idx]], matches_for_all[idx], p1, p2);
		get_matched_colors(colors_for_all[idx], colors_for_all[match_idx[idx]], matches_for_all[idx], c1, c2);

		//����֮ǰ��õ�R��T������ά�ؽ�
		vector<Point3f> next_structure;
		reconstruct(K, rotations[i], motions[i], R, T, p1, p2, next_structure);

		//���µ��ؽ������֮ǰ���ں�
		fusion_structure(matches_for_all[idx], correspond_struct_idx[idx], correspond_struct_idx[match_idx[idx]], structure, next_structure, colors, c1);
	}

	//�ų�Rotations��Motions��Ϊ�յ����
	vector<Mat> final_rotations;
	vector<Mat> final_motions;
	for (int i = 0; i < rotations.size(); ++i) {
		if (rotations[i].empty() && motions[i].empty())
			continue;
		final_rotations.push_back(rotations[i]);
		final_motions.push_back(motions[i]);
	}

	//����
	if (structure.size() != 0)
		save_structure(".\\structure.yml", final_rotations, final_motions, structure, colors);

	system("PAUSE");

}
