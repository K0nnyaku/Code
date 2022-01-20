#include<bits/stdc++.h>
using namespace std;
const int CN = 1e6 + 10;
int T, n, a[CN], stk[CN], due[CN];
bool work(int L, int R, int dep){
	if(dep > n + n){
		for(int i = 1; i <= n + n; i++)
		    (stk[i] == 1) ? putchar('L') : putchar('R');
		putchar('\n'); return 1;
	}
	
	if(!due[a[L]]){
		due[a[L]] = n + n - dep + 1, stk[dep] = 1;
		if(work(L + 1, R, dep + 1)) return 1;
		due[a[L]] = 0, stk[dep] = 0;
	}
	else if(due[a[L]] == dep){
		stk[dep] = 1;
		if(work(L + 1, R, dep + 1)) return 1;
		stk[dep] = 0;
	}
	
	if(!due[a[R]]){
		due[a[R]] = n + n - dep + 1, stk[dep] = 2;
		if(work(L, R - 1, dep + 1)) return 1;
		due[a[R]] = 0, stk[dep] = 0;
	}
	else if(due[a[R]] == dep){
		stk[dep] = 2;
		if(work(L, R - 1, dep + 1)) return 1;
		stk[dep] = 0;
	}
	
	return 0;
}
bool checker(int A[], int L){
	for(int i = 1; i <= L; i++) if(A[L - i + 1] ^ A[i]) return 0;
	return 1;
}
int get(){
	int N = 0;
	for(int i = 2; i <= n + n; i++) if(a[i] == a[1]) {N = i; break;}
	return N;
}
bool arcker(){
	int N = get();
	return checker(a, N) && checker(a + N, n + n - N);
}
int main(){
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &T); while(T--){
		scanf("%d", &n); for(int i = 1; i <= n + n; i++) scanf("%d", &a[i]), stk[i] = due[i] = 0;
		if(n <= 20){
			if(!work(1, n + n, 1)) putchar('-'), putchar('1'), putchar('\n');
		}
		else if(checker(a, n + n)){
			for(int i = 1; i <= n + n; i++) putchar('L');
			putchar('\n');
		}
		else if(arcker()){
			int N = get();
			for(int i = 1; i <= (N >> 1); i++) putchar('L');
			for(int i = 1; i <= n + n - N; i++) putchar('R');
			for(int i = 1; i <= (N >> 1); i++) putchar('L');
			putchar('\n');
		}
		else putchar('-'), putchar('1'), putchar('\n');
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
