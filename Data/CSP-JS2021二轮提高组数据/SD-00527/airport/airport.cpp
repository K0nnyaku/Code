#include<bits/stdc++.h>//记得打子文件 
#define ll long long
using namespace std;
const int maxn = 1e5 + 10;//看数据范围，不要老1e5
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
} 
void print(ll x){
	if(x<=0){ putchar('-'); x=-x; }
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
struct node{
	ll num,i,k;
}c[maxn<<2],f[maxn<<2];
ll coc[maxn],tmlc[maxn],xcc,xc,npc[maxn],colc,nxtc[maxn],ans;
ll cof[maxn],tmlf[maxn],xcf,xf,npf[maxn],colf,nxtf[maxn];
ll cmp(node a,node b){
	return a.num<b.num;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	ll n=read(),mc=read(),mf=read();
	for(int i=1;mc>=i;i++) {
		c[i].num=read(),c[i+mc].num=read();
		c[i].i=++colc,c[i+mc].i=colc;
		c[i].k=1,c[i+mc].k=-1;
	}
	sort(c,c+2*mc,cmp);
	for(int i=0;n>=i;i++) nxtc[i]=i+1;
	for(int i=1;2*mc>=i;i++){
		xcc=c[i].k;
		if(xcc==1){
			npc[0]+=1;npc[xc+1]-=1;
			tmlc[c[i].i]=xc;
			xc=nxtc[xc];
			//cout<<coc[i]<<" "<<tmlc[coc[i]]<<endl;
		}
		else if(xcc==-1){
			nxtc[tmlc[c[i].i]]=xc;
			xc=tmlc[c[i].i];
		}
	}
	for(int i=1;mf>=i;i++) {
		f[i].num=read(),f[i+mf].num=read();
		f[i].i=++colf,f[i+mf].i=colf;
		f[i].k=1,f[i+mf].k=-1;
	}
	sort(f,f+2*mf,cmp);
	for(int i=0;n>=i;i++) nxtf[i]=i+1;
	for(int i=1;2*mf>=i;i++){
		xcf=f[i].k;
		if(xcf==1){
			npf[0]+=1;npf[xf+1]-=1;
			tmlf[f[i].i]=xf;
			xf=nxtf[xf];
			//fout<<fof[i]<<" "<<tmlf[fof[i]]<<endl;
		}
		else if(xcf==-1){
			nxtf[tmlf[f[i].i]]=xf;
			xf=tmlf[f[i].i];
		}
	}
	//for(int i=0;n>=i;i++) fout<<np[i]<<" ";
	for(int i=1;n>=i;i++) npc[i]+=npc[i-1];
	for(int i=1;n>=i;i++) npf[i]+=npf[i-1];
	for(int i=0;n>=i;i++) npc[i]=mc-npc[i];
	for(int i=0;n>=i;i++) npf[i]=mf-npf[i];
		//for(int i=0;n>=i;i++) cout<<npc[i]<<" ";cout<<endl;
		//	for(int i=0;n>=i;i++) cout<<npf[i]<<" ";
	for(int i=0;n>=i;i++) ans=max(ans,npc[i]+npf[n-i]);
	cout<<ans<<endl;
	return 0;
}
