#include "GetCameraMat.h"

Mat get_camera_mat(vector<string>& image_names,string file_name)
{
	//ofstream fout("caliberation_result.txt");  /* ����궨������ļ� */
	FileStorage fs(file_name, FileStorage::WRITE);
											   //��ȡÿһ��ͼ�񣬴�����ȡ���ǵ㣬Ȼ��Խǵ���������ؾ�ȷ��	
	cout << "��ʼ��ȡ�ǵ㡭����������";
	int image_count = 0;  /* ͼ������ */
	Size image_size;  /* ͼ��ĳߴ� */
	Size board_size = Size(7, 7);    /* �궨����ÿ�С��еĽǵ��� */
	vector<Point2f> image_points_buf;  /* ����ÿ��ͼ���ϼ�⵽�Ľǵ� */
	vector<vector<Point2f>> image_points_seq; /* �����⵽�����нǵ� */
	int count = -1;//���ڴ洢�ǵ������
	for (int i = 0; i < image_names.size(); i++)
	{
		image_count++;
		// ���ڹ۲�������
		cout << "image_count = " << image_count << endl;
		/* �������*/
		cout << "-->count = " << count;
		Mat imageInput = imread(image_names[i]);
		if (image_count == 1)  //�����һ��ͼƬʱ��ȡͼ������Ϣ
		{
			image_size.width = imageInput.cols;
			image_size.height = imageInput.rows;
			cout << "image_size.width = " << image_size.width << endl;
			cout << "image_size.height = " << image_size.height << endl;
		}

		/* ��ȡ�ǵ� */
		if (0 == findChessboardCorners(imageInput, board_size, image_points_buf))
		{
			cout << "can not find chessboard corners!\n"; //�Ҳ����ǵ�
			exit(1);
		}
		else
		{
			Mat view_gray;
			cvtColor(imageInput, view_gray, CV_RGB2GRAY);
			/* �����ؾ�ȷ�� */
			find4QuadCornerSubpix(view_gray, image_points_buf, Size(5, 5)); //�Դ���ȡ�Ľǵ���о�ȷ��
																			//cornerSubPix(view_gray,image_points_buf,Size(5,5),Size(-1,-1),TermCriteria(CV_TERMCRIT_EPS+CV_TERMCRIT_ITER,30,0.1));
			image_points_seq.push_back(image_points_buf);  //���������ؽǵ�
														   /* ��ͼ������ʾ�ǵ�λ�� */
			drawChessboardCorners(view_gray, board_size, image_points_buf, false); //������ͼƬ�б�ǽǵ�
		}
	}
	int total = image_points_seq.size();
	cout << "total = " << total << endl;
	int CornerNum = board_size.width*board_size.height;  //ÿ��ͼƬ���ܵĽǵ���
	for (int ii = 0; ii < total; ii++)
	{
		if (0 == ii % CornerNum)// 24 ��ÿ��ͼƬ�Ľǵ���������ж������Ϊ����� ͼƬ�ţ����ڿ���̨�ۿ� 
		{
			int i = -1;
			i = ii / CornerNum;
			int j = i + 1;
			cout << "--> �� " << j << "ͼƬ������ --> : " << endl;
		}
		if (0 == ii % 3)	// ���ж���䣬��ʽ����������ڿ���̨�鿴
		{
			cout << endl;
		}
		else
		{
			cout.width(10);
		}
		//������еĽǵ�
		cout << " -->" << image_points_seq[ii][0].x;
		cout << " -->" << image_points_seq[ii][0].y;
	}
	cout << "�ǵ���ȡ��ɣ�\n";

	//������������궨
	cout << "��ʼ�궨������������";
	/*������ά��Ϣ*/
	Size square_size = Size(10, 10);  /* ʵ�ʲ����õ��ı궨����ÿ�����̸�Ĵ�С */
	vector<vector<Point3f>> object_points; /* ����궨���Ͻǵ����ά���� */
										   /*�������*/
	Mat cameraMatrix = Mat(3, 3, CV_32FC1, Scalar::all(0)); /* ������ڲ������� */
	vector<int> point_counts;  // ÿ��ͼ���нǵ������
	Mat distCoeffs = Mat(1, 5, CV_32FC1, Scalar::all(0)); /* �������5������ϵ����k1,k2,p1,p2,k3 */
	vector<Mat> tvecsMat;  /* ÿ��ͼ�����ת���� */
	vector<Mat> rvecsMat; /* ÿ��ͼ���ƽ������ */
						  /* ��ʼ���궨���Ͻǵ����ά���� */
	int i, j, t;
	for (t = 0; t < image_count; t++)
	{
		vector<Point3f> tempPointSet;
		for (i = 0; i < board_size.height; i++)
		{
			for (j = 0; j < board_size.width; j++)
			{
				Point3f realPoint;
				/* ����궨�������������ϵ��z=0��ƽ���� */
				realPoint.x = i * square_size.width;
				realPoint.y = j * square_size.height;
				realPoint.z = 0;
				tempPointSet.push_back(realPoint);
			}
		}
		object_points.push_back(tempPointSet);
	}
	/* ��ʼ��ÿ��ͼ���еĽǵ��������ٶ�ÿ��ͼ���ж����Կ��������ı궨�� */
	for (i = 0; i < image_count; i++)
	{
		point_counts.push_back(board_size.width*board_size.height);
	}
	/* ��ʼ�궨 */
	calibrateCamera(object_points, image_points_seq, image_size, cameraMatrix, distCoeffs, rvecsMat, tvecsMat, 0);
	cout << "�궨��ɣ�\n";

	fs << "Camera" << cameraMatrix;

	return cameraMatrix;
}