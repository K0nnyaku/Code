#include<iostream>
using namespace std;
int n,k,s[501],t[501],sum;
char S[501];

void ck(){
	if(t[n]==3||t[1]==3)return;
	int f=0;
	for(int i=1;i<=n-k;i++){
		if(t[i]==3){
			f=0;
			for(int j=i;j<=i+k;j++){
				if(t[j]!=3)f=1;
			}
			if(!f)return;
		}
	}
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++){
		if(cnt2&&cnt1>cnt2&&t[i]==1)return;
		if(t[i]==1)cnt1++;
		if(t[i]==2)cnt2++;	
		if(cnt1<cnt2)return;
	}
	int f1=0,f2=0,p1=0,p2=n;
	for(int i=1;i<=n;i++){
		if(t[i]==1&&p1&&i<p2&&i-p1-1)f1=1;
		if(t[i]==2&&p2!=n&&p2>p1&&i-p2-1)f2=1;
		if(t[i]==1)p1=i;
		if(t[i]==2)p2=i;
	}
	if(f1&&f2)return;
	if(cnt1==cnt2)sum++;
//	if(cnt1==cnt2){for(int i=1;i<=n;i++)cout<<t[i];
//	cout<<endl;}
	return;
}

void go(int x){
	if(x==n+1){ck();return;}
	if(s[x]){go(x+1);}
	else{
	t[x]=1;go(x+1);
	t[x]=2;go(x+1);
	t[x]=3;go(x+1);
	}
}



int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>S;
	for(int i=0;i<n;i++){
		if(S[i]=='(')s[i+1]=1;
		if(S[i]==')')s[i+1]=2;
		if(S[i]=='*')s[i+1]=3;
	}
//	for(int i=1;i<=n;i++)cout<<s[i];
	for(int i=1;i<=n;i++)t[i]=s[i];
	go(1);
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//21!9-324@emb
//7 3 (*??*??
//10 5 ((??????()
//3 2 ???
//4 2 ????
//10 2 ???(*??(?)

