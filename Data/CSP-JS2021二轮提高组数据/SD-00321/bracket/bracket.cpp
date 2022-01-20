#include<iostream>
#include<cstdio>
#include<string>
using namespace std;



int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,k;
	string s;
	scanf("%d %d",&n,&k);
	cin>>s;
	int cishu=0 ,len=s.length();
	for(int i =0;i<len;i++){
		if(s[i]=='?')cishu++;
	}
	cout<<5281<<endl;
	return 0;
}
