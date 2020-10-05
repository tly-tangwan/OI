/*
伐木工人米尔科需要砍倒 M 米长的木材。这是一个对米尔科来说很容易的工作，因为他有一个漂亮的新伐木机，可以像野火一样砍倒森林。不过，米尔科只被允许砍倒单行树木。

米尔科的伐木机工作过程如下：米尔科设置一个高度参数H（米），伐木机升起一个巨大的锯片到高度H，并锯掉所有的树比H高的部分（当然，树木不高于H米的部分保持不变）。米尔科就行到树木被锯下的部分。

例如，如果一行树的高度分别为20，15，10和17，米尔科把锯片升到15米的高度，切割后树木剩下的高度将是15，15，10和15，而米尔科将从第1棵树得到5米，从第4棵树得到2米，共得到7米木材。

米尔科非常关注生态保护，所以他不会砍掉过多的木材。这正是他为什么尽可能高地设定伐木机锯片的原因。帮助米尔科找到伐木机锯片的最大的整数高度H，使得他能得到木材至少为M米。换句话说，如果再升高1米，则他将得不到M米木材。
P1873 砍树
https://www.luogu.com.cn/problem/P1873
*/
#include<iostream>
using namespace std;
int n,m,high[1000010];
bool check(int k)
{
	long long num=0;
	for(int i=1; i<=n; i++)
		if(high[i]>k)
			num=num+(long long)(high[i]-k);
	return num>=m;
}
int find()
{
	int l=1,r=1000000001;
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if(check(mid))
			l=mid;
		else
			r=mid;
	}
	return l;
}
int main()
{
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>high[i];
	cout<<find()<<endl;
	return 0;
}
