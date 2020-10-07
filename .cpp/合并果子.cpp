#include<queue>
#include<cstdio>
using namespace std;
priority_queue<int>q;
int n,x,t,ans=0;
int main()
{
	scanf("%d",&n);
	for(register int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		q.push(-x);
	}
	while(--n)
	{
		t=0;
		t-=q.top();
		q.pop();
		t-=q.top();
		q.pop();
		ans+=t;
		q.push(-t);
	}
	printf("%d",ans);
	return 0;
}
