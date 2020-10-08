#include <iostream>
using namespace std;
int cnt=0,n,next[100001],head[100001],to[100001],depth[100001];
bool in[50001];
void add(int u,int v)
{
	next[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
void dfs(int u,int deep)
{
	in[u]=1;
	depth[u]=deep+1;
	for(int i=head[u]; i; i=next[i])
	{
		int k=to[i];
		if(!in[k])
			dfs(k,deep+1);
	}
}
int main()
{
	int a,b;
	scanf("%d",&n);
	for(int i=1; i<=n-1; i++)
	{
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	dfs(1,-1);
	for(int i=1; i<=n; i++)
		printf("%d\n",depth[i]);
	return 0;
}
