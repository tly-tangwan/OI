#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 30005;
priority_queue<ll,vector<ll> > q1;
priority_queue<ll, vector<ll>, greater<ll> > q2;
ll a[maxn];
int b[maxn];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		while(!q1.empty())
			q1.pop();
		while(!q2.empty())
			q2.pop();
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		
		int n, m;
		cin>>n>>m;
		for (int i = 1; i <= n; i++)
			cin>>a[i];
		b[0] = 0;
		for (int i = 1; i <= m; i++)
			cin>>b[i];
		for (int i = 1; i <= m; i++)
		{
			for (int j = b[i - 1] + 1; j <= b[i]; j++)
			{
				q1.push(a[j]);
				q2.push(q1.top());
				q1.pop();
			}
			q1.push(q2.top());
			q2.pop();
			cout << q1.top() << '\n';
		}
		cout<<endl;
	}
	return 0;
}

