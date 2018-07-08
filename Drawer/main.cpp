#include <opencv2/highgui/highgui.hpp>  

#include <opencv2/imgproc/imgproc.hpp>  

#include <opencv2/core/core.hpp>  

#include <iostream>

#include <time.h>

#include "PointCloud.h"


using namespace cv;
using namespace std;

/*
string static getTime()
{
	time_t timep;
	time(&timep);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
	return tmp;
}*/

int main()

{
	double PI = 4*atan(1);
	//line3D* l = new line3D(p1,p2);
	Point3d p1, p2, p3, p4, p5,ball, ball1, ball2;
	//Ball = new Point3d[1000000];
	/*Ball2 = new Point3d[1000000];
	Ball1 = new Point3d[1000000];*/
	DrawPoint *cloud;

	cloud = new DrawPoint[10000];

	p1.x = 0;
	p1.y = 0;
	p1.z = 0;
	p2.x = 1;
	p2.y = 0;
	p2.z = 0;
	p3.x = 100;
	p3.z = 10;
	p3.y = 100;
	p4.x = 0;
	p4.y = 1;
	p4.z = 0;
	p5.x = 0;
	p5.y = 0;
	p5.z = 1;
	
	ball.x = 20;
	ball.y = 0;
	ball.z = 0;

	ball1.x = 10;
	ball1.y = 0;
	ball1.z = 0;

	ball2.x = 10;
	ball2.y = 0;
	ball2.z = 0;
	

	double A = 0.0;
	
		double a, b, C, h;
		h = 0.01;

		for (int i = 1; i < 3333; i++) {
			a = 15.0;
			b = 35.0;
			C = 2.5;

			ball.x = ball.x + h*a*(ball.y - ball.x);
			ball.y = ball.y + h*(ball.x*(b - ball.z) - ball.y);
			ball.z = ball.z + 0.01*(ball.x*ball.y - ball.z*C);
			a = 15.0;
			b = 25.0;
			C = 8.0 / 3.0;

			ball1.x = ball1.x + h*a*(ball1.y - ball1.x);
			ball1.y = ball1.y + h*(ball1.x*(b - ball1.z) - ball1.y);
			ball1.z = ball1.z + 0.01*(ball1.x*ball1.y - ball1.z*C);

			a = 15.0;
			b = 30.0;
			C = 4;

			ball2.x = ball2.x + h*a*(ball2.y - ball2.x);
			ball2.y = ball2.y + h*(ball2.x*(b - ball2.z) - ball2.y);
			ball2.z = ball2.z + 0.01*(ball2.x*ball2.y - ball2.z*C);

			cloud[3*i].P = ball;
			cloud[3 * i].R = 255;

			cloud[3*i+1].P = ball1;
			cloud[3 * i+1].G = 255;

			cloud[3*i+2].P = ball2;
			cloud[3 * i+2].B = 255;
		}

		PointCloud* PC = new PointCloud();

		PC->SetCloud(cloud, 10000);

		PC->SetCamera(p3, 0, PI / 4);

		PC->Show();
		/*
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				b = 2.0 * PI*(double)i / 99.0;
				a = 4.0 * PI*(double)j / 99.0;
				ball.x = 10 * cos(a)*cos(b);
				ball.y = 10 * sin(a)*cos(b);
				ball.z = 10 * (sin(b)+a);
				Ball[i * 100 + j] = ball;
			}
		}*/
		//莫比乌斯
		/*
		for (int i = 0; i < 1000; i++) {
			for (int j = 0; j < 1000; j++) {
				b = 2.0 * PI*(double)i / 99.0;
				a = -1 + 2 * (double)j / 99.0;
				ball.x = 20*(1.0 + (a / 2)*cos(b / 2))*cos(b);
				ball.y = 20 * (1.0 + (a / 2)*cos(b / 2))*sin(b);
				ball.z = 20 * (a / 2)*sin(b / 2);
				Ball[i * 100 + j] = ball;
			}
		}
		*/
		/*for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				b = 6.0 * PI*(double)i / 99.0;
				a = 6.0 * PI*(double)j / 99.0;
				ball.x = 20*cos(a)*sin(b/a);
				ball.y = 20*sin(a)*cos(a/b);
				ball.z = 20*(sin(a + b)+ cos(a * b));
				Ball[i * 100 + j] = ball;
			}
		}*/

		/*for (int i = 0; i < 10000; i++) {
				ball.x += 2 * ((double)rand() / RAND_MAX - 0.5);
				ball.y += 2 * ((double)rand() / RAND_MAX - 0.5);
				ball.z += 2 * ((double)rand() / RAND_MAX - 0.5);
				Ball[i] = ball;
		}*/

		/*line3D *l1, *l2, *l3,  *DLT[6];
		l1 = new line3D(p1, p2, true, false);
		l2 = new line3D(p1, p4, true, false);
		l3 = new line3D(p1, p5, true, false);*/


}
