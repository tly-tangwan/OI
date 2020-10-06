#include<iostream>
using namespace std;
int main()
{
	char x;
	int t,stk(0);
	while(1)
	{
		cin>>x;
		if(x == '@')
		{
			if(!stk)
				printf("YES");
			else
				printf("NO");
			break;
		}
		t = (x == '(')-(x == ')');
		if(t == 1)
			stk++;
		else if(t == -1)
		{
			if(!stk)
			{
				printf("NO");
				break;
			}
			stk--;
		}
	}
	return 0;
}
