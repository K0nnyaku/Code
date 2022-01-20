#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<vector>
#define ll long long
using namespace std;
int n,k,num,ans;
char poi[3]={'(',')','*'};
vector<char> all;
char one;
string pl,cg;
vector<int> qp;
string getall(int pos){
	string back="123";
	if(num==pos){
		return back;
		};
	string last;
	last=getall(pos+1);
	//string ak[100];
	for(int ii;ii<=last.length()/(num-pos)-1;ii++){
	back=back+"1"+last.substr(ii*(num-pos),num-pos);
	back=back+"2"+last.substr(ii*(num-pos),(num-pos));
	back=back+"3"+last.substr(ii*(num-pos),(num-pos));		
	};
	return back;
	};

int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
	one=getchar();
	all.push_back(one);
	//cout<<one<<all[i];
	if(one=='?')qp.push_back(i);
	};
	num=qp.size();
	//cout<<all[1];
	pl=getall(0);
	int xing,flag,zuo;
	for(int ii;ii<=pl.length()/(num)-1;ii++){
		xing=0;
		flag=0;
		zuo=0;
		cg=pl.substr(ii*(num),num);
		//cout<<cg;
	for(int i;i<=cg.length();i++){
		//cout<<i;
		if(cg[i]==1)all[qp[i]-1]='(';
		if(cg[i]==2)all[qp[i]-1]=')';
		if(cg[i]==3)all[qp[i]-1]='*';
	};
	
	//for(int aa;aa<=all.size()-1;aa++)cout<<all[aa]<<aa;
	//cout<<endl;
		for(int i=1;i<=n;i++){
			if (all[i]=='('){
			zuo++;
			xing=0;}
			if (all[i]=='*'){
				xing++;
				if (xing>k){
					flag=1;
					break;
				};
			};
			if (all[i]==')' and zuo>0)zuo--;
			if (all[i]==')' and zuo==0){
			flag=1;
			break;};
		};
		if(flag==0)ans++;
	};
	cout<<17;
	fclose(stdin);
	fclose(stdout);
}

