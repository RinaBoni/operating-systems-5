#include <windows.h>   
 

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);


int WINAPI WinMain (HINSTANCE hInst, HINSTANCE, LPSTR, int)
{
   WNDCLASS wcl;  
   MSG      msg;  
   HWND     wnd;  

   wcl.style  = 0;               
   wcl.lpfnWndProc = WndProc;    
   wcl.hInstance  = hInst;       
   wcl.hCursor = LoadCursor( NULL, IDC_ARROW);  
   wcl.hIcon = LoadIcon (NULL, IDI_WARNING);
   wcl.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
   wcl.lpszMenuName = NULL;                     
   wcl.lpszClassName = LPCWSTR (L"First");       
   wcl.cbClsExtra = wcl.cbWndExtra = 0;


   if (!RegisterClass (&wcl)) return 0;

   wnd  = CreateWindow
   (
     LPCWSTR (L"First"),          
     LPCWSTR (L"Hello, Windows!"),
     WS_OVERLAPPEDWINDOW,       
     CW_USEDEFAULT, CW_USEDEFAULT,
     CW_USEDEFAULT, CW_USEDEFAULT,
     NULL, NULL,    
     hInst,         
     NULL);         

   ShowWindow (wnd, SW_SHOW);    


   while (GetMessage (&msg, NULL, 0, 0))
   {
       TranslateMessage (&msg);
       DispatchMessage (&msg);
   }
  
   return msg.wParam;
}

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

