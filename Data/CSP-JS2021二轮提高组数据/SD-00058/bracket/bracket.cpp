#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <stack>
using namespace std;
const long long MOD = 1e9+7;
int n,k,len;
long long ans;
char a[1000],aa[1000];
int pd(char a[]){
	int t[1000],tot=0;
	stack <char> st;
	st.push('(');
	for (int i=0;i<len;i++){
		if (a[i]=='*'&&!st.size()){
			return 0;
		}
		if (a[i]=='('){
			tot++;
			st.push(a[i]);
		}
		if (a[i]==')'){
			t[tot--]=0;
			st.pop();
		}
		if (a[i]=='*'){
			t[tot]++;
			if (t[tot]>=k)return 0;
		}
	}
	st.pop();
	if (st.size()) return 0;
	return 1;
}
int fin (int k,char aa[]){
	int i;
	for (i=k+1;i<len;i++){
		aa[i]=a[i];
		if (a[i]=='?'){
			aa[i]='*';
			fin(i,aa);
			aa[i]='(';
			fin(i,aa);
			aa[i]=')';
			fin(i,aa);
		}
	}
	if (i>=len-1){
		aa[len]=')';
		ans+=pd(aa);
		ans%=MOD;
	}
}
int main ( ) {
	freopen ("bracket.in","r",stdin);
	freopen ("bracket.out","w",stdout);
	scanf("%d%d%s",&n,&k,a);
	len=strlen(a)-1;
	if ((a[len]!=')'&&a[len-1]!='?')||(a[0]!='('&&a[0]!='?')){
		printf("0\n");
		return 0;
	}
	a[len]=aa[len]=')';
	a[0]=aa[len]='(';
	fin(0,aa);
	fclose (stdin);
	fclose (stdout);
	return 0;
}
