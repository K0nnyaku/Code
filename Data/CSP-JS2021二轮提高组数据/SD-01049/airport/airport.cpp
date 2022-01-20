#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	char ch=getchar();
	while(ch!='-'&&(ch>'9'||ch<'0'))
	{
		ch=getchar();
	}
	ll ans=0,t=1;
	if(ch=='-'){
		t=-1;
		ch=getchar();
	} 
	while(ch>='0'&&ch<='9'){
		ans=ans*10+(ch-'0');
		ch=getchar();
	}
	return ans*t;
}
ll n,m1,m2;
const int N=1e5+10;
struct node
{
	ll l,r;
}p[N];
struct node1{
	ll l,r;
}p1[N];
bool cmp1(node a,node b){
	return a.l<b.l;
}
bool cmp2(node1 a,node1 b){
	return a.l<b.l;
}
struct way{
	ll lv;
	way(ll a){
		lv=a;
	}
	bool operator <(const way another) const
	{
		return lv>another.lv;
	}
};
priority_queue<way>q;
ll plane[N],plane1[N];//分几个廊桥能停几个飞机 
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>p[i].l>>p[i].r;
	}
	for(int i=1;i<=m2;i++){
		cin>>p1[i].l>>p1[i].r;
	}
	sort(p+1,p+m1+1,cmp1);
	sort(p1+1,p1+m2+1,cmp2);
	for(int i=1;i<=n;i++){
		int k=i;
		for(int j=1;j<=m1;j++){
			if(j==1){
				plane[i]++;
				q.push(way(p[j].r));
				k--;
			}
			else
			{
				if(p[j].l>q.top().lv)
				{
					while(p[j].l>q.top().lv&&!q.empty())
					{
						k++;
						q.pop();
					}
					plane[i]++;
					q.push(way(p[j].r));
					k--;
				}
				else
				{
					if(k>0){
						k--;
						q.push(way(p[j].r));
						plane[i]++;
					}
				}
			}
		}
	}
	while(!q.empty()){
		q.pop();
	}
	for(int i=1;i<=n;i++){
		int k=i;
		for(int j=1;j<=m2;j++){
			if(j==1){
				plane1[i]++;
				q.push(way(p1[j].r));
				k--;
			}
			else
			{
				if(p1[j].l>q.top().lv)
				{
					while(p1[j].l>q.top().lv&&!q.empty())
					{
						k++;
						q.pop();
					}
					plane1[i]++;
					q.push(way(p1[j].r));
					k--;
				}
				else
				{
					if(k>0){
						k--;
						q.push(way(p1[j].r));
						plane1[i]++;
					}
				}
			}
		}
	}
	ll ans=0;
	for(int i=0;i<=n;i++){
		ans=max(ans,plane[i]+plane1[n-i]);
	}
	cout<<ans;
	return 0;
} 

