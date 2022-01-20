#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int vis[N];
int nums[N]={0};
bool cmp(string x,string y){
	if(x.size()!=y.size()) return x.size()<y.size();
	int lenh=x.size();
	for(int i=0;i<lenh;i++){
		if(x[i]!=y[i]) return ((int)x[i]) < ((int)y[i]);
	}
}
int tot=0;
string ans[2050];
int n;
bool check(int nu[],string s){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(nu[i]==nu[2*n-i+1])sum++;
	}	

	if(sum==n){
		ans[++tot]=s;	
		return 1;	
	}
	else return 0; 
}
void sc(int nuu[],int laan,int l,int r,string cz){
	if(laan==2*n){
		check(nuu,cz);	
		return;
	}
	laan=laan+1;
	nuu[laan]=nums[l];
	sc(nuu,laan,l+1,r,cz+"L");
	nuu[laan]=nums[r];
	sc(nuu,laan,l,r-1,cz+"R");
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int q;
	cin>>q;
	while(q--){
		string s;
	//	memset(ans,0,sizeof(ans));
		for(int i=1;i<=tot;i++){
			ans[i]="";
		}
		tot=0;
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++)
			scanf("%d",&nums[i]);
		int nnn[1000]={0};
		sc(nnn,0,1,2*n,"");
		sort(ans+1,ans+tot+1,cmp);
		if(ans[1].size()==0){
			cout<<"-1"<<endl;
		}
		else cout<<ans[1]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

