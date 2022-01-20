//我就是那个可怜的小c 

#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<cstring>

using namespace std;

const int MAXSIZE=507;

int n=0;
int k=0;
int ans=0;
//int ssss=0;

char s[MAXSIZE];

stack<int > st;

void init(){
	scanf("%d%d",&n,&k);
	scanf("%s",&s);
}

bool bct(char s[]){
//	ssss++;
	int temp = 0;
	for(int i=0;i<n;i++){
		if(s[i]=='('){
			temp=0;
			st.push(1);
		}
		else if(s[i]=='*'){
			if(++temp>k) return 0;
		} 
		else if(s[i]==')'){
			if(st.empty()) return 0;
			st.pop();
		}
	} 
	if(!st.empty()) return 0;
	return 1;
}

int fuck(int i,int j,char a[]){
	if(j==(n-1)) {
//		cout<<a<<endl;
		return bct(a);
	}
	switch(i-0) {
		case 1:
			a[j]='(';
			break;
		case 2:
			a[j]='*';
			break;
		case 3:
			a[j]=')';
			break;
		default:
			break;
	}
//	cout<<a<<endl;
	return fuck(1,j+1,a)+fuck(2,j+1,a)+fuck(3,j+1,a);
}

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	init();
	if(n==0) printf("0");
	else if(s[n-1]=='*' || s[0]=='*') printf("0");
	else if(s[n-1]=='?') {
		s[n-1]=')';
	}
	for(int i=0;i<n;i++){
		if(s[i]=='?') {
//			cout<<i<<endl;
			cout<<fuck(1,i,s)+fuck(2,i,s)+fuck(3,i,s)<<endl;
			break;
		}
	}
//	cout<<ssss<<endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
