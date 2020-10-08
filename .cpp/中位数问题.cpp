#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0;
	bool f=0;
	char c=getchar();
	while (c<'0'||c>'9')
	{
		if (c=='-')f=1;
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return f?-x:x;
}
priority_queue<int,vector<int> > big;//大根堆
priority_queue<int,vector<int>,greater<int> > small;//小根堆
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		while(!big.empty())
			big.pop();
		while(!small.empty())
			small.pop();

		int x;
		x=read();
		int n=read();
		cout<<x<<" "<<(n+1)/2<<endl;
		big.push(read());
		cout<<big.top()<<" ";
		for (int i=2; i<=n; i++)
		{
			int input=read();
			if (input>big.top())
				small.push(input);
			else
				big.push(input);

			while (1)
			{
				int bb=big.size(),ss=small.size();
				if(abs(bb-ss)<1)
					break;	
				if (bb>ss && bb && ss)
				{
					small.push(big.top());
					big.pop();
				}
				else
				{
					big.push(small.top());
					small.pop();
				}
			}
			if (i%2)
			{
				int bb=big.size(),ss=small.size();
				cout<<(bb>ss && bb && ss?big.top():small.top());
			}
			if (!i%10)
				cout<<endl;
			else if(i%2)
				cout<<" ";
		}
	}
	return 0;
}
