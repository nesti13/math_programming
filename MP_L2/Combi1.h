#pragma once 
namespace combi1
{
    struct  subset       // ���������  ��������� ���� �����������    
    {
        short  n,        // ���������� ��������� ��������� ��������� < 64  
            sn,          // ���������� ��������� ��������  ������������
            * sset;             // ������ �������� �������� ������������ 
        unsigned __int64 mask;  // ������� �����  
        subset(short n = 1);    // �����������(���-�� ��-�� ���. ��-��) 
        short getfirst();       // �����. ������ �������� �� ������� �����    
        short getnext();        // ++����� � ������������ ������ �������� 
        short ntx(short i);       // �������� i-� ������� ������� �������� 
        unsigned __int64 count(); // ��������� ����� ���-�� ����������� 
        void reset();             // �������� ���������, ������ ������� 
    };
};
