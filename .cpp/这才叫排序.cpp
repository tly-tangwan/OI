#include<iostream>
using namespace std;
int n,t,num[500010],mx=0;
int main()
{
	scanf("%d",&n);
	for(register int i=1;i<=n;i++)
	{
		scanf("%d",&t);
		num[t]++;
		mx=max(t,mx);
	}
	for(register int i=1;i<=mx;i++)	
		for(register int j=1;j<=num[i];j++)
			printf("%d\n",i);
	return 0;
}
