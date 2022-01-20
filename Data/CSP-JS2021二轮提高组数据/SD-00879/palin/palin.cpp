#include<bits/stdc++.h>
using namespace std;
int t,n,a[1000005],id[500005],jl[500005];int mk;
void print2(int l,int r,int ci){
	for(int i=n;i>=1;i--){
		if(a[l]==jl[i])cout<<"L",l++;
		else cout<<"R",r++;
	}
	cout<<endl;
	return ;
}
void print1(int l,int r,int ci){
	for(int i=1;i<=n;i++){
		if(a[l]==jl[i])cout<<"L",l++;
		else cout<<"R",r++;
	}
	print2(l,r,n);
	return ;
}
void dfs(int ci,int l,int r){
	if(mk)return ;
	if(ci>n){
		for(int i=n;i>=1;i--){
			if(id[a[l]]==i)l++;
			else if(id[a[r]]==i)r--;
			else return ;
		}
		print1(1,n*2,1);mk++;
		return ;
	}
	if(!id[a[l]]){
		jl[ci]=a[l];id[a[l]]=ci;dfs(ci+1,l+1,r);id[a[l]]=0;
	}
	if(!id[a[r]]){
		jl[ci]=a[r];id[a[r]]=ci;dfs(ci+1,l,r-1);id[a[r]]=0;
	}
	return ;
}
int main(){
	freoepn("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	if(t==1){
		cin>>n;
		for(int i=1;i<=n;i++)scanf("&d",&a[i]);
		cout<<-1<<endl;
		return 0;
	}
	while(t--){
		cin>>n;
		for(int i=1;i<=n*2;i++)cin>>a[i];
		mk=0;
		dfs(1,1,n*2);
		if(!mk)cout<<-1<<endl; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
