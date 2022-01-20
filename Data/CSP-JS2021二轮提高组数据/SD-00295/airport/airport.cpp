#include<bits/stdc++.h>
#define il inline
#define POS(i,l,r) for(int i=l;i<=r;i++)
#define REV(i,l,r) for(int i=r;i>=l;i--)
using namespace std;
int read(){
	int ans=0,fl=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')fl=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		ans=(ans<<1)+(ans<<3)+(ch^48);
		ch=getchar();
	}
	return ans*fl;
}
int n,m1,m2;
struct airp{
	int a,b;
}inc[100010],outc[100010];
int end1[100010],end2[100010];
int ans1[100010],ans2[100010];
int sum1[100010],sum2[100010];
int cnt1,cnt2;
int min1=2e9,min2=2e9,max1,max2;
bool cmp(airp x,airp y){
	return x.a<y.a;
}
int ans;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();
	m1=read(),m2=read();
	for(int i=1;i<=m1;i++){
		inc[i].a=read();
		inc[i].b=read();
		min1=min(min1,inc[i].b);
		max1=max(max1,inc[i].a);
	}
	if(min1>max1){
		for(int i=1;i<=n;i++){
			sum1[i]=sum1[i-1]+1;
		}
		goto THR;
	}
	
	sort(inc+1,inc+m1+1,cmp);
	for(int i=1;i<=m1;i++){
		for(int j=1;j<=cnt1;j++){
			if(end1[j]<=inc[i].a){
				//cout<<j<<endl;
				ans1[j]++;
				end1[j]=inc[i].b;
				goto Here;
			}
		}
		cnt1++;
		ans1[cnt1]=1;
		end1[cnt1]=inc[i].b;
		Here:;
	}
	THR:;
	for(int i=1;i<=m2;i++){
		outc[i].a=read();
		outc[i].b=read();
		min2=min(min2,outc[i].b);
		max2=max(max2,outc[i].a);
	}
	if(min2>max2){
		for(int i=1;i<=n;i++){
			sum2[i]=sum2[i-1]+1;
		}
		goto THRER;
	}
	sort(outc+1,outc+m2+1,cmp);
	for(int i=1;i<=m2;i++){
		for(int j=1;j<=cnt2;j++){
			if(end2[j]<=outc[i].a){
				ans2[j]++;
				end2[j]=outc[i].b;
				goto Heree;
			}
		}
		cnt2++;
		ans2[cnt2]=1;
		end2[cnt2]=outc[i].b;
		Heree:;
	}
	THRER:;
	for(int i=1;i<=m1;i++){
		sum1[i]=sum1[i-1]+ans1[i];
	}
	for(int i=1;i<=m2;i++){
		sum2[i]=sum2[i-1]+ans2[i];
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,sum1[i]+sum2[n-i]);
	}
	cout<<ans;
	return 0;
}


