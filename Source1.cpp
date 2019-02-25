#include <cstdio>

int main() {
	const double a = 1, b = 1.5, h = 0.1;
	double y = 0.77, y1 = 0.44, x = a, z = y1;
	while (x <= b) {
		printf("x = %3.1lf, y = %3.5lf, z = %l3.5f", x, y, z);
		y1 = y + h * z;
		z *= h*(z / x + y);
		y = y1;
		x += h;
	}

	return 0
}