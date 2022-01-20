#include<bits/stdc++.h>
using namespace std;
const int N=550;
int n,k;	
struct node{
	int firstt;
	int secondd;
};
stack<node>s;
bool check(string ss){
	while(!s.empty()){
		s.pop();
	}
	int sum3=0;
	if(ss[0]=='*'||ss[ss.size()-1]=='*') return 0;
	int lenh=ss.size();
	for(int i=0,sum1=0,sum2=0;i<lenh;i++){
		sum3=0;
		while(ss[i]=='*'){
			sum3++;
			if(sum3>k){
				return 0;
			}
			i++;
		}
		if(ss[i]=='(')s.push((node){1,i});
		else if(ss[i]==')'){
			if(!s.empty()){
				if(s.top().firstt==1){
					sum1=0,sum2=0;
					for(int j=i;j<lenh;j++){
						if(ss[j]=='('){sum1++;}
						if(ss[j]=='*'){sum2++;}
					}
					if(sum1==0&&sum2!=0&&i!=lenh-1){return 0;}
					s.pop();		
				}
				else if(s.top().firstt!=1){
					s.push((node){2,i});
				}
				else {
					return 0;
				}
			} 
			else return 0;
		}
		else if(ss[i]=='?'){
			return 0;	
		}
	}
	if(s.empty()){
		return 1;
	}
	else{
		while(!s.empty()) s.pop();
		return 0;	
	}
}
int sum=0;
void sc(string S,int kkk){
	int lenh=S.size();
	if(kkk==lenh-1)
		sum+=check(S);
	for(int i=0;i<lenh;i++){
		if(S[i]=='?'){
			S[i]='*',sc(S,i);
			S[i]='(',sc(S,i);
			S[i]=')',sc(S,i);
			return;
		}
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	string S;
	cin>>S;
	sc(S,0);
	cout<<sum<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
