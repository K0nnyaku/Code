#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n,m1,m2;
long long ans;
int insta[100003],intop,outsta[100003],outtop;

struct node{
	int from,to;
};
vector<node>inc,outc;

bool vcmp(node a,node b){
	return a.from<b.from;
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	
	int temp1,temp2;
	for(int i=1;i<=m1;++i){
		scanf("%d%d",&temp1,&temp2);
		inc.push_back((node){temp1,temp2});
	}
	for(int i=1;i<=m2;++i){
		scanf("%d%d",&temp1,&temp2);
		outc.push_back((node){temp1,temp2});	
	}
	
	sort(inc.begin(),inc.end(),vcmp);
	sort(outc.begin(),outc.end(),vcmp);
	
	int cnt=0,now=0;//计数，时间 
	
	while(!inc.empty()){//国内 
		now=0;
		cnt=0;
		int size=inc.size();
		for(int i=0;i<size;++i){
			if(now<inc[i].from){
				now=inc[i].to;
				++cnt;
				inc.erase(inc.begin()+i);
				--size;
				--i;
			}
		}
		insta[++intop]=cnt;
	}
	
	while(!outc.empty()){//国外 
		now=0;
		cnt=0;
		int size=outc.size();
		for(int i=0;i<size;++i){
			if(now<outc[i].from){
				now=outc[i].to;
				++cnt;
				outc.erase(outc.begin()+i);
				--size;
				--i;
			}
		}
		outsta[++outtop]=cnt;
	}
	
	for(int i=1;i<=n;++i){
		insta[i+1]+=insta[i];
		outsta[i+1]+=outsta[i];
	}
	
	int temp;
	for(int i=0;i<=n;++i){
		temp=insta[i]+outsta[n-i];
		ans=temp>ans?temp:ans;
	}
	printf("%lld\n",ans);
	
	return 0;
}
