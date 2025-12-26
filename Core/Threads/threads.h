#pragma once
#include <iostream>
#include <windows.h>

struct Processes_arguments
{
	int* ptr;
	int size;
};


DWORD WINAPI Min_max(LPVOID Min_max_arguments);

DWORD WINAPI Average(LPVOID Average_arguments);