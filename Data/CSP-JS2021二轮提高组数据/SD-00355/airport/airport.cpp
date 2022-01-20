#include<iostream>
#include<algorithm>
#include<cstdio>
#define R register
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') 
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

int max(int x,int y){
	return x>y?x:y;
}
struct node{
	int l,r;
}a1[100010],a2[100010];
bool cmp(node x,node y){
	return x.r<y.r;
}
int r1,r2,b1[100010],b2[10010];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n=read(),m1=read(),m2=read();
	for(R int i=1;i<=m1;i++){
		a1[i].l=read(),a1[i].r=read();
		r1=max(r1,a1[i].r);
		b1[a1[i].l]++;b1[a2[i].r+1]--;
	}
	for(R int i=1;i<=m2;i++){
		a2[i].l=read(),a2[i].r=read();
		r2=max(r2,a2[i].r);
		b2[a2[i].l]++;b2[a2[i].r+1]--;
	}
	for(R int i=1;i<=r1+1;i++)b1[i]+=b1[i-1];
	for(R int i=1;i<=r2+1;i++)b2[i]+=b2[i-1];
	sort(a1,a1+1+m1,cmp),sort(a2,a2+1+m2,cmp);
	sort(b1+1,b1+1+m1),sort(b2+1,b2+1+m2);
	int ans=(b2[1]+b1[2])>>1;
	printf("%d\n",ans);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
