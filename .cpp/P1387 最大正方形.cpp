/*
https://www.luogu.com.cn/problem/P1387
在一个n*m的只包含0和1的矩阵里找出一个不包含0的最大正方形，输出边长。

4 4
0 1 1 1
1 1 1 0
0 1 1 0
1 1 0 1


2
*/
#include <algorithm>
#include <iostream>
using namespace std;
int a[103][103];
int b[103][103];  // 前缀和数组，相当于上文的 sum[]
int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      b[i][j] =
          b[i][j - 1] + b[i - 1][j] - b[i - 1][j - 1] + a[i][j];  
    }
  }

  int ans = 1;

  int l = 2;
  while (l <= min(n, m)) {
    for (int i = l; i <= n; i++) {
      for (int j = l; j <= m; j++) {
        if (b[i][j] - b[i - l][j] - b[i][j - l] + b[i - l][j - l] == l * l) 
          ans = max(ans, l);
    }
    l++;
  }

  cout << ans << endl;
  return 0;
}
