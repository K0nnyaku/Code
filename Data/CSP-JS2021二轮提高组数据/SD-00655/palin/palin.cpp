#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <ctime>
using namespace std;
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)

template <typename T>
T read(T &a)
{
	T res = 0, sign = 1;
	char c;
	while((c = getchar()) < '0' || c > '9') if(c == '-') sign = -1;
	while(c <= '9' && c >= '0') res = res * 10 + c - '0', c = getchar();
	a = res * sign;
	return a;
}

const int N = 1000010;
int n, t;
int a[N], l[N], r[N], wz[N];
int l1, r1, l2, r2, ok;

void dfs(int step)
{
	if(ok == 1) return;
	if(step == n+1)
	{
		ok = 1;
		int ll = 1, rr = 2 * n;
		rep(i,1,2*n)
		{
			if(wz[ll] == i)
			{
				putchar('L');
				ll++;
			}
			else if(wz[rr] = i)
			{
				putchar('R');
				rr--;
			}
		}
		puts("");
		//rep(i,1,2*n) cout << i << " " << wz[i] <<endl; 
		//cout <<l[3] <<endl;
		return;
	}
	if(step == 1)
	{
		l2 = r2 = r[a[1]];
		l1++;
		wz[1] = 1; wz[r[a[1]]] = 2*n;
		dfs(step+1);
		l1--;
		wz[1] = wz[r[a[1]]] = 0;if(ok == 1) return;
		l2 = r2 = l[a[2*n]];
		r1--;
		wz[2*n] = 1; wz[l[a[2*n]]] = 2*n;
		dfs(step+1);
		r1++;
		wz[2*n] = wz[l[a[2*n]]] = 0;if(ok == 1) return;
	}
	else
	{
		if(a[l1] != a[l2-1]
            && a[l1] != a[r2+1]
            && a[r1] != a[l2-1]
            && a[r1] != a[r2+1]) return;
		if(!wz[l1] && !wz[l2-1] && l1 != (l2-1) && a[l1] == a[l2-1])
		{
			wz[l1] = step;
			wz[l2-1] = 2*n + 1 - step;
			l1++; l2--;
			dfs(step+1);
			l1--; l2++;
			wz[l1] = wz[l2-1] = 0;if(ok == 1) return;
		}
		if(!wz[l1] && !wz[r2+1] && l1 != (r2+1) && a[l1] == a[r2+1])
		{
		    wz[l1] = step;
			wz[r2+1] = 2*n + 1 - step;
			l1++; r2++;
			dfs(step+1);
			l1--; r2--;
			wz[l1] = wz[r2+1] = 0;if(ok == 1) return;
		}
		if(!wz[r1] && !wz[l2-1] && r1 != (l2-1) && a[r1] == a[l2-1])
		{
			wz[r1] = step;
			wz[l2-1] = 2*n + 1 - step;
			r1--; l2--;
			dfs(step+1);
			r1++; l2++;
			wz[r1] = wz[l2-1] = 0;if(ok == 1) return;
		}
		if(!wz[r1] && !wz[r2+1] && r1 != (r2+1) && a[r1] == a[r2+1])
		{
		    wz[r1] = step;
			wz[r2+1] = 2*n + 1 - step;
			r1--; r2++;
			dfs(step+1);
			r1++; r2--;
			wz[r1] = wz[r2+1] = 0;if(ok == 1) return;
		}
	}
}

int main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	read(t);
	rep(hi,1,t)
	{
		ok = 0;
		read(n);
		l1 = 1, r1 = 2 * n;
		rep(i,1,n) l[i] = 0;
		rep(i,1,2*n)
		{
		    read(a[i]);
		    if(l[a[i]]) r[a[i]] = i;
		    else l[a[i]] = i;
		}
		dfs(1);
		if(ok == 0) puts("-1");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//O(ะþัง)
