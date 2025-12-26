#pragma once
#include <iostream>
#include <windows.h>
#include "../Threads/threads.h"
#include "../Globals/globals.h"

int Input_massive_size();

void Input_massive_elements(int*& massive, int& n);

void Change_massive(int* massive, int size);

void Output_massive_size(int size);

void Output_massive(int* massive, int size);

bool Create_Threads(Processes_arguments& Mas, HANDLE& min_max, HANDLE& average);

void Wait(HANDLE& min_max, HANDLE& average);
