#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include "Prototypes.h"
#include "resource.h"

DWORD __stdcall SystemTime(LPVOID lpParameter)
{
	SYSTEMTIME st;
	GetSystemTime(&st);

	_swprintf(CurrentYear, L"Current year: %d", st.wYear);

	return 1;
}

int ThreadFunc()
{
	DWORD StreamID;

	StreamDescriptor = CreateThread(NULL, 0, SystemTime, CurrentYear, 0, &StreamID);

	if (StreamDescriptor)
	{
		WaitForSingleObject(StreamDescriptor, INFINITE);
		CloseHandle(StreamDescriptor);

		return EXIT_SUCCESS;
	}
}

int WINAPI WinMain(HINSTANCE InstanceDescriptor, HINSTANCE PrevInstanceDescriptor, LPSTR lpCmdLine, int nCmdShow)
{
	fontRectangle = CreateFontA(
		80, 30, 0, 0, FW_MEDIUM,
		FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY,
		FF_DECORATIVE, "CustomFont"
	);

	WNDCLASS MainClass = InitWindowClass((HBRUSH)COLOR_WINDOW,
		LoadCursor(NULL, IDC_ARROW),
		InstanceDescriptor,
		LoadIcon(InstanceDescriptor, MAKEINTRESOURCE(IDI_ICON1)),
		ClassName,
		MainProcedure);

	if (!RegisterClass(&MainClass))
		return EXIT_FAILURE;

	MSG Message{};

	CreateWindow(ClassName, NameProg, WS_OVERLAPPEDWINDOW | WS_VISIBLE, 600, 400, 500, 270, NULL, NULL, NULL, NULL);

	while (GetMessage(&Message, NULL, NULL, NULL))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}

	//TerminateThread(StreamDescriptor, 0);

	return EXIT_SUCCESS;
}

WNDCLASS InitWindowClass(HBRUSH BackgroundColor,
	HCURSOR Cursor,
	HINSTANCE InstanceDescriptor,
	HICON Icon,
	LPCWSTR ClassName,
	WNDPROC Procedure)
{
	return WNDCLASS
	{
		{},
		Procedure,
		{},
		{},
		InstanceDescriptor,
		Icon,
		Cursor,
		BackgroundColor,
		{},
		ClassName,
	};
}

LRESULT CALLBACK MainProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_COMMAND:

		switch (wp)
		{
		case OnClikedButton:
			MessageBoxA(hwnd, AboutAuthor, Author, MB_OK);
			break;
		case OnExit:
			PostQuitMessage(EXIT_SUCCESS);
			break;
		default: break;
		}
		break;
	case WM_CREATE:
		ThreadFunc();

		AddMenues(hwnd);
		AddWidgets(hwnd);

		break;
	case WM_DESTROY:
		PostQuitMessage(EXIT_SUCCESS);
		break;
	default:
		return DefWindowProc(hwnd, msg, wp, lp);
		break;
	}

	return EXIT_SUCCESS;
}

void AddMenues(HWND hwnd)
{
	HMENU RootMenu = CreateMenu();
	HMENU SubMenu = CreateMenu();

	AppendMenu(RootMenu, MF_POPUP, (UINT_PTR)SubMenu, L"File");
	AppendMenu(SubMenu, MF_STRING, OnExit, L"Exit");

	SetMenu(hwnd, RootMenu);
}

void AddWidgets(HWND hwnd)
{
	Childhwnd = CreateWindowA("static", NULL, WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 5, 490, 200, hwnd, NULL, NULL, NULL);
	CreateWindowA("button", "About Me", WS_VISIBLE | WS_CHILD, 5, 170, 80, 30, hwnd, (HMENU)OnClikedButton, NULL, NULL);

	SendMessageA(Childhwnd, WM_SETFONT, (WPARAM)fontRectangle, TRUE);

	SetWindowText(Childhwnd, CurrentYear);
}