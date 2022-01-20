#### 对于字符串$S$
* 周期和$Border$
	* 周期: 对于$0 < p \leq |S|$, 若$S_i = S_{i+p}$ 对于所有 $i\in [0, |S|-p-1]$成立, 称$p$是$S$的周期
	* $Border$: 对于$0 \leq r < |S|$, 若$S$长度为$r$的前缀和后缀相等, 就称$S$长度为$r$的前(后)缀为$S$的$Border$
	* $~\Rightarrow~$ $|S|-r$是$S$的周期
* 每个前缀的出现次数
	* 对于串自身 
	  ```cpp
	  IR(i, 1, n) Ans[Nt[i]]++;
	  SR(i, n, 2) Ans[Nt[i-1]] += Ans[i];
	  IR(i, 1, n) Ans[i]++;
	  ```
#### Todo

#### 代码
```cpp
	sln = strlen(S+1), pln = strlen(P+1);

	IR(i, 2, pln, v=0) { 
		while(v && P[v+1] != P[i]) v = Nt[v];
		Nt[i] = (v += P[v+1]==P[i]);
	}

	IR(i, 1, sln, v=0) { 
		while(v && P[v+1] != S[i]) v = Nt[v];
		v += P[v+1]==S[i];
		if(v == pln) cout << i-v+1 << "\n";
	}
```
