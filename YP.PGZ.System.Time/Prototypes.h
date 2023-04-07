#pragma once

#define OnExit			1
#define OnClikedButton	2

const static auto NameProg = L"ИР Управление ресурсами в вычислительных системах";
const static auto ClassName = L"PGZ.V18";

const static auto Author = "Автор";
const static auto AboutAuthor = "Работу выполнил: Cальников Дмитрий Даниилович ПМ-04.\nВариант: 18";

static TCHAR CurrentYear[50]{};

HANDLE StreamDescriptor = nullptr;
HWND Childhwnd; 
HFONT fontRectangle;


DWORD  __stdcall SystemTime(void*);

LRESULT __stdcall MainProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS InitWindowClass(HBRUSH BackgroundColor, HCURSOR Cursor, HINSTANCE InstanceDescriptor, HICON Icon, LPCWSTR ClassName, WNDPROC Procedure);

void AddMenues(HWND hwnd);
void AddWidgets(HWND hwnd);