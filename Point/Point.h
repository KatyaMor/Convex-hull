#pragma once
#pragma once

#include <iostream>

using namespace std;

struct point {
	float x, y;
	point() {
		x = 0; y = 0;
	}
	point(float aX, float aY) {
		x = aX; y = aY;
	}
	// comparison is done first on y coordinate and then on x coordinate
	bool operator < (point b) {
		if (y != b.y)
			return y < b.y;
		return x < b.x;
	}
};
