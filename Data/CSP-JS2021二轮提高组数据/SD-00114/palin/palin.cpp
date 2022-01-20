//__frj SD-00114
//题目名，注释。保存，freopen
//不要想着A题，打暴力就行了！
//TIME +7min
//期望得分：28 
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>

#define ll long long
#define ull unsigned long long
using namespace std;
int read(){
	int s=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int a[1004],b[1004],T,n;
char c[1004];
bool p=0;
void dfs(int l,int r,int t){//填完了T个数 
	if(r<l||t>2*n){
		p=1;
		return;
	}
	if(t>n&&b[t]!=b[2*n+1-t]) return;
	c[t+1]='L';b[t+1]=a[l];dfs(l+1,r,t+1);
	if(p==1) return;
	c[t+1]='R';b[t+1]=a[r];dfs(l,r-1,t+1);
	return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	for(int i=1;i<=T;i++){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		p=0;
		n=read();
		for(int j=1;j<=2*n;j++){
			a[j]=read(); 
		}
		dfs(1,2*n,0);
		if(p==0) cout<<-1<<endl;
		else{
			for(int j=1;j<=2*n;j++){
				cout<<c[j];
			}
			cout<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//要开ll吗？会MLE吗？sizeof
//I AK CSP-S！


