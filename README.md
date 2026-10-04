Leetcode_works
提醒：题目所有权均属于Leetcode，我只不过发布自己关于题目的看法，如有侵权，联系我删除
105 从前序与中序序列构造二叉树 https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
力扣的1584题目是非常典型的prim(普利姆)问题,
Prim算法的顺序是  1.初始化visit数组  2创建一个distance数组来表示未遍历的节点距离树的最短路径 3设置while循环次数，一般用count表示
1584题题解链接[.\Graph_works\minCostConnectPoints.cpp](https://github.com/yuncixiu/Leetcode_works/blob/main/Graph_works/minCostConnectPoints.cpp)

# 排序问题
## 一.插入排序:
1.直接插入排序 思路 -> 可以比较成摸牌，不过要从1序列开始摸牌(因为第0序列默认成已经排好序的).第二步，就是比较目前摸到的牌和之前摸到的牌的大小，如果目前摸到的牌大，就什么也不做，如果摸到的牌小，就从当前的牌的前一个开始遍历，一直到摸到的牌大于前面的牌。  注意：不要一遍遍历一边比较牌的大小，可以用一个更巧妙的方法，就是在[找到左边的元素小于当前摸到的元素之前，把所有的元素右移]   

