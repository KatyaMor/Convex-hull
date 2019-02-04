#include "functions.h"

double calculateAlpha(point p1, point p2)
{
	return atan((p2.y - p1.y) / (p2.x - p1.x))*180.0/M_PI;
}

bool compareXCoordinateSmallest(point a, point b)
{
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

vector<point> KirkpatrickHull(vector<point>& points)
{
	if(points.size()<=2) cout << "points should consist of more than 2 points\n";

	vector<point> sortedPoints;
	for (point &point : points)
	{
		sortedPoints.push_back(point);
	}
	sort(sortedPoints.begin(), sortedPoints.end(), compareXCoordinateSmallest);

	point p_min = sortedPoints.at(0);
	point p_max = sortedPoints.at(sortedPoints.size()-1);

	double x_med = (p_min.x + p_max.x) / 2;

	vector<point> L;
	vector<point> R;

	for (point &point : sortedPoints)
	{
		if (point.x < x_med) L.push_back(point);
		else R.push_back(point);
	}

	double alpha_med = 0;

	int n = sortedPoints.size() / 2;

	for (int i = 0;i <= n;i++)
	{
		alpha_med += calculateAlpha(sortedPoints[i], sortedPoints[sortedPoints.size() - 1 - i]);
	}
	alpha_med /= n;
	/*
	vector<int> i_L;
	vector<int> i_R;

	for (int i=1; i<L.size();i++)
	{
		for (int j = L.size()-1;j>i;j--)
		{
			if (calculateAlpha(L[i], L[j])>=alpha_med)
			{
				if (compareXCoordinateSmallest(L[i], L[j])) i_L.push_back(i);
				else i_L.push_back(j);
			}
		}
	}

	for (int i = 1; i < R.size();i++)
	{
		for (int j =R.size()-1;j >i;j--)
		{
			if (calculateAlpha(R[i], R[j]) <= alpha_med)
			{
				if (compareXCoordinateSmallest(R[i], R[j])) i_R.push_back(j);
				else i_R.push_back(i);
			}
		}
	}

	for (int i = i_L.size() - 1; i >= 0;i--)
	{
		L.erase(L.begin() + i_L[i]);
	}

	for (int i = i_R.size() - 1; i >= 0;i--)
	{
		R.erase(R.begin() + i_R[i]);
	}

	return R;*/
}