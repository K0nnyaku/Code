#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int n,k,q=0,s=0,f=0,l=0;
char w[505]={0};
void gameover(){
	cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	scanf("%s",&w);
	if(w[0]==')'||w[0]=='*'){//
		gameover();return 0;
	}
	for(int i=1;i<n-1;++i){
		if(w[i]=='?'){
			q++;
		}
		else if(w[i]=='('){
			f++;
		}
		else if(w[i]==')'){
			l++;
		}
		else if(w[i]=='*'){
			s++;
			if(k-s<0){//
				gameover();return 0;
			}
		}
	}
	s=k-s;
	if(!s&&(q%2)){//
		gameover();return 0;	
	}
	if(max(f-l,l-f)>q){//
		gameover();return 0;	
	}
	if(w[n-1]=='('||w[n-1]=='*'){//
		gameover();return 0;
	}
	if(q%2){//
		cout<<(max(f-l,l-f)+1+(q-1)/2)%(10000000+7);
	}
	else if(!q%2){
		if(s>=2){
		cout<<(max(f-l,l-f)+q/2)%(10000000+7);			
		}
		else{//
			gameover();return 0;
		}
	}
	//cout<<" "<<n<<" "<<k<<" "<<q<<" "<<f<<" "<<l; 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
