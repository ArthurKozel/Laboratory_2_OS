#include "utilities.h"

using namespace std;

int Input_massive_size()
{
	int size;
	cout << "Input massive size: ";
	cin >> size;
	return size;
}

void Input_massive_elements(int*& massive, int& n)
{
	cout << "Input massive elements: ";
	for (int i = 0; i < n; i++)
		cin >> massive[i];
}

void Change_massive(int* massive, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (massive[i] == min_value || massive[i] == max_value)
			massive[i] = average_value;
	}
}

void Output_massive_size(int size)
{
	cout << "Massive size : " << size << endl;
}

void Output_massive(int* massive, int size)
{
	cout << "Massive elements:";
	for (int i = 0; i < size; i++)
		cout << " " << massive[i];
	cout << endl;
}

bool Create_Threads(Processes_arguments& Mas, HANDLE& min_max, HANDLE& average)
{
	DWORD ID_min_maxThread;
	min_max = CreateThread(NULL, 0, Min_max, &Mas, 0, &ID_min_maxThread);

	DWORD ID_averageThread;
	average = CreateThread(NULL, 0, Average, &Mas, 0, &ID_averageThread);

	return (min_max != NULL && average != NULL);
}

void Wait(HANDLE& min_max, HANDLE& average)
{
	WaitForSingleObject(min_max, INFINITE);
	CloseHandle(min_max);

	WaitForSingleObject(average, INFINITE);
	CloseHandle(average);
}
