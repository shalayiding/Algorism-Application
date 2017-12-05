#include "Progressbar.h"

HWND PrograssBar::PrograssBar_Creat(int y, HWND hWnd, HINSTANCE hInst)
{
HWND ProGrassbar=CreateWindowEx(0, PROGRESS_CLASS, (LPTSTR)NULL, WS_CHILD | WS_VISIBLE | PBS_SMOOTH
		, x, y, high, width, hWnd, (HMENU)0, hInst, NULL);

	return ProGrassbar;
}

int PrograssBar::Prograss_Counter_Control(int & NumberCount)
{
	


	return 0;
}
