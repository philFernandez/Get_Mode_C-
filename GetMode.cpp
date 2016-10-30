#include <iostream>
#include <string>

using namespace std;


template <class T>

// Template returs the most frequently occurring element of any type array
T GetMode(int size, T arr[])
{

	// selection sort------------------------------------
	int minIndex;
	T minValue;
	for (int i = 0; i < (size - 1); i++)
	{
		minIndex = i;
		minValue = arr[i];
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < minValue)
			{
				minValue = arr[j];
				minIndex = j;
			}
		}
		arr[minIndex] = arr[i];
		arr[i] = minValue;
	}
	// --------------------------------------------------


	// find most frequentlly occuring element------------
	int most = 0;
	T mode;
	for (int i = 0; i < (size - 1); i++)
	{
		int counter = 0;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] == arr[j])
				counter++;
		}
		if (counter > most)
		{
			most = counter;
			mode = arr[i];
		}
	}
	// --------------------------------------------------
	
	return mode;
}

// main function calls GetMode with an array of string and an array of int.
int main()
{
	const int N = 9;
	string x[N] = { "cat", "dog", "dog", "dog", "cat", "cat", "cat", "cat", "dog" };
	int y[N] = { 10, 2, 4, 5, 6, 10, 4, 10, 3 };
	cout << GetMode <string>(N, x) << "\n";
	cout << GetMode <int>(N, y) << "\n";
	return 0;
}