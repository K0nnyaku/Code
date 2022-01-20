#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int inline read(){
	int s=0,t=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') t=-1;
		ch=getchar();
	} 
	while(ch>='0'&&ch<='9'){
		s=(s<<1)+(s<<3)+ch-'0';
		ch=getchar();
	} 
	return s*t;
} 
int const N=1e6+10;
int n,ma,mb,ans,res;
int ll,rr,cnt;
priority_queue<int>q; 
struct node{
	int l,r;
}a[N],b[N];
int cmp(node x,node y){
	return x.l<y.l;
}
int sola1(int k){
	if(k==0||ma==0) return 0;
	cnt=1,res=1;
	q.push(-a[1].r);//´æÊ±¿Ì 
	//if(k==10) cout<<a[1].r<<endl;
	for(int i=2;i<=ma;i++){
		int l=a[i].l,r=a[i].r;
		//if(k==10)cout<<l<<" "<<r<<endl;
		while(cnt!=0&&l>-q.top()) q.pop(),cnt--;
		if(cnt<k) q.push(-r),cnt++,res++;
	}
	//if(k==10) cout<<res<<endl;
	return res;
}
int solb1(int k){
	if(k==0||mb==0) return 0;
	cnt=1,res=1;
	q.push(-b[1].r);//´æÊ±¿Ì 
	for(int i=2;i<=mb;i++){
		int l=b[i].l,r=b[i].r;
		while(cnt!=0&&l>-q.top()) q.pop(),cnt--;
		if(cnt<k) q.push(-r),cnt++,res++;
	}
	return res;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>ma>>mb;
    for(int i=1;i<=ma;i++)
	    a[i].l=read(),a[i].r=read();
	for(int i=1;i<=mb;i++)
	    b[i].l=read(),b[i].r=read();
	sort(a+1,a+ma+1,cmp);
	sort(b+1,b+mb+1,cmp);
	for(int i=0;i<=n;i++){
        int x=sola1(i);
	    int y=solb1(n-i);
	    //cout<<i<<" "<<x<<" "<<y<<endl;
	    ans=max(ans,x+y);
	} 
	cout<<ans;
	
	return 0;
} 
