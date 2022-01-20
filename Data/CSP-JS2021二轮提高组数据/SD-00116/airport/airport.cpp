#include<bits/stdc++.h>
using namespace std;
const int CN = 2e5 + 10;

// flight   an arrive pai xu
class FL{
  public: int ar, ap; // arrive apart
    bool operator < (const FL &o) const {return ar < o.ar;}
} D[CN], A[CN]; // demostic abroad

// li san hua
int val[CN << 2]; 
int g(int x) {return lower_bound(val + 1, val + val[0] + 1, x) - val;}

//
int n, m1, m2, tagd[CN], taga[CN], fd[CN], buc1[CN], buc2[CN];

// xian duan shu
class SGT{
  public: int d[CN << 2];
    void clear() {memset(d, 0x3f, sizeof(d));}
    void md(int l, int r, int k, int p, int x){
    	if(l == r) {d[k] = x; return;} int m = (l + r) >> 1;
    	if(p <= m) md(l, m, k << 1, p, x); else md(m + 1, r, k << 1 | 1, p, x);
    	d[k] = min(d[k << 1], d[k << 1 | 1]);
	}
	int qu(int l, int r, int k, int p){
		if(p < 1) return 0x3f3f3f3f;
		if(l == r) return d[k]; int m = (l + r) >> 1;
		if(p <= m) return qu(l, m, k << 1, p);
		return min(d[k << 1], qu(m + 1, r, k << 1 | 1, p));
	}
} T;
int tim[CN << 2]; // pao dao [i] bei zhan yong dao shen me shi hou

void work(int N, int tag[], FL a[]){ // mo ni tian fei ji
    int cur = 0; T.clear(); memset(tim, 0, sizeof(tim));
    for(int i = 1; i <= N; i++){
    	int s = a[i].ar, t = a[i].ap; // s arrive   t apart
    	if(!cur){
    		cur++, tag[i] = cur;
    		T.md(1, val[0], 1, t, cur), tim[cur] = t;
		}
		else{
			int mid = T.qu(1, val[0], 1, s - 1); // zui xiao ke yong pao dao
			if(mid <= cur){
				tag[i] = mid;
				T.md(1, val[0], 1, tim[mid], 0x3f3f3f3f);
				T.md(1, val[0], 1, t, mid), tim[mid] = t;
			}
			else{
				cur++, tag[i] = cur;
    		    T.md(1, val[0], 1, t, cur), tim[cur] = t;				
			}
		}
	}
}

int main(){
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m1, &m2);
	for(int i = 1; i <= m1; i++){
	    scanf("%d%d", &D[i].ar, &D[i].ap);
		val[++val[0]] = D[i].ar, val[++val[0]] = D[i].ap;
    }
	for(int i = 1; i <= m2; i++){
		scanf("%d%d", &A[i].ar, &A[i].ap);
		val[++val[0]] = A[i].ar, val[++val[0]] = A[i].ap;
	}
	
	sort(val + 1, val + val[0] + 1), val[0] = unique(val + 1, val + val[0] + 1) - val - 1;
	for(int i = 1; i <= m1; i++) D[i].ar = g(D[i].ar), D[i].ap = g(D[i].ap);
	for(int i = 1; i <= m2; i++) A[i].ar = g(A[i].ar), A[i].ap = g(A[i].ap);
	
	sort(D + 1, D + m1 + 1), sort(A + 1, A + m2 + 1);
	work(m1, tagd, D), work(m2, taga, A);
	
	memset(buc1, 0, sizeof(buc1)), memset(buc2, 0, sizeof(buc2));
	for(int i = 1; i <= m1; i++) buc1[tagd[i]]++; for(int i = 1; i <= m2; i++) buc2[taga[i]]++;
	for(int i = 1; i <= n; i++) buc1[i] += buc1[i - 1], buc2[i] += buc2[i - 1];
	int ans = 0; for(int i = 0; i <= n; i++) ans = max(ans, buc1[i] + buc2[n - i]);
	printf("%d\n", ans);
	
	fclose(stdin); fclose(stdout);
	return 0;
}
