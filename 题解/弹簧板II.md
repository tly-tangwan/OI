## 描述

有一个小球掉落在一串连续的弹簧板上，小球落到某一个弹簧板后，会被弹到某一个地点，直到小球被弹到弹簧板以外的地方。
假设有 n 个连续的弹簧板，每个弹簧板占一个单位距离，a[i],b[i] 代表第 i 个弹簧板会把小球向前弹 a[i] 或 b[i]个距离。比如位置 1 的弹簧能让小球前进 2 个距离到达位置 3。如果小球落到某个弹簧板后，经过一系列弹跳会被弹出弹簧板，那么小球就能从这个弹簧板弹出来。
现在小球掉到了 1 号弹簧板上面，那么这个小球会被弹起多少次，才会弹出弹簧板。1 号弹簧板也算一次。

输入
第一个行输入一个 n 代表一共有 n(1≤n≤1000000) 个弹簧板。
第二行输入 n 个数字，中间用空格分开。第 i个数字 ai 代表第 i 个弹簧板可以让小球移动的距离。
第三行输入 n 个数字，中间用空格分开。第 i个数字 bi 代表第 i 个弹簧板可以让小球移动的距离。
第 i 个弹簧板可以选择移动 a[i] 或 b[i] 之中的一个距离。

输出==
输出一个整数，表示小球被弹起的最小次数。



输入样例1  
5          
2 2 3 1 2
1 2 3 4 1

输出样例1
2


输入样例2            
7
5 6 8 1 1 6 7
2 5 6 9 8 4 1

输出样例2
2

## 准备

> - [ ] **BFS**算法(宽搜)
> - [ ] **struct** 结构体
> - [ ] **队列**基本函数

## 解题思路 (gif)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20190503173128970.gif)


## 算法实现    	~~写的有点繁琐，还请见谅~~

先开数组（全局储存是一个好习惯哦）

```
int a[1000010],b[1000010];//数组a,b用来存小球在i这个位置跳哪些地方
bool tly[1000010];
```

当然，为了精简代码，所以我们可以将标记与次数合为一体，即：

```
int a[1000010],b[1000010]，tly[1000010];
```

再把弹簧板个数带进去

```
int n;
```

打一个结构体（同样是为了方便调用）

```
struct node
{
	int x;
	int t;
}；
```

==**千万注意“ } ”后面的“ ； ”十年OI一场空,不打分号见祖宗**==

先开一个队列(可以放在函数中)

```
queue <node> qu;
```

定义一个函数可以更方便我们的调用

```
int bfs()
{
}
```

插入了结构体就要用嘛

```
node now; //指针两只
node nxt; 
now.t=0;
now.x=1;
```

先插入队列头并且赋值

```
qu.push(1);
tly[now.x]=1;
```

##### 那么前面就构成了准备的环节

```java
#include <bits/stdc++.h>
using namespace std;
int a[10000001],b[10000001],tly[10000001];
int n; 
struct node
{
	int x;
	int t;
};
queue <node> qu;
```

再介入循环

```
while (!qu.empty())
```

>关于队列函数的问题，我在文末做了一下总结[^queue]

保险起见，先清空队列

```
qu.pop();
```

如果n有毒，直接退出并返回0

```
if (now.x>n)	reutrn now.t;
```

循环前先加

```
nxt.t=now.t+1;
nxt.x=now.x+a[now.x]//因为他是在原位置的基础上加上a[i]或b[i]
```

判断是否为零，如果是零，删除nxt

```
if (tly[nxt.x]==0)
{
	qu.push(nxt);
	tly[nxt.x]=1;//标记，不然内存会爆
}
```

```
nxt.x=now.x+b[now.x];
		if (tly[nxt.x]==0)
		{
			qu.push(nxt);
			tly[nxt.x]=1;//标记
		}
```

最后的return

```
return -1;
```

##### 那么，函数这一节就END了

```java
int bfs()
{
	node now; 
	node nxt; 
	now.t=0;
	now.x=1;
	qu.push(now); 
	tly[now.x]=1;
	while (!qu.empty())
    {
		now=qu.front();
		qu.pop();
		if (now.x>n)
			return now.t;
		
		nxt.t=now.t+1;
		nxt.x=now.x+a[now.x];
		if (tly[nxt.x]==0)
        {
			qu.push(nxt);
			tly[nxt.x]=1;
		}
		nxt.x=now.x+b[now.x];
		if (tly[nxt.x]==0)
		{
			qu.push(nxt);
			tly[nxt.x]=1;
		}
	}
	return -1;
}
```

##### 进入main，没什么可讲的，输入函数输出就OK了

```java
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++)
		cin>>b[i];
	cout<<bfs();
	return 0;
}
```

### 代码如下：

```java
#include <bits/stdc++.h>
using namespace std;
int a[10000001],b[10000001],tly[10000001];
int n; 
struct node
{
	int x;
	int t;
};
queue <node> qu;
int bfs()
{
	node now; 
	node nxt; 
	now.t=0;
	now.x=1;
	qu.push(now);
	tly[now.x]=1;
	while (!qu.empty())
    {
		now=qu.front();
		qu.pop();
		if (now.x>n)
			return now.t;
		nxt.t=now.t+1;
		nxt.x=now.x+a[now.x];
		if (tly[nxt.x]==0)
        {
			qu.push(nxt);
			tly[nxt.x]=1;
		}
		nxt.x=now.x+b[now.x];
		if (tly[nxt.x]==0)
		{
			qu.push(nxt);
			tly[nxt.x]=1;
		}
	}
	return -1;
}
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++)
		cin>>b[i];
	cout<<bfs();
	return 0;
}
```

> 注：此题可用于解 **弹簧板**

# ==**END**==

[^queue]: 

![luogu](https://imgconvert.csdnimg.cn/aHR0cHM6Ly93d3cubHVvZ3Uub3JnL2ltYWdlcy9jb25ncmF0dWxhdGlvbi5wbmc#pic_center)
from-->luogu.org

#### queue队列常用函数

| 函数名 | 释义             |
| ------ | ---------------- |
| push   | 插入一个元素     |
| pop    | 删除一个元素     |
| size   | 返回队列元素个数 |
| empty  | 判断队列是否为空 |
| front  | 返回第一个元素   |
| back   | 返回最后一个元素 |
