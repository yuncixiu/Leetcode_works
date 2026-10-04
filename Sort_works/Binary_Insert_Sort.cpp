#include<iostream>
#include<vector>
using namespace std;
void Binary_Insert_Sort(vector<int>& arr)
{
	int n = arr.size();
	for (int i = 1; i < n; i++)
	{
		int temp = arr[i];
		if (arr[i-1] > temp)
		{
			int left = 0;
			int right = i - 1;
			while (left <= right)
			{
				int mid = (left + right) / 2;
				if (temp >= arr[mid])//说明插入位置在mid右边，至于为什么要写成大于等于，是因为如果有相同元素，
					//我们为了保证稳定性，插入位置只能在相同元素的右边
				{
					left = mid + 1;
				}
				else { right = mid - 1; }
			}
			//这时候left是第一个大于temp的元素,所以将left与i-1之间的元素全部后移动
			for (int k = i - 1;k >= left;k--)
			{
				arr[k+1] = arr[k];
			}
			arr[left] = temp;

		}
	}
}