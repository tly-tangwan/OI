/*
https://www.luogu.com.cn/problem/P4377
P4377 [USACO18OPEN]Talent Show G
*/
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
long long f[10000];
int n,W,t[300],w[300];

bool chack(int mid)
{
	memset(f,~0x3f,sizeof(f));
	f[0]=0;
	long long tmp=f[W];
	for(int i=1; i<=n; i++)
		for(int j=W; j>=0; j--)
			if(f[j]!=tmp)
			{
				int wi=min(w[i]+j,W);
				f[wi]=max(f[wi],f[j]+t[i]-(long long)w[i]*mid);
			}
	return f[W]>=0;
}
int find()
{
	int l=1,r=1000000001;
	while(l+1<r)
	{
		int mi=(l+r)/2;
		if(chack(mi))
			l=mi;
		else
			r=mi;
	}
	return l;
}
int main()
{
	scanf("%d%d",&n,&W);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&w[i],&t[i]),t[i]*=1000;
	printf("%d\n",find());
	return 0;
}
