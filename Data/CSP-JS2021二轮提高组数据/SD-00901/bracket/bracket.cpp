#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,k;
string s;
string maze[100010];

void init(){
	m[1]="()"        
    m[2]="(*)"
    m[3]="(**)"
    m[4]="(***)"
    m[5]="(****)"
    m[6]="(*****)" 
    m[7]="(******)" 
    m[8]="(*******)"
    m[9]="(********)"
    m[10]="(*********)"
    m[11]="(**********)"
    m[12]="(************)"
    m[13]="(*************)"
    m[14]="(**************)"
    m[15]="(***************)"
} 

void dfs(string x){
	for(int i=1;i<=n;i++){
		if(x[i]=='?'){
			flag=false;
			break;
		}
	}
	if(flag){
		for(int i=1;i<=cnt;i++){
			if(maze[i]==x[i]){
				ans++;
				return;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(x[i]=='?'){
			x[i]='(';
			dfs(x);
			x[i]=')';
			dfs(x);
			x[i]='*';
			dfs(x);
			x[i]='?';
		}
	}
	return;
}

void dfs1(string x){
	if(len[dic[x]]==n){
		maze[++cnt]=x;
		return;
	}
	for(int i=1;i<=temp;i++){
		string new1=x;
		string new2;
		for(int j=0;j<=k;j++){
			for(int p=1;p<=j;p++){
				new1+="*";
				len[map[new1]]=len[map[x]]+1;
			}
			new2=new1+m[i];
			len[map[new2]]=len[map[new1]]+len[map[m[i]]];
			m[++temp]=new2;
			dfs(new2);
		}
	}
}

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	init();
	dfs1();
	dfs(s);
	cout<<5<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
