#include<iostream>
#include<cstdio>
#include<algorithm>
#include<memory.h>
using namespace std;
int n,m1,m2;
bool channel[105][100005]={0};
int china[100005][3],foreign[100005][3];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
    cin>>n>>m1>>m2;
    for(int i=1;i<=m1;i++)
        cin>>china[i][1]>>china[i][2];
    for(int i=1;i<m1;i++)
        for(int j=i+1;j<=m1;j++)
            if(china[i][1]>china[j][1]){
            	int t=china[i][1];china[i][1]=china[j][1];
            	china[j][1]=t;t=china[i][2];
            	china[i][2]=china[j][2];china[j][2]=t;
			}
    for(int i=1;i<=m2;i++)
        cin>>foreign[i][1]>>foreign[i][2];
    for(int i=1;i<m2;i++)
        for(int j=i+1;j<=m2;j++)
            if(foreign[i][1]>foreign[j][1]){
            	int t=foreign[i][1];foreign[i][1]=foreign[j][1];
            	foreign[j][1]=t;t=foreign[i][2];
            	foreign[i][2]=foreign[j][2];foreign[j][2]=t;
			}
    int maxn=-1;
    for(int i=0;i<=n;i++){
    	int c=i,f=n-i;
    	int ans=0;
		for(int j=1;j<=n;j++)
		    for(int k=1;k<=10005;k++)
		        channel[j][k]=0;
    	for(int j=1;j<=m1;j++){
    		bool t=true;
    		for(int k=1;k<=c&&t;k++)
    			if(channel[k][china[j][1]]==0){
    				ans++;
    				for(int l=china[j][1];l<=china[j][2];l++)
    				    channel[k][l]=1;
    				t=false;
				}
		}
		for(int j=1;j<=m2;j++){
			bool t=true;
			for(int k=c+1;k<=n&&t;k++)
				if(channel[k][foreign[j][1]]==0){
					ans++;
					for(int l=foreign[j][1];l<=foreign[j][2];l++)
					    channel[k][l]=1;
					t=false;
				}
		}
		if(ans>maxn) maxn=ans;
	}
	cout<<maxn<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

