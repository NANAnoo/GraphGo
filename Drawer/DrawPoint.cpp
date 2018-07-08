#include "DrawPoint.h"

DrawPoint::DrawPoint(Point3d p, int r, int g, int b) {
	P = p;
	R = r;
	G = g;
	B = b;
}

DrawPoint::DrawPoint() {
	R = 0;
	G = 0;
	B = 0;
}