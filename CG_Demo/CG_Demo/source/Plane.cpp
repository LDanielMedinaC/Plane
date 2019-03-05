#include "Plane.h"



Plane::Plane(double _widht, double _height, int _vDivs, int _hDivs)
{
	widht = _widht;
	height = _height;
	vDivs = _vDivs;
	hDivs = _hDivs;
}

void Plane::printGeometry() {

	double hd = widht / hDivs;
	double vd = height / vDivs;

	double sh = -widht / 2.0;
	double sv = -height / 2.0;
	for (double j = -sv; j >= sv; j -= vd) {
		for (double i = sh; i <= -sh; i += hd) {
			printf("v %f 0 %f\n", i, j);
		}
		printf("\n");
	}
}

void Plane::printNormal() {
	printf("vn 0 1 0\n");
}

void Plane::printTopology() {
	for (int i = 0; i <= vDivs - 1; i++) {
		for (int j = 1; j <= hDivs; j++) {
			int ith = i * hDivs + j + i;
			printf("f %d//1 %d//1 %d//1\n", ith, ith + 1, ith + hDivs + 2);
			printf("f %d//1 %d//1 %d//1\n", ith, ith + hDivs + 2, ith + hDivs + 1);
			printf("\n");
		}
		printf("\n");
	}
}
	

Plane::~Plane()
{
}
