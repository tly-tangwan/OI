#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int maxx[500010],high[1000010],root,si,minn[500010];
inline int init()
{
	for(int i=1; i<=si; i++)
	{
		minn[i]=0x3f3f3f3f;
		for(int t=(i-1)*root+1; t<=i*root; t++)
		{
			maxx[i]=max(high[t],maxx[i]);
			minn[i]=min(high[t],minn[i]);
		}
	}
}
inline int workmax(int l,int r)
{
	int lbelong=(l/root)+(l%root!=0?1:0),rbelong=(r/root)+(r%root!=0?1:0),ans=0;
	if(lbelong==rbelong)
	{
		for(int i=l; i<=r; i++)
			ans=max(ans,high[i]);
		return ans;
	}
	for(int i=l; i<=lbelong*root; i++)
		ans=max(ans,high[i]);
	for(int i=(rbelong-1)*root+1; i<=r; i++)
		ans=max(ans,high[i]);
	for(int i=lbelong+1; i<=rbelong-1; i++)
		ans=max(ans,maxx[i]);
	return ans;
}
int workmin(int l,int r)
{
	int lbelong=(l/root)+(l%root!=0?1:0),rbelong=(r/root)+(r%root!=0?1:0),ans=0x3f3f3f3f;
	if(lbelong==rbelong)
	{
		for(int i=l; i<=r; i++)
			ans=min(ans,high[i]);
		return ans;
	}
	for(int i=l; i<=lbelong*root; i++)
		ans=min(ans,high[i]);
	for(int i=(rbelong-1)*root+1; i<=r; i++)
		ans=min(ans,high[i]);
	for(int i=lbelong+1; i<=rbelong-1; i++)
		ans=min(ans,minn[i]);
	return ans;
}
int main()
{
	int n,q;
	while(~scanf("%d%d",&n,&q))
	{
		for(register int i=1; i<=n; i++)
			scanf("%d",&high[i]);
		root=(int)sqrt(n);
		si=n/root;
		init();
		while(q--)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%d\n",workmax(l,r)-workmin(l,r));
		}
	}
	return 0;
}
