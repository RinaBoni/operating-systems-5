/************************************************************************
                          ������������ ������ N3

                                ������ 1.

                               DLLCALLER.CPP

       �������� ��������� ��� ������ ������� �� DLL (������� ����������)

************************************************************************/
#include <windows.h>

extern LPCWSTR Test (void);

int WINAPI WinMain (HINSTANCE, HINSTANCE, LPSTR, int)
{
    LPCWSTR str = Test ();        
    return MessageBox (NULL, str, L"����� �� DLL!", MB_OK | MB_ICONEXCLAMATION);
}

