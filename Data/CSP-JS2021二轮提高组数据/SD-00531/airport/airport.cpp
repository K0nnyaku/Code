#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;
inline int R(){
	int x=0,f=1;char c='c';
	while(c>'9'||c<'0'){f=f*(c=='-'?-1:1);c=getchar();}
	while(c<='9'&&c>='0'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
struct plapla{int iii,uuu;}nnn[300233],www[300233];
int n,myi,mer,lll,rrr,ans=-1919810,qwq=1919810;
int opn[300233],ctn,opw[300233],ctw;
int pwn[300233],pww[300233];
int dun[300233],duw[300233];
int mnn[300233],mnw[300233];
int zn,zw,usaaa,usbbb;
priority_queue<int,vector<int>,greater<int> > hahap;
bool cmp(plapla a,plapla b){
	return a.iii<b.iii;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=R();myi=R();mer=R();
	for(int i=1;i<=myi;++i){
		lll=R();rrr=R();nnn[i].iii=lll;nnn[i].uuu=rrr;
		opn[++ctn]=lll;opn[++ctn]=rrr;
	}
	for(int i=1;i<=mer;++i){
		lll=R();rrr=R();www[i].iii=lll;www[i].uuu=rrr;
		opw[++ctw]=lll;opw[++ctw]=rrr;
	}
	int papan=(myi<<1),papaw=(mer<<1);
	sort(opn+1,opn+papan+1);sort(opw+1,opw+papaw+1);
	for(int i=1;i<=myi;++i){
		nnn[i].iii=lower_bound(opn+1,opn+papan+1,nnn[i].iii)-opn;
		nnn[i].uuu=lower_bound(opn+1,opn+papan+1,nnn[i].uuu)-opn;
		usaaa=nnn[i].iii;usbbb=nnn[i].uuu;
		dun[usaaa]=usbbb;
		dun[usbbb]=usaaa;
		pwn[usaaa]=1;
		pwn[usbbb]=-1;
	}	
	for(int i=1;i<=mer;++i){
		www[i].iii=lower_bound(opw+1,opw+papaw+1,www[i].iii)-opw;
		www[i].uuu=lower_bound(opw+1,opw+papaw+1,www[i].uuu)-opw;
		usaaa=www[i].iii;usbbb=www[i].uuu;
		duw[usaaa]=usbbb;
		duw[usbbb]=usaaa;
		pww[usaaa]=1;
		pww[usbbb]=-1;
	}
	for(int i=1;i<=papan;++i){
		zn=zn+pwn[i];
		if(pwn[i]==1){
			if(hahap.size()){
				qwq=hahap.top();
				hahap.pop();
			}
			pwn[i]=min(zn,qwq);
			mnn[pwn[i]]++;
			qwq=19198100;
		}
		else{
			hahap.push(pwn[dun[i]]);
		}
	}
	while(hahap.size()){
		hahap.pop();
	}
	for(int i=1;i<=papan;++i){
		zw=zw+pww[i];
		if(pww[i]==1){
			if(hahap.size()){
				qwq=hahap.top();
				hahap.pop();
			}
			pww[i]=min(zw,qwq);
			mnw[pww[i]]++;
			qwq=19198100;
		}
		else{
			hahap.push(pww[duw[i]]);
		}
	}
	for(int i=1;i<=n;++i){
		mnn[i]+=mnn[i-1];
		mnw[i]+=mnw[i-1];
	}
	for(int i=0;i<=n;++i){
		ans=max(ans,mnn[i]+mnw[n-i]);
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

