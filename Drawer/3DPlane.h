#pragma once
//Create By ZH
//a plane in 3D space

#include "3Dline.h"

class Plane3D
{
public:
	Plane3D();

	//点和法线确定一个面
	Plane3D(Point3d p,double Vx, double Vy, double Vz);

	//点是否在面上
	bool hasPoint(Point3d p);

	//点投影
	Point3d PointShadow(Point3d p);

	//线是否在面上
	bool hasLine(line3D l);

	//求线面交点
	Point3d CrossPoint(line3D l);

	//面上的一个点
	Point3d P;

	//法线向量
	double Vx;

	double Vy;

	double Vz;
	
};
