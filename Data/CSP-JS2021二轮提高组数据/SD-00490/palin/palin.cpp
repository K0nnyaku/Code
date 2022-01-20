#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int num[500005];
char ans[500005];
int n,T,f=1,l,i;
void ac(int f,int l,int i){
	ans[i++]=num[f]<num[l]?'L':'R';
	ac(f+1,l-1,i+1);
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	for(int I=1;I<=T;++I){
		cin>>n;
		l=n;
		for(i=1;i<=n;++i){
			cin>>num[i];
		}
		i=1;
	}
	cout<<-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
