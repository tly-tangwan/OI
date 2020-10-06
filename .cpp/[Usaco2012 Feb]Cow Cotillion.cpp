#include<bits/stdc++.h>
using namespace std;
int main() {
	char a[1001];
	int n;
	cin>>n;
	while(n--)
	{
		int m,top=0;
		cin>>m;
		cin>>a;
		for(int i=0;i<m;i++)
		{
			if(a[i]=='>')
			top++;
			else
			top--;
			if(top<0)
			break;
		}
		if(top==0)
		cout<<"legal"<<endl;
		else
		cout<<"illegal"<<endl;
	}

	return 0;
}
