#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<cmath>
#include<vector>
#define lll long long
using namespace std;
const int maxn=100005;
int n,m1,m2;
struct pl{
	int a;
	int b;
	friend bool operator <(pl x,pl y){
		return x.a<y.a;
	} 
}p1[maxn],p2[maxn];
int cnt1,cnt2;
int num[maxn][2];
int len[maxn][2];
int sum[maxn];
int summ[maxn];
int ans;
void deal(int x){
	int tem=0;
	memset(len,0,sizeof(len));
	for(int i=1;i<=m1;++i){
		for(int j=1;j<=x;++j){
			if(len[j][0]<=p1[i].a){
				tem++;
				len[j][0]=p1[i].b;
				break;
			}
		}
	}
	x=n-x;
	for(int i=1;i<=m2;++i){
		for(int j=1;j<=x;++j){
			if(len[j][1]<=p2[i].a){
				tem++;
				len[j][1]=p2[i].b;
				break;
			}
		}
	}
	//cout<<x<<" "<<tem<<endl;;
	ans=max(ans,tem);
	return ;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	//fclose(stdin);
	//fclose(stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;++i){
		scanf("%d%d",&p1[i].a,&p1[i].b); 
	}
	sort(p1+1,p1+m1+1);
	for(int i=1;i<=m2;++i){
		scanf("%d%d",&p2[i].a,&p2[i].b); 
	}
	sort(p2+1,p2+m2+1);
	for(int i=0;i<=n;++i){
		deal(i);
	}
	cout<<ans;
	return 0;
}

