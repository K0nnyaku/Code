---
title: AC自动机
date: 2022-1-6 20:35:23
tags: [字符串, AC自动机, 模版]
---

### [LG3808](https://www.luogu.com.cn/problem/P3808)

### 代码
```cpp
template<int N, int K>
struct Automaton {
	struct Node { int fl, oc, Ch[K]; };
	Node Tr[N];   int rt, cnt;
	
#define F(x)   Tr[x].fl
#define O(x)   Tr[x].oc
#define C(x,y) Tr[x].Ch[y]

	int New() { return ++cnt; }
	void Ins(char *S) {
		int p = rt, len = strlen(S);
		Ir(i, 0, len, v) {
			v = S[i] - 'a';
			if(C(p, v)) p = C(p, v);
			else        C(p, v) = New(), p = cnt;
		}
		O(p)++;
	}

	void Init() {
		queue<int> Q;
		Ir(i, 0, 26) if(C(rt,i)) Q.push(C(rt,i));
		while(Q.size()) {
			int x = Q.front(); Q.pop();
			Ir(i, 0, 26) 
				if(C(x,i)) F(C(x,i)) = C(F(x), i), Q.push(C(x,i));
				else        C(x,i) = C(F(x), i);
		}
	}
	int Qy(char *S) {
		int p = rt, len = strlen(S), res = 0;

		Ir(i, 0, len, v) {
			v = S[i] - 'a'; p = C(p, v); 
			for(int k = p; k && ~O(k); k = F(k))
				res += O(k), O(k) = -1;
		}
		return res;
	}
};
```
