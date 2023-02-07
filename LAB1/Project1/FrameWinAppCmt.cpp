/************************************************************************
                          ������������ ������ N1

                                ������ 2.

                              HELLOWIN2.CPP

                        ��������� ���������� Windows

************************************************************************/
#include <windows.h>    // ���������� �������� ������� API, ����������� �����
                        // Windows � �.�.

/*  ��������� �������� ������� ������� (����� ��� ���������� WndProc).
    ��� ������������� ��������: LRESULT CALLBACK (������� ��������� ������).
    ���������: ���������� ����, �������� ����������� �������,
               ������������� ���������, ����������� �������,
               ��������� ��������� (WPARAM � LPAPAM).
*/


LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);


/* �������� ������� WinMain():
   ��� ������������� �������� - WINAPI,
   ���������:
              HINSTANCE hInst - ���������� �������� ���������� ����������,
              HINSTANCE       - �� ������������ (������ NULL)
              LPSTR           - ��������� ��������� ������
              int             - ����� ������ ����  

   � ������ ������ ������������ ������ ������ ��������, ������� �� �����
   ����������� �������� hInst. ������ ��������� �� ������������.
*/

int WINAPI WinMain (HINSTANCE hInst, HINSTANCE, LPSTR, int)
{
   WNDCLASS wcl;        // ��������� ��� ������ ����
   MSG      msg;        // ��������� ��� �������� ����������� ���������
   HWND     wnd;        // ���������� ����


   // ���������� ��������� WNDCLASS - �������� ������ ����

   wcl.style  = 0;                // ����� ���� - �� ���������
   wcl.lpfnWndProc = WndProc;     // ������� �������� ����������� WndProc
   wcl.hInstance  = hInst;        // ���������� ����������
   wcl.hCursor = LoadCursor( NULL, IDC_ARROW);  // ����� ������� � ����
   wcl.hIcon = LoadIcon (NULL, IDI_APPLICATION);  // ������ ����������      
   wcl.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);  // ���� ����      
   wcl.lpszMenuName = NULL;                     // �������� ���� ��� (NULL)
   wcl.lpszClassName = LPCWSTR (L"First");            // ��� ������ ����
   wcl.cbClsExtra = wcl.cbWndExtra = 0; // �������������� ��������� (�� ��������)


   if (!RegisterClass (&wcl)) return 0;   // ����������� ������ ����

   // �������� ����
   wnd  = CreateWindow
   (
     LPCWSTR (L"First"),                   // ����� ����
     LPCWSTR (L"Hello, Windows!"),         // ����� � ��������� ����
     WS_OVERLAPPEDWINDOW,       // ����� - ������� ���� �  ������
     CW_USEDEFAULT, CW_USEDEFAULT,  // ���������� � ������� ���� - �� ���������
     CW_USEDEFAULT, CW_USEDEFAULT,
     NULL, NULL,           // ������������� ���� � �������� ���� ���
     hInst,           // ���� ����������� ���������� � ������������ hInst     
     NULL);           // �������������� ���������� ���  

   ShowWindow (wnd, SW_SHOW);           // ����� ���������� ����


   /*
      ������ ����� ��������� ���������
      ���� ����������� �� ��� ���, ���� ������� GetMessage(), ����������
      ��������� �� ������� ��������� ����������, �� ������� ��������� WM_QUIT,
      ��������������� � ���������� ������. � ���� ������ GetMessage()
      ���������� 0, � ���� �����������. ������ ����� ���������� ����������
      ���������� ����� ������ ����������� ������ TranslateMessage (), �����
      ������� DispatchMessage () �������� ������������ ��������� ������� 
      Windows, ������� �������� ������������� ��� ����������� ������ ����
      callback-������� (� ������ ������ - WndProc). 
   */

   while (GetMessage (&msg, NULL, 0, 0))
   {
       TranslateMessage (&msg);
       DispatchMessage (&msg);
   }
  
   return msg.wParam;
}


/*
    ������� ������� ����������� ���������� � ��������� MSG ���������.
    ���� ��������� ��������� WM_DESTROY (���� ������� �������� ����),
    �� ���������� ��������� ����������� ��������� � ���������� ������
    ������� PostQuitMessage(). ��� ������ ��������� �������������� ��
    ��������� ����� ������������ ��������. ��� ����� ��� ���������� �
    Windows ����������� ������ DefWindowProc().
*/
LRESULT CALLBACK WndProc (HWND wnd, UINT msg, WPARAM wp, LPARAM lp)
{
   switch( msg )
   {

      case WM_DESTROY:
         PostQuitMessage(0);
         return 0;

      default:
         return DefWindowProc( wnd, msg, wp, lp );

   }
}

