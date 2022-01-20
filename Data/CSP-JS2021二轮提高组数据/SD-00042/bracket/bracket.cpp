#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
using namespace std;
int n,k,sum=0,cs=0;
string a;
stack<int>s;
int zhan[505]={-1},b[505];
void cyh(){
	int c[505]={0};
	int sum=0;
	for(int i=0;i<n;i++){
		if(b[i]==3&&c[i]==0){
			for(int j=i-1;j>=0;j--){
				if(b[j]==2&&c[j]==0){
					sum++;
				}
				else if(b[j]==1&&c[j]==0){
					if(sum<k||sum==k){
						for(int k=j;k<=i;k++){
							c[k]=1;
						}
						break;
					}
				}
			}
		}
	}
	bool flag=true;
	for(int i=0;i<n;i++){
		if(c[i]==0){
			flag=false;
		}
	}
	if(flag==true){
		cs++;
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]=='?'){
			a[i]='(';
			s.push(i);
		}
		if(a[i]=='('){
			b[i]=1;
		}
		if(a[i]=='*'){
			b[i]=2;
		}
		if(a[i]==')'){
			b[i]=3;
		}
	}
	int len=s.size();
	for(int o=0;o<len;o++){
		zhan[o]=s.top();
		s.pop();
	}
	long long baba=pow(3,len);
	while(baba--){
		if(baba==pow(3,len)-1);
		else{
			b[zhan[0]]+=1;
		}
		cyh();
		if(b[zhan[0]]==3){
			for(int o=1;o<len;o++){
				if(b[zhan[o]]!=3){
					b[zhan[o]]+=1;
					for(int oo=1;oo<o;oo++){
						b[zhan[oo]]=1;
					}
					b[zhan[0]]=0;
					break;
				}
			}
		}
	}
	cout<<cs;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
