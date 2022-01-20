#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100010;
int n,m1,m2,tmp[maxn],cnt,cnt_,a1[maxn],a2[maxn],b1[maxn],b2[maxn],mx=0,Ans=-1,nxt1[maxn],nxt2[maxn];
void work(int *d,int len){
	for(int i=1;i<=len;++i) 
		d[i]=lower_bound(tmp+1,tmp+cnt+1,d[i])-tmp,mx=max(mx,d[i]);
}
int f1[maxn],f2[maxn],in1[maxn],in2[maxn],out1[maxn],out2[maxn];
int in1_[maxn],in2_[maxn],out1_[maxn],out2_[maxn];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;++i) cin>>a1[i]>>b1[i],tmp[++cnt_]=a1[i],tmp[++cnt_]=b1[i];
	for(int i=1;i<=m2;++i) cin>>a2[i]>>b2[i],tmp[++cnt_]=a2[i],tmp[++cnt_]=b2[i];
	sort(tmp+1,tmp+cnt_+1);
	cnt=unique(tmp+1,tmp+cnt_+1)-(tmp+1);
	work(a1,m1),work(b1,m1),work(a2,m2),work(b2,m2);
	for(int i=1;i<=m1;++i) in1_[a1[i]]=1,out1_[b1[i]]=1,in1[a1[i]]=1,out1[b1[i]]=1,nxt1[a1[i]]=b1[i];
	for(int i=1;i<=m2;++i) in2_[a2[i]]=1,out2_[b2[i]]=1,in2[a2[i]]=1,out2[b2[i]]=1,nxt2[a2[i]]=b2[i];
	for(int i=0;i<=n;++i){
		for(int j=1;j<=mx;++j) 
			in1[j]=in1_[j],out1[j]=out1_[j],in2[j]=in2_[j],out2[j]=out2_[j];
		int now=0,ans1=0,ans2=0;
		for(int j=1;j<=mx;++j){
			if(in1[j]){
				if(now<i) ans1++,now++;
				else out1[nxt1[j]]=0;
			}
			if(out1[j]) now--;
		} 
		now=0;
		for(int j=1;j<=mx;++j){
			if(in2[j]){
				if(now<n-i) ans2++,now++;
				else out2[nxt2[j]]=0;
			}
			if(out2[j]) now--;
		} 
		Ans=max(Ans,ans1+ans2);		
	}
	cout<<Ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
