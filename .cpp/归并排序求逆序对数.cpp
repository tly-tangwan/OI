/*
https://www.luogu.com.cn/problem/P1908
*/
#include<iostream>
#include<cstdio>
using namespace std;
long long n,num[5000001],temporary[5000001],ans;

inline void msort(int l,int r)
{
	if(l==r)//l->mid,mid->r
		return;
	int mid=(l+r)/2;
	msort(mid+1,r);
	msort(l,mid);
	
	int i=l,j=mid+1,k=l;
	while(i<=mid && j<=r)
	{
		if(num[i]>num[j])
		{
			ans+=mid-i+1;
			temporary[k++]=num[j++];
		}
		else
			temporary[k++]=num[i++];
	}
	for(register int _=i;_<=mid;_++)
		temporary[k++]=num[_];
	for(register int _=j;_<=r;_++)
		temporary[k++]=num[_];
	for(register int _=l;_<=r;_++)
		num[_]=temporary[_];
}

int main()
{
	scanf("%lld",&n);
	for(register int i=1; i<=n; i++)
		scanf("%d",&num[i]);
	msort(1,n);
	printf("%lld\n",ans);
	return 0;
}
