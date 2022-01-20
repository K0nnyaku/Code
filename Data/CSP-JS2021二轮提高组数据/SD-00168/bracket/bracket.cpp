#include <bits/stdc++.h>
using namespace std;
int n,k,kh[3],qus[505],st[505],ans;
char ab[3]={'*','(',')'};
string s;
bool checker(string x){
	
}
void builder(int pl){
	if(pl==kh[2]){
		if(checker){
			ans++;
		}
		return;
	}
	for(int i=0;i<3;i++){
		if(i==0&&st[qus[pl]]>=k){
			continue;
		}
		if(i==1&&kh[0]-kh[1]>=kh[2]-pl){
			continue;
		}
		if(i==2&&kh[1]-kh[0]>=kh[2]-pl){
			continue;
		}
		s[qus[pl]]=ab[i];
		builder(pl+1);
		s[qus[pl]]='?';
	}
	return;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d",&n,&k);
	if(n<=1){
		cout<<"0";
		return 0;
	}
	for(int i=0;i<n;i++){
		int a=getchar();
		if(i==0&&a=='?'){
			a='(';
		}
		if(i==n-1&&a=='?'){
			a=')';
		}
		if(a=='('){
			kh[0]++;
		}
		if(a==')'){
			kh[1]++;
		}
		if(a=='?'){
			qus[kh[2]]=i;
			kh[2]++;
		}
		if((a=='*'||a=='?')&&s[i-1]=='*'){
			st[i]=st[i-1]+1;
		}
		s+=a;
	}
	if(kh[2]==0){
		if(checker(s)){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	builder(0);
	cout<<ans;
	return 0;
} 


