#include<cstdio>
#include<cstring>
#include<queue>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define ll long long
int n,m1,m2,cnt,ans,dis[100005],al[100005];
priority_queue <int,vector<int>,greater<int> > q;
struct note{
	int bg,en;
}ch[100005],na[100005];

int ye(int chl,int nal){
	int now=0,_sum=0;
	for(int i=1;i<=m1;i++){
		while(!q.empty()){
			if(q.top()<ch[i].bg){
				q.pop();
				now--;
			}
			else break;
		}
		if(now<chl){
			_sum++;
			now++;
			q.push(ch[i].en);
		}
	}
	while(!q.empty())
		q.pop();
	now=0;
	for(int i=1;i<=m2;i++){
		while(!q.empty()){
			if(q.top()<na[i].bg){
				q.pop();
				now--;
			}
			else break;
		}
		if(now<nal){
			_sum++;
			now++;
			q.push(na[i].en);
		}
	}
	while(!q.empty())
		q.pop();
	dis[chl]=_sum;
	//printf("---%d %d\n",chl,sum);
	return _sum;
}

void half(int l,int r){
	if(l>=r){
		return;
	}
	int mid=l+r>>1,mid1=l+mid>>1,mid2=mid+1+r>>1;
	int mida,mid1a,mid2a,nextl=l,nextr=r;
	if(dis[mid]) mida=dis[mid];
	else mida=ye(mid,n-mid);
	if(dis[mid1]) mid1a=dis[mid1];
	else mid1a=ye(mid1,n-mid1);
	if(dis[mid2]) mid2a=dis[mid2];
	else mid2a=ye(mid2,n-mid2);
	int maxn=max(max(mida,mid1a),mid2a);
	if(mid1a<maxn) nextl=mid1+1;
	if(mid2a<maxn) nextr=mid2-1;
	//printf("%d %d %d\n",mida,mid1a,mid2a);
	ans=maxn;
	half(nextl,nextr);
}

bool cmp(note a,note b){
	return a.bg<b.bg;
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
		scanf("%d%d",&ch[i].bg,&ch[i].en);
	for(int i=1;i<=m2;i++)
		scanf("%d%d",&na[i].bg,&na[i].en);
	sort(ch+1,ch+m1+1,cmp);
	sort(na+1,na+m2+1,cmp);
	if(n*n*sqrt(m1+m2)<=50000000){
		for(int i=0;i<=n;i++)
			ans=max(ans,ye(i,n-i));
		printf("%d\n",ans);
		return 0;
	}
	for(int i=1;i<=m1;i++){
		while(!q.empty()){
			if(q.top()<ch[i].bg){
				q.pop();
				cnt--;
			}
			else break;
		}
		cnt++;
		q.push(ch[i].en);
		//printf("*%d %d\n",i,cnt);
	}
	while(!q.empty())
		q.pop();
	half(0,cnt);
	printf("%d\n",ans);
	return 0;
}
/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/
/*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*/
