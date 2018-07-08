#include "Camera.h"

//旋转后坐标
Point3d TakeRound(Point3d p, double Yalpha, double Zalpha) {
	double X = p.x;
	double Y = p.y;
	double Z = p.z;
	double X1, X2, Y2, Z2;
	//先绕Y再绕Z
	Z2 = Z*cos(Yalpha) - X*sin(Yalpha);
	X1 = Z*sin(Yalpha) + X*cos(Yalpha);

	X2 = X1*cos(Zalpha) - Y*sin(Zalpha);
	Y2 = X1*sin(Zalpha) + Y*cos(Zalpha);

	Point3d P;
	P.x = X2;
	P.y = Y2;
	P.z = Z2;

	return P;
}
//旋转回ZOY后坐标
Point2d RoundBack(Point3d p, double Yalpha, double Zalpha) {
	double X = p.x;
	double Y = p.y;
	double Z = p.z;
	double X1, X2, Y1, Y2, Z1, Z2, sinY, cosY, sinZ, cosZ;
	sinY = sin(-Yalpha);
	sinZ = sin(-Zalpha);
	cosY = cos(-Yalpha);
	cosZ = cos(-Zalpha);
	//先绕Z在绕Y
	X1 = X*cosZ - Y*sinZ;
	Y2 = X*sinZ + Y*cosZ;

	Z2 = Z*cosY - X1*sinY;//???????
	X2 = Z*sinY + X1*cosY;

	Point2d P;
	P.x = Y2;
	P.y = Z2;

	return P;
}


Camera::Camera() {

}

Camera::Camera(Point3d p, double yalpha, double zalpha, int W, int H) {
	Position = p;
	Yalpha = yalpha;
	Zalpha = zalpha;
	Width = W;
	Height = H;
	ReBuild();
}

void Camera::ReBuild() {
	//定义视窗原来是Z0Y平面，视点在X轴上1.0.0.视窗法线 -1.0.0
	ViewPoint.x = 1;
	ViewPoint.y = 0;
	ViewPoint.z = 0;
	
	//实际视点位置
	ViewPoint = TakeRound(ViewPoint, Yalpha, Zalpha);

	ViewPoint.x += Position.x;
	ViewPoint.y += Position.y;
	ViewPoint.z += Position.z;

	//求法线向量
	Vx = Position.x - ViewPoint.x;
	Vy = Position.y - ViewPoint.y;
	Vz = Position.z - ViewPoint.z;

	//确定视图
	Plane = new Plane3D(Position, Vx, Vy, Vz);
}

Point2i Camera::getScreenPoint(Point3d p) {
	line3D l(p, ViewPoint);

	Point3d P = Plane->CrossPoint(l);
	
	Point2i S;

	if ((p.x - P.x)*(P.x - ViewPoint.x) > 0) {
	    P.x -= Position.x;
	    P.y -= Position.y;
	    P.z -= Position.z;
	    P.x = P.x * 10000;
	    P.y = P.y * 10000;
	     P.z = P.z * 10000;
	
	    Point2d T = RoundBack(P, Yalpha, Zalpha);
     	
    	S.x = (int)(Width * T.x/10000) + Width/2;
	    S.y = (int)(Height *(-T.y)/10000) + Height/2;

		IsBack = false;
	    return S;
	}
	else {
		IsBack = true;
		return S;
	}

}

void Camera::draw3DLine(Mat M, line3D* l, int r, int g, int b) {
	bool S1isBack, S2isBack;
	Point2i S1 = getScreenPoint(l->Point1());
	S1isBack = IsBack;
	Point2i S2 = getScreenPoint(l->Point2());
	S2isBack = IsBack;

	if (S1isBack||S2isBack)
		return;
	/*circle(M, S1, 2, Scalar(255,255,255), -1);
	circle(M, S2, 2, Scalar(255, 255, 255), -1);*/


	double vx, vy, K;

	vx = S1.x - S2.x;
	vy = S1.y - S2.y;

	Point P1, P2;
	//获取连线与X=0与X=1000交点
	if (vx == 0) {
			P1.x = S1.x;
			P2.x = S2.x;
			P1.y = 0;
			P2.y = Height;
		}
		else {
			K = vy / vx;
			P1.x = 0;
			P2.x = Width;
			P1.y = - S1.x *K + S1.y;
			P2.y = (Width - S1.x)*K + S1.y;
			if (P1.y > Height||P1.y<0|| P1.y > Height || P1.y<0) {
				if (K != 0.0) {
					P1.y = 0;
					P1.x = -S1.y / K + S1.x;
					P2.y = Height;
					P2.x = (Height - S1.y) / K + S1.x;
				}
				else
					return;
			}
		}
	//如果是线段
	if (l->end1&&l->end2) {
		line(M, S1, S2, Scalar(b, g, r));
	}
	//如果是直线
	if ((!l->end1) && (!l->end2)) {
		
		line(M,P1,P2,Scalar(b, g, r));
	}

	if ((l->end1 && (!l->end2)) || (l->end2 && (!l->end1))) {
		//存储四个点在直线上的相对位置
		int L[4] = {0,1,2,3};
		int J[4];
		if (vx != 0) {
			J[0] = S1.x;
			J[1] = S2.x;
			J[2] = P1.x;
			J[3] = P2.x;
		}
		else
		{
			J[0] = S1.y;
			J[1] = S2.y;
			J[2] = P1.y;
			J[3] = P2.y;
		}
		int k, m;//排序
		for (int i = 0; i < 4; i++) {
			k = J[i];m = i;
			for (int j = i + 1; j < 4; j++) {
				if (J[i] > J[j]) {
					m = j;
				}
			}
			if (m != i) {
				J[i] = J[m];
				J[m] = k;
				k = L[i];
				L[i] = L[m];
				L[m] = k;
			}
		}
		int index1,index2;
		for (int i = 0; i < 4; i++) {
			if (L[i] == 0) index1 = i;
			if (L[i] == 1) index2 = i;
		}
		Point2i Left, Right;
		if (L[0] == 0) Left = S1;
		if (L[0] == 1) Left = S2;
		if (L[0] == 2) Left = P1;
		if (L[0] == 3) Left = P2;
		if (L[3] == 0) Right = S1;
		if (L[3] == 1) Right = S2;
		if (L[3] == 2) Right = P1;
		if (L[3] == 3) Right = P2;
		//以S1开头的射线
		if (l->end1 && (!l->end2)) {
			if (index1 > index2)
				line(M, S1, Left, Scalar(b, g, r));
			else
				line(M, S1, Right, Scalar(b, g, r));
		}

		//以S2开头的射线
		if (l->end2 && (!l->end1)) {
			if (index1 > index2)
				line(M, S2, Right, Scalar(b, g, r));
			else
				line(M, S2, Left, Scalar(b, g, r));
		}
	}
}

void Camera::draw3DPoint(Mat M, Point3d p, int r, int g, int b) {
	Point S = getScreenPoint(p);
	if(!IsBack)
		circle(M,S,0,Scalar(b,g,r),-1);
}
void Camera::draw3DPoint(Mat M, Point3d p, int r, int g, int b,int w) {
	Point S = getScreenPoint(p);
	if (!IsBack)
		circle(M, S, w, Scalar(b, g, r), -1);
}