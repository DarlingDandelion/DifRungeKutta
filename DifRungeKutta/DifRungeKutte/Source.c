#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <locale.h>

float func(float x, float y)
{
	return x + cos(y/2.25);
}

void RungeKutta(float x, float  y, float h, float d) 
{
	float k1, k2, k3, k4;
	int n = d / h;
	printf("i:%d)x = %f,  y= %f\n", 0, x, y);
	for (int i = 0; i < n; i++)
	{
		k1 = h*func(x, y);
		k2 = h * func(x + h / 2, y + k1 / 2);
		k3 = h * func(x + h / 2, y + k2 / 2);
		k4 = h * func(x + h, y + k3);
		y += ((float)1 / 6)*(k1 + 2 * k2 + 2 * k3 + k4);
		x += h;
		printf("i:%d)x = %f, y= %f\n", i+1, x, y);
	}
}

void main(int argc, char **argv)
{	
	float x0, y0, b, h, result;
	int n;
	bool f = false;
	setlocale(LC_ALL, "");
	while (!f)
	{
		f = true;
		printf("‘ункци€>> x+cos(y/2,25)\n");
		printf("¬ведите начальные услови€\nx0 = ");
		scanf("%f", &x0);
		printf("y0 = ");
		scanf("%f", &y0);
		printf("¬ведите отрезок[%f, b]:\nb = ", x0);
		scanf("%f", &b);
		printf("¬ведите шаг интегрировани€(0,0001 < h < 1): h = ");
		scanf("%f", &h);
		if (b < x0 || !(0, 0001 <= h <= 1))
		{
			f = false;
		}
	}
	RungeKutta(x0, y0, h, b - x0);
}


