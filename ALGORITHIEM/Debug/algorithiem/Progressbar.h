#pragma once
#include<Windows.h>
#include<iostream>
#include<CommCtrl.h>
class PrograssBar
{
public:
	HWND PrograssBar_Creat(int y, HWND hWnd, HINSTANCE hInst);
	int Prograss_Counter_Control(int &NumberCount);

private:
	int x=150;
	int high=300;
	int width=30;

};
