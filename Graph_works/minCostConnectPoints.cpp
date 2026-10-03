#include<cmath>
#include<climits>
#include<vector>
using namespace std;
class Solution {
public:
int calculate_dis(vector<int>x,vector<int>y)
{
    int dis = abs(x[0]-y[0]) + abs(x[1]-y[1]);
    return dis;
}
int minCostConnectPoints(vector<vector<int>>& points) 
{
    int n = points.size();
    vector<int>min_val_dis(n,INT_MAX);//这个用于存储未遍历的的节点距离和已经遍历过的结点距离。初始设置为INT_MAX(limits头文件里面的),
    min_val_dis[0] = 0;
    vector<bool>visit(n,false);
    //随便取一个初始节点，默认的话为第0结点
    visit[0] = true;
    int count = 0;//记录循环次数，用作退出循环
    int ans = 0; //作为答案返回
    //循环之前必须要进行初始化，防止全是INT_MAX进入无限循环
    for(int j = 1;j < n;j++)
    {
        int dis = calculate_dis(points[0],points[j]);
        min_val_dis[j] = dis;
    }
    while(count<n)
    {
        int u = -1;//记录当前结点情况
        int dis_val = INT_MAX;
        for(int i = 0;i < n;i++)
        {
            if(!visit[i] && min_val_dis[i] < dis_val)
            {
                //找到了一个元素,第一次循环肯定是0；
                dis_val = min_val_dis[i];
                u = i;
            }
        
        }
        if(u == -1)
        {
            break;//注意:本题目while循环标准情况应该是循环n-1次，因为我初始化0了，但是因为有这个防御性代码，可以直接循环n次
        }
        visit[u] = true;
        //用找到的元素u去更新min_val_dis的情况
        for(int v = 0;v < n; v++)
        {
            if(!visit[v])
            {
                int dis = calculate_dis(points[u],points[v]);
                if(dis < min_val_dis[v])
                {
                    min_val_dis[v] = dis;
                }
            }
        }
        ans += min_val_dis[u];
        count ++;
    }
    return ans;

}
};