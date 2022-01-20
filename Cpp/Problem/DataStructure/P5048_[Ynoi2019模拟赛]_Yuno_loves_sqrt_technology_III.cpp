#include<bits/stdc++.h>
using namespace std;

#define IOR(x, y, z) for(int x = y; x < z; x++)
#define LOR(x, y, z) for(int x = y; x > z; x--)

const int MB=1<<21;
struct FastIN
{
	char buf[MB+100],*p,*e;
	int getChar()
	{
		if(p==e) p=buf,e=buf+fread(buf,1,MB,stdin);
		return p==e?EOF:*p++;
	}
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getChar())l=c;
		for(x=0;isdigit(c);c=getChar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IN;

const int MAXN = 5e5 + 10;
const int MAXNUM = 1e3 + 10;

vector<int> Loc[MAXN];
int F[MAXNUM][MAXNUM];
int A[MAXN], Lmp[MAXN], C[MAXN], Cmp[MAXN], Pos[MAXN], L[MAXN], R[MAXN], Cnt[MAXN];
int n, m, ans, idx, block, num;

int Turn(int x);
int Ask(int x, int y);
void Pre();

int main() { /**/
#ifdef LOCAL 
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif

    IN >> n >> m;
    IOR(i, 1, n+1) IN >> A[i], C[i] = A[i];
    block = sqrt(n);
    num = block;

    Pre();
    while(m--) {
        int x, y; IN >> x >> y;
        x ^= ans, y ^= ans;
        printf("%d\n", ans = Ask(x, y));
    }

//    cerr << "\n-----------------\n";
//    IOR(i, 1, num+1) cerr << "i = " << i << " l = " << L[i] << " r = " << R[i] << " F = " << F[i][i] << "\n";

    return 0;
} /**/

void Pre() {
    sort(C+1, C+n+1);
    idx = unique(C+1, C+n+1) - C - 1;

    IOR(i, 1, n+1) Cmp[i] = Turn(A[i]);

    IOR(i, 1, num+1) 
        L[i] = (i - 1) * block + 1,
        R[i] = i * block;
    if(R[num] < n) num++, L[num] = R[num-1] + 1, R[num] = n;

    IOR(i, 1, num+1) 
        IOR(v, L[i], R[i]+1) Pos[v] = i;

    IOR(i, 1, n+1) 
        Loc[Cmp[i]].push_back(i),
        Lmp[i] = Loc[Cmp[i]].size() - 1;

    IOR(i, 1, num+1) {
        memset(Cnt, 0, sizeof Cnt);
        IOR(v, i, num+1) {
            F[i][v] = F[i][v-1];
            IOR(k, L[v], R[v] + 1) 
                Cnt[Cmp[k]]++,
                F[i][v] = max(F[i][v], Cnt[Cmp[k]]);
        }
    }
}

int Turn(int x) {
    return lower_bound(C+1, C+idx+1, x) - C;
}

int Ask(int x, int y) {
    int l = Pos[x] + 1, r = Pos[y] - 1;
    int res;

    if(Pos[x] == Pos[y]) {
        res = 0;
        IOR(i, x, y+1) Cnt[Cmp[i]] = 0;

        IOR(i, x, y+1) 
            Cnt[Cmp[i]]++,
            res = max(res, Cnt[Cmp[i]]);

        IOR(i, x, y+1) Cnt[Cmp[i]] = 0;
        return res;
    }

    res = F[l][r];
    IOR(i, x, L[l])
        while(Lmp[i] + res < Loc[Cmp[i]].size()
            && Loc[Cmp[i]][Lmp[i] + res] <= y) {
                res++;
//                printf("i = %d, Lmp = %d, res = %d, Loc = %d, Cmp = %d\n", 
//                    i, Lmp[i], res, Loc[Cmp[i]][Lmp[i]+res], Cmp[i]);
            } 

//    printf("%d\n", Loc[Cmp[5]][Lmp[5]+2]);

    IOR(i, R[r]+1, y+1) 
        while(Lmp[i] - res >= 0 
            && Loc[Cmp[i]][Lmp[i] - res] >= x) res++;
    
    return res;
}