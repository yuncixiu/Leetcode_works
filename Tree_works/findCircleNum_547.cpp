#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //并查集的Find函数
    int Find(int x,vector<int>&parent)//别忘了是引用传递，要修改parent的
    {
        int root = x;
        while(root != parent[root] )
        {
            root = parent[root];
        }
        while(x != root)//这个循环是将x结点往上的所有结点统统置为x的根节点
        {
            int t = parent[x];
            parent[x] = root;
            x =  t;
        }
        return root;
    }
    // void Union(int root1,int root2)
    // {
    //     //合并并查集根相同的集合,但是对于岛屿问题用不到，因为是必须要遍历一次这个isConnected数组，可以动态合并，但是也要掌握该方法，但是不适用于这个题目，因为我们初始化parent的下标从0开始，是正值。
    //     if(root1 == root2) return;
    //     else if(parent[root1] > parent[root2])
    //     {
    //         parent[root2] += parent[root1];
    //         parent[root1] = parent[root2];
    //     }
    //     else{
    //         parent[root1] += parent[root2];
    //         parent[root2] = parent[root1];
    //     }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        //对于无向图，最好的方法是并查集；因为题目中包含了:[1.省份和省份之间联通2.求各个子集的数量]
        //初始化并查集
        int n = isConnected.size();
        vector<int>parent(n);
        int count = n; //假设初始省份每个都是单独的子集，遇到可以合并的就用并查集的Union函数，再count--.
        for(int i =  0;i < n;i++)
        {
            parent[i] = i;
        }

        //遍历整个isConnected数组,i表示岛屿1，j表示岛屿2
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j<i;j++)//处理到小于i就行了，当j==i是他自身，它自身肯定是相连的
            {
                if(isConnected[i][j] == 1)
                
                {
                    int root1 = Find(i,parent);
                    int root2 = Find(j,parent);
                    if(root1 != root2)//可以合并
                    {
                        parent[root2] = root1;
                        count --;
                    }
                }
            }
        }
        return count;

    }
};