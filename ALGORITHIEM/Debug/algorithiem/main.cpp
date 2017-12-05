#include<iostream>
#include"sorting algorithms.h"
#include<Windows.h>
#include<tchar.h>
#include<string>
#include<string.h>
#include<CommCtrl.h>
#include"Progressbar.h"
#include"resource1.h"
using namespace std;
//#define ID_BTN 1
#define ID_TEXTBOX 2
#define ID_TEXTOUT 3
DWORD IDC_TIMER[6];
DWORD nCounter[6];
static TCHAR szWindowClass[] = _T("Sorting APP");//window Class name
static TCHAR szTitle[] = _T("Sorting App");

						//Golobel Var
bool PrograssBarStart = false;
int Bottom_ID[6] = {10,11,12,13,14,15};
struct Window_DATA_Center
{
	int WindowSizex=1200;
	int WindowSizey=800;
	int Bottom_High = 110;
	int Bottom_With = 50;
	HWND Window_Bottom(int x, int y, int high, int with,HWND hWnd, char Bottomstr[]);
};
void Hold_Code_PrograssBar(HWND hWnd);
void Hold_Code_Bottom(HWND hWnd);
HINSTANCE hInst;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
int CALLBACK WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Window_DATA_Center WDC;
	WNDCLASSEX wndclassex;					//Difualt seting 
	wndclassex.cbSize = sizeof(WNDCLASSEX);
	wndclassex.style = CS_HREDRAW | CS_VREDRAW;
	wndclassex.lpfnWndProc = WndProc;
	wndclassex.cbClsExtra = 0;
	wndclassex.cbWndExtra = 0;
	wndclassex.hInstance = hInst;
	wndclassex.hIcon = LoadIcon(hInst,MAKEINTRESOURCE(IDI_ICON1));
	wndclassex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclassex.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
	wndclassex.lpszMenuName = NULL;
	wndclassex.lpszClassName = szWindowClass;
	wndclassex.hIconSm = LoadIcon(wndclassex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

											//Check for the Register
	if (!RegisterClassEx(&wndclassex))
	{
		MessageBox(NULL,
			_T("wndclassex register error "),
			_T("Sorting App"),
			MB_OK);
		return 1;
	}

											//Creatwindow Set basic Data			
	HWND hWnd = CreateWindow(				
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		WDC.WindowSizex, WDC.WindowSizey,
		NULL,
		NULL,
		hInst,
		NULL
	);
											//check window creat statu
	if (!hWnd)
	{
		MessageBox(NULL,
			_T("wndclassex creatwindow error "),
			_T("Sorting App"),
			MB_OK);
		return 1;
	}
	
											//show window 
	ShowWindow(hWnd, nCmdShow);
	MSG msg;
	while (GetMessage(&msg, hWnd, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

static HWND hWndTextbox;
static HWND Bottom[6];
static HWND hwndTextOut;
static HWND Progressbar[6];
LRESULT CALLBACK WndProc(HWND hWnd, UINT Data, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	Window_DATA_Center WDC;
	switch (Data)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;


	case WM_CREATE: {//creat window insider 
		 
														//creat edit text bar
		hWndTextbox = CreateWindow(TEXT("EDIT"), TEXT(" "),
			WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
			110, 25, 200, 20,
			hWnd, (HMENU)ID_TEXTBOX, NULL, NULL);
		
		Hold_Code_PrograssBar(hWnd);//Creat PrograssBar 
		Hold_Code_Bottom(hWnd);     //creat bottom 
	
											//creat static string
		hwndTextOut = CreateWindow(TEXT("STATIC"), TEXT("Enter Data Array Size : "),
			WS_VISIBLE | WS_CHILD,
			10, 10, 100, 50,
			hWnd, NULL,NULL,NULL
			);

		break;
	}
	case WM_TIMER: {
		if (PrograssBarStart)
		{
			for (int i = 0; i < 6; i++)
			{
				nCounter[i] = nCounter[i] + 1;
				SendMessage(Progressbar[i], PBM_STEPIT, 0, 0);
				if (nCounter[i] == 100)
				{
					KillTimer(hWnd, IDC_TIMER[i]);
				}
			}
		}
		break;
	}
	case WM_COMMAND: {					// action resposnt
		static char text[500];
		
		for (int i = 0; i < 6; i++)
		{
			
			if (LOWORD(wParam) == Bottom_ID[i])
			{

				PrograssBarStart = true;

				//creat vars
				//int len = GetWindowTextLength(hWndTextbox) + 1;
				//int text1 = GetWindowText(hWndTextbox, text, len);
				//SetWindowText(hWnd, text);
			}
		}
		break;
	}

	default:
		return DefWindowProc(hWnd, Data, wParam, lParam);
		break;
	}
	return 0;
}

HWND Window_DATA_Center::Window_Bottom(int x, int y, int high, int with,HWND hWnd,char Bottomstr[])
{
	HWND Bottum[6];
	for (int i = 0; i < 6; i++)
	{
		 Bottom[i]= CreateWindow(TEXT("button"), TEXT(Bottomstr),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,//
			x, y, high
			, with,
			hWnd, (HMENU)Bottom_ID[i], NULL, NULL
		);
		 return Bottum[i];
	}
	
}
void Hold_Code_PrograssBar(HWND hWnd)         // hold code for prograss bar
{
	PrograssBar Progbar;
	int PrograssBar_y = 80;
	for (int i = 0; i < 6; i++)
	{
		
		Progressbar[i] = Progbar.PrograssBar_Creat(PrograssBar_y, hWnd, hInst);
		PrograssBar_y += 100;
		SetTimer(hWnd, IDC_TIMER[i], 100, 0);
		SendMessage(Progressbar[i], PBM_SETSTEP, (WPARAM)1, 0);
		if (PrograssBarStart)
		{
			
			SendMessage(Progressbar[i], PBM_SETRANGE, 0, MAKELPARAM(0, 100));
			
			

			
		}
		
	}
	nCounter[0] = 0;
	

}

void Hold_Code_Bottom(HWND hWnd)
{
	Window_DATA_Center WDC;
	char *Bottom_Text[6];
	Bottom_Text[0] = "SelectionSort";
	Bottom_Text[1] = "InsertionSort";
		Bottom_Text[2] = "BubbleSort";
		Bottom_Text[3] = "MergeSort";
		Bottom_Text[4] = "QuickSort";
		Bottom_Text[5] = "HeapSort";
	int x = 10;
	int y = 70;
	for (int i = 0; i < 6; i++)
	{
		Bottom[i] = WDC.Window_Bottom(x, y+(i*100), WDC.Bottom_High, WDC.Bottom_With, hWnd, Bottom_Text[i]);
	}

}


