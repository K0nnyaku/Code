#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define ZERO(x) memset(x, 0, sizeof x);
#define T(x) E[x].to
#define V(x) E[x].val

struct FastIO
{
	template<typename T>
	FastIO& operator>>(T& x) {
		char c,l;
		for(c=0;!isdigit(c);c=getchar())l=c;
		for(x=0;isdigit(c);c=getchar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
    template<typename T>
    FastIO& operator<<(T x) {
        cout << x;
        return *this;
    }
}IO;

vector<int> I;

vector<int> Wk(int x);

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
    I.push_back(1);
    int n;
    IO >> n;
    vector<int> Ans = Wk(n);
    IOR(i, 0, Ans.size()) 
        IO << Ans[i];

	return 0;
} /**/

vector<int> Wk(int x) {
    if(x == 1) return I;
    vector<int> T = Wk(x - 1), S;
    S.clear();
    IOR(i, 0, T.size()) {
        int v = i;
        for(; v < T.size() - 1 && T[v] == T[v+1]; v++);
        S.push_back(v - i + 1); 
        S.push_back(T[i]);
        i = v;
    }

    return S;
}