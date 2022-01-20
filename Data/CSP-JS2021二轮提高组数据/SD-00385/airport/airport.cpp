#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int read(){
	int f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar(); 
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}
int n,m1,m2,lisan[100001],cnt=0,tree[100001],q[100001];
struct air{
	int bg,en;
	friend bool operator <(air a,air b){
		return a.bg<b.bg;
	}
}a[100001],b[100001];
int lowbit(int x){
	return x&-x;
} 
void add(int now,int ad){
	for(int i=now;i<=cnt;i+=lowbit(i)){
		tree[i]+=ad;
	}
}
int query(int now){
	int res=0;
	for(int i=now;i;i-=lowbit(i)){
		res+=tree[i];
	}
	return res;
}
int check1(int mid){
	int ans=0;
	q[0]=0;
	for(int i=1;i<=m1;i++){
		int temp=query(cnt)-query(a[i].bg-1);
		if(temp<mid){
			add(a[i].en,1);
			q[++q[0]]=a[i].en;
			ans++;
		}
	}
	for(int i=1;i<=q[0];i++){
		add(q[i],-1);
	}
	return ans;
}
int check2(int mid){
	int ans=0;
	q[0]=0;
	for(int i=1;i<=m2;i++){
		int temp=query(cnt)-query(b[i].bg-1);
		if(temp<mid){
			add(b[i].en,1);
			q[++q[0]]=b[i].en;
			ans++;
		}
	}
	for(int i=1;i<=q[0];i++){
		add(q[i],-1);
	}
	return ans;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++){
		a[i].bg=read(),a[i].en=read();
		lisan[++cnt]=a[i].bg,lisan[++cnt]=a[i].en;
	}
	for(int i=1;i<=m2;i++){
		b[i].bg=read(),b[i].en=read();
		lisan[++cnt]=b[i].bg,lisan[++cnt]=b[i].en;
	}
	sort(lisan+1,lisan+1+cnt);
	sort(a+1,a+1+m1);
	sort(b+1,b+1+m2);
	for(int i=1;i<=m1;i++){
		a[i].bg=lower_bound(lisan+1,lisan+1+cnt,a[i].bg)-lisan;
		a[i].en=lower_bound(lisan+1,lisan+1+cnt,a[i].en)-lisan;
	}
	for(int i=1;i<=m2;i++){
		b[i].bg=lower_bound(lisan+1,lisan+1+cnt,b[i].bg)-lisan;
		b[i].en=lower_bound(lisan+1,lisan+1+cnt,b[i].en)-lisan;
	}
	int l=0,r=n,mid=n/2,ans=0,nowon;
	while(l<mid&&mid<r){
		int mmid=(l+mid)/2,mmid1=(mid+r)/2;
		int temp1=check1(mmid)+check2(n-mmid),temp2=check1(mmid1)+check2(n-mmid1);
		if(temp1>temp2){
			ans=temp1;
			nowon=mmid;
			r=mid;
			mid=(l+r)/2;
		}else{
			ans=temp2;
			nowon=mmid1;
			l=mid;
			mid=(l+r)/2;
		}
	}
	l=max(nowon-5,0),r=min(nowon+5,n);
	for(int i=l;i<=r;i++){
		ans=max(ans,check1(i)+check2(n-i));
	}
//	for(int i=0;i<=n;i++){
//		ans=max(ans,check1(i)+check2(n-i));
//	}	//cout<<check1(i)<<" "<<check2(n-i)<<" "<<i<<endl;
//	
	cout<<ans;
	return 0;
}
