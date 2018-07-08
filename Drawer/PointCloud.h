#pragma once

#include "Camera.h"
#include "DrawPoint.h"
#include <time.h>

class PointCloud
{
public:
	PointCloud();

	//设置窗口大小
	PointCloud(int W,int H);

	void SetCloud(DrawPoint *cloud,int Count);

	void SetCamera(Point3d Position,double Yalpha,double Zalpha);

	void Show();
private:

	//点云集合
	DrawPoint *Cloud;
	//点的数量
	int Count;
	//相机
	Camera *camera;
	//图像
	Mat *M;
};
