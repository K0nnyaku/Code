#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t;
int n;
int head,tail;
int a[1000005];
int ans[1000005]={0};
int c[1000005]={0};
int tong[1000005]={0};
int flag=0;
int cnt=1;
bool check(){
	for(int i=1;i<=n*2;i++){
		if(c[i]!=c[n*2+1-i]){
			return false;
		}
	}
	return true;
}
void print(){
	for(int i=1;i<=n*2;i++){
		if(ans[i]==-1){
			cout<<"L";
		}else{
			cout<<"R";
		}
	}
	cout<<endl;
}
void dfs(int dis){
	if(cnt<=n&&tong[cnt]>1){
		return;
	}
	if(flag==1){
		return;
	}
	if(cnt>n*2){
		if(check()){
			print();
			flag=1;
		}
		return;
	}
	if(dis==-1){
		c[cnt]=a[head];
		tong[a[head]]++;
		ans[cnt]=dis;
		head++;
		cnt++;
		
		dfs(-1);
		dfs(1);
		
		head--;
		
		tong[a[head]]--;
	
		cnt--;
		ans[cnt]=0;
		c[cnt]=0;
	}else{
		c[cnt]=a[tail];
		tong[a[tail]]++;
		ans[cnt]=dis;
		tail--;
		cnt++;
		
		dfs(-1);
		dfs(1);
		
		
		tail++;
		tong[a[tail]]--;
		cnt--;
		ans[cnt]=0;
		c[cnt]=0;
		
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--){
		memset(ans,0,sizeof(ans));
		memset(c,0,sizeof(c));
		memset(tong,0,sizeof(tong));
		flag=0;
		cin>>n;
		head=1;
		tail=n*2;
		for(int i=1;i<=n*2;i++){
			cin>>a[i];
		}
		dfs(-1);
		dfs(1);
		if(flag==0){
			cout<<-1<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
