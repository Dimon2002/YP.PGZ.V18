#pragma once

#define OnExit			1
#define OnClikedButton	2

const static auto NameProg = L"�� ���������� ��������� � �������������� ��������";
const static auto ClassName = L"PGZ.V18";

const static auto Author = "�����";
const static auto AboutAuthor = "������ ��������: C�������� ������� ���������� ��-04.\n�������: 18";

static TCHAR CurrentYear[50]{};

HANDLE StreamDescriptor = nullptr;
HWND Childhwnd; 
HFONT fontRectangle;


DWORD  __stdcall SystemTime(void*);

LRESULT __stdcall MainProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS InitWindowClass(HBRUSH BackgroundColor, HCURSOR Cursor, HINSTANCE InstanceDescriptor, HICON Icon, LPCWSTR ClassName, WNDPROC Procedure);

void AddMenues(HWND hwnd);
void AddWidgets(HWND hwnd);