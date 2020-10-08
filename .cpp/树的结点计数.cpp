#include<iostream>
using namespace std;
int n,tot=0,next[100001],head[100001],to[100001],ans[50001];
bool in[50001];
void add(int u,int v)
{
	next[++tot]=head[u];
	to[tot]=v;
	head[u]=tot;
}
void dfs(int x)
{
	in[x]=1;
	for(int i=head[x]; i; i=next[i])
		if(!in[to[i]])//If never visited, then down
		{
			dfs(to[i]);
			ans[x]=ans[x]+1+ans[to[i]];// add this son and add your son's son
		}
}
int main()
{
	scanf("%d",&n);
	
	int x,y;
	for(int i=1; i<n; i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1);
	for(int i=1; i<=n; i++)
		printf("%d\n",ans[i]);
	return 0;
}
