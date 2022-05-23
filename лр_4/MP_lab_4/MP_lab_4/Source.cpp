#include "Task1.h"
#include "Levenshtein.h"
#include <iostream>
#include <cmath>
#include <memory.h>
#include "MultyMatrix.h"


using namespace std;
void Task1();
void Task2();
void Task5();

void main()
{
	setlocale(LC_ALL, "rus");

	//Task1();
	cout << "-----------------\n\n\n";
	Task2();
	cout << "-----------------\n\n\n";
	//Task5();
}

 

void Task1()
{
	char* str250 = getString(250);
	char* str300 = getString(300);
	cout << "������ ������ 250 �������� = " << str250 << endl << endl;
	cout << "������ ������ 300 �������� = " << str300 << endl << endl;
}

void Task2()
{
	clock_t t1 = 0, t2 = 0, t3, t4;
	char x[] = "���", y[] = "�����";
	int  lx = sizeof(x) - 1, ly = sizeof(y) - 1;
	std::cout << std::endl << "-- ���������� ����������� -----" << std::endl;
	std::cout << std::endl << "--����� --- �������� -- ���.�������. ---" << std::endl;
	for (int i = 8; i < std::min(lx, ly); i++)
	{
		t1 = clock();
		levenshtein_r(i, x, i - 2, y);
		t2 = clock();
		t3 = clock();
		levenshtein(i, x, i - 2, y);
		t4 = clock();
		std::cout << std::right << std::setw(2) << i - 2 << "/" << std::setw(2) << i
			<< "        " << std::left << std::setw(10) << ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC)
			<< "   " << std::setw(10) << ((double)(t4 - t3)) / ((double)CLOCKS_PER_SEC) << std::endl;
	}

}

void Task5()
{
#define N 6
	int Mc[N + 1] = { 20, 15, 30, 53, 10, 20, 11 }, Ms[N][N], r = 0, rd = 0;

	memset(Ms, 0, sizeof(int) * N * N);
	r = OptimalM(1, N, N, Mc, OPTIMALM_PARM(Ms));
	std::cout << std::endl;
	std::cout << std::endl << "-- ����������� ������ (����������� �������) "
		<< std::endl;
	std::cout << std::endl << "����������� ������: ";
	for (int i = 1; i <= N; i++) std::cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";
	std::cout << std::endl << "����������� ���������� �������� ���������: " << r;
	std::cout << std::endl << std::endl << "������� S" << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < N; j++)  std::cout << Ms[i][j] << "  ";
	}
	std::cout << std::endl;

	memset(Ms, 0, sizeof(int) * N * N);
	rd = OptimalMD(N, Mc, OPTIMALM_PARM(Ms));
	std::cout << std::endl
		<< "-- ����������� ������ (���������� ����������������) " << std::endl;
	std::cout << std::endl << "����������� ������: ";
	for (int i = 1; i <= N; i++)
		std::cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";
	std::cout << std::endl << "����������� ���������� �������� ���������: "
		<< rd;
	std::cout << std::endl << std::endl << "������� S" << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < N; j++)  std::cout << Ms[i][j] << "  ";
	}
	std::cout << std::endl << std::endl;

}