#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
using namespace std;
const int MAXN=5e5+55;
struct data{
	int id;
	int number;
	int toid;
} a[MAXN];
int n,stacks[MAXN],tops;
string sl,sr;
bool used[MAXN];
bool cmp1(data x,data y){
	return x.number<y.number;
}
bool cmp2(data x,data y){
	return x.id<y.id;
}
bool dfs_left(){
	tops=0;
	memset(used,0,sizeof(used));
	sl="";
	int l=a[1].toid,r=a[1].toid,lf=2,rf=2*n,cnt=0;
	bool flag=1;
	sl+="L";
	stacks[tops++]=a[1].number;
	while(cnt<n-1){
		if(a[lf].toid==l-1 && used[a[lf].number]==0){
			stacks[tops++]=a[lf].number;used[a[lf].number]=1;
			sl+="L";lf++;cnt++;l--;
			continue;
		}
		if(a[lf].toid==r+1 && used[a[lf].number]==0){
			stacks[tops++]=a[lf].number;used[a[lf].number]=1;
			sl+="L";lf++;cnt++;r++;
			continue;
		}
		if(a[rf].toid==l-1 && used[a[rf].number]==0){
			stacks[tops++]=a[rf].number;used[a[rf].number]=1;
			sl+="R";rf--;cnt++;l--;
			continue;
		}
		if(a[rf].toid==r+1 && used[a[rf].number]==0){
			stacks[tops++]=a[rf].number;used[a[rf].number]=1;
			sl+="R";rf--;cnt++;r++;
			continue;
		}
		return 0;
	}
	for(int i=tops-1;i>=0;i--){
		int u=stacks[i];
//		cout<<u<<endl;
		if(u==a[lf].number){
			sl+="L";lf++;
			continue;
		}
		if(u==a[rf].number){
			sl+="R";rf--;
			continue;
		}
		return 0;
	}
	
	return 1;
}
bool dfs_right(){
	tops=0;
	memset(used,0,sizeof(used));
	sr="";
	int l=a[2*n].toid,r=a[2*n].toid,lf=1,rf=2*n-1,cnt=0;
	bool flag=1;
	sr+="R";
	stacks[tops++]=a[2*n].number;
	while(cnt<n-1){
		if(a[lf].toid==l-1 && used[a[lf].number]==0){
			stacks[tops++]=a[lf].number;used[a[lf].number]=1;
			sr+="L";lf++;cnt++;l--;
			continue;
		}
		if(a[lf].toid==r+1 && used[a[lf].number]==0){
			stacks[tops++]=a[lf].number;used[a[lf].number]=1;
			sr+="L";lf++;cnt++;r++;
			continue;
		}
		if(a[rf].toid==l-1 && used[a[rf].number]==0){
			stacks[tops++]=a[rf].number;used[a[rf].number]=1;
			sr+="R";rf--;cnt++;l--;
			continue;
		}
		if(a[rf].toid==r+1 && used[a[rf].number]==0){
			stacks[tops++]=a[rf].number;used[a[rf].number]=1;
			sr+="R";rf--;cnt++;r++;
			continue;
		}
		return 0;
	}
	for(int i=tops-1;i>=0;i--){
		int u=stacks[i];
//		cout<<u<<endl;
		if(u==a[lf].number){
			sr+="L";lf++;
			continue;
		}
		if(u==a[rf].number){
			sr+="R";rf--;
			continue;
		}
		return 0;
	}
	
	return 1;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=2*n;i++){
			a[i].id=i;
			cin>>a[i].number;
		}
		sort(a+1,a+1+2*n,cmp1);
		for(int i=1;i<=2*n;i+=2){
			a[i].toid=a[i+1].id;
			a[i+1].toid=a[i].id;
		}
		sort(a+1,a+1+2*n,cmp2);
//		for(int i=1;i<=2*n;i++)
//			cout<<a[i].toid<<" ";cout<<endl;
		bool flag1=dfs_left();
		bool flag2=dfs_right();
		if(flag1 && flag2){
			cout<<sl<<endl;
			continue;
		}
		if(flag1){
			cout<<sl<<endl;
			continue;
		}
		if(flag2){
			cout<<sr<<endl;
			continue;
		}
		cout<<-1<<endl;
	}
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3

*/
