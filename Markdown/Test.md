#include<bits/stdc++.h> using namespace std;

#define IR(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i <= k; i++)
#define Ir(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i <  k; i++)
#define SR(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i >= k; i--)
#define Sr(i, v, k, ...) for(int i = v-1, ##__VA_ARGS__; i >= k; i--)
#define ER(i, v, p, q, k, ...) for(int  i = p.k[q], v = p.To[i], ##__VA_ARGS__; i; i = p.Nt[i], v = p.To[i])
#define Er(i, v, p, q, k, ...) for(int &i = p.k[q], v = p.To[i], ##__VA_ARGS__; i; i = p.Nt[i], v = p.To[i])
#define FL(x, y) memset(x, y, sizeof x)
#define DG(x) cout << "Debug: " << #x << "=" << x << "\n"
#define ERR   cout << "Fuck\n"

struct FastIN 
{
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c, l;
		for(c = 0; !isdigit(c); c = getchar() ) l = c;
		for(x = 0; isdigit(c); c = getchar() ) x = x * 10 - '0' + c;
		if(l == '-') x =- x;
		return *this;
	}
}IN;

template<int N, int M> 
struct Automaton {
	struct Node { vector<int> Qt; int fail, Ch[M]; };

	Node Tr[N];
	int rt, cnt;

	Automaton() { rt = cnt = 1; }
#define Q(x)    Tr[x].Qt
#define F(x)    Tr[x].fail
#define C(x, y) Tr[x].Ch[y]
#define TN       (S[i]-'a')

	void Ins(const string &S, int pos) {
		int p = rt;
		Ir(i, 0, S.size()) {
			int &ch = C(p, TN);
			p = ch ? ch : ch=++cnt;
		}
		Q(p).push_back(pos);
	}

	void ItAC(stack<int> &Fn) {
		Ir(i, 0, M) C(0, i) = rt;
		queue<int> Q; Q.push(rt);

		while(Q.size()) {
			int p = Q.front(); Q.pop();

			Fn.push(p);

			Ir(i, 0, M) {
				int &ch = C(p, i), f = F(p);
				if(ch) F(ch) = C(f, i), Q.push(ch);
				else     ch  = C(f, i);
			}
		}
	}

	void Match(const string &S, int *A) {
		Ir(i, 0, S.size(), p=rt) p = C(p, TN), A[p]++;
	}

	Node* operator[](const int &x) { return &Tr[x]; }
};

const int N_ = 2e5 + 7;
const int L_ = 2e5 + 7;

Automaton<L_, 26> AC;
string S;
stack<int> Fn;
int Qt[N_], Ans[N_], n;

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	cin >> n;
	IR(i, 1, n) cin >> S, AC.Ins(S, i);

	AC.ItAC(Fn);

	cin >> S;
	AC.Match(S, Qt);

	while(Fn.size()) {
		int x = Fn.top(); Fn.pop();
		Qt[AC[x]->fail] += Qt[x];
	}

	IR(i, 2, AC.cnt) {
		vector<int> &T = AC[i]->Qt;
		Ir(v, 0, T.size()) Ans[T[v]] += Qt[i];
	}

	IR(i, 1, n) cout << Ans[i] << "\n";

	return 0;
} /**/
## [???????????????]Tree II
### ????????????
?????? $n$ ?????????????????????????????????????????? $1$???  
?????????????????? $q$ ??????????????????????????????????????????????????????

- `+ u v c`?????? $u$ ??? $v$ ????????????????????????????????????????????? $c$???

- `- u1 v1 u2 v2`???????????????????????? $(u_1,v_1)$ ??????????????????????????? $(u_2,v_2)$?????????????????????????????????????????????

- `* u v c`?????? $u$ ??? $v$ ????????????????????????????????????????????? $c$???

- `/ u v`????????? $u$ ??? $v$ ????????????????????????????????????????????? $51061$ ?????????

### ????????????
????????????????????? $n,q$

????????? $n-1$ ???????????????????????? $u,v$?????????????????????????????????

????????? $q$ ?????????????????????????????????

### ????????????
??????????????????????????????????????????????????????????????????

### ??????????????????
#### ????????????1
```
3 2
1 2
2 3
* 1 3 4
/ 1 1
```
#### ????????????1
```
4
```
### ??????/??????
??????????????????   
?????? $10\%$ ????????????$1\le n,q \le 2000$???   
?????? $15\%$ ????????????$1 \le n,q \le 5\times 10^4$????????? `-` ???????????????????????????????????????    
?????? $35\%$ ????????????$1 \le n,q \le 5\times 10^4$????????? `-` ?????????  
?????? $100\%$ ????????????$1\le n,q \le 10^5$???$0\le c \le 10^4$???

By (?????????)

