#include<cstdio>
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
    stack<string> back,forward;
    string now,URL;
    back.push("http://www.acm.org/");
    while(cin>>now)
    {
        if(now[0]=='Q')
            break;
        else if(now[0]=='V')
        {
            cin>>URL;
            back.push(URL);
            cout<<URL<<endl;
            while(!forward.empty())
                forward.pop();
        }
        else if(now[0]=='B')
        {
            if(back.size()>1)
            {
                forward.push(back.top());
                back.pop();
                cout<<back.top()<<endl;
            }
            else
                cout<<"Ignored"<<endl;
        }
        else
        {
            if(!forward.empty())
            {
                back.push(forward.top());
                cout<<forward.top()<<endl;
                forward.pop();
            }
            else
                cout<<"Ignored"<<endl;
        }
    }
    return 0;
}
