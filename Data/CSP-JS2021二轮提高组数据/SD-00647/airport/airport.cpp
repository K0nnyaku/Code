#include<algorithm>
#include<iostream>
#include<climits>
#include<cstring>
#include<fstream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#include<deque>
#include<set>

int numnei[100005], numwai[100005];
struct plain
{
	int l, r;
}a[100005], b[100005];
int dpa[100005], dpb[100005];
bool cmp(plain a, plain b) { return a.l < b.l; }
using namespace std;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int num, nei, wai, n;
	cin >> num >> nei >> wai;
	for (int i = 1; i <= nei; i++)
	{
		scanf("%d %d", &a[i].l, &a[i].r);
	}
	for (int i = 1; i <= wai; i++)
	{
		scanf("%d %d", &b[i].l, &b[i].r);
	}
	sort(a + 1, a + nei, cmp);
	sort(b + 1, b + wai, cmp);
	for (int i = 1; i <= nei; i++)
	{
		int j = 1;
		bool b = false;
		while (dpa[j] != 0 && j <= num)
		{
			if (a[i].l > dpa[j])
			{
				dpa[j] = a[i].r;
				b = true;
				while (dpa[j] != 0 && j <= num)
				{
					numnei[j]++;
					j++;
				}
				break;
			}
			j++;
		}
		numnei[j]++;
		if (!b) dpa[j] = a[i].r;
		j++;
		while (j <= num)
		{
			numnei[j] = numnei[j - 1];
			j++;
		}
	}
	for (int i = 1; i <= wai; i++)
	{
		int j = 1;
		bool d = false;
		while (dpb[j] != 0 && j <= num)
		{
			if (b[i].l > dpb[j])
			{
				dpb[j] = b[i].r;
				d = true;
				while (dpb[j] != 0 && j <= num)
				{
					numwai[j]++;
					j++;
				}
				break;
			}
			j++;
		}
		numwai[j]++;
		if (!d) dpb[j] = b[i].r;
		j++;
		while (j <= num)
		{
			numwai[j] = numwai[j - 1];
			j++;
		}
	}
	
	int ans = 0;
	for (int i = 0; i <= num; i++)
	{
		ans = max(ans, numnei[i] + numwai[num - i]);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

