#include <iostream>
#include <iomanip> 
#include "Salesman.h"

#define N 5

using namespace std;

int main()
{
 setlocale(LC_ALL, "Russian");

 int d[N][N] = {    
	           {INF, 12,  27,  INF, 6 },   
               {6,   INF, 21,  62,  78 },  
               {8,   18,  INF, 86,  55 },  
               {23,  52,  24,  INF, 18 },  
               {87,  72,  52,  19,  INF}  
               }; 
			   
int r[N];    
 
int s = salesman (            
                  N,          // [in]  ���������� ������� 
                  (int*)d,    // [in]  ������ [n*n] ���������� 
                  r           // [out] ������ [n] ������� 0 x x x x  
      
                 );

 cout << "-- ������ ������������ -- ";
 cout << endl << "-- ����������  �������: " << N;
 cout << endl << "-- ������� ���������� : ";
 
 for(int i=0; i<N; i++)
 { 
    cout << endl;
    
	for(int j=0; j<N; j++)

       if (d[i][j] != INF) 
		   cout << setw(3) << d[i][j] << " ";

       else 
		   cout << setw(3) << "INF" << " ";
 }
 
 cout << endl << "-- ����������� �������: "; 
 
 for(int i=0; i<N; i++) 
	 cout << r[i] +1<< "-->"; 
     cout << 1;
     cout << endl << "-- ����� ��������     : " << s;  
     cout << endl;
 
system("pause");
return 0;
}