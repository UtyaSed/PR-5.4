// Lab_05_4.cpp
// Обухова Віктора
// Лабораторна робота No 5.4
// Обчислення сум та добутків за допомогою рекурсії
// Варіант 0.7

#include <iostream>
#include <cmath>

using namespace std;
double S0(const int N);
double S1(const int N, const int k);
double S2(const int N, const int k);
double S3(const int N, const int k, double t);
double S4(const int N, const int k, double t);






double S0(const int N)
{
	double s = 0;
	for (int k = 1; k <= N; k++)
		s += 1 / ((2 * (1. * k) + 1) * (2 * (1. * k) + 1));
	return s;
}
double S1(const int N, const int k)
{
	if (k > N)
		return 0;
	else
		return (1 / ((2 * (1. * k) + 1) * (2 * (1. * k) + 1))) + S1(N, k + 1);
}
double S2(const int N, const int k)
{
	if (k < 1)
		return 0;
	else
		return (1 / ((2 * (1. * k) + 1) * (2 * (1. * k) + 1))) + S2(N, k - 1);
}
double S3(const int N, const int k, double t)
{
	t = t + (1 / ((2 * (1. * k) + 1) * (2 *  k + 1)));
	if (k >= N)
		return t;
	else
		return S3(N, k + 1, t);
}
double S4(const int N, const int k, double t)
{
	t = t + (1 / ((2 * (1. * k) + 1) * (2 * k + 1)));
	if (k <= 1)
		return t;
	else
		return S4(N, k - 1, t);
}

int main()

{
	int k, N;
	cout << "N = "; cin >> N;


	k = 1;

	cout << "(iter) S0 = " << S0(N) << endl;
	cout << "(rec up ++) S1 = " << S1(N, 1) << endl;
	cout << "(rec up --) S2 = " << S2(N, N) << endl;
	cout << "(rec down ++) S3 = " << S3(N, 1, 0) << endl;
	cout << "(rec down --) S4 = " << S4(N, N, 0) << endl;
	return 0;
}
