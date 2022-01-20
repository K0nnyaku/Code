#include <bits/stdc++.h>
using namespace std;
int k,n,sum=0;
char b[505];
char h[3] = {'*','(',')'};
bool dfs(char c[505], int x, int y){
	if(x==y) return false;
	int u=0,o=0;
	for(int i=0;i<=y;i++){
		if(c[i]=='*') u++;
		if(u==k) return false;
		if(c[i] == '(') o++;
		if(c[i] == ')') o--;
	}
	if(o!=0) return false;
	else return true;
}

void g(char c[], char b[], int y){
	int m=0,j=-1;
	for(int i=0;i<=y;i++){
		if(c[i]=='?'){
			m=1;
			j=i;
		}
	}
	cout << m << endl;
	if(m==1){
		for(int r=0;r<3;r++){
			b[j] = h[r];
			g(b,b,y);
		}
	}
	else if(m==0){
		if(dfs(c,0,y)) sum++;
	}
	return;
}

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin >> n >> k;
	int i=0;
	while(i<=n-1){
		cin >> b[i];
	}
	g(b,b,n-1);
	cout << sum; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
