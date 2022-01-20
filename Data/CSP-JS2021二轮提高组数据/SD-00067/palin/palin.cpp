#include<bits/stdc++.h>
using namespace std;
int m,T,now,l,r;
map<int,int>mp[101];
int a[1000000],b[1000000];
int cz[1000000],czw[1000000];
void dfs(int now){
	if(l==r){
		for(int i=1;i<=m;i++){
			if(czw[i]>cz[i]){
				for(int k=1;k<=2*m;k++){
					cz[k]=czw[k];
				}
				return;
			}
		}
		return;
	}
	for(int i=1;i<=2;i++){
		if(i==1){
			if(mp[T][a[++l]]!=now+1&&mp[T][a[i]]){
				l--;
				continue;
			}
			b[++now]=a[l];
			mp[T][a[l]]=2*m+1-now;
			dfs(now);
			mp[T][a[l]]=0;
			l--;now--;
			//cout<<"L";
		}
		if(i==2){
			if(mp[T][a[--r]]!=now+1&&mp[T][a[i]]){
				r++;
				continue;
			}
			b[++now]=a[r];
			mp[T][a[r]]=2*m+1-now;
			dfs(now);
			mp[T][a[l]]=0;
			r++;now--;
			//cout<<"R";
		}
	}
	return;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>m;
		l=0;
		r=2*m+1;
		for(int i=1;i<=2*m;i++){
			scanf("%d",&a[i]);
		}
		dfs(now);
		if(cz[1]==0)cout<<-1;
		else for(int i=1;i<=2*m;i++){
				if(cz[i]==1)cout<<"L";
				else cout<<"R";
			}
		cout<<endl;
		for(int i=1;i<=2*m;i++)cout<<b[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

