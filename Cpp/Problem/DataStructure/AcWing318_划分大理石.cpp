#include<bits/stdc++.h>
using namespace std;

#define IR(i, st, ed) for(int i = st; i <= ed; i++)
#define SR(i, st, ed) for(int i = st; i >= ed; i--)
#define ER(i, x) for(int i = Head[x]; i; i = E[i].next)

struct FastIN
{
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c, l;
		for(c = 0; !isdigit(c); c = getchar() ) l = c;
		for(x = 0; isdigit(c); c = getchar() ) x = x * 10 - '0' + c;
		if(l == '-') x = -x;
		return *this;
	}
} IN;

const int N_ = 6 + 2;
const int V_ = 2e4 * 6 + 2;

int Num[N_], Mk[V_];
int sum;
bool F[V_];

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\AC.out", "w", stdout);
#endif

	IR(i, 1, 6) IN >> Num[i], sum += Num[i] * i;
	while(sum) {
		memset(F, 0, sizeof F);
		F[0] = 1; 

		IR(i, 1, 6) {
			memset(Mk, 0, sizeof Mk);
			IR(v, i, sum / 2) if(!F[v] && F[v-i] && Mk[v-i] < Num[i])
				Mk[v] = Mk[v-i] + 1, F[v] = true;
		}

		if(F[sum/2] && !(sum % 2)) 
			printf("Can\n");
		else
			printf("Can't\n");

		sum = 0;
		IR(i, 1, 6) IN >> Num[i], sum += Num[i] * i;
	}


	return 0;
} /**/


















