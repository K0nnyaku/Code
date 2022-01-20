#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int N=100005;
struct NODE{
	int co,lv;
};
NODE aa[N],bb[N];
int n,m1,m2;
int li[N];
int ans;
bool cmp(NODE a,NODE b){
	if(a.co!=b.co){
		return a.co<b.co;
	}
	return a.lv<b.lv;
	
}
int check(int k,bool ki){
	int left=k;
	memset(li,-1,sizeof(li));
	int now=1,len=0;
	int cnt=0;
	if(ki){//guonei 
		 for(int i=1;i<=m1;++i){
		 	//printf("home:\n");
		 	for(int j=1;j<=len;++j){
		 		if(li[j]==-1){
		 			continue;
				}
		 		if(li[j]<aa[i].co){
					if(j<now){
						now=j;
					}
					li[j]=-1;
					++left;
					break;
				}
			}
			if(left==0){
		 		continue;
			}
			//printf("%d %d\n",aa[i].co,aa[i].lv);
		 	--left;
			li[now]=aa[i].lv;
			++len;
			while(li[now]!=-1){
				now++;
			}
			++cnt;
		 }
		 return cnt;
	}
	else{
		//printf("aboard\n");
		for(int i=1;i<=m2;++i){
		 	for(int j=1;j<=len;++j){
		 		if(li[j]==-1){
		 			continue;
				}
		 		if(li[j]<bb[i].co){
					now=j<now?j:now;
					li[j]=0;
					++left;
					break;
				}
			}
			if(left==0){
		 		continue;
			}
			//printf("%d %d\n",bb[i].co,bb[i].lv);
		 	--left;
			li[now]=bb[i].lv;
			++len;
			while(li[now]!=-1){
				now++;
			}
			++cnt;
		 }
		 return cnt;
	}
}
int main(){
	freopen("airport.in","r",stdin);
	//freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;++i){
		scanf("%d%d",&aa[i].co,&aa[i].lv);
	}
	for(int i=1;i<=m2;++i){
		scanf("%d%d",&bb[i].co,&bb[i].lv);
	}
	sort(aa+1,aa+1+m1,cmp);
	sort(bb+1,bb+1+m2,cmp);
	for(int i=0;i<=n;++i){
		int tmp=check(i,1)+check(n-i,0);
		if(tmp>ans){
			ans=tmp;
		}
		//printf("%d\n",tmp);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
