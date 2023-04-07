#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include "Prototypes.h"
#include "resource.h"

int ThreadFunc(LPVOID lpParameter)
{
	// Загружаем dll библиотеку
	HINSTANCE hinstLib = LoadLibrary(L"info.dll");

	if (hinstLib == NULL)
		return EXIT_FAILURE;

	// Создаем тип данных указателя на функцию
	typedef int(*ImportFunction)(TCHAR*);
	// Создаем переменную этого типа
	ImportFunction DLLInfo; 
	// Присваиваем ей функцию
	DLLInfo = (ImportFunction)GetProcAddress(hinstLib, "Information");
	// Вызываем функцию
	DLLInfo((TCHAR*)lpParameter);

	// Освобождаем ресурсы, связанные с dll
	FreeLibrary(hinstLib);
	return EXIT_SUCCESS;
}

// Входная точка
int WINAPI WinMain(HINSTANCE InstanceDescriptor, HINSTANCE PrevInstanceDescriptor, LPSTR lpCmdLine, int nCmdShow)
{
	// Создаем шрифт текста, выводимого в качестве ответа на задание
	fontRectangle = CreateFontA(
		80, 30, 0, 0, FW_MEDIUM,
		FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY,
		FF_DECORATIVE, "CustomFont"
	);

	// Инициализируем окно приложения
	WNDCLASS MainClass = InitWindowClass((HBRUSH)COLOR_WINDOW,
		LoadCursor(NULL, IDC_ARROW),							  // Загружаем курсор, используемый в приложении
		InstanceDescriptor,
		LoadIcon(InstanceDescriptor, MAKEINTRESOURCE(IDI_ICON1)), // Загружаем иконку приложения
		ClassName,
		MainProcedure);

	// Если не удалось зарегестрировать окно -> завершаем програму
	if (!RegisterClass(&MainClass))
		return EXIT_FAILURE;

	MSG Message{};

	// Создаем окно
	CreateWindow(ClassName, NameProg, WS_OVERLAPPEDWINDOW | WS_VISIBLE, 600, 400, 500, 270, NULL, NULL, NULL, NULL);

	// Цикл обработки сообщений
	while (GetMessage(&Message, NULL, NULL, NULL))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}

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
	// Обработка сообщений
	switch (msg)
	{
	// Обработка команд
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
	// Создание окна
	case WM_CREATE:
		DWORD StreamID;
		// Создание дочернего потока
		StreamDescriptor = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadFunc, CurrentYear, 0, &StreamID);

		if (!StreamDescriptor) break;
		// Ожидание дочернего потока
		WaitForSingleObject(StreamDescriptor, INFINITE);
		// Освобождение ресурсов, связанных с дочерним потоком
		CloseHandle(StreamDescriptor);

		AddMenues(hwnd);
		AddWidgets(hwnd);

		break;
	// Закрытие окна
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
	// Создание меню
	HMENU RootMenu = CreateMenu();
	HMENU SubMenu = CreateMenu();

	// Встройка SubMenu в RootMenu
	AppendMenu(RootMenu, MF_POPUP, (UINT_PTR)SubMenu, L"File");
	AppendMenu(SubMenu, MF_STRING, OnExit, L"Exit");

	// Установка меню в окно
	SetMenu(hwnd, RootMenu);
}

void AddWidgets(HWND hwnd)
{
	// Создать статическое поле с выводом информации о текущем годе, установленном на ПК
	Childhwnd = CreateWindowA("static", NULL, WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 5, 490, 200, hwnd, NULL, NULL, NULL);
	// Создать кнопку с информацией об авторе
	CreateWindowA("button", "About Me", WS_VISIBLE | WS_CHILD, 5, 170, 80, 30, hwnd, (HMENU)OnClikedButton, NULL, NULL);

	// Установить шрифт для текста
	SendMessageA(Childhwnd, WM_SETFONT, (WPARAM)fontRectangle, TRUE);

	// Установить текст в окно
	SetWindowText(Childhwnd, CurrentYear);
}