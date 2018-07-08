#include "PointCloud.h"

PointCloud::PointCloud()
{
	Count = -1;
	camera = new Camera();
	//默认数值
	M = new Mat(1000, 1000, CV_8UC3);
	camera->Width = 1000;
	camera->Height = 1000;
}

PointCloud::PointCloud(int W,int H)
{
	Count = -1;
	camera = new Camera();
	//默认数值
	M = new Mat(W, H, CV_8UC3);
	camera->Width = W;
	camera->Height = H;
}


void PointCloud::SetCloud(DrawPoint*cloud, int count)
{
	Cloud = cloud;
	Count = count;
}

void PointCloud::SetCamera(Point3d Position, double Yalpha, double Zalpha)
{
	camera->Position = Position;
	camera->Yalpha = Yalpha;
	camera->Zalpha = Zalpha;
	camera->ReBuild();
}

void PointCloud::Show() {
	int Key;
	clock_t start, finish;
	double Mx = 0, My = 0, Mz = 0, Mzalpha = 0, Myalpha = 0;

	Point3d O, X, Y, Z;

	X.x = 10;
	Y.y = 10;
	Z.z = 10;

	line3D Lx(O, X , true, true);
	line3D Ly(O, Y , true, true);
	line3D Lz(O, Z , true, true);

	double PI = atan(1) * 4;
	start = clock();
	Rect R(0,0,camera->Width,camera->Height);
	while (true)
	{
		camera->Position.x += Mx;
		camera->Position.y += My;
		camera->Position.z += Mz;

		camera->Zalpha = camera->Zalpha + Mzalpha;
		camera->Yalpha = camera->Yalpha + Myalpha;

		camera->ReBuild();

		camera->draw3DLine(*M, &Lx, 255, 0, 0);
		camera->draw3DLine(*M, &Ly, 0, 255, 0);
		camera->draw3DLine(*M, &Lz, 0, 0, 255);

		for (int i = 0; i < Count; i++) {
			camera->draw3DPoint(*M, Cloud[i].P, Cloud[i].R, Cloud[i].G, Cloud[i].B);
		}

		imshow("",*M);
		rectangle(*M, R, Scalar(0, 0, 0),-1);
		finish = clock();
		switch (Key = waitKey(30)) {
			//W
		case 87:
			Mx = -(double)(start - finish) / 50 * camera->Vx;
			My = -(double)(start - finish) / 50 * camera->Vy;
			Mz = -(double)(start - finish) / 50 * camera->Vz;
			break;
			//A
		case 65:
			Mx = (double)(start - finish) / 50 * camera->Vy;
			My = -(double)(start - finish) / 50 * camera->Vx;
			break;
			//S
		case 83:
			Mx = (double)(start - finish) / 50 * camera->Vx;
			My = (double)(start - finish) / 50 * camera->Vy;
			Mz = (double)(start - finish) / 50 * camera->Vz;
			break;
			//D
		case 68:
			Mx = -(double)(start - finish) / 50 * camera->Vy;
			My = (double)(start - finish) / 50 * camera->Vx;
			break;
			//SPACE
		case 32:
			Mz = -(double)(start - finish) / 50;
			break;
			//Q
		case 81:
			Mz = (double)(start - finish) / 50;
			break;
		case 56:
			Myalpha = -(double)(start - finish) / 50 * PI / 180;
			break;
		case 53:
			Myalpha = (double)(start - finish) / 50 * PI / 180;
			break;
		case 52:
			Mzalpha = -(double)(start - finish) / 50 * PI / 180;
			break;
		case 54:
			Mzalpha = (double)(start - finish) / 50 * PI / 180;
			break;
		}
		if (Key == -1) {
			Mx = 0;
			My = 0;
			Mz = 0;
			Myalpha = 0;
			Mzalpha = 0;
		}
		cout <<"FPS:"<<1000.0/-(start-finish) << endl;
		start = finish;
	}
}