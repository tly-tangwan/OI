#include<iostream>
#include<cstdio>
#include<cmath>
#define re register int
using namespace std;
int n,x[500010],y[500010],w[500010],head[500010],cnt=0,ans=0,temporary[500010];
struct node
{
	int nxt,to;
} e[500010];

inline int add(int u,int v)
{
	cnt++;
	e[cnt].nxt=head[u];
	head[u]=cnt;
	e[cnt].to=v;
}

inline void dfs(int u,int fa)
{
	temporary[u]=w[u];
	for(re i=head[u]; i; i=e[i].nxt)
		if(e[i].to!=fa)
		{
			dfs(e[i].to,u);
			if(temporary[e[i].to]>0)
				temporary[u]+=temporary[e[i].to];
		}
}

int main()
{
	scanf("%d",&n);
	for(re i=1; i<=n; i++)
		scanf("%d%d%d",&x[i],&y[i],&w[i]);
	for(re i=1; i<=n; i++)
		for(re j=i+1; j<=n; j++)
			if(abs(x[i]-x[j])+abs(y[i]-y[j])==1)
				add(i,j),add(j,i);
	for(re i=1; i<=n; i++)
	{
		dfs(i,0);
		ans=max(ans,temporary[i]);
	}
	printf("%d",ans);
	return 0;
}
