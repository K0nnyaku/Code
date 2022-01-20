#include<bits/stdc++.h>
using namespace std;
long long read(){
	int k=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')k=-1;
		ch=getchar();
	} 
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return k*x;
}
int t,n,a[500005],k;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	while(t--){
		k=0;
		n=read();
		for(int i=1;i<=2*n;i++){
			a[i]=read();
			if(a[i]==a[i-1])k++;
			
		}
		if(k>2){
			cout<<"-1"<<endl;
		}
		else if(a[1]!=a[2]&&a[2*n]!=a[2*n-1]&&k==2){
			cout<<"-1"<<endl;
		}
		else if(k==1){
			for(int i=1;i<=2*n;i++){
				cout<<"L";
			}
			cout<<endl;
		}
		else if(a[1]==a[2]){
			cout<<"L";
			for(int i=1;i<2*n;i++)cout<<"R";
			cout<<endl;
		}
		else if(a[2*n]==a[2*n-1]){
			cout<<"R";
			for(int i=1;i<2*n;i++)cout<<"L";
			cout<<endl;
		}
	}
	return 0;
}
