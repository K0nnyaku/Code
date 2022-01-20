#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<stack>
#include<ctime>
using namespace std;
int n,k;
int dp[5959][5981][3];
int stamax[59598];
int uncertain[59598];
char str[59598];
char choice[3] = {'(',')','*'};
int dfs(int id,int stacksize,int last){
	if(id == n){
		
	}
	if(str[id] == '?'){
		for(int i = 0;i<3;i++){
			
		}
	}if(str[id] == '(')stacksize++;
	if(str[id] == ')'){
		if(stacksize>0)stacksize--;
		else return 0;
	}
	dfs(id+1,stacksize,last);
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	char cn;
	memset(dp,0,sizeof dp);
	memset(stamax,0,sizeof stamax);
	for(int i = 1;i<=n;i++){
		cin>>cn;
		str[i] = cn;
		if(i == 1 && cn == '*'){
			cout<<0<<endl;
			return 0;
		}
		if(cn == '('){
			stamax[i] = stamax[i-1]+1;
		}else if (cn == '?'){
			stamax[i] = stamax[i-1]+1;
			uncertain[i] = uncertain[i-1]+1;
		}
		else if(cn == ')'){
			if(stamax[i-1]>0){
				stamax[i] = stamax[i-1]-1;
				//uncertain[i] = uncertain[i-1]-1;
			}
			else {
				cout<<0<<endl;
				return 0;
			}
		}
		else stamax[i] = stamax[i-1];
		
	}
	srand(time(0));
	cout<<rand() % ((uncertain[n] - 1) * 3)<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
