#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T;
int n;
int a[500005];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		for(int i=1;i<=n;i++)
			a[i]=0; 
		for(int i=1;i<=2*n;i++){
			cin>>a[i];
		}
		int flag=1;
		for(int i=1;i<=n;i++){
			if(a[i]==a[2*n+1-i])
				continue;
			else{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			for(int i=1;i<=n;i++)
				cout<<"LL";
		}
		else
		cout<<-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
