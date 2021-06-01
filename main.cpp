
#include "stdafx.h"
double f1(double*);
double f2(double*);
double f3(double*);
double f4(double*);
void eiler(double, double*, double*, double, double(*f[4])(double*));
double(*f[4])(double*);

int main()
{
	setlocale(LC_CTYPE, "russian");
	ofstream ff("outt.txt");
	ofstream ffa("outy0.txt");
	ofstream ffb("outy1.txt");
	ofstream ffc("outy2.txt");
	ofstream ffd("outy3.txt");
	double y0[4], y[4], t = 0, h;
	int k = 0;
	h = 0.00001;
	y0[0] = 2;
	y0[1] = 0;
	y0[2] = 0;
	y0[3] = 0;
	f[0] = f1;
	f[1] = f2;
	f[2] = f3;
	f[3] = f4;
	cout << "\nВторая модификация\n";
	do
	{
		eiler(t, y0, y, h, f);
		t += h;
		k++;
		if (k % 100 == 0)
		{
			cout << t << '\n';
			cout.width(5);
			cout << int(1000 * y[0]) / 1000. << ' ';
			cout.width(5);
			cout << int(1000 * y[1]) / 1000. << ' ';
			cout.width(5);
			cout << int(1000 * y[2]) / 1000. << ' ';
			cout.width(5);
			cout << int(1000 * y[3]) / 1000. << '\n';
			ff << t << '\n';
			ffa.width(5);
			ffa << int(1000 * y[0]) / 1000. << '\n';
			ffb.width(5);
			ffb << int(1000 * y[1]) / 1000. << '\n';
			ffc.width(5);
			ffc << int(1000 * y[2]) / 1000. << '\n';
			ffd.width(5);
			ffd << int(1000 * y[3]) / 1000. << '\n';
		}
		y0[0] = y[0];
		y0[1] = y[1];
		y0[2] = y[2];
		y0[3] = y[3];
	} while (t < 10000 * h);
	return 0;
}
double f1(double *y)
{
	return -0.0065 * y[0] + y[1] * 0.405 - y[3];
}
double f2(double *y)
{
	return 0.0065 * y[0] - y[1] * 0.405;
}
double f3(double* y)
{
	return y[0];
}

double d[4];

double f4(double* y)
{
	d[0] = -0.0089;
	d[1] = -15.021;
	d[2] = -0.5;
	d[3] = 44.6;
	double s = d[0] * y[0] + d[1] * y[1] + d[2] * y[2] + d[3] * y[3];
	double u;
	if (s < 0)
		u = -1;
	else
		u = 1;

	// Я так и не понял, как мне найти d1, d2,.., поэтому пока поставил всё равным единице,
	// а H -- -1, потому что он у нас, как я понял, должен быть отрицательным

	double H = -1;
	return H * fabs(y[2]) * u;
}

void eiler(double x, double *y0, double *y, double h, double(*f[4])(double*))
{
	double *tmp;
	tmp = new double[4];
	tmp[0] = y0[0] + (*f[0])(y0) * h;
	tmp[1] = y0[1] + (*f[1])(y0) * h;
	tmp[2] = y0[2] + (*f[2])(y0) * h;
	tmp[3] = y0[3] + (*f[3])(y0) * h;
	y[0] = y0[0] + ((*f[0])(y0) + (*f[0])(tmp)) * h / 2;
	y[1] = y0[1] + ((*f[1])(y0) + (*f[1])(tmp)) * h / 2;
	y[2] = y0[2] + ((*f[2])(y0) + (*f[2])(tmp)) * h / 2;
	y[3] = y0[3] + ((*f[3])(y0) + (*f[3])(tmp)) * h / 2;
	delete tmp;
}


