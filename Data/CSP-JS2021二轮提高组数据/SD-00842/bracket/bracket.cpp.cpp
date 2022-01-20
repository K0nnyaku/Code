#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod_=1e9+7;
int m,k;
char a[600];
short z[600];
int ans,num;
bool pd_(int head,int tail){
	int i,j;
	for(i=head+1;i<=tail;i++) if(a[i]==')') break;
	for(j=tail-1;j>=head;j--) if(a[j]=='(') break;
	if(i<j){
	 if(i>head+1&&j<tail-1&&j==i+1) return 0;
	 //如果这个字符串是这样的，直接0就行了
	 if(!pd_(head,i)||!pd_(j,tail)) return 0;	
	}
	else if(j<i){
		if(j!=i-1&&!pd_(j,i))return 0;
	}
	return 1;
}
bool num_(){
	int num=0;
	for(int i=1;i<=m;i++){
		if(a[i]=='(')num++;
		if(a[i]==')')num--;
		if(num<0) return 0;
	}
	if(num==0) return 1;
	return 0;
}
bool star_(){
	memset(z,0,sizeof(z));
	for(int i=1;i<=m;i++){
		if(a[i]=='?') return 0;
		if(a[i]=='*'){
			if(a[i-1]=='*') z[i]=z[i-1]+1;
			else z[i]=1; 
			if(z[i]>k) return 0;
		}
	}	
	return 1;
}
void print_(int x){
//	cout<<"现在在第"<<x<<"位上"<<endl; 
	for(int i=1;i<=m;i++) cout<<a[i];
	cout<<endl;
	return ;
}

void dfs(int x){     
	print_(x);
	if(x>m){
//		cout<<"hey1"<<endl;
		if(pd_(1,m)){
//			cout<<"pd yes"<<endl;
			if(star_()){
//				cout<<"star yes"<<endl;
				if(num_()){
//					cout<<"num yes"<<endl;
				}
			}
		}
		/*if(pd_(1,m)&&star_()&&num_()){
			ans++;
			cout<<"       answer:";
			print_(x); 
		}
		cout<<"hey2"<<endl;*/
		return ;
	}
	if(a[x]=='?'){
		a[x]='(';
		dfs(x+1);
		a[x]='*';
		dfs(x+1);
		a[x]=')';
		dfs(x+1);
		a[x]='?';
	}
	//别忘了会直接到这里来,万不要忘了dfs 
	
	dfs(x+1);
	
	return ; 
}

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i];
	//简单地先把字符串记下
	if(a[1]!='('&&a[1]!='?') {cout<<0;return 0;}
	dfs(1);
	cout<<ans%mod_<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
7 3
(*??*??


*/

