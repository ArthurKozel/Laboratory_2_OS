#include "threads.h"

using namespace std;

volatile int max_value = 0;
volatile int min_value = 0;
volatile int average_value = 0;

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
