#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

DWORD  __stdcall ThreadFunc(void*);

DWORD __stdcall ThreadFunc(void*)
{
	SYSTEMTIME st;
	GetSystemTime(&st);

	cout << "Current year: " << st.wYear << endl;;

	exit(EXIT_SUCCESS);
}

int main()
{
	HANDLE StreamDescriptor = nullptr;
	DWORD StreamID;

	StreamDescriptor = CreateThread(NULL, 0, ThreadFunc, NULL, 0 /*CREATE_SUSPENDED*/, &StreamID);

	if (StreamDescriptor)
	{
		WaitForSingleObject(StreamDescriptor, 5); // Почему-то если поставить INFINITY вторым параметром поток завершается прежде чем будет осуществлен вывод текущего года на консоль
		CloseHandle(StreamDescriptor);

		return EXIT_SUCCESS;
	}

	cout << GetLastError();

	return EXIT_FAILURE;
}