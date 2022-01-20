#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

int n,k;
string s,ts;

void getsM(string &ts,int cpoi,int o){
	
	for(int i=cpoi;i<s.size();i++){
		if(ts[i]=='?'){
			if(o==0){
				ts[i]=')';
			}else if(o==1){
				ts[i]='(';
			}else if(o==2){
				ts[i]='*';
			}
			
			getsM(ts,i+1,0);//改为) 
			getsM(ts,i+1,1);//改为( 
			getsM(ts,i+1,2);//改为* 
			
		}
		
	}
//	cout<<ts<<endl;
	
}

int main(){
	freopen("bracket4.in","r",stdin);
//	freopen("bracket.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	cin>>s;
	int isNum=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='?')isNum++;
	}
	int ans=1<<isNum;
	cout<<(int)((ans+n-k)/(n-k));

	return 0;
}

