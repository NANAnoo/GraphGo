#include "Reader.h"

bool ReadPointCloud(string filename, vector<Mat>&rotations, vector<Mat>&motions, vector<Point3f>&points, vector<Vec3b>&colors)
{
	FileNode Points, Colors;
	Point3f P;
	Vec3b V;
	FileStorage readfs(filename, FileStorage::READ); //读的形式打开yml。当然也可以打开xml，主要看后缀

	if (!readfs.isOpened()) {
		readfs.release();
		return false;
	}

	readfs["Rotations"] >> rotations;

	readfs["Motions"] >> motions;

	Points = readfs["Points"];

	Colors = readfs["Colors"];

	FileNodeIterator fni = Points.begin();

	FileNodeIterator fniEnd = Points.end();

	FileNodeIterator fnic = Colors.begin();

	for (; fni != fniEnd; fni++)
	{
		P.x = (float)(*fni)[0];
		P.y = (float)(*fni)[1];
		P.z = (float)(*fni)[2];

		V[0] = (int)(*fnic)[0];
		V[1] = (int)(*fnic)[1];
		V[2] = (int)(*fnic)[2];

		points.push_back(P);
		colors.push_back(V);
		fnic++;
	}
	readfs.release();
	return true;
}

bool ReadKeyPoints(string & imgname, vector<KeyPoint>& key_points, Mat & descriptor, vector<Vec3b> & colors)
{
	FileNode KPS,Colors;
	KeyPoint P;
	Vec3b C;
	string fileName = ".\\KeyPoints\\" + parseName(imgname);
	FileStorage readfs(fileName, FileStorage::READ); //读的形式打开yml。

	if (!readfs.isOpened()) {
		readfs.release();
		return false;
	}

	///Read KeyPoints
	KPS = readfs["Key Points"];
	FileNodeIterator fni = KPS.begin();
	FileNodeIterator fniEnd = KPS.end();

	for (; fni != fniEnd; fni++) {
		P.pt.x = (float)(*fni)[0];
		P.pt.y = (float)(*fni)[1];
		P.size = (float)(*fni)[2];
		P.angle = (float)(*fni)[3];
		P.response = (float)(*fni)[4];
		P.octave = (float)(*fni)[5];
		P.class_id = (int)(*fni)[6];
		key_points.push_back(P);
	}

	//Read Descriptor
	readfs["Descriptor"] >> descriptor;

	//Read Colors
	Colors = readfs["Colors"];
	fni = Colors.begin();
	fniEnd = Colors.end();

	for (; fni != fniEnd; fni++) {
		C[0] = (int)(*fni)[0];
		C[1] = (int)(*fni)[1];
		C[2] = (int)(*fni)[2];
		colors.push_back(C);
	}

	return true;
}
