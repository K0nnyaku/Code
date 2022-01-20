#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int a[10000000];
int d[10000000];
int b[10000000];
string ca;
int main(){
	FILE *asdf,*asd;
	asd=freopen("palin.in","r",stdin);
	asdf=freopen("palin.out","w",stdout);
	int te;cin>>te;
	for(int op=1;op<=te;op++){
		int n;cin>>n;
		for(int i=1;i<=2*n;i++){
			cin>>a[i];
		}
		int ko=1,ok=1;
		for(int i=0;i<(1<<(2*n))&&ko;i++){
			int l=1,r=2*n,tt=0;ok=1;
			for(int k=2*n-1;k!=-1;k--){
				tt=2*n-k;
				if((1<<k)&i)b[tt]=a[r--];
				else b[tt]=a[l++];
				if(k<n&&b[k+1]!=b[tt]){
					ok=0;break;
				}
				//for(int i=1;i<=2*n;i++)cout<<b[i]<<" ";cout<<endl;
			}
			if(ok!=0){
				for(int k=2*n-1;k!=-1;k--){
					if((1<<k)&i)cout<<"R"; 
					else cout<<"L";		
				}
				ko=0;cout<<endl;
				break;
			}
		} 
		if(ko)cout<<"-1"<<endl;
	}
	fclose(asdf);fclose(asd);
	return 0;
} 
