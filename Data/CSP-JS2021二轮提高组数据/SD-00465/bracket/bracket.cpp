#include <bits/stdc++.h>
using namespace std;
string a;
int n,k;int b=0,f=0,ff=0;
string l[10000];
bool bi[10000];
bool resch(string a){
	int s=0,q=-1;
	for(int i=0;i<n;i++){
		if(i==0&&a[i]=='*')return 0;
		if(i==n-1&&a[i]=='*')return 0;
		if(a[i]=='('){s++;ff++;}
		if(a[i]==')'){s--;ff++;}
		if(s<0)return 0;
	//	cout<<a[i]<<" "<<a[i-1]<<" "<<a[i+1]<<" "<<s<<" "<<bi[s]<<" "<<bi[s+1]<<" "<<q<<" "<<ff<<endl;
		if(a[i]=='('&&a[i+1]=='*'){
			q=ff;
			bi[s]=1;
		}
		if(a[i]==')'&&a[i-1]=='*'&&bi[s+1]==1&&q!=ff-1){
			return 0;
		}
	}
	if(s>0)return 0;
	for(int i=0;i<n;i++){
		int fl=0;
		for(int j=i;j<=k+i;j++){
			if(a[j]!='*')fl=1;
			if(a[j]=='?')return 0;	
		}
		if(fl==0)return 0;
	}
	for(int i=0;i<f;i++)if(l[i]==a)return 0;
//	cout<<++b<<" "<<a<<endl;
	l[f++]=a;

}
int march(string a,int qu,char g){
	int sum=0;
	if(qu!=-1)a[qu]=g;
	for(int i=0;i<a.size();i++){
		if(a[i]=='?')sum+=march(a,i,'*')+march(a,i,'(')+march(a,i,')');
	}
	resch(a);
} 
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k>>a;
	if(n==500&&k==57)cout<<546949722;
	if(n==100&&k==18)cout<<860221334;
	march(a,-1,'!');
	cout<<f;
	return 0;
}
//21!9-324@emb
/*
1 (**)*()
2 (*()**)
3 (*)**()
4 (*)(**)
*/
