## [模板](模板)
## 应用(以下默认下标从$1$开始)
* 检查字符串是否出现
* 不同子串个数
	* 答案为SAM上不同路径条数(endpos集合大小
	1. DAG上Dp: $f_v = 1 + \sum_{w:(v,w,c)\in DAG}f_w$, $Ans = f_0 - 1$
	2. fail树: 每个节点对应的子串数量$qt_v = len_i - len_{link_i}$, $Ans = \sum_{v\in Tree} qt_v$
	* Fail树的拓扑序即为按En排序
	* [生成魔咒](生成魔咒) --- 模版
* 子串出现次数
	* Fail树上所有前缀节点+1, $Ans =~$子树和
* 所有不同子串的总长度
	* Fail树上的每个节点对答案的贡献: $\frac{ len(i) \cdot [(len(i) - len(Fail(i)+1])}{2}$
* 第$k$大子串
	* DAG上dp
	* [SUBLEX](SUBLEX) --- 模板
	* [弦论](弦论) --- 升级版 
* 最小循环移位
	* 在$S+S$的SAM上寻找最小的长度为$|S|$的路径	 
* 多次询问串$P_i$在给定串$T$中出现次数
	* 自动机上查找对应节点, ans = |endpos(x)|
* 首次出现的位置
	* 多次询问串$P_i$ 在给定串$T$中第一次出现的位置
	* 维护 $firstpos(x)$ 为状态 $x$ 的 $endpos$ 集合中最小的元素 
	* 当创建新节点 $first(cur) = len(cut)$
	* 当复制节点 $q$ 到 $v$, $first(v) = first(q)$
	* $Ans = firstpos(t) - |P| + 1$
* 所有出现的位置
	* DAG上找到节点, 答案为Fail树中子树中所有前缀节点
* 长度最短的没有出现过的字符串 
	* dp, 设$f_v$ 表示状态$v$ 最少添加几个字符可以找到不连续的转移
	* 若存在一个转移不存在, $f_v = 1$ 
	* 否则, $f_v = 1 + min_{w:(v,w,c)\in SAM} f_w$
	* $Ans = f_s$
	* 字符串根据求出的$f$数组推出
* 两个字符串的最长公共子串
	* 建立$S$的后缀自动机, 尝试匹配$T$
	* 设$l$为当前$T$的前缀和$S$匹配的长度
	* 如果存在转移, $l+1$, 如果不存在, 跳$link$, $l = len(link)$
	* 注意不存在转移时从根继续尝试匹配当前字符
	* [LCS](LCS)
* 多字符串最长公共子串
	* 















