#pragma once
#include "3DPlane.h"

class Camera
{
public:
	Camera();

	Camera(Point3d p,double Yalpha, double Zalpha,int W,int H);

	void draw3DLine(Mat M, line3D* l,int r,int g,int b);

	void draw3DPoint(Mat M, Point3d p, int r, int g, int b);

	void draw3DPoint(Mat M, Point3d p, int r, int g, int b,int w);

	//获取点在屏幕中位置
	Point2i getScreenPoint(Point3d p);
	//在每次修改完数据后重建相机
	void ReBuild();
	//视窗大小
	int Width;
	int Height;

	//视图中点即位置
	Point3d Position;

	//视图视点
	Point3d ViewPoint;

	//视图面
	Plane3D* Plane;

	//法向量
	double Vx;

	double Vy;

	double Vz;

	//旋转的角度
	double Zalpha;

	double Yalpha;

private:

	//点是否在视面后方
	bool IsBack;
};
