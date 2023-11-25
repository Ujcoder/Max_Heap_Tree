#include<iostream>
using namespace std;

void ShiftDown(int num[], int root, int bottom);
void HeapSort(int num[], int ub)
{
	for (int i = (int)ceil((ub / 2.0)) - 1; i >= 0; i--)
		ShiftDown(num, i, ub);
}

void ShiftDown(int num[], int root, int bottom)
{
	int done, MaxChild, temp;
	done = 0;
	while ((root * 2 + 1 <= bottom) && (!done))
	{
		if (root * 2 + 1 == bottom || num[root * 2 + 1] > num[root * 2 + 2])
			MaxChild = root * 2 + 1;
		else
			MaxChild = root * 2 + 2;
		if (num[root] < num[MaxChild])
		{
			temp = num[root];
			num[root] = num[MaxChild];
			num[MaxChild] = temp;
			root = MaxChild;
		}
		else
			done = 1;
	}
}

int main()
{
	int num[20];
	int i, n;
	cout << "Enter Size of Array : ";   cin >> n;
	cout << "Enter Element in Array " << endl;
	for (i = 0; i < n; i++)
		cin >> num[i];
	cout << "After Sorting Elem : " << endl;
	HeapSort(num, n - 1); // Max Heap
	for (i = 0; i < n; i++)
		cout << num[i] << endl;
	return 0;
}