#include "3Dline.h"

line3D::line3D() {
	this->end1 = false;

	this->end2 = false;
}


line3D::line3D(Point3d p1, Point3d p2) {
	this->p1 = p1;

	this->p2 = p2;

	Vx = this->p1.x - this->p2.x;

	Vy = this->p1.y - this->p2.y;

	Vz = this->p1.z - this->p2.z;

	this->end1 = false;

	this->end2 = false;

}

line3D::line3D(Point3d p1, Point3d p2,bool end1,bool end2) {
	this->p1 = p1;

	this->p2 = p2;

	 Vx = this->p1.x - this->p2.x;

	 Vy = this->p1.y - this->p2.y;

	 Vz = this->p1.z - this->p2.z;

	this->end1 = end1;

	this->end2 = end2;
}

bool line3D::hasPoint(Point3d p,bool mode) {
	//三边长度
	double a, b, c;

	a = sqrt((p.x - this->p1.x)*(p.x - this->p1.x)
		+ (p.y - this->p1.y)*(p.y - this->p1.y)
	+ (p.z - this->p1.z)*(p.z - this->p1.z));

	b = sqrt((p.x - this->p2.x)*(p.x - this->p2.x)
		+ (p.y - this->p2.y)*(p.y - this->p2.y)
		+ (p.z - this->p2.z)*(p.z - this->p2.z));

	c = sqrt((this->p1.x - this->p2.x)*(this->p1.x - this->p2.x)
		+ (this->p1.y - this->p2.y)*(this->p1.y - this->p2.y)
		+ (this->p1.z - this->p2.z)*(this->p1.z - this->p2.z));

	bool k = (a==b+c) || (b==a+c) || (c=a+b);
	if (mode) {
		if (k == false)
			return false;
		else
		{
			if (end1 && !end2 && !(b == a + c))
				return true;
			if (end2 && !end1 && !(a == b + c))
				return true;
			if (end1 && end2 && c == a + b)
				return true;
			if (!end1 && !end2)
				return true;
			return false;
		}

	}else return k;

}

double line3D::length() {
	return sqrt((this->p1.x - this->p2.x)*(this->p1.x - this->p2.x)
		+ (this->p1.y - this->p2.y)*(this->p1.y - this->p2.y)
		+ (this->p1.z - this->p2.z)*(this->p1.z - this->p2.z));
}

bool line3D::setPoint1(Point3d p) {

	this->p1 = p;

	Vx = this->p1.x - this->p2.x;

	Vy = this->p1.y - this->p2.y;

	Vz = this->p1.z - this->p2.z;

	return true;
}

bool line3D::setPoint2(Point3d p) {

	this->p2 = p;

	Vx = this->p1.x - this->p2.x;

	Vy = this->p1.y - this->p2.y;

	Vz = this->p1.z - this->p2.z;

	return true;
}

void line3D::closePoint1() {
	end1 = false;
}

void line3D::closePoint2() {
	end2 = false;
}

void line3D::openPoint1() {
	end1 = true;
}

void line3D::openPoint2() {
	end2 = true;
}

Point3d line3D::Point1() {
	return p1;
}

Point3d line3D::Point2() {
	return p2;
}