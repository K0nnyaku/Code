---
title: AcWing350 巡逻
date: 2021-10-31 20:51:47
tags: [图论, 树的直径, dp, dfs]
---

### [AcWing350](https://www.acwing.com/problem/content/352/)

### 解

* #### k = 1: 直径 ans = 2 * (n-1) - dia + 1
* #### k = 2: 新构成的环和前一个环重叠则损失->直径上负-1权后再求一边直径 ans = 2 * (n-1) - dia - sdia + 2

### Trick
* #### 记录每个点在邻接表中其父节点的位置

