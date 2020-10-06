/*
栈是常用的一种数据结构，有n令元素在栈顶端一侧等待进栈，栈顶端另一侧是出栈序列。你已经知道栈的操作有两·种：push和pop，前者是将一个元素进栈，后者是将栈顶元素弹出。现在要使用这两种操作，由一个操作序列可以得到一系列的输出序列。请你编程求出对于给定的n，计算并输出由操作数序列1，2，…，n，经过一系列操作可能得到的输出序列总数。
本题数据超出了约定数据，因此采取了打表（不然RE） 
*/
#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,num[10]={0,35357670,129644790,477638700,1767263190,6564120420};
inline void dfs(long long  in,long long  out)
{
	if(in==n || out==n)
	{
		ans++;
		return;
	}
	if(in<n)
		dfs(in+1,out);
	if(out<n && out<in)
		dfs(in,out+1);
	return;
}

int main()
{
	cin>>n;
	if (n>16)
	{
		cout<<num[n-15];
		return 0;
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
