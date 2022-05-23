#include "Auxil.h"                            // ��������������� ������� 
#include <iostream>
#include <ctime>
#include <locale>
using namespace std;                    

int main()
{
	int cycle = 100000;
	double  av1 = 0, av2 = 0;
	clock_t  t1 = 0, t2 = 0;

	setlocale(LC_ALL, "rus");

	auxil::start();                          // ����� ��������� 
	t1 = clock();                            // �������� ������� 
	for (int i = 0; i < 10; i++)
	{
		t1 = clock();
		for (int i = 0; i < cycle; i++)
		{
			av1 += (double)auxil::iget(0, 100); // ����� ��������� ����� 
			av2 += auxil::dget(-100, 100);         // ����� ��������� ����� 
		}
	t2 = clock();                            // �������� ������� 

	cout << endl << "���������� ������:         " << cycle;
	cout << endl << "������� �������� (int):    " << av1 / cycle;
	cout << endl << "������� �������� (double): " << av2 / cycle;
	cout << endl << "����������������� (�.�):   " << (t2 - t1);
	cout << endl << "                  (���):   "
		<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);

	cycle += 500000;
    }
	system("pause");
	return 0;
}