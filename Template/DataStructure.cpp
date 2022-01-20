//树状数组
//PS
template<class T, int N>
struct FenWickTree {
    T A[N+3];
    T AkP(int x) {
        T res = 0;
        while (x > 0) res += A[x], x -= x & -x;
		return res;
    }
    T AkS(int l, int r) { return AkP(r) - AkP(l - 1); }
    void CgP(int x, T w) { while (x <= N) A[x] += w, x += x & -x; }

	T& operator[](const int &x) { return A[x]; }
};
//PS->维护差分数组
template<class T, int N>
struct FenWickTree {
	T A[N+3], C[N+3];		
	T AkP(int x) {
		T res = 0, y = x;
		while(x > 0) res += C[x], x -= x & -x;
		return res + A[y];
	}
	void CgP(int x, T w) { while(x <= N) C[x] += w, x += x & -x; }
	void CgS(int x, int y, T w) { CgP(x, w); CgP(y+1, -w); }

	T& operator[](const int &x) { return A[x]; }
};
//SS->
template<typename T, int N>
struct FenWickSS {
	struct FenWickPS {
		T A[N+3];	
		T AkP(int x) {
			T res = 0;
			while(x >= 0) res += A[x], x -= x & -x;
			return res;
		}
		T AkS(int l, int r)  { return AkP(r) - AkP(l-1); }
		void CgP(int x, T y) { while(x <= N) A[x] += y, x += x & -x; }
	};

	FenWickPS S, C;
	T Sm[N];

	T AkP(int x) { return (x+1) * S.AkP(x) - C.AkP(x) + Sm[x]; }
	T AkS(int l, int r) { return AkP(r) - AkP(l-1); }

	void CgS(int l, int r, T v) {
		S.CgP(l, v); 	S.CgP(r+1, -v);
		C.CgP(l, v*l);  C.CgP(r+1, -(r+1)*v);
	}

	T& operator[](const int &x) { return Sm[x]; }
};

















