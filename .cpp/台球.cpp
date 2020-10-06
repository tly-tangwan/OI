#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
	int total,t,instr[100000], outstr[100000];
	stack<int> s;
	cin>>t;
	while(t--)
	{
		cin >> total;
		for(int i=0; i<total; i++)
			cin>>outstr[i];
		vector<int> vin, vout;
		for(int i = 0; i < total; i++)
			instr[i] = i + 1;
		for(int i = 0; i < total; i++)
			vin.push_back(instr[i]);
		for(int i = 0; i < total; i++)
			vout.push_back(outstr[i]);
		int i = 0, j = 0;
		for(; i < total; i++)
		{
			s.push(vin[i]);
			while(!s.empty() && s.top() == vout[j])
			{
				s.pop();
				j++;
			}
		}
		if(i == j)
			cout << "Not a proof" << endl;
		else
			cout << "Cheater" << endl;
	}
	return 0;
}
