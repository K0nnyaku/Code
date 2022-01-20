# 二进制枚举
* 枚举子集
```cpp
	const int st;
	for(int v = st; v; v = (v-1) & st) 
		//do sth.
```
* 枚举和
```cpp
	const int Num[N];
	int Sum[i] = Num[i]
	Ir(i, 1, 1<<lenth+1) 
		Sum[i] = Sum[i&(i-1)] + Sum[i&-i],
		//do sth. 
		;
```

# 
