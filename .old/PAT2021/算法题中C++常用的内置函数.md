# 算法题中C++常用的内置函数

格式：

+ 二级标题 头文件
+ 三级标题 函数名
  + 作用
  + 拓展阅读
  + 相关题目
  + 实例代码

***

## cmath

### pow()

+ 作用：`pow(x, y)` 返回x的y次幂
+ 相关题目：
  + PAT
    + [1103 Integer Factorization (30 分)](https://pintia.cn/problem-sets/994805342720868352/problems/994805364711604224)

### sqrt()

+ 作用：`sqrt(x)` 返回x的平方根，作用与pow(x, 1.0/2)相同（还可以用pow()开高次方）
+ 相关题目：
  + PAT
    + [1096 Consecutive Factors (20 分)](https://pintia.cn/problem-sets/994805342720868352/problems/994805370650738688)

### round()、floor()、ceil()

+ 作用：`round()`四舍五入，`floor()`向下取整，`ceil()`向上取整

```shell
value   round   floor   ceil    trunc
-----   -----   -----   ----    -----
2.3     2.0     2.0     3.0     2.0
3.8     4.0     3.0     4.0     3.0
5.5     6.0     5.0     6.0     5.0
-2.3    -2.0    -3.0    -2.0    -2.0
-3.8    -4.0    -4.0    -3.0    -3.0
-5.5    -6.0    -6.0    -5.0    -5.0
```

+ 相关题目：
  + PAT
    + [1137 Final Grading (25 分)](https://pintia.cn/problem-sets/994805342720868352/problems/994805345401028608)

***

## algorithm

### swap()

+ 作用：`swap(v[i], v[j])` 交换两个变量的内容
  
+ 相关题目：
  + Leetcode
    + [31. Next Permutation](https://leetcode-cn.com/problems/next-permutation/)

### reverse()

+ 作用：`reverse(v.begin(), v.end())` 倒置指定区间容器元素

### sort()

+ 作用：用于为容器内元素排序，默认按从小到大排序

    sort(f.begin(), f.end(), cmp):对容器f给定范围内的元素排序，排序方式按cmp（默认从小到大）


### lower_bound() 和 upper_bound()

+ 作用：用于二分查找数组、容器内元素位置的函数。

    `lower_bound(f.being(), f.end(), val)`:返回容器中第一个值**大于或等于**val的元素的iterator位置。

    `upper_bound(f.begin(), f.end(), val)`: 返回容器中第一个值**大于**val的元素的iterator位置。
+ 拓展阅读：[C/C++-STL中lower_bound与upper_bound的用法](https://blog.csdn.net/jadeyansir/article/details/77015626)
+ 相关题目：

  + Leetcode
    + [300. Longest Increasing Subsequence](https://leetcode-cn.com/problems/longest-increasing-subsequence/)
    + [354. Russian Doll Envelopes](https://leetcode-cn.com/problems/russian-doll-envelopes/)

### fill()

+ 作用：给数组赋想要的值
  
  ```c++
  fill(a,a+n,val)； // 一维, a[n]全部赋值val
  fill(a[0],a[0]+n*n,val);  // 二维, a[n][n]全部赋值val
  ```

+ 拓展阅读：[【c++/c】fill和memset函数的区别](https://www.jianshu.com/p/09d2c4dc9814)

*** 

## cstring

### memset()

+ 作用：适合给char数组复制，给int只能赋值0，-1
  
  ```c++
  memset(a, 'b', sizeof(a)); // 一维, char a[n]全部赋值'b'
  memset(b, 0, sizeof(b));  // 二维, int b[n][n]全部赋值0
  ```

+ 拓展阅读：
  + [【c++/c】fill和memset函数的区别](https://www.jianshu.com/p/09d2c4dc9814)
  > 因为memset赋值时按照字节填充，所以更适合给char类型的数组赋值（一维/二维），因为在c/c++中char占用1一个字节（8位），而int占用2个字节，如果要使用memset给int赋值只适用于0，-1，但还有一种巧妙的方法，如果要将一个数组（一维/二维）全部赋值一个很大的值也可以通过将这个最大值M设置为0x3f3f3f3f
  + [C++中memset()函数的用法详解](https://blog.csdn.net/lyj2014211626/article/details/65481630)

### substr()

+ 作用：`s.substr(pos, len)`, 获得s的从pos开始长度为len的子字符串

### getline()

+ 作用：`getline(cin, str)`, 为str读取一行数据，直到遇到换行符停止，因此要特别小心之前如果有输入的话，需要先把上一行的换行符读掉（比如使用`getchar()`）。

+ 拓展阅读：
  + [c++中的cin.getline(),cin.get(),getline()](https://blog.csdn.net/huangfei711/article/details/47128183)
  > cin.getline()是cin的一个成员函数，定义在<iostream>头文件中，该函数有两个参数，第一个参数是用来存储输入行的数组的名称，第二个参数是要读取的字符数，如果这个参数为20，则函数最多读取19个字符，余下的空间用于存储自动在结尾处添加的空字符，getline()成员函数在读取指定数目的字符或遇到换行符就停止读取，功能跟上面的一样，如cin.getline(name, 20);

  > cin.get()有两种方式，第一种跟cin.getline()类似，它们接受的参数相同，解释参数的方式也相同，并且都读到行尾，但是get不在读取并抛弃换行符，而是将其留在输入队列中。如果执行完一个cin.get(name, size)后，再用cin.get(name, size)时，则不会读新的一行，只会读取换行符；第二种方式就是cin.get()没有参数，该功能读取一个字符，包括换行符。

### stoi()、to_string()

+ 作用：`stoi(str)` 将string类型转换成int，`to_string(num)` 将数字类型转换成字符串

+ 拓展阅读：
  + [c++中的atoi()和stoi()函数的用法和区别](https://blog.csdn.net/qq_33221533/article/details/82119031)


## numeric

### accumulate

+ 作用`accumulate(v.begin(), v.end(), init)`, 从init开始累加v中元素