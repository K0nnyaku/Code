### Suffix Array
#### Sa: 排名为i的后缀的位置
#### 求解Sa:
* 倍增 sort ($nlog^2n$)
* 基数排序 $nlogn$
#### Hight: 排名为i的后缀和排名为i-1的后缀的LCP,H[1]=0
#### 性质:
* $Hight[Rank[i-1]] - 1 \leq Hight[Rank[i]]$ \
-> $O(n)$ 求解Hight 
  
#### 应用
* 求本质不同字串的个数
