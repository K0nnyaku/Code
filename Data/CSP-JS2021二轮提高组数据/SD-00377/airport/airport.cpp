#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
priority_queue<int,vector<int>,greater<int> >c;
int n,m;
int ina,outa;
int sum[100005];
int cnt[100005];
int summ[100005];
int cntt[100005];
struct ljy{
	int a,b;
}s[100005],g[100005];
int amp(ljy q,ljy w)
{
	return q.a < w.a;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>ina>>outa;
	for(int i = 1;i <= ina;i++){
		cin>>s[i].a>>s[i].b;
	}
	sort(s + 1,s + ina + 1,amp);
	int f = 1,l = 0;
	sum[1] = 0;
	for(int i = 1;i <= ina;i++){
		l = 0;
		for(int j = 1;j <= f;j++){
			if(s[i].a > sum[j]){
				sum[j] = s[i].b;
				cnt[j]++;
				l = 1;
				break;
			}
		}
		if(l == 0){
			f++;
			sum[f] = s[i].b;
			cnt[f]++;
		}
	}
	for(int i = 1;i <= outa;i++){
		cin>>g[i].a>>g[i].b;
	}
	sort(g + 1,g + outa + 1,amp);
	int ff = 1,ll = 0;
	summ[1] = 0;
	for(int i = 1;i <= outa;i++){
		ll = 0;
		for(int j = 1;j <= ff;j++){
			if(g[i].a > summ[j]){
				summ[j] = g[i].b;
				cntt[j]++;
				ll = 1;
				break;
			}
		}
		if(ll == 0){
			ff++;
			summ[ff] = g[i].b;
			cntt[ff]++;
		}
	}
	int inn,ouu,ans = 0;
	int mx = 0;
	if(n <= f){
		inn = n;
		ouu = 0;
	}
	else{
		inn = f;
		ouu = (n - f);
	}
//	for(int i = 1;i <= f;i++)cout<<cnt[i]<<" ";
//	cout<<endl;
//	for(int i = 1;i <= ff;i++)cout<<cntt[i]<<" ";
//	cout<<endl;
	for(int i = 1;i <= inn;i++)ans += cnt[i];
	for(int i = 1;i <= ouu;i++)ans += cntt[i];
	mx = ans;
	for(;ouu <= ff && inn >= 0;){
		ans -= cnt[inn];
		inn--;
		ouu++;
		ans += cntt[ouu];
		mx = max(ans,mx);
		if(ouu == ff || inn == 0)break;
	}
	cout<<mx;
	return 0;
}
