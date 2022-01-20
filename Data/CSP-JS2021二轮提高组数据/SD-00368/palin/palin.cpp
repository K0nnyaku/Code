#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#define MAXN 1100

using namespace std;
bool np[MAXN];
int a[MAXN];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
	bool judgei=1;
		int n;
		cin>>n;
		for(int i=1;i<=2*n;i++){
			cin>>a[i];
		}
		for(int f=2*n;f>=0;f--){
			int s=2*n-f;
			for(int i=1;i<=f;i++){
				np[i]=0;
			}
			for(int i=f+1;i<=2*n;i++){
				np[i]=1;
			}
			
			do{
				int lin[MAXN];
				int l=1;
				int r=2*n;
				bool judge=1;
				for(int i=1;i<=2*n;i++){
					if(np[i]==0){
						lin[i]=a[l];
						l++;
					}
					else{
						lin[i]=a[r];
						r--;
					}
				}
				for(int i=1;i<=n;i++){
					if(lin[i]!=lin[2*n-i+1]){
						judge=0;
						break;
					}
				}
				if(!judge){
					continue;
				}
				for(int i=1;i<=n*2;i++){
					if(i==n*2){
						cout<<'L';
						break;
					}
					if(np[i]==0){
						cout<<'L';
					}else{
						cout<<'R';
					}
				}cout<<endl;
				judgei=0;
				break;
			}while(next_permutation(np+1,np+n+1));
			if(judgei==0)break;
		}
		if(judgei)cout<<-1<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
