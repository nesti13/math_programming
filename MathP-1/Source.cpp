#include "Auxil.h"                            // вспомогательные функции 
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

	auxil::start();                          // старт генерации 
	t1 = clock();                            // фиксация времени 
	for (int i = 0; i < 10; i++)
	{
		t1 = clock();
		for (int i = 0; i < cycle; i++)
		{
			av1 += (double)auxil::iget(0, 100); // сумма случайных чисел 
			av2 += auxil::dget(-100, 100);         // сумма случайных чисел 
		}
	t2 = clock();                            // фиксация времени 

	cout << endl << "количество циклов:         " << cycle;
	cout << endl << "среднее значение (int):    " << av1 / cycle;
	cout << endl << "среднее значение (double): " << av2 / cycle;
	cout << endl << "продолжительность (у.е):   " << (t2 - t1);
	cout << endl << "                  (сек):   "
		<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);

	cycle += 500000;
    }
	system("pause");
	return 0;
}