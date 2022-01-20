#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return x * f;
} 
set<pair<int, int> > s1, s2;
set<pair<int, int> >::iterator it, nxt;
vector<pair<int, int> > v1, v2;
int n, mm1, mm2; 
int a, b;
int cnt = 1;
int ans1[1001000], ans2[1001000];
int ans = 0;
int num1 = 0, num2 = 0;
int vis[1000100], vis2[1001000];
int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n = read();
	if(n <= 5000)
	{
	mm1 = read();
	mm2 = read();
	for(int i = 1; i <= mm1; i ++)
	{
		a = read(); b = read();
		v1.push_back(make_pair(a, b));
	}
	for(int i = 1; i <= mm2; i ++)
	{
		a = read(); b = read();
		v2.push_back(make_pair(a, b));
	}
	sort(v1.begin(), v1.end());
	int num = 0, cnt = 1, now = 0;
	while(cnt != 0)
	{
		cnt = 0, now = 0;
		for(int i = 0; i < v1.size(); i ++)
		{
			if(vis[i]) continue;
			if(v1[i].first > now)
			{
				vis[i] = 1;
				cnt ++;
				now = v1[i].second;
			}
		}
		if(cnt != 0)
		{
			ans1[num + 1] = ans1[num] + cnt;
			num ++;
		}
	}
	int num2 = 0;
	cnt = 1, now = 0;
	sort(v2.begin(), v2.end());
	while(cnt != 0)
	{
		cnt = 0, now = 0;
		for(int i = 0; i < v2.size(); i ++)
		{
			if(vis2[i]) continue;
			if(v2[i].first > now)
			{
				vis2[i] = 1;
				cnt ++;
				now = v2[i].second;
			}
		}
		if(cnt != 0)
		{
			ans2[num2 + 1] = ans2[num2] + cnt;
			num2 ++;
		}
	}
	for(int i = 0; i <= n; i ++)
	{
		int nowa = (i > num) ? num : i;
		int nowb = ((n - i) > num2) ? num2 : (n - i);
		//cout << i << " " << ans1[nowa] << " " << ans2[nowb] << endl; 
		ans = max(ans, ans1[nowa] + ans2[nowb]);
	}
	cout << ans << endl;
	return 0;
	}
	else
	{
	mm1 = read();
	mm2 = read();
	for(int i = 1; i <= mm1; i ++)
	{
		a = read(); b = read();
		s1.insert(make_pair(a, b));
	}
	while(s1.begin() !=s1.end() )
	{
		it = s1.begin();
		cnt = 1;
		int now = (*it).second;
		//cout << now << endl;
		s1.erase(it);
		nxt = upper_bound(s1.begin(), s1.end(), make_pair(now,0));
		while(nxt != s1.end())
		{
			cnt ++;
			now = (*nxt).second;
			//cout << now << endl;
			s1.erase(nxt);
			nxt = upper_bound(s1.begin(), s1.end(), make_pair(now,0));
		}
		ans1[num1 + 1] = ans1[num1] + cnt;
		num1 ++;
	}
	for(int i = 1; i <= mm2; i ++)
	{
		a = read(); b = read();
		s2.insert(make_pair(a, b));
	}
	while(s2.begin() !=s2.end() )
	{
		it = s2.begin();
		cnt = 1;
		int now = (*it).second;
		//cout << now << endl;
		s2.erase(it);
		nxt = upper_bound(s2.begin(), s2.end(), make_pair(now,0));
		while(nxt != s2.end())
		{
			cnt ++;
			now = (*nxt).second;
			//cout << now << endl;
			s2.erase(nxt);
			nxt = upper_bound(s2.begin(), s2.end(), make_pair(now,0));
		}
		ans2[num2 + 1] = ans2[num2] + cnt;
		num2 ++;
	}
	for(int i = 0; i <= n; i ++)
	{
		int nowa = (i > num1) ? num1 : i;
		int nowb = ((n - i) > num2) ? num2 : (n - i);
		//cout << i << " " << ans1[nowa] << " " << ans2[nowb] << endl; 
		ans = max(ans, ans1[nowa] + ans2[nowb]);
	}
	cout << ans << endl;
	return 0;
	}

	
}
