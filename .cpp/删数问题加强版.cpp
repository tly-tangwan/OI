#include<iostream>
using namespace std;
string a;
int b[1000005];
int main()
{
	int k;
	cin>>a>>k;
	int l=a.length();
	b[l]=0x3f;

	for(int i=l-1; i>=0; i--)
	{
		if(a[i]>a[i+1])
			b[i]=i+1;
		else
		{
			int t=i+1;
			while(a[i]<=a[t] && a[t]!=0x3f )
				t=b[t];
			b[i]=t;
		}
	}
	int i=0;
	bool flag=false;
	while(k>0)
	{
		if((b[i]-i)<=k)
		{
			k-=(b[i]-i);
			i=b[i];
			flag=true;
		}
		if(!flag)
			printf("%c",a[i++]);
		else
			flag=false;
	}
	while(i<l)
		printf("%c",a[i++]);
	return 0;
}
