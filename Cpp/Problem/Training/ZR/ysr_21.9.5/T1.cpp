#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define ZERO(x) memset(x, 0, sizeof x);
#define T(x) E[x].to
#define V(x) E[x].val

struct FastIN
{
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getchar())l=c;
		for(x=0;isdigit(c);c=getchar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IN;

const string CH[3] = { "R", "P", "S" };

struct As {
    string S;
    bool flag;

    bool friend operator<(const As& x, const As& y) {
        return x.flag == y.flag ? x.S < y.S : x.flag < y.flag;
    }
}Ans[5];

int t;
int Num[10];
int Tnum[10];

void Solve(int pos, int kd, int dep);
string Reduce(string S);

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif

    IN >> t;
    while(t--) {
        IN >> Num[0] >> Num[1] >> Num[2];

        int d = log2(Num[0] + Num[1] + Num[2]);

        IOR(i, 0, 3) 
            Ans[i].S = "", Ans[i].flag = 0;

        IOR(i, 0, 3) {
            IOR(v, 0, 3) Tnum[v] = Num[v];

            if(Num[i] != 0) Solve(i, i, d);
            else Ans[i].flag = 1;

            IOR(v, 0, 3) Ans[i].flag |= (Tnum[v] != 0);
        }

        sort(Ans, Ans+3);

        int idx = 0;
        string SS[10];
        IOR(i, 0, 3) if(!Ans[i].flag) 
            SS[idx++] = Reduce(Ans[i].S);
        
        sort(SS, SS + idx);

        if(idx != 0) 
            cout << SS[0] << "\n";
        else
            cout << -1 << '\n';
    }

	return 0;
} /**/

void Solve(int pos, int kd, int dep) {
    if(!dep) { 
        Ans[pos].S += CH[kd]; Tnum[kd]--; 
        return ;
    }

    if(kd == 0) 
        Solve(pos, 0, dep-1),
        Solve(pos, 2, dep-1);
    else
    if(kd == 1) 
        Solve(pos, 1, dep-1),
        Solve(pos, 0, dep-1);
    else
    if(kd == 2) 
        Solve(pos, 1, dep-1),
        Solve(pos, 2, dep-1);
}

string Reduce(string S) {
    int len = S.size();
//    cout << S << endl;
    for(int i = 1; i <= len / 2; i *= 2) {
        for(int v = 0; v < i; v += i + 1) {
            string A, B;
            A = S.substr(v, i);
            B = S.substr(v+i, i);

//            cout << A << endl;
//            cout << B << endl;
//            cout << S << endl;

            if(A > B) {
                S.replace(v, i, B);
                S.replace(v+i, i, A);
            }
        }
    } 

//    cout << "!!!!" << S << "!!!" << endl;

    return S;
}

/*
            cout << "\n-----------------------\n" ;
            cout << "i = " << i << " " << "S = " << Ans[i].S << "\n" ;
            cout << "flag = " << Ans[i].flag << "\n";
            IOR(v, 0, 3) cout << Tnum[v] << " " ;
            cout << "\n-----------------------\n" ;
        */