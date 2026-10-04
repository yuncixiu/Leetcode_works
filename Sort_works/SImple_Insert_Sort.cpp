#include<iostream>
#include<vector>
using namespace std;
void insert_sort(vector<int>&arr)
{
	int n = arr.size();
	for (int i = 1;i < n;i++)
	{
		int temp = arr[i]; //当前摸到的牌数
		int j = i - 1;
		while (j >= 0 && arr[j] > temp)//确保是升序排列
		{
			arr[j + 1] = arr[j];
			j--; //这两行代码是让整体元素后移并覆盖掉arr[i]，所以才需要temp变量记录
		}
		arr[j + 1] = temp;
	}
}