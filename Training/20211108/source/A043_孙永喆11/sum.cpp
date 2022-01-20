#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+9,_inf=-1e9-9;
int nums[101],ans=inf,n,k,c,start_,now_;
bool cmp1(int a,int b){
	return a<b;
}
bool cmp2(int a,int b){
	return a>b;
}
int a1[101],used[101];
int check1(){
	for(int i=1;i<=n;i++)
		a1[i]=nums[i];
	sort(a1+1,a1+1+n,cmp1);
	int num=0;
	for(int i=1;i<=n;i++){
		if(used[i]) continue;
		int cnt=1,minn=a1[i],maxn=a1[i],lasts=a1[i];
		used[i]=1;
		for(int j=i+1;j<=n && cnt<n/k;j++){
			if(used[j] || a1[j]==lasts) continue;
			used[j]=1;
			minn=min(minn,a1[j]);
			maxn=max(maxn,a1[j]);
			cnt++;
		}
		if(maxn==minn) return inf;
		num+=(maxn-minn);
	}
	return num;
}
int check2(){
	for(int i=1;i<=n;i++)
		a1[i]=nums[i],used[i]=0;
	sort(a1+1,a1+1+n,cmp2);
	int num=0;
	for(int i=1;i<=n;i++){
		if(used[i]) continue;
		int cnt=1,minn=a1[i],maxn=a1[i],lasts=a1[i];
		used[i]=1;
		for(int j=i+1;j<=n && cnt<n/k;j++){
			if(used[j] || a1[j]==lasts) continue;
			used[j]=1;
			minn=min(minn,a1[j]);
			maxn=max(maxn,a1[j]);
			cnt++;
		}
		if(maxn==minn) return inf;
		num+=(maxn-minn);
	}
	return num;
}
int a3[101];
int check3(){
	for(int i=1;i<=n;i++)
		a3[i]=nums[i];
	int num=0;
	sort(a3+1,a3+1+n,cmp1);
	for(int i=1;i<=c;i++){
		for(int j=i+c;j<=n;j+=c){
			if(a3[i]==a3[j] || a3[j]==a3[j-c]) return inf;
			if(j+k>n) num+=(a3[j]-a3[i]);
		}
	}
	return num;
}
int main()
{
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	cin>>n>>k;
	c=n/k;
	for(int i=1;i<=n;i++)
		cin>>nums[i];
	ans=min(ans,check1());
	ans=min(ans,check2());
	ans=min(ans,check3());
	cout<<ans<<endl;
	return 0;
}
