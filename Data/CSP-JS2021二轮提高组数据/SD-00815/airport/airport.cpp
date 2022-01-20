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

const int N = 1e5 + 4;
int k, n1, n2, tot1, tot2;
int ans1[N], ans2[N]; // ans
int tong1[N], tong2[N], siz1, siz2; // tong

struct edge{
   int l , r;   
}e1[N], e2[N];

struct node{
   int x;
   int id;
   bool opt; // 0->l, 1->r
   bool operator<(const node &a) const{
      return x < a.x;
   }
}q1[N * 2], q2[2 * N];

int main()
{
   freopen("airport.in", "r", stdin);
   freopen("airport.out", "w", stdout);
   k = read(),  n1 = read(), n2 = read();
   for(int i = 1; i <= n1; ++i)
   {
      e1[i].l = read(), e1[i].r = read();
      q1[++tot1] = (node){e1[i].l, i, 0};
      q1[++tot1] = (node){e1[i].r, i, 1};
   }
   for(int i = 1 ; i <= n2; ++i)
   {
      e2[i].l = read(), e2[i].r = read();
      q2[++tot2] = (node){e2[i].l, i, 0};
      q2[++tot2] = (node){e2[i].r, i, 1};
   }
   sort(q1 + 1, q1 + tot1 + 1);
   sort(q2 + 1, q2 + tot2 + 1);
   
   int x, id, opt;
   bool ok1 = 0, ok2 = 0;
   
   /* n1 */
   for(int l = 1; l <= k; ++l) // limit
   {
      if(ok1)
      {
         ans1[l] = n1;
         continue;
      }
      for(int j = 1; j <= tot1; ++j)
      {
         x = q1[j].x, id = q1[j].id, opt = q1[j].opt;
         if(opt == 0) // s
         {
            if(siz1 == l) continue;                    // if limit -> no
            tong1[id] = 1, ++ans1[l], ++siz1;          // insert
         }
         else // t
         {
            if(tong1[id] == 0) continue; // Already no
            tong1[id] = 0, --siz1;       // remove
         }
      }
      if(ans1[l] == n1) ok1 = 1;
   }
   
   /* n2 */
   for(int l = 1; l <= k; ++l) // limit
   {
      if(ok2)
      {
         ans2[l] = n2;
         continue;
      }
      for(int j = 1; j <= tot2; ++j)
      {
         x = q2[j].x, id = q2[j].id, opt = q2[j].opt;
         if(opt == 0) // s
         {
            if(siz2 == l) continue;                    // if limit -> no
            tong2[id] = 1, ++ans2[l], ++siz2;          // insert
         }
         else // t
         {
            if(tong2[id] == 0) continue; // Already no
            tong2[id] = 0, --siz2;       // remove
         }
      }
      if(ans2[l] == n2) ok2 = 1;
   }
   
//   for(int i = 0; i <= k; ++i)
//      W(ans1[i], ' ');
//   for(int i = 0; i <= k; ++i)
//      W(ans2[i], ' ');
//   putchar('\n');
   
   int maxn = 0;
   for(int i = 0; i <= k; ++i)
   {
      int j = k - i;
      maxn = max(maxn, ans1[i] + ans2[j]);
   }
   
   W(maxn, '\n');
   return 0;
}
