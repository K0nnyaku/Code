#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=10050;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct lsh{
	int p,num;
}l[N];
bool cmp(lsh x,lsh y){
	return x.p<y.p;
}
struct lq{
	int a,b;
}c[N];
bool cmp2(lq x,lq y){
	return x.a<y.a;
}
void clear_(){
	memset(l,0,sizeof(l));
	memset(c,0,sizeof(c));
}
int n,m1,m2,f1[N],f2[N],cf1[N],cf2[N],t[N],ans,lt;
int ck(int x){
	for(int i=1;i<=lt;i++)t[i]=0;
	int cnt=0,f=0,ll=1;
	for(int i=1;i<=lt;i++){
		f+=t[i];
		if(i==c[ll].a){
			if(f<x){
				f++;
				cnt++;
				t[c[ll].b+1]--;
			}
			ll++;
		}
	}
	return cnt;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=2*m1;i++){
		l[i].p=read();
		l[i].num=i+1;
	}
	sort(l+1,l+2*m1+1,cmp);
	lt=0;
	for(int i=1;i<=2*m1;i++){
		if(l[i].p!=l[i-1].p)lt++;
		if(l[i].num%2==0){
			c[l[i].num/2].a=lt;
		}
		else c[l[i].num/2].b=lt;
	}
	sort(c+1,c+m1+1,cmp2);
	for(int i=1;i<=n;i++){
		f1[i]=ck(i);
	}
	clear_();
	for(int i=1;i<=2*m2;i++){
		l[i].p=read();
		l[i].num=i+1;
	}
	sort(l+1,l+2*m2+1,cmp);
	lt=0;
	for(int i=1;i<=2*m2;i++){
		if(l[i].p!=l[i-1].p)lt++;
		if(l[i].num%2==0){
			c[l[i].num/2].a=lt;
		}
		else c[l[i].num/2].b=lt;
	}
	sort(c+1,c+m2+1,cmp2);
	for(int i=1;i<=n;i++){
		f2[i]=ck(i);
	}
	for(int i=0;i<=n;i++){
		ans=max(ans,f1[i]+f2[n-i]);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
