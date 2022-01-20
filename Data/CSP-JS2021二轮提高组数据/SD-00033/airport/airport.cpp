#include<iostream> 
#include<cstdio>
#include<cstring>
#include<algorithm>

/*

get a good job!
整个好活 

lcj AK IOI every day!!
lyx 吊打国家队

froepen
//freopen("airport.in","w",stdout);
//freopen("airport3.ans","r",stdin);

//fclose(stdin);
//fclose(stdout);

cin<<"你被骗了";

CCCCCCCCCCCCCCCCCCCOrz

#define mod ((long long)(1e9+7))

#define ccf for(int i=1;i<=n;++i)

airports?

bra ckets?

cout>>"你又被骗了"; 

pulin palen pelin pilan polan? 

我嫌弃了polan! 

traffic jam

AFO? 
第一题简单点吧 
第一题简单点吧 
第一题简单点吧 
第一题简单点吧 
第一题简单点吧 
第一题简单点吧 
第一题简单点吧 
第一题简单点吧 
第一题简单点吧 
第一题简单点吧 
第一题简单点吧 
目标：120

密码：21!9-324@emb 

*/ 

using namespace std;
struct shijian{
	int T,zhonglei,peidui;
};
shijian a[200001],b[200001];
bool cmp(shijian a,shijian b){
	return a.T<b.T;
}
int cnt1,cnt2;
int n,M1,M2;
int vis[100001];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>M1>>M2;
	for(int i=1;i<=M1*2;++i){
		int x;
		cin>>x;
		a[i].T=x,a[i].zhonglei=i%2,a[i].peidui=(i-1)/2;
	}
	for(int i=1;i<=M2*2;++i){
		int x;
		cin>>x;
		b[i].T=x,b[i].zhonglei=i%2,b[i].peidui=(i-1)/2;
	}
	sort(a+1,a+M1*2+1,cmp);
	sort(b+1,b+M2*2+1,cmp);
	int i,j;
	int maxx=0;
	for(i=0;i<=n;++i){
		int lang1=i,lang2=n-i;
		int sum=0;
		for(j=1;j<=M1*2;++j){
			if(a[j].zhonglei==1){
				if(lang1){
					--lang1;
					vis[a[j].peidui]=1;
					++sum;
				}
			}
			else{
				if(vis[a[j].peidui]){
					vis[a[j].peidui]--;
					++lang1;
				}
			}
		}
		for(j=1;j<=M2*2;++j){
			if(b[j].zhonglei==1){
				if(lang2){
					--lang2;
					vis[b[j].peidui]=1;
					++sum;
				}
			}
			else{
				if(vis[b[j].peidui]){
					vis[b[j].peidui]--;
					++lang2;
				}
			}
		}
		if(sum>maxx) maxx=sum;
		if(maxx==M1+M2) break;
	}
	cout<<maxx;
	return 0;
}
