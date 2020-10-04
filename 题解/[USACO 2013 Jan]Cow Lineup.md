# 题目

**Description**
Cow Lineup [Brian Dean and Daniel Dara, 2012] Farmer John's N cows 
(1 <= N <= 100,000) are lined up in a row. Each cow is identified
 by an integer "breed ID" in the range 0...1,000,000,000; the breed 
ID of the ith cow in the lineup is B(i). Multiple cows can share the 
same breed ID. FJ thinks that his line of cows will look much more 
impressive if there is a large contiguous block of cows that all have 
the same breed ID. In order to create such a block, FJ chooses up to K 
breed IDs and removes from his lineup all the cows having those IDs. 
Please help FJ figure out the length of the largest consecutive block 
of cows with the same breed ID that he can create by doing this. 
有N头牛(1 <= N <= 100,000) 排成一列。每头牛有一个标号，范围在0到1000000000，
第 i 头牛的编号为B(i)。多头牛可以共享一个编号。John想，如果前后相邻的多头牛
能有相同的编号，将会更好。为了使前后相连且编号相同的牛的数量尽可能多，
John将选择 K 个编号，然后移除编号与这K个编号相同的牛。请帮忙选择编号。
**Input**
第1行：N和K 
第2至N+1行：Line i+1 第i头牛的编号 B(i)
**Output**
连续的编号相同的牛的最大总数。
**Sample Input**
9  1
2
7
3
7
7
3
7
5
7
有9头牛，要选择1个编号的牛移除。
**Sample Output**
4
提示：通过移除编号是3 的牛，将有4个编号为7的牛相连

# 思路

以样例为例
我们可以从头扫到尾
当i=1时，数列为2
当i=2时，数列为2,7
当i=3时，我们发现数列加入3后，有三类数字出现了。于是	头结点右移，数列变成7，3
当i=4时，7的出现次数多了1，有两个七了
当i=5时，七的出现次数多了一，又三个七了
当i=6时，三的出现次数多了一，有两个三了
当i=7时，七的出现次数多了一，有四个七了
此时会找到答案，在区间[7 3 7 7 3 7]中出现了四个七
当i=8时，出现了五，于是区间内有三种数字了
于是不断地移动头结点，直到区间为[7,5]时，保证其中只有两类数字
i=9时，7出现次数多了一，有2个七了
最终对比大小，4最大，COUT4

# 注意

题中还有要求删除的编号的个数是一个变量

# ANSWER

```C++
#include<bits/stdc++.h>
using namespace std;
map<long long,int> vis;
int a=0,kind=0,head=1,shuzu[100005],ans=0,n,k;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>shuzu[i];
    while(kind<=n)
    {
        kind++;
        if(vis[shuzu[kind]]==0)
            a++;
        vis[shuzu[kind]]++;
        while(a==k+2)
        {
            vis[shuzu[head]]--;
            if(vis[shuzu[head]]==0)
                a--;
            head++;
        }
        ans=max(ans,vis[shuzu[kind]]);
    }
    cout<<ans;
    return 0;
}
```
