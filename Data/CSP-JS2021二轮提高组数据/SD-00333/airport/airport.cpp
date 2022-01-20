#include<bits/stdc++.h>
using namespace std;
inline int rread(){
	int x=0;
	char c=getchar(),o=' ';
	while(c<'0'||c>'9')o=c,c=getchar();
	while(c>='0'&&c<='9')x=x*10+(c^48),c=getchar();
	if(o=='-')x=~x+1;
	return x; 
}
struct node{
	int l,r;
}a[100001],b[10001];
bool operator <(const node& x,const node& y){
	return x.r==y.r?x.l<y.l:x.r<y.r;
}
int n,m1,m2;
int lst[100001];
inline int check(int x){
	int ans=0;
	memset(lst,0,sizeof lst);
	lst[0]=0x3fffffff;
	int j,len;
	if(x){
		j=0;
		len=0;
		for(int i=1;i<=m1;i++){
			if(lst[j]<=a[i].l){
//				cout<<lst[j]<<' '<<a[i].l<<' '<<a[i].r<<' '<<j<<'\n';
				lst[j]=a[i].r;
				j++;
				if(j>len)j=1;
				ans++;
			}else if(len<x){
//				cout<<a[i].l<<' '<<a[i].r<<' '<<len+1<<'\n';
				lst[++len]=a[i].r;
				ans++;
				if(len==1)j=1;
			}
		}
	}
//	cout<<'\n';
	memset(lst,0,sizeof lst);
	lst[0]=0x3fffffff;
	if(n-x>0){
		j=0;
		len=0;
		for(int i=1;i<=m2;i++){
			if(lst[j]<=b[i].l){
//				cout<<lst[j]<<' '<<b[i].l<<' '<<b[i].r<<' '<<j<<'\n';
				lst[j]=b[i].r;
				j++;
				if(j>len)j=1;
				ans++;
//				cout<<j<<' '<<lst[j]<<' '<<b[i+1].l<<' '<<b[i+1].r<<'\n';
			}else if(len<n-x){
//				cout<<b[i].l<<' '<<b[i].r<<' '<<len+1<<'\n';
				lst[++len]=b[i].r;
				ans++;
				if(len==1)j=1;
			}
		}
	}
//	cout<<"!"<<ans<<'\n';
	return ans;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout); 
	n=rread();
	m1=rread();
	m2=rread();
	for(int i=1;i<=m1;i++){
		a[i]=(node){rread(),rread()};
	}
	for(int i=1;i<=m2;i++){
		b[i]=(node){rread(),rread()};
	}
	sort(a+1,a+1+m1);
	sort(b+1,b+1+m2);
//	for(int i=1;i<=m1;i++){
//		cout<<a[i].l<<' '<<a[i].r<<'\n';
//	}
//	cout<<endl;
//	for(int i=1;i<=m2;i++){
//		cout<<b[i].l<<' '<<b[i].r<<'\n';
//	}
//	cout<<endl;
//	for(int i=0;i<=n;i++){
//		cout<<"!!! "<<check(i)<<'\n';
//	}
	int l=0,r=n;
	while(l<r){
//		cout<<l<<' '<<r<<'\n';
		int lm=l+(r-l+1)/3;
		int rm=r-(r-l+1)/3;
		if(check(lm)<=check(rm)){
			l=lm+1;
		}else{
			r=rm-1;
		}
	}
	cout<<check(l)<<'\n';
	return 0;
}

