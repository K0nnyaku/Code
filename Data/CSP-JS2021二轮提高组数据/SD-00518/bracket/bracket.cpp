#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
int n,k,cnt,tnt,ttnt,ans,sd;
const int N=1000;
struct node{
char in;
int fl;
}s[N];
int ct[N];

bool find1(){
	bool be=0;
	for(int i=1;i<=n;i++){
		if(s[i].in =='('){
			cnt++;
			if(s[i-1].in=='*'){
				be=1;	
			}	
		}
		if(s[i].in ==')'){
			cnt--;
			if(be==1&&s[i+1].in=='*')
			return 0;
			
		}
		if(cnt<0) return 0;
	}
	return cnt==0;
}

bool find2(){
	for(int i=1;i<=n;i++){
		if(s[i].in =='*'){
			tnt++;
			ttnt=max(ttnt,tnt);
		}
		else tnt=0;
	}
	return ttnt<=k;
}

int sear(){
	for(int i=1;i<=n;i++){
		if(s[i].in =='?'){
			s[i].in ='*';
			s[i].fl =1;
			sd++;
		}
	}
	if(find1()){
		for(int i=1;i<=n-1;i++){
			for(int j=n-1;j>0;j--){
				if(s[i].fl&&i!=j&&s[j].fl){
					s[i].in=')',s[j].in='(';
					if(find1()&&find2()){
					ans++;

					}
					
					s[i].in='*',s[j].in='*';		
				} 
		
			}
		}
		return ans;
	}


}

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<=n;i++){
		s[i].in =getchar();
		if(i==n) s[i].in =')';
		if(i==1) s[i].in ='(';
	};		
	printf("%d\n",sear());

	return 0;
}  
