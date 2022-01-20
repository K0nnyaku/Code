#include<iostream>
#include<cstdio>
#include<algorithm>
#include<iomanip>
using namespace std;
inline int read(){
	int f=1,sum=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		sum=(sum<<3)+(sum<<1)+(ch^48);
		ch=getchar();
	}
	return sum*f;
}
int gnt[100010],gwt[100010],n,m1,m2,e1,e2,ans;
struct node{
	int ar;
	int le;
};
node gn[100010],gw[100010];
bool cmd(node x,node y){
	return x.ar<y.ar;
}
void findn(int x){
	for(int i=x+1;i<=m1;++i){
		if(gn[i].ar>gn[x].le&&gn[i].ar!=-1&&gn[x].le!=-1){
			gnt[e1]++;
			findn(i);
			gn[x].ar=-1;
			gn[x].le=-1;
			return;
		}
	}
	gn[x].ar=-1;
	gn[x].le=-1;
}
void findw(int x){
	for(int i=x+1;i<=m2;++i){
		if(gw[i].ar>gw[x].le&&gw[i].ar!=-1&&gw[x].le!=-1){
			gwt[e2]++;
			findw(i);
			gw[x].ar=-1;
			gw[x].le=-1;
			return;
		}
	}
	gw[x].ar=-1;
	gw[x].le=-1;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	//cin>>n>>m1>>m2;
	n=read();
	m1=read();
	m2=read();
	//gn
	for(int i=1;i<=m1;++i){
		gn[i].ar=read();
		gn[i].le=read();
	} //cin>>gn[i].ar>>gn[i].le;
	sort(gn+1,gn+m1+1,cmd);
//	for(int i=1;i<=m1;++i) cout<<gn[i].ar<<" "<<gn[i].le<<endl;
	
	for(int i=1;i<=m1;++i){
		if(gn[i].ar!=-1&&gn[i].le!=-1){
		    e1++;
		    gnt[e1]=1;
			findn(i);
			//cout<<gnt[e1]<<endl;
			//maxn=max(maxn,gnt[e]);
		} 
	} 
	for(int i=1;i<=e1;++i){
		gnt[i]+=gnt[i-1];
	}
	//gn^
	//gw
	for(int i=1;i<=m2;++i){
		gw[i].ar=read();
		gw[i].le=read();
	} //cin>>gw[i].ar>>gw[i].le;
	sort(gw+1,gw+m2+1,cmd);
	for(int i=1;i<=m2;++i){
		if(gw[i].ar!=-1&&gw[i].le!=-1){
		    e2++;
		    gwt[e2]=1;
			findw(i);
			//cout<<gwt[e2]<<endl;
		} 
	} 
	for(int i=1;i<=e2;++i){
		gwt[i]+=gwt[i-1];
	}
	//for(int i=1;i<=m1;++i) cout<<gn[i].ar<<" "<<gn[i].le<<"||";
	for(int i=1;i<=n;++i){
		if(i>e1&&n-i>e2) ans=max(ans,gnt[e1]+gwt[e2]);
		else if(n-i>e2) ans=max(ans,gnt[i]+gwt[e2]);
		else if(i>e1) ans=max(ans,gnt[e1]+gwt[n-i]);
		else ans=max(ans,gnt[i]+gwt[n-i]);
	}
	//cout<<gnt[e1]<<" "<<gwt[e2]<<" "<<ans;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

