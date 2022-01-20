#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define LL long long
#define f1(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
int n,t,k,head,r,tail,a[100009],b[100009],rr;
char dd[100009];
int check(){
	for(int i=1,j=2*n;i<=2*n;i++,j--)
		if(b[i]!=b[j])return 0;
	return 1;
}
int dfs(int d){
	if(rr)return 0;
	if(check()&&k==n*2){
		for(int i=1;i<=d;i++)
		cout<<dd[i];rr=1;
		cout<<endl;
		return 0;
	}if(k==n*2)return 0;
	if(head>tail)return 0;
	k++;
	b[k]=a[head];head++;
	dd[d]='L';
	dfs(d+1);
	head--;
	k--;b[k+1]=0;
	if(head>tail)return 0;
	b[++k]=a[tail];tail--;
	dd[d]='R';
	dfs(d+1);
	tail++;k--;b[k+1]=0;
}
int main(){
    freopen("palin.in","r",stdin);
    freopen("palin.out","w",stdout);
	cin>>t;
	while(t--){
		rr=0;
		cin>>n;head=1;tail=2*n;
		for(int i=1;i<=2*n;i++)
			scanf("%d",&a[i]);
		dfs(1);
		if(!rr)cout<<-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

