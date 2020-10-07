#include<queue>
#include<cstdio>
using namespace std;
priority_queue<int>q;
int n,x,ans=0,k,add=0,temporary=0,num;
int main()
{
	scanf("%d%d",&n,&k);
	for(register int i=1; i<=n; i++)
	{
		scanf("%d",&x);
		q.push(-x);
	}
	num=n;
	while(1)
//if you use a larger number without `while`,you cannot push(0) when you need it .
	{
		int division=num/k,mod=num%k;
		num=division+mod;
		if(num<=k)
		{
			add=k-num;
			break;
		}

	}
	while(add--)
		q.push(0);
	while(!q.empty())
	{
		temporary=0;
		for(register int i=1; i<=k; i++)
			temporary-=q.top(),q.pop();
		ans+=temporary;
		if(q.empty())
		{
			printf("%d\n",ans);
			return 0;
		}
		q.push(-temporary);
	}
	return 0;
}
