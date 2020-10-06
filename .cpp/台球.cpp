#include<iostream>
using namespace std;
#include<stack>
#include<cassert>
int out[50010],in[50010];
template<class T>
bool test(int *stack_in, int *stack_out,size_t n)
{
	assert(stack_in&&stack_out);
	stack<T> s;
	int j = 0;
	for (size_t i = 0; i < n; i++)
	{
		s.push(stack_in[i]);
		while (!s.empty()&&s.top()==stack_out[j])
		{
			s.pop();
			++j;
		}
	}
	return (s.size() == 0) ? true : false;

}
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1; i<=n; i++)
			cin>>out[i],in[i]=i;
		if(test<int>(in,out,n-1))
			cout<<"Not a proof"<<endl;
		else
			cout<<"Cheater"<<endl;
	}
	return 0;
}
