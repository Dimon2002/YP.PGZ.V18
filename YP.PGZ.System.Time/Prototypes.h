#pragma once

#define OnExit					1
#define OnClikedButton			2

LPCWSTR NameProg = L"Individual Work on URVS";
LPCWSTR ClassName = L"PGZ.V18";

const static auto Author = "Author";
const static auto AboutAuthor = "The work was performed by: Salnikov Dmitry Daniilovich PM-04.\nOption 18";

static TCHAR CurrentYear[50]{};

// ���������� �������
HANDLE StreamDescriptor = nullptr;
// �������� ����
HWND Childhwnd;
// ��������� ����
HFONT fontRectangle;

// ��������� � dll ����������
int ThreadFunc(LPVOID lpParameter);

// ��������� ��������� ���������
LRESULT __stdcall MainProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);

// ������������� ���� ����������
WNDCLASS InitWindowClass(HBRUSH BackgroundColor, HCURSOR Cursor, HINSTANCE InstanceDescriptor, HICON Icon, LPCWSTR ClassName, WNDPROC Procedure);

// ���������� ���� � ������� ������ ����������
void AddMenues(HWND hwnd);
// ���������� ��������� � ����, ����� ��� ������ � "static" ���� � ����������
void AddWidgets(HWND hwnd);