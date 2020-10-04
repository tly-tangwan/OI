NOIP的考试技巧awa
# map
一对一的hash，遇到字符串搭配数组的时候就不需要hash了。
```
#include<map>
map<int, string> p;
string s;
int i;
p[i]=s;//insert 
begin()//返回指向map头部的迭代器
clear(）// 删除所有元素
count() //返回指定元素出现的次数
empty()//如果map为空则返回true
end()//返回指向map末尾的迭代器
erase()// 删除一个元素
find()// 查找一个元素
lower_bound()//返回键值>=给定元素的第一个位置
size()//返回map中元素的个数
upper_bound() // 返回键值>给定元素的第一个位置
```
# 快速读写
>如果想尝试一下比较可的优化，大概“寥寥”60几行吧，所以还是老实的用`read()`
```
int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {  // ch 不是数字时
    if (ch == '-') w = -1;        // 判断是否为负
    ch = getchar();               // 继续读入
  }
  while (ch >= '0' && ch <= '9') {  // ch 是数字时
    x = x * 10 + (ch - '0');  // 将新读入的数字’加’在 x 的后面
    // x 是 int 类型，char 类型的 ch 和 ’0’ 会被自动转为其对应的
    // ASCII 码，相当于将 ch 转化为对应数字
    // 此处也可以使用 (x<<3)+(x<<1) 的写法来代替 x*10
    ch = getchar();  // 继续读入
  }
  return x * w;  // 数字 * 正负号 = 实际数值
}
inline void write(int x) {
  static int sta[35];
  int top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top) putchar(sta[--top] + 48);  // 48 是 '0'
}
```
