#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
struct node{
	int qi,zou;
	int vis=0;
}pn[100005];
node pw[100005];
int n,mn,mw;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>mn>>mw;
	if(n>=mn+mw){
		cout<<mn+mw;
		return 0;
	}
	for(int i=1;i<=mn;i++){
		scanf("%d%d",&pn[i].qi,&pn[i].zou);
	}
	for(int i=1;i<=mw;i++){
		scanf("%d%d",&pw[i].qi,&pw[i].zou);
	}
	for(int i=1;i<=mn;i++){
		for(int j=i+1;j<=mn;j++){
			if(pn[i].qi>pn[j].qi){
				swap(pn[i].qi,pn[j].qi);
				swap(pn[i].zou,pn[j].zou);
			}
		}
	}
	for(int i=1;i<=mw;i++){
		for(int j=i+1;j<=mw;j++){
			if(pw[i].qi>pw[j].qi){
				swap(pw[i].qi,pw[j].qi);
				swap(pw[i].zou,pw[j].zou);
			}
		}
	}
	int gn=0,mmax=-1;
	while(gn<=n){
		for(int i=1;i<=mw;i++) pw[i].vis=0;
		for(int i=1;i<=mn;i++) pn[i].vis=0;
		int xx=1;
		int anss=gn,mans=0,dtime=pn[1].zou;
		if(anss!=0){
			for(int i=1;i<=mn;i++){
				while(pn[i].qi>=dtime){
					anss++;
					xx++;
					while(pn[xx].vis!=2&&pn[xx].vis!=0) xx++;
					dtime=pn[xx].zou;
				}
				if(anss>0){
					anss--;
					mans++;
					pn[i].vis=2;
				}else pn[i].vis=1;
			}
		}
		xx=1,anss=n-gn,dtime=pw[1].zou;
		int mmans=0;
		if(anss!=0){
			for(int i=1;i<=mw;i++){
				while(pw[i].qi>=dtime){
					anss++;
					xx++;
					while(pw[xx].vis!=2&&pw[xx].vis!=0) xx++;
					dtime=pw[xx].zou;
				}
				if(anss>0){
					anss--;
					mmans++;
					pw[i].vis=2;
				}else pw[i].vis=1;
			}
		}
		if(mans+mmans>mmax) mmax=mans+mmans;
		gn++;
	}
	cout<<mmax;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
