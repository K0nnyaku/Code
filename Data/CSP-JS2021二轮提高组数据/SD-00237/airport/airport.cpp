#include<ctime>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<algorithm>
#define maxn 100005
using namespace std;
struct lq{
	int zh,al;
}sl[maxn],zl[maxn];

//int cmp_1(struct lq o,struct lq c){
//	return o.al>c.al;
//}

struct hb{
	int a,b;
}nei[maxn],wai[maxn];

int cmp(struct hb e,struct hb r){
	return e.a<r.a;
}
bool wq=true;
int n,mx,my,ans=0;
int k=1,f=1,yu=1,ye=1;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&mx,&my);
	memset(nei,0,sizeof(nei));
	memset(wai,0,sizeof(wai));
	memset(sl,0,sizeof(sl));
	memset(zl,0,sizeof(zl));
	for(int i=1;i<=mx;i++){
		scanf("%d %d",&nei[i].a,&nei[i].b);
	}
	sort(nei+1,nei+mx+1,cmp);   
	sl[1].zh=nei[1].b;            
	sl[1].al=1; 
	for(int i=1;i<=mx;i++){
		for(int j=1;j<=k;j++){
			if(sl[j].zh<nei[i].a){
				sl[j].al++;
				sl[j].zh=nei[i].b;
				wq=false;
				//continue;
				break;
			}
		}
		if(wq==false){
			k++;
			sl[k].al=1;
			sl[k].zh=nei[i].b;
			wq=true;
		}
	}			
	
	for(int i=1;i<=my;i++){
		scanf("%d %d",&wai[i].a,&wai[i].b);
	}
	sort(wai+1,wai+my+1,cmp);
	
	wq=true;
	zl[1].zh=wai[1].b;
	zl[1].al=1;
	for(int i=1;i<=my;i++){
		for(int j=1;j<=f;j++){
			if(zl[j].zh<wai[i].a){
				zl[j].al++;
				zl[j].zh=wai[i].b;
				wq=false;
				//continue;
				break;
			}
		}
		if(wq==false){
			f++;
			zl[f].al=1;
			zl[f].zh=wai[i].b;
			wq=true;
		}
	}

	for(int i=1,j=1;(i+j)-1<=n;i=yu,j=ye){
		if(sl[i].al>zl[j].al){
			ans+=sl[i].al;
			yu++;
		}
		else{
			ans+=zl[j].al;
			ye++;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
