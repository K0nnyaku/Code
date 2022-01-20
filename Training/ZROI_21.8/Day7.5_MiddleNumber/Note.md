### 中位数
#### [AT2165](https://www.luogu.com.cn/problem/AT2165)
* 二分， 最下层的每个数大于mid设为1，小于mid设为0
* 向上传递: 对于每三个数， 0的个数>1则为0, 1的个数>1则为1
* 特判10交替

#### [LAOSHI](https://www.luogu.com.cn/problem/AT2165