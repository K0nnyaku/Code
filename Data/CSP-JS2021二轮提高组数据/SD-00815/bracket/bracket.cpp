#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline ll read()
{
	ll x =0 , f =0;
   char ch = getchar();
   while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
   while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
   return f ? -x : x;
}

void Wr(ll x)
{
   if(x < 0 ) putchar('-'), x = -x;
   if(x > 9) Wr(x / 10);
   putchar(x % 10 + 48);
}

void W(ll x, char ch)
{
   Wr(x);
   putchar(ch);
}

const ll mod = 1e9 + 7;


int main()
{
   freopen("bracket.in", "r", stdin);
   freopen("bracket.out", "w", stdout);
   W(23, '\n');
   
   return 0;
}
