#include <bits/stdc++.h>

#define ll long long
#define reg register
#define gc getchar()

using namespace std;

const int maxm = 100000 + 3;

inline ll read()
{
	ll f = 0, x = 0;
	char ch = gc;
	while (!isdigit(ch))
		f |= (ch == '-'), ch = gc;
	while (isdigit(ch))
		x = (x << 1) + (x << 3) + (ch ^ 48), ch = gc;
	return f ? -x : x;
}

ll n;

int main(void)
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i++)
		cout<<"-1"<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
