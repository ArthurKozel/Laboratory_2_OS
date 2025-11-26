#include <iostream>
#include <windows.h>

using namespace std;

volatile int max_value = 0;
volatile int min_value = 0;
volatile int average_value = 0;

struct Processes_arguments
{
	int* ptr;
	int size;
};


DWORD WINAPI Min_max(LPVOID Min_max_arguments)
{
	Processes_arguments* arguments = (Processes_arguments*)Min_max_arguments;
	int* massive = arguments->ptr;
	int size = arguments->size;
	max_value = min_value = massive[0];
	for (int i = 1; i < size; i++)
	{
		if (massive[i] < min_value)
			min_value = massive[i];
		if (massive[i] > max_value)
			max_value = massive[i];
		Sleep(7);
	}

	cout << "Min element: " << min_value << endl;
	cout << "Max element: " << max_value << endl;

	return 0;
}

DWORD WINAPI Average(LPVOID Average_arguments)
{
	Processes_arguments* arguments = (Processes_arguments*)Average_arguments;
	int* massive = arguments->ptr;
	int size = arguments->size;
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += massive[i];
		Sleep(12);
	}
	average_value = sum / size;
	cout << "Average value: " << average_value << endl;
	return 0;
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

void Create_Process(Processes_arguments& Mas, HANDLE& min_max, HANDLE& average)
{
	DWORD ID_min_maxThread;
	min_max = CreateThread(NULL, 0, Min_max, &Mas, 0, &ID_min_maxThread);

	DWORD ID_averageThread;
	average = CreateThread(NULL, 0, Average, &Mas, 0, &ID_averageThread);
}

void Wait(HANDLE& min_max, HANDLE& average)
{
	WaitForSingleObject(min_max, INFINITE);
	CloseHandle(min_max);

	WaitForSingleObject(average, INFINITE);
	CloseHandle(average);
}

int main()
{
	int n;
	cout << "Input massive size: ";
	cin >> n;
	int* massive = new int[n];
	cout << "Input massive elements: ";
	for (int i = 0; i < n; i++)
		cin >> massive[i];

	Processes_arguments Mas;
	Mas.ptr = massive;
	Mas.size = n;

	HANDLE min_max = NULL;
	HANDLE average = NULL;

	Create_Process(Mas, min_max, average);

	if (min_max == NULL || average == NULL)
		return GetLastError();

	Wait(min_max, average);

	Change_massive(massive, n);
	Output_massive(massive, n);

	delete[] massive;

	return 0;
}