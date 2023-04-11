#pragma once

#define OnExit					1
#define OnClikedButton			2

LPCWSTR NameProg = L"Individual Work on URVS";
LPCWSTR ClassName = L"PGZ.V18";

const static auto Author = "Author";
const static auto AboutAuthor = "The work was performed by: Salnikov Dmitry Daniilovich PM-04.\nOption 18";

static TCHAR CurrentYear[50]{};

// Дескриптор обьекта
HANDLE StreamDescriptor = nullptr;
// Дочернее окно
HWND Childhwnd;
// Параметры фона
HFONT fontRectangle;

// Обращение к dll библиотеке
int ThreadFunc(LPVOID lpParameter);

// Процедура обработки сообщений
LRESULT __stdcall MainProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);

// Инициализация окна приложения
WNDCLASS InitWindowClass(HBRUSH BackgroundColor, HCURSOR Cursor, HINSTANCE InstanceDescriptor, HICON Icon, LPCWSTR ClassName, WNDPROC Procedure);

// Добавление меню в верхнюю панель приложения
void AddMenues(HWND hwnd);
// Добавление компонент в окно, таких как кнопка и "static" поле с сообщением
void AddWidgets(HWND hwnd);