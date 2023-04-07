#pragma once

#define OnExit					1
#define OnClikedButton			2

const static auto NameProg = L"ИР Управление ресурсами в вычислительных системах";
const static auto ClassName = L"PGZ.V18";

const static auto Author = "Автор";
const static auto AboutAuthor = "Работу выполнил: Cальников Дмитрий Даниилович ПМ-04.\nВариант: 18";

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