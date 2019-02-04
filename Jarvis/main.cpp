#include "functions.h"

int main() 
{
	vector<point> points;
	points.push_back(point(0, -3));
	points.push_back(point(1, 1));
	points.push_back(point(2, 2));
	points.push_back(point(4, 4));
	points.push_back(point(0, 0));
	points.push_back(point(1, 2));
	points.push_back(point(3, 1));
	points.push_back(point(3, 3));

	///////////////JARVIS///////////////
	vector<point> convex_points;
	cout << "\t\t\tJARVIS\n";

	cout << "------------------ points: -------------------" << endl;
	for (int i = 0; i<int(points.size()); i++) 
	{
		cout << "(" << (points.at(i)).x << "," << (points.at(i)).y << ")" << endl;
	}
	convex_points = JarvisHull(points);
	cout << "------------------ convex hull: -------------------" << endl;
	for (auto it = convex_points.begin(); it != convex_points.end(); it++)
	{
		cout << "(" << (*it).x << ", " << (*it).y << ")" << endl;
	}

	//////////////GRAHAM////////////////
	cout << "\n\t\t\tCRAHAM\n";
	cout << "\n" << "------------------ points: -------------------" << endl;
	for (point& point : points)
	{
		cout << "(" << point.x << ", " << point.y << ")" << endl;
	}
	cout << "------------------ convex hull: -------------------" << endl;
	GrahamHull(points);

	///////////QUICKHULL/////////////
	vector<point> res;
	cout << "\n\t\t\tQUICKHULL\n";
	cout << "\n" << "------------------ points: -------------------" << endl;
	for (auto it = points.begin(); it != points.end(); it++)
	{
		cout << "(" << (*it).x << ", " << (*it).y << ")" << endl;
	}
	res = QuickHull(points);
	cout << "------------------ convex hull: -------------------" << endl;
	for (auto it = res.begin(); it != res.end(); it++)
	{
		cout << "(" << (*it).x << ", " << (*it).y << ")" << endl;
	}

	system("pause");
	return 0;
}