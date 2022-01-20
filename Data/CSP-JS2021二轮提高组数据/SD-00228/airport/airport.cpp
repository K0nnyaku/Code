//1
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct pl{
	int s,l;
}gn[100005],gw[100005];
int q[100005],n,m1,m2,ans;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}
void print(int x){
	if(x<0)putchar('-'),x=~x+1;
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
bool cmp(pl a,pl b){
	return a.s<b.s;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	if(n>=m1+m2){
		print(m1+m2);
		return 0;
	}
	for(int i=1;i<=m1;i++)gn[i].s=read(),gn[i].l=read();
	sort(gn+1,gn+m1+1,cmp);
	for(int i=1;i<=m2;i++)gw[i].s=read(),gw[i].l=read();
	sort(gw+1,gw+m2+1,cmp);
	for(int i=0;i<=n;i++){
		int g1=i,g2=n-i,t=0;
		if(g1!=0){
			for(int j=1;j<=g1;j++)q[j]=j,t++;
			for(int j=g1+1;j<=m1;j++)
				for(int k=1;k<=g1;k++)
					if(gn[q[k]].l<gn[j].s){
						q[k]=j;
						t++;
						break;
					}
		}
		if(g2!=0){
			for(int j=1;j<=g2;j++)q[j]=j,t++;
			for(int j=n-i+1;j<=m2;j++){
				for(int k=1;k<=g2;k++)
					if(gw[q[k]].l<gw[j].s){
						q[k]=j;
						t++;
						break;
					}
			}
		}
		ans=max(ans,t);	
	}
	print(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
