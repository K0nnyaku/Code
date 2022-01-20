#include<bits/stdc++.h>
#include<deque>
#include<cstdio>
#include<queue>
using namespace std;
int n,ans=0;
deque<int> num;
deque<int> an;
vector<char> c;
vector<vector<char> > cs;
bool cmp(const vector<char>& t1,const vector<char>& t2){
	int l=t1.size();
	for(int i=0;i<l;i++){
		if(t1[i]<t2[i])return true;
	}
	return false;
}
bool check(){
	/*deque<int> s(ss);
	
	while(s.front()==s.back()){
		s.pop_back();
		s.pop_front();
	}
	if(s.empty())return true;
	deque<int>::iterator it=num.begin(),it1=num.end();
	for(int i=0;i<n/2;i++){
		if(*it!=*(it1-1))return false;
		it++;it1--;
	}*/
	for(int i=0;i<n;i++)
	if(num[i]!=num[i+=n/2])return false;
	
	return true;
}

void ds(int n){
	if(n==0){
		if(check()){
			ans++;
			cs.push_back(c);
		}
		return;
	}
	else{
		int a=num.front();
		num.pop_front();
		an.push_back(a);
		c.push_back('L');
		ds(n-1);
		num.push_front(a);
		an.pop_back();
		
		a=num.back();
		num.pop_back();
		an.push_back(a);
		c.push_back('R');
		ds(n-1);
		num.push_back(a);
		an.pop_back();
	}
	return;
}
int main(){
	int t;
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	
	for(int i=0;i<t;i++){
		scanf("%d",&n);
		n*=2;
		for(int i=0;i<n;i++){
			int t;
			scanf("%d",&t);
			num.push_back(t);
		}
		
		ds(n);
		if(cs.empty()) puts("-1\n");
		else{
			sort(cs.begin(),cs.end(),cmp);
			for(int i=0;i<n;i++){
				printf("%c",(cs[0])[i]);
			}
			
		}
		cout<<'\n';
		num.clear();
	}
	
	
	return 0;
}


