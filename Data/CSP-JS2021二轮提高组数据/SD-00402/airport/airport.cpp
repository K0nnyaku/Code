#include <bits/stdc++.h>
using namespace std;
const int N=5050;
int n,m1,m2; 
bool vis[N*2];
struct node{
	int start,end,i;
}a1[2*N],a2[2*N],a[N],b[N];
bool cmp(node a,node b){
	return a.start<b.start;
}
map<int,int> map1,map2;
//wjl hhk 
//n log n ÄæÐò¶Ô£¿ 
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);

	cin>>n>>m1>>m2;
	//input 1
	for(int i=1;i<=2*m1;i++){
		scanf("%d",&a1[i].start);
		a1[i].i=(i+1)/2;
	}
	sort(a1+1,a1+1+m1*2,cmp);
	int cnt=0;
	for(int i=1;i<=2*m1;i++){
		if(vis[a1[i].i]==0){
			a[a1[i].i].start=++cnt;
			vis[a1[i].i]=1;
		}else{
			a[a1[i].i].end=++cnt;
		}
	}
	sort(a+1,a+1+m1,cmp);
	
	
	//input 2
	memset(vis,0,sizeof vis);
	for(int i=1;i<=2*m2;i++){
		scanf("%d",&a2[i].start);
		a2[i].i=(i+1)/2;
	}
	sort(a2+1,a2+1+m2*2,cmp);
	cnt=0;
	for(int i=1;i<=2*m2;i++){
		if(vis[a2[i].i]==0){
			b[a2[i].i].start=++cnt;
			vis[a2[i].i]=1;
		}else{
			b[a2[i].i].end=++cnt;
		}
	}
	sort(b+1,b+1+m2,cmp);
	for(int i=1;i<=m1;i++){
		map1[a[i].start]=a[i].end;
		map1[a[i].end]=0;
	}
	for(int i=1;i<=m2;i++){
		map2[b[i].start]=b[i].end;
		map2[b[i].end]=0;
	}
	
	
	int ans=-1,nei=0,wai=0,sum1=0,sum2=0;
	for(int i=0;i<=n;i++){
		nei=i,wai=n-i;
		memset(vis,0,sizeof vis);
		sum1=0,sum2=0;
		for(int j=1;j<=2*m1;j++){
			if(vis[j]==1){
				nei++;
			}
			if(map1[j]==0){
				continue;
			}
			if(nei){
				sum1++;
				nei--;
				vis[map1[j]]=1;
			}			
		}
		
		memset(vis,0,sizeof vis);
		for(int j=1;j<=2*m2;j++){
			if(vis[j]==1){
				wai++;
			}
			if(map2[j]==0){
				continue;
			}
			if(wai){
				sum2++;
				wai--;
				vis[map2[j]]=1;
			}			
		}
		ans=max(ans,sum1+sum2);
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
