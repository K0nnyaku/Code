#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
# define MOD 1000000007
int n,k,bian,a[510],san[510];
long long ans;
char s[510];
void chai(long long x){
	int tota=0;
	while(x!=0){
		san[bian-tota]=x%3;
		x/=3;
		tota++;
	}
}
bool pan(){
	int iss=0;
	for(int i=0;i<n;i++){
		if(s[i]=='*'){
			iss++;
		}
		else{
			iss=0;
		}
		if(iss>k) return 0;
	}
	return 1;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin.getline(s,n);
	for(int i=0;i<n;i++){
		if(s[i]=='?'){
			a[++bian]=i;
		}
	}
	long long num=pow(3,bian);
	for(long long i=0;i<num;i++){
		chai(i);
		for(int j=1;j<=bian;j++){
			if(san[j]==0){
				s[a[j]]='(';
			}
			else if(san[j]==1){
				s[a[j]]='*';
			}
			else{
				s[a[j]]=')';
			}
		}
		if(pan()){
			ans=(ans+1)%MOD;
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
