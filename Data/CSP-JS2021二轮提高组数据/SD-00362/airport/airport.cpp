#include<bits/stdc++.h>
using namespace std;
int n,mm1,mm2;
int a1[1000001];
int b1[1000001];
int a2[1000001];
int b2[1000001];
int sum=0;
int maxn1[1000001];
int maxn2[1000001];
int ans=0,maxn3=-1,qq=0;
int minn1=100000001,minn2=10000001;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>mm1>>mm2;
	for(int i=1;i<=mm1;i++){
		cin>>a1[i]>>b1[i];
	}
	for(int i=1;i<=mm2;i++){
		cin>>a2[i]>>b2[i];
    }
    for(int i=0;i<=n;i++){
    	for(int j=n-i;j>=0;j--){
    		int k=i;
    		int h=j;
    		if(k>0||a1[i]>maxn1[ans++]){
				if(k>1){
					for(int y=0;y<=ans;y++){
						if(maxn1[y]<minn1) minn1=maxn1[y];
					}
					maxn1[ans++]=minn1;
				}
				else{
					maxn1[ans++]=b1[i];
				}
    			k--;
    			sum++;
			}
			if(h>0||a2[j]>maxn2[qq++]){
				if(h>1){
					for(int r=0;r<=qq;r++){
						if(maxn2[r]<minn2) minn2=maxn2[r];
					}
					maxn2[qq++]=minn2;
				}
				else{
					maxn2[qq++]=b2[i];
				}
				h--;
				sum++;
			}
		}
		if(sum>maxn3) maxn3=sum;
	}
	cout<<maxn3<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
