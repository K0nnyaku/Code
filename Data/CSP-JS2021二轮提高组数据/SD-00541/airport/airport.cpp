#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rop(i,a,b) for(int i=a;i<b;++i) 
namespace webbermys{
	const int N=100000;
	int n,m111,m222,ans;
	int ans1[N+20],ans2[N+20];
	int cnt__1,cnt__2;
	std::vector<int> plannei[N+20];
	std::vector<int> planwai[N+20];
	struct node{
		int l,r;
	}timet[N+20];
	bool cmp(node xxx,node yyy){
		return xxx.l<yyy.l;
	}
	inline long long max(long long xxx,long long yyy){
		return (xxx>yyy)?xxx:yyy; 
	}
	void Main(){
		freopen("airport.in","r",stdin);
		freopen("airport.out","w",stdout);
		scanf("%d%d%d",&n,&m111,&m222);
		rep(i,1,m111)
			scanf("%d%d",&timet[i].l,&timet[i].r);
		std::sort(timet+1,timet+1+m111,cmp);
		rep(j,1,m111){
			bool flag=0;
			rep(i,1,cnt__1)
				if(timet[j].l>=plannei[i][plannei[i].size()-1])
					{plannei[i].push_back(timet[j].r);flag=1;++ans1[i];break;}
			if(!flag){
				plannei[++cnt__1].push_back(timet[j].r);
				++ans1[cnt__1];
			}
		}
		rep(i,1,m222)
			scanf("%d%d",&timet[i].l,&timet[i].r);
		std::sort(timet+1,timet+1+m222,cmp);
		rep(j,1,m222){
			bool flag=0;
			rep(i,1,cnt__2)
				if(timet[j].l>=planwai[i][planwai[i].size()-1])
					{planwai[i].push_back(timet[j].r);flag=1;++ans2[i];break;}
			if(!flag){
				planwai[++cnt__2].push_back(timet[j].r);
				++ans2[cnt__2];
			}
		}
		rep(i,1,n){
			ans1[i]=ans1[i-1]+ans1[i];
			ans2[i]=ans2[i-1]+ans2[i];
		}
		rep(i,0,n)
			ans=max(ans,ans1[i]+ans2[n-i]);
		printf("%d",ans);
	}
}
 
int main(){
	webbermys::Main();
	return 0;	
}

