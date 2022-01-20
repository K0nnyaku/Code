#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

bool cmp(int x,int y){
	return x>y;
}

int n,m1,m2;
int a1[100005],b1[100005],a2[100005],b2[100005];
int h,t,br1,br2,num[100005],ans,flag;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>a1[i]>>b1[i];
	}
	for(int i=1;i<=m2;i++){
		cin>>a2[i]>>b2[i];
	}
	for(int i=1;i<=m1;i++){
		if(a1[i]==0) continue;
		br1++;
		num[br1]=1;
		flag=0;
		for(int j=i+1;j<=m1;j++){
			if(flag==0){
				h=a1[i];
				t=b1[i];
			}
		//	cout<<a1[j]<<"  "<<t<<endl;
			if(a1[j]>=t) {
				t=b1[j];
				a1[j]=0;
				num[br1]++;
				flag=1;
			}
		}
	}
	flag=0;
	for(int i=1;i<=m2;i++){
		if(a2[i]==0) continue;
		br2++;
		num[br2+1+br1]=1;
		flag=0;
		for(int j=i+1;j<=m2;j++){
			if(flag==0){
				h=a2[i];
				t=b2[i];
			}
			
			if(a2[j]>=t) {
				t=b2[j];
				a2[j]=0;
				num[br2+1+br1]++;
				flag=1;
			}
		}
	}
	/*for(int i=1;i<=20;i++){
			//ans+=num[i];
			cout<<num[i]<<endl;
		}*/
	if(n>=br1+br2) cout<<m1+m2;
	else {
		sort(num+1,num+br1+br2+1,cmp);
		for(int i=1;i<=n;i++){
			ans+=num[i];
			//cout<<num[i]<<endl;
		}
		cout<<ans;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

