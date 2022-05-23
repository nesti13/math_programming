// Knapsack.cpp 
#include "MyTask1.h"
#define NINF 0x80000000    // ����� ����� int-�����  
int calcv(combi1::subset s, const int v[])  // ����� � �������
{
    int rc = 0;
    for (int i = 0; i < s.sn; i++) rc += v[s.ntx(i)];
    return rc;
};
int calcc(combi1::subset s, const int v[], const int c[]) //��������� � ������� 
{
    int rc = 0;
    for (int i = 0; i < s.sn; i++) rc += (v[s.ntx(i)] * c[s.ntx(i)]);
    return rc;
};
void setm(combi1::subset s, short m[]) //�������� ��������� �������� 
{
    for (int i = 0; i < s.n; i++) m[i] = 0;
    for (int i = 0; i < s.sn; i++) m[s.ntx(i)] = 1;
};
int   knapsack_s(
    int VolumeOfBag,         // [in] ����������� ������� 
    short n,       // [in] ���������� ����� ��������� 
    const int size[], // [in] ������ �������� ������� ����  
    const int price[], // [in] ��������� �������� ������� ����
    short  m[]     // [out] ���������� ��������� ������� ���� {0,1} 
)
{
    combi1::subset s(n);
    int maxc = NINF, figoten = 0;
    short  ns = s.getfirst();
    while (ns >= 0)
    {
        if (calcv(s, size) <= VolumeOfBag)
            if ((figoten = calcc(s, size, price)) > maxc)
            {
                maxc = figoten;
                setm(s, m);
            }
        ns = s.getnext();
    };
    return maxc;
};
