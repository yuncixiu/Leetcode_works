#include<iostream>
#include<vector>
using namespace std;
void Bubble_Sort(vector<int>& arr)
{
	int n = arr.size();
	for (int i = 0; i < n;i++)
	{
		bool flag = true;
		for (int j = n - 1;j > i ;j--)
		{
			if (arr[j - 1] > arr[j]) //大数下沉
			{
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j - 1] = temp;
				flag = false;
			}
		}
		if (flag)
			break;
	}
}