#include<iostream>
#include<cstdio> 
#include<algorithm>
#include<cstring>
#define MAXN 1000010
using namespace std;
int T,n;
int f[MAXN],vis[MAXN];
bool check()
{
	for(int i=1;i<=2*n;i++)
		if(f[i]!=f[2*n-i+1])
			return 0;
	return 1;
}
int t1,t2,t3;
int p;
void pre(int s)
{
	for(int i=1;i<=2*n;i++){
		if(s!=i&&f[i]==f[s]){
			t1=f[i-1];
			t2=f[i+1];
			t3=i;
			break;
		}
	}
}
char a[MAXN],b[MAXN];
int aa,bb;
void work(int s)
{
	//cout<<s<<' ';
	vis[s]=1;
	if(aa==n*2)
		return;
	pre(s);
	if((f[s+1]==t1||f[s+1]==t2))
		a[++aa]='L',work(s+1);
	if(s==1)
		if((f[2*n]==t1||f[2*n]==t2))
			a[++aa]='R',work(2*n);
	if((f[s-1]==t1||f[s-1]==t2))
			a[++aa]='R',work(s-1);
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
			scanf("%d",&f[i]);
		if(check()){
			for(int i=1;i<=2*n;i++)
				cout<<"L";
			cout<<endl;
		}
		else{
			aa=0;
			a[++aa]='L';
			work(1);
			for(int i=1;i<=aa;i++){
				if(a[i]!='L'&&a[i]!='R'){
					cout<<-1;
					break;
				}
			}
			for(int i=1;i<=aa;i++)
				cout<<a[i];
			cout<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
