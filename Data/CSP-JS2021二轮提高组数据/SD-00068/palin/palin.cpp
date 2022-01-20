#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
long long t,n,a[100005]={0},shu[100005]={0},j=1,ans=0;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		long long s=1,mmin=9999999999;
		for(long long i=1;i<=2*n;i++){
			cin>>a[i];
			s*=2;
		}
		for(long long i=1;i<=s;i++){
			long long as=i,bs=s;j=1;ans=0;
			while(bs!=1){
				bs/=2;
				if(as>bs){
					as=as-bs;
					shu[j]=1;
				}else{
					shu[j]=0;
				}
				j++;
			}
			long long lef=1,rig=2*n;
			for(long long z=1;z<=j-1;z++){
				if(shu[z]==0){
					ans*=10;
					ans+=a[lef];
					lef++;
				}else{
					ans*=10;
					ans+=a[rig];
					rig--;
				}
			}
			long long asdf[1005],anss=ans;
			for(long long z=1;z<=2*n;z++){
				asdf[z]=ans%10;
				ans/=10;
			}
			bool flag=1;
			for(long long z=1;z<=n;z++){
				if(asdf[z]!=asdf[2*n-z+1]){
					flag=0;
					break;
				}
			}
			if(flag==1&&anss<mmin){
				mmin=anss;
			}
			cout<<anss<<" "<<flag<<endl;
		}
		if(mmin==9999999999){
			cout<<-1<<endl;continue;
		}
		cout<<mmin<<endl;
		long long leftt=1,rightt=2*n;
		long long bsdf[1005];
		for(long long i=1;i<=2*n;i++){
			bsdf[i]=mmin%10;
			mmin/=10;
			cout<<a[i];
		}
		for(long long i=1;i<=2*n;i++){
			if(bsdf[i]==a[leftt]){
				cout<<"L";
				leftt++;
			}else{
				cout<<"R";
				rightt--;
			} 
			cout<<leftt<<rightt<<" ";
		}
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
