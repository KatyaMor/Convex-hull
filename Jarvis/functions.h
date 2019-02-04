#pragma once
#include <algorithm>
#include <stack>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

#define M_PI 3.14159265358979323846

using namespace std;

struct point {
	double x, y;
	point() {
		x = 0; y = 0;
	}
	point(double X, double Y) {
		x = X; y = Y;
	}
	// comparison is done first on y coordinate and then on x coordinate
	bool operator < (point b) {
		if (y != b.y)
			return y < b.y;
		return x < b.x;
	}
	bool operator==(point b)
	{
		return (x == b.x && y == b.y);
	}
	bool operator!=(point b)
	{
		return (x != b.x && y != b.y);
	}
	point operator=(point e)
	{
		x = e.x;
		y = e.y;
		return *this;
	}
};

double calculateAlpha(point p1, point p2);
bool compareXCoordinateSmallest(point a, point b);
vector<point> KirkpatrickHull(vector<point>& points);

/////////JARVIS/////////
vector<point> JarvisHull(vector<point>&);
bool compareYCoordinateSmallest(point, point);
point findSmallestPointAngle(point, point, vector<point>);
double calculateAngle(point, point, point);

/////////GRAHAM////////
point nextToTop(stack<point>& );
void swap(point&, point&);
int dist(point, point);
int orientation(point, point, point);
int compare(const void *, const void *);
void GrahamHull(vector<point>&);

////////QUICKHULL////////
bool isLeft(point, point, point);
//void getLine(point, point, double&, double&, double&);
double AreaOfTriangle(point&, point&, point&);
point FurthestPoint(vector<point>&, point&, point&);
point GetMinX(vector<point>&);
point GetMaxX(vector<point>&);
vector<point> QuickHull(vector<point>&);
void FindHull(vector<point>, vector<point>&, point&, point&);

