#include "3DPlane.h"
Plane3D::Plane3D() {
}

Plane3D::Plane3D(Point3d a, double vx, double vy, double vz) {
	P = a;
	Vx = vx;
	Vy = vy;
	Vz = vz;
}

bool Plane3D::hasPoint(Point3d p) {
	double x, y, z;
	x = p.x - P.x;
	y = p.y - P.y;
	z = p.z - P.z;

	//判断连线向量与法线是否垂直
	return 0 == x*Vx + y*Vy + z*Vz;
}

Point3d Plane3D::PointShadow(Point3d p) {
	return p;
}

bool Plane3D::hasLine(line3D l) {
	Point3d p1 = l.Point1();
	Point3d p2 = l.Point2();

	return this->hasPoint(p1) && this->hasPoint(p2);
}

Point3d Plane3D::CrossPoint(line3D l) {
	double vpt = Vx*l.Vx + Vy*l.Vy + Vz*l.Vz;
	Point3d result;
	if (vpt == 0) {
		return result;
	}
	else
	{
		//比例值T
		Point3d result,p1;
		p1 = l.Point1();
		double T = ((this->P.x - p1.x)*Vx + (this->P.y - p1.y)*Vy +(this->P.z - p1.z)*Vz)/vpt;

		result.x = p1.x + l.Vx * T;
		result.y = p1.y + l.Vy * T;
		result.z = p1.z + l.Vz * T;

		return result;
	}
	
}