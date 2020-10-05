/*题目描述
松鼠的新家是一棵树，前几天刚刚装修了新家，新家有nn 个房间，并且有 n-1n−1 根树枝连接，每个房间都可以相互到达，且俩个房间之间的路线都是唯一的。天哪，他居然真的住在“树”上。

松鼠想邀请小熊前来参观，并且还指定一份参观指南，他希望小熊能够按照他的指南顺序，先去a1，再去a2最后到an参观新家。可是这样会导致重复走很多房间，懒惰的维尼不停地推辞。可是松鼠告诉他，每走到一个房间，他就可以从房间拿一块糖果吃。

小熊是个馋家伙，立马就答应了。现在松鼠希望知道为了保证维尼有糖果吃，他需要在每一个房间各放至少多少个糖果。

因为松鼠参观指南上的最后一个房间 an是餐厅，餐厅里他准备了丰盛的大餐，所以当维尼在参观的最后到达餐厅时就不需要再拿糖果吃了。

输入格式
第一行一个正整数 n，表示房间个数第二行 n 个正整数，依次描述 a1,a2,a3...

接下来 n-1 行，每行两个正整数 x,y，表示标号 x 和 y 的两个房间之间有树枝相连。

输出格式
一共 n 行，第 i 行输出标号为 i 的房间至少需要放多少个糖果，才能让小熊有糖果吃。

输入输出样例
输入 #1
5
1 4 5 3 2
1 2
2 4
2 3
4 5
输出 #1
1
2
1
2
1
说明/提示
2<=n<=3*10^5,1<=ai<=n.
https://www.luogu.com.cn/problem/P3258
*/
#include<iostream>//bis/stdc++.h
using namespace std;
struct node
{
	int u,v,nxt;
} edge[300001*2];
int deep[300001],ch[300001],head[300001],a[300001],f[300001][30],n,num=1;
int read()
{
	int x=0,w=1;
	char ch=0;
	while (ch<'0'||ch>'9')    
	{
		if (ch=='-') w=-1;     
		ch=getchar();             
	}
	while (ch>='0'&&ch<='9')   
	{
		x=x*10+(ch-'0');  
		ch=getchar(); 
	}
	return x*w;
}
inline void write(int x)
{
	static int sta[35];
	int top=0;
	do
		sta[top++]=x%10,x/=10;
	while (x);
	while (top) putchar(sta[--top]+48);
}
void add_edge(int x,int y)  
{
	edge[num].u=x;
	edge[num].v=y;
	edge[num].nxt=head[x];
	head[x]=num;
	num++;
}
void build(int r)   
{
	for(int i=head[r]; i!=-1; i=edge[i].nxt)
	{
		int xx=edge[i].v;
		if(deep[xx]==0)   
		{
			deep[xx]=deep[r]+1;
			f[xx][0]=r;
			build(xx);
		}
	}
}
int lca(int x,int y)
{
	if(deep[x]<deep[y]) 
		swap(x,y);
	for(int i=29; i>=0; i--)
		if(deep[f[x][i]]>=deep[y])
			x=f[x][i];
	if(x==y) 
		return x;
	for(int i=29; i>=0; i--)
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	return f[x][0];
}
void dfs(int r)
{
	for(int i=head[r]; i!=-1; i=edge[i].nxt)
	{
		int xx=edge[i].v;
		if(xx==f[r][0]) 
			continue;
		dfs(xx);
		ch[r]+=ch[xx];
	}
}
int main()
{
	n=read();
	for(int i=1; i<=n; i++)
	{
		a[i]=read();
		head[i]=-1;
	}
	int xx,yy;
	for(int i=1; i<=n-1; i++)
	{
		xx=read();
		yy=read();
		add_edge(xx,yy);
		add_edge(yy,xx);
	}
	deep[1]=1;
	build(1);
	for(int i=1; i<=29; i++)
		for(int j=1; j<=n; j++)
			f[j][i]=f[f[j][i-1]][i-1];
	for(int i=1; i<=n-1; i++)
	{
		xx=a[i];
		yy=a[i+1];
		ch[xx]++;
		ch[yy]++;
		ch[lca(xx,yy)]--;
		ch[f[lca(xx,yy)][0]]--;
	}
	dfs(1);
	for(int i=2; i<=n; i++)
		ch[a[i]]--;
	for(int i=1; i<=n; i++)
		write(ch[i]),printf("\n");
	return 0;
}
