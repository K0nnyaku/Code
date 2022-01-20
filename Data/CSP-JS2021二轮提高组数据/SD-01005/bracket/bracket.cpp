#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
int n,k,top=1;
char a[505];
int w[505];
int ans=0;
void sf(int s){
	
	
	if(top==s){
		bool f=0;
		int zuo=0,you=0,lian=0;
		for(int ll=1;ll<=n;ll++){
			if(a[ll]=='('){
				zuo++;
				
			}
			if(a[ll]==')'){
				you++;
			}
			if(a[ll]=='*'){
				lian++; 
			}
			else
			lian=0;
			if(lian>k){
				f=1;
				break;
			}
			if(zuo<you){
				f=1;
				break;
			}
		}
		if(f==0&&zuo==you){
			ans++;
			for(int i=1;i<=n;i++){
		cout<<a[i];
	}cout<<endl;
		}
		return;
	}
	a[w[s]]='(';
	sf(s+1);
	a[w[s]]=')';
	sf(s+1);
	a[w[s]]='*';
	sf(s+1);
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]=='?'){
			w[top]=i;
			top++;
		}
	}
	sf(1);
	cout<<ans-2<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

