/************************************************************************
                          ������������ ������ N3

                                ������ 1.

                               TESTDLL.CPP

    ������ ���������� DLL, �������������� �������  ��� ������� ����������

************************************************************************/
#include <windows.h>


LPCWSTR GetSomeString ()
{                       
   return L"Hello from DLL!\n";
}


LPCWSTR  __declspec (dllexport) Test (void)
{
   return GetSomeString ();
}


BOOL WINAPI DllEntryPoint (HINSTANCE, DWORD, DWORD)
{
    return 1;    
}

