#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define ZERO(x) memset(x, 0, sizeof x);

const int MB=1<<21;
struct FastIO
{
	char buf[MB+100],*p,*e;
	int getChar()
	{
		if(p==e) p=buf,e=buf+fread(buf,1,MB,stdin);
		return p==e?EOF:*p++;
	}
	template<typename T>
	FastIO& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getChar())l=c;
		for(x=0;isdigit(c);c=getChar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IO;

const int PRM[] = {2, 3, 5, 7, 11, 13, 17, 19};
const int MAXN = 5e2 + 10;
const int MAXP = 1 << 9;

struct Node {
    long long val, vAl;
    friend bool operator<(const Node& x, const Node& y) {
        return x.vAl < y.vAl;}
}Num[MAXN];

long long F1[MAXP][MAXP], F2[MAXP][MAXP], FE[MAXP][MAXP];
int n, p;

void Pre(long long* x, int y, long long* z);

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif

    IO >> n >> p;
    IOR(i, 2, n+1) 
        Pre(&Num[i].val, i, &Num[i].vAl);

    sort(Num+3, Num+n+1);

   	FE[0][0] = 1;
    IOR(i, 2, n+1) {
		if(i == 2 || Num[i].vAl != Num[i-1].vAl || Num[i].vAl == 1) 
			memcpy(F1, FE, sizeof FE), 
			memcpy(F2, FE, sizeof FE);

//		IOR(v, 0, 1 << 8) IOR(k, 0, 1 << 8) {
		LOR(v, (1 << 8)-1, -1) LOR(k, (1 << 8) - 1, -1) {
			if(v & k) continue;
			if(!(v & Num[i].val)) 
//				F1[v][k | Num[i].val] += F1[v][k], F1[v][k | Num[i].val] %= p;
				F1[v][k | Num[i].val] = (F1[v][k | Num[i].val] % p + F1[v][k] % p) % p;
			if(!(k & Num[i].val)) 
//				F2[v | Num[i].val][k] += F2[v][k], F2[v | Num[i].val][k] %= p;
				F2[v | Num[i].val][k] = (F2[v | Num[i].val][k] % p + F2[v][k] % p) % p;
		}

		if(i == n || Num[i].vAl != Num[i+1].vAl || Num[i].vAl == 1) 
			IOR(v, 0, 1 << 8) IOR(k, 0, 1 << 8) 
				if(!(v & k)) //FE[v][k] = F1[v][k] + F2[v][k] - FE[v][k], FE[v][k] %= p;
					FE[v][k] = (((F1[v][k] % p + F2[v][k] % p) % p) - FE[v][k] % p + p) % p;
    }

	long long ans = 0;
	IOR(v, 0, 1 << 8) IOR(k, 0, 1 << 8)
		if(!(v & k)) //ans += FE[v][k], ans %= p;
			ans = (ans % p + FE[v][k] % p) % p;  
    
	printf("%lld", ans);

	return 0;
} /**/

void Pre(long long* x, int y, long long* z) {
    IOR(i, 0, 8) 
        while(y != 1 && !(y % PRM[i])) 
            *x |= (1 << i), y /= PRM[i];
    *z = y;
}