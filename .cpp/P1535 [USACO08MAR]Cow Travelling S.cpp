#include<iostream>
#include<cstdio>
using namespace std;
int n,m,r1,r2,c1,c2,t,ans=0;
char c;
bool mp[110][110];

inline int abs(int s)
{
	return s<0 ? -s : s;
}

inline void dfs(int x,int y,int time)
{
	if(time==0 && x==r2 && y==c2)
		ans++;
	if(!time || abs(x-r2)+abs(y-c2)>time)
		return;
	if(x<n && mp[x][y]==true)	dfs(x+1,y,time-1);
	if(x>1 && mp[x][y]==true)	dfs(x-1,y,time-1);
	if(y<m && mp[x][y]==true)	dfs(x,y+1,time-1);
	if(y>1 && mp[x][y]==true)	dfs(x,y-1,time-1);
}

int main()
{
	scanf("%d%d%d",&n,&m,&t);
	for(register int i=1; i<=n; i++)
		for(register int j=1; j<=m; j++)
			cin>>c,c=='.' ? mp[i][j]=true : mp[i][j]=false;
	scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
	dfs(r1,c1,t);
	printf("%d\n",ans);
	return 0;
}
