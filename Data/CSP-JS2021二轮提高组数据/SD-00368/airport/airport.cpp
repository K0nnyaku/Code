#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#define MAXN 100050
using namespace std;
struct node{
	int a,b;
};
node guonei[MAXN];
node quenei[MAXN];
node queji[MAXN];
node guoji[MAXN];
int n,m,mm;
bool cmp(node xaq,node yaq){
	return xaq.a<yaq.a;
}
bool cmp1(node xaq,node yaq){
	return xaq.b<yaq.b;
}
int ans=0;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m>>mm;
	for(int i=1;i<=m;i++){
		cin>>guonei[i].a>>guonei[i].b;
	}
	sort(guonei+1,guonei+m+1,cmp);
	for(int i=1;i<=mm;i++){
		cin>>guoji[i].a>>guoji[i].b;
	}
	sort(guoji+1,guoji+mm+1,cmp);
	for(int nei=0;nei<=n;nei++){
		int ji=n-nei;
		int sum=0;
		int topnei=0;
		int topji=0;
		int lasnei=1;
		int lasji=1;
		sum+=nei;
		
		for(int i=1;i<=nei;i++){
			topnei++;
			quenei[topnei]=guonei[i];
		}
		sort(quenei+1,quenei+1+topnei,cmp1);
		int pl=nei+1;
		while(lasnei<=topnei){
			node lin=quenei[lasnei];
			lasnei++;
			for(int i=pl;i<=m;i++){
				if(guonei[i].a>=lin.b){
					topnei++;
					quenei[topnei]=guonei[i];
					sort(quenei+lasnei,quenei+topnei+1,cmp1);
					sum++;
					pl=i+1;
					break;
				}
			}
		}
		sum+=ji;
		
		for(int i=1;i<=ji;i++){
			topji++;
			queji[topji]=guoji[i];
		}
		sort(queji+1,queji+1+topji,cmp1);
		pl=ji+1;
		while(lasji<=topji){
			node lin=queji[lasji];
			lasji++;
			for(int i=pl;i<=m;i++){
				if(guoji[i].a>=lin.b){
					topji++;
					queji[topji]=guoji[i];
					sort(queji+lasji,queji+topji+1,cmp1);
					sum++;
					pl=i+1;
					break;
				}
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
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
