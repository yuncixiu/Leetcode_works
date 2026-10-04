#include<iostream>
#include<vector>
using namespace std;
void Shell_Sort(vector<int>& arr)
{
	int n = arr.size();
	//这里有一个非常好记的方法,只要你会简单插入排序,在最前面加上一个for(int d = n/2; d >= 1;d //= 2)，然后把j+1全部换成j+d
	for(int d = n/2; d >= 1; d /= 2)
		{
			for (int i = d;i < n;i++)
			{
				int temp = arr[i];
				int j = i - d;
				while (j >= 0 && arr[j] > temp)
				{
					arr[j + d] = arr[j];
					j -= d;
				}
				arr[j + d] = temp;
			}
		}
}