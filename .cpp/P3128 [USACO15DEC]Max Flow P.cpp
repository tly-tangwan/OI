/*
P3128 [USACO15DEC]Max Flow P
https://www.luogu.com.cn/problem/P3128
一开始数据范围开小了
FJ 给他的牛棚的N（2<=N<=50000） 个隔间之间安装了 N-1 根管道，隔间编号从 1 到 N 。所有隔间都被管道连通了。

FJ有 K(1<=K<=100000) 条运输牛奶的路线，第 i 条路线从隔间 si 运输到隔间 ti 。一条运输路线会给它的两个端点处的隔间以及中间途径的所有隔间带来一个单位的运输压力，你需要计算压力最大的隔间的压力是多少。

需要统计每个点经过了多少次，那么就用树上差分将每一次的路径上的点加一，可以很快得到每个点经过的次数。这里采用倍增法进行 lca 的计算。最后对 DFS 遍历整棵树，在回溯时对差分数组求和就能求得答案了。
*/


#include<bits/stdc++.h>
using namespace std;
struct node
{
	int to,next;
} e[100010];
int head[50010],sum[50010],n,m,d[50010],fa[50010][30],ans,num;

inline int read()
{
	int s=0;
	char c=getchar();
	while (c<'0' || c>'9') c=getchar();
	while (c>='0' && c<='9') s=s*10+c-'0',c=getchar();
	return s;
}
inline void add(int x,int y)
{
	e[++num].to=y;
	e[num].next=head[x];
	head[x]=num;
}
inline void work(int u,int fath)
{
	d[u]=d[fath]+1;
	fa[u][0]=fath;
	for (int i=0; fa[u][i]; ++i)
		fa[u][i+1]=fa[fa[u][i]][i];
	for (int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if (v!=fath)
			work(v,u);
	}
}
inline int Lca(int u,int v)
{
	if (d[u]>d[v])
		swap(u,v);
	for (int i=20; i>=0; --i)
		if (d[u]<=d[v]-(1<<i))
			v=fa[v][i];
	if (u==v)
		return u;
	for (int i=20; i>=0; --i)
		if (fa[u][i]!=fa[v][i])
			u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
inline void Get(int u,int fath)
{
	for (int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if (v==fath)
			continue;
		Get(v,u);
		sum[u]+=sum[v];
	}
	ans=max(ans,sum[u]);
}

int main()
{
	n=read(),m=read();
	int x,y;
	for (int i=1; i<n; ++i)
	{
		x=read(),y=read();
		add(x,y);
		add(y,x);
	}
	work(1,0);
	for (int i=1; i<=m; ++i)
	{
		x=read(),y=read();
		int lca=Lca(x,y);
		++sum[x];
		++sum[y];
		--sum[lca];
		--sum[fa[lca][0]];
	}
	Get(1,0);
	printf("%d\n",ans);
	return 0;
}
