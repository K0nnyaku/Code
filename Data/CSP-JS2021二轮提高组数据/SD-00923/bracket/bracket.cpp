#include <iostream>
#include <iomanip>
#include <cmath>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
char ch[509];
int mod=1e9+7;
char zhan[509];
int head=1,tail;
int ykh[509];
int ans;
int n,k;
int tot;
char xx[4]={'0','(',')','*'};
void find(int xu,int xin){
	if(xin>k)return;
	if(xu==n&&tail==0){
		ans++;
	}
	if(ch[xu]=='('){
		tail++;
		zhan[tail]='(';
		tot++;
		ykh[tot]=tail+1;
		find(xu+1,xin);
		tot--;
		tail--;
	}
	else if(ch[xu]==')'){
		int x=tail;
		tail=ykh[tot];
		tot--;
		find(xu+1,xin);
		tot++;
		tail=x;
	}
	else if(ch[xu]=='*'){
		tail++;
		zhan[tail]='*';
		find(xu+1,xin+1);
		tail--;
	}
	else if(ch[xu]=='?'){
		for(int i=1;i<=3;i++){
			ch[xu]=xx[i];
			find(xu,xin);
		}
		ch[xu]='?';
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>ch[i];
	}
	find(1,0);
	cout<<(ans%mod+mod)%mod;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

