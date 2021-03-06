// Diffuri.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>


using namespace std;
float func(float x, float y) {
	return y * (1 - x);
}

void eul(float x0,float  y0,float  a, float b, int n, double (*ptr2f)(double, double)) {
	float h, Yi;
	h = (b - a) / n;
	Yi = y0;
	cout << "     i    " << " x      " << "     Yi   " << endl;
	for (int i = 0; i <= n; i++) {
		Yi += h * ptr2f(x0, y0);
		x0 += h;
		y0 = Yi;
		cout << "    " << i << "     " << x0 - h << "       " << Yi << "  " << endl;
	}
	
}

void runge(float  a, float b, int n) {
	float h, y = 1;
	int i = 0;
	h = (b - a) / n;
	cout << "     i    " << " x      " << "     Yi   " << endl;
	for (float x = a; x <= (b - h); x += h) {
		float k1, k2, k3, k4;
		k1 = func(x, y);
		k2 = func((x + h / 2), (y + h / 2 * k1));
		k3 = func((x + h / 2), (y + h / 2 * k2));
		k4 = func((x + h), (y + h * k3));
		cout << "    " << i << "     " << x - h << "       " << y << "  " << endl;
		y += (h / 6 * (k1 + 2 * k2 + 2 * k3 + k4));
		i += 1;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Метод Эйлера: " << endl;
	eul(0, 1, 0, 1, 1000);
	cout << "Метод Рунге-Кутта: " << endl;
	runge(0, 1, 1000);
	system("pause");
    return 0;
}

