#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T,n;
char record[1000010];
int a[1000010];
bool flag=false;
int pow_mod(int a,int b){
	long long res=1;
	while(b>0){
		if(b&1){
			res=res*a; 
		}
		a=a*a;
		b>>=1;
	}
	return res;
}

bool judge(int x){
	int temp=x;
	int c=0;
	while(temp>0){
		c=c*10+(temp%10);
		temp/=10;
	}
	if(c==x){
		return true;
	}else{
		return false;
	}
}

void dfs(int size,int x,int front,int l,int r){
	if(l==r){
		if(judge(x)){
			for(int i=1;i<=2*n;i++){
				cout<<record[i]<<" ";
			}
			flag=true;
		}
	}
	if(flag){
		return;
	}
	if(l<1||r<1||l>r){
		return;
	}
	if(size==0&&x==0&&front==0){
		if(a[l]>a[r]){
			record[size]='R';
			dfs(size+1,x*10+a[r],a[r],l,r-1);
			record[size]='L';
		    dfs(size+1,a[l]*pow_mod(10,size)+x,a[l],l+1,r);
		}else{
			record[size]='L';
			dfs(size+1,a[l]*pow_mod(10,size)+x,a[l],l+1,r);
			record[size]='R';
		    dfs(size+1,x*10+a[r],a[r],l,r-1);
		}
	}
	if(front<a[l]){
		record[size]='R';
		dfs(size+1,x*10+a[r],front,l,r-1);
		record[size]='L';
		dfs(size+1,a[l]*pow_mod(10,size)+x,a[l],l+1,r);
	}else{
		record[size]='L';
		dfs(size+1,a[l]*pow_mod(10,size)+x,a[l],l+1,r);
		record[size]='R';
		dfs(size+1,x*10+a[r],front,l,r-1);
	}
	return;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		memset(record,'0',sizeof(record));
		flag=false;
		for(int i=1;i<=2*n;i++){
			cin>>a[i];
		}
		dfs(0,0,0,1,2*n);
		if(!flag){
			cout<<-1<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
