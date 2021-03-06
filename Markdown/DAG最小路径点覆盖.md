## 定义
* 最小路径点覆盖: 不交的简单路径覆盖所有点
* 拆点二分图每一个点 x 作为左部, x’, 作为右部, 原图中每一条边(x, y), 连接 x 和 y’ 
## 性质/定理
* 最小路径点覆盖的路径条数即为点数 n-拆点二分图的最大匹配的边数
* 证明:
	1. 每一个覆盖方案都可以与拆点二分图的一组匹配对应, 其中每一
个左部的非匹配点 x 对应一条路径的终点, 右部的非匹配点 x’ 对
应一条路径的起点
	2. 最小化路径条数 ⇔ 最小化终点数 ⇔ 最大化匹配点数
* 由上 1. 从左部每一个非匹配点 x 出发, 由 x, Ada[x’], Ada[Ada[x’]’]...
直到第一个右部非匹配点 y 组成的路径即为最小路径点覆盖的一条路
径
## 可重复点覆盖
通过传递闭包, 对于所有可以间接到达的点对 (x, y) 连边, 新图上跑不相交最小点覆盖
