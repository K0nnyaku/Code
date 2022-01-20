#include<bits/stdc++.h>
using namespace std;

#define IR(i, st, ed) for(int i = st; i <= ed; i++)
#define Ir(i, st, ed) for(int i = st; i < ed; i++)
#define SR(i, st, ed) for(int i = st; i >= ed; i--)
#define Sr(i, st, ed) for(int i = st; i > ed; i--)
#define ER(i, x) for(int i = Head[x]; i; i = E[i].next)

const int N_ = 20;
const int Q_ = 3;
const int V_ = 30;

int A[10000];

int main()
{
    freopen("/home/k0nnyaku/Code/Data/In.in", "w", stdout);

	srand(time(0));
    mt19937 Rand(time(NULL));
	
	int n = Rand() % N_ + 1;
	cout << n << "\n";
	IR(i, 1, n) cout << Rand() % V_ + 1 << " ";
	cout << "\n";
	Ir(i, 1, n) 
		cout << i << " " << i + 1 << "\n";


    return 0;
}

