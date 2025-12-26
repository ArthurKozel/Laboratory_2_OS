#include "main.h"

using namespace std;

int main()
{
	int n = Input_massive_size();
	if(n <= 0)
	{
		cout << "Input data error! The number of array elements must be a positive number.";
		return 0;
	}
	int* massive = new int[n];
	Input_massive_elements(massive, n);

	Processes_arguments Mas;
	Mas.ptr = massive;
	Mas.size = n;

	HANDLE min_max = NULL;
	HANDLE average = NULL;

	Create_Threads(Mas, min_max, average);

	if (min_max == NULL || average == NULL)
		return GetLastError();

	Wait(min_max, average);

	Change_massive(massive, n);
	Output_massive(massive, n);

	delete[] massive;

	return 0;
}