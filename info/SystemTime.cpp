#define _CRT_SECURE_NO_WARNINGS

#include <tchar.h>
#include <Windows.h>

extern "C" __declspec(dllexport) int Information(TCHAR* CurrentYear)
{
	SYSTEMTIME st;
	GetSystemTime(&st);

	_swprintf(CurrentYear, L"Current year: %d", st.wYear);

	return 1;
}