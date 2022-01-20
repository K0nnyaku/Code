#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int N=1000000;
int n,m1,m2;
struct han{
	int q,z;
};
han u[1000000];
bool cmp(han a,han b){
	return a.q<b.q;
}
int sg[1000000];
int s[1000000];
int t[1000000];
void clear(int w,int l,int r){
	t[w]=0;
	if(l==r)return;int mi=(l+r)/2;
	clear(w*2,l,mi);
	clear(w*2+1,mi+1,r); 
}
void add(int w,int l,int r,int c,int k){
	if(r<c||c<l)return;
	if(l==r){
		t[w]=k;return;
	}
	int mi=(l+r)/2;
	add(w*2,l,mi,c,k);
	add(w*2+1,mi+1,r,c,k);
	t[w]=min(t[w*2],t[w*2+1]);
}
int cha(int w,int l,int r,int cr,int o){
	if(cr<l||t[w]>o)return -1;
	if(l==r)return l;
	int mi=(l+r)/2;
	int k=cha(w*2,l,mi,cr,o);
	if(k==-1)return cha(w*2+1,mi+1,r,cr,o);
	else return k;
}

int main(){
	FILE *asdf,*asd;
	asdf=freopen("airport.in","r",stdin);
	asd=freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>u[i].q>>u[i].z;
	}
	sort(u+1,u+1+m1,cmp);
	int gs=0;
	for(int i=1;i<=m1;i++){
		int k1=cha(1,1,n,gs,u[i].q);
		if(k1==-1)k1=++gs;	
		add(1,1,n,k1,u[i].z);
		sg[k1]++;
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+sg[i];sg[i]=0;
	}
	clear(1,1,n);
	for(int i=1;i<=m2;i++){
		cin>>u[i].q>>u[i].z;
	}
	sort(u+1,u+1+m2,cmp);
	gs=0;
	for(int i=1;i<=m2;i++){
		int k1=cha(1,1,n,gs,u[i].q);
		if(k1==-1)k1=++gs;	
		add(1,1,n,k1,u[i].z);
		sg[k1]++;
	}
	int now=0,ans=0;
	for(int i=0;i<=n;i++){
		now+=sg[i];
		ans=max(ans,now+s[n-i]);
	}
	cout<<ans;
	fclose(asdf);fclose(asd);
	return 0;
} 
