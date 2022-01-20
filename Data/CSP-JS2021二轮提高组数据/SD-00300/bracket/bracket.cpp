#include<bits/stdc++.h>
using namespace std;
int cnt,n,k,a[1000],s[1000],top;
char c[1000];
void init(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k>>c;
	for(int i=0;i<n;i++){
		if(c[i]=='(')a[++cnt]=-2;
		if(c[i]==')')a[++cnt]=-1;
		if(c[i]=='?')a[++cnt]==0;
		if(c[i]=='*')a[++cnt]=1;
		if(a[cnt]>0,a[cnt-1]>0)a[cnt-1]+=a[cnt],cnt--;
	}
	fclose(stdin);
	fclose(stdout);
}
int disp(int depth){
	int flag=0,csq=0;
	if(s[top]>0&&s[top-1]>0)flag=-s[top],s[top-1]+=s[top],s[top--]=0;
	if(s[top]==-1){
		if(s[top-1]==-2)flag=1,s[top--]=0,s[top--]=0;
		if(s[top-1]>0&&s[top-2]==-2)flag=s[top-1]+1,s[top--]=0,s[top--]=0,s[top--]=0;
	} 
	if(depth>cnt)csq=(top==0);
	else if(a[depth]==0){
		s[++top]=-1;
		csq+=disp(depth+1);
		s[++top]=-2;
		csq+=disp(depth+1);
	    if(s[top]<0||s[top]+1<=k)s[++top]==1;
		csq+=disp(depth+1);
	}
	else{
		s[++top]=a[depth];
		csq+=disp(depth+1);
	}
	if(flag<0)s[top]+=flag;
	if(flag==1)s[++top]=-2;
	if(flag>1)s[++top]=-2,s[++top]=flag-1;
	return csq;
}
int main(){
	init();
	cout<<disp(1)<<endl;
	return 0;
} 
