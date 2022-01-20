#include<bits/stdc++.h>
using namespace std;

struct plane{
	int start;
	int away;
	plane(int _start,int _away):start(_start),away(_away){}
	bool operator< (plane x)const {return start < x.start;}
};

int inC,ab;

set<plane> inside;
set<plane> abroad;

set<plane> ins;
set<plane> abr;
int ans = 0,maxans = 0;

void endp(int t,set<plane>s){
	for(auto i = s.begin();i != s.end();i++){
		if(i->away < t){
			s.erase(i);
		}
	}		
}

bool canPark(plane p,set<plane> s){
	for(auto it = s.begin();it!=s.end();it++){
		if(it->start <= p.away||it->away >= p.start)return false;
	}
	return true;
}


int main(){
	freopen("airport.in","r",stdin); 
	freopen("airport.out","w",stdout);
	
	
	int n,m1,m2,a,b;
	cin>>n>>m1>>m2;
	
	for(int i = 0;i < m1;i++){
		cin>>a>>b;
		inside.insert(plane(a,b));		
	}// guonei
	
	for(int i = 0;i < m2;i++){
		cin>>a>>b;
		abroad.insert(plane(a,b));		
	}// input abroad
	

	for(int i = 0;i <= n;i++){
		inC = i; // guonei
		ab = n - inC; // abroad
		ins.clear();
		abr.clear();
		ans = 0;
		
	
		for(auto i = inside.begin();i != inside.end();i++){
			// endp(i->start,ins);
			if(ab - ins.size() > 0&&canPark(*i,ins)){
				ins.insert(*i);
				ans++;
			}
		}
		for(auto i = abroad.begin();i != abroad.end();i++){
			// endp(i->start,abr);
			if(ab - abr.size() > 0&&canPark(*i,abr)){
				abr.insert(*i);
				ans++;
			}
		}
		
		
		maxans = max(ans!=0?ans:maxans,maxans);
	}
	cout<<maxans;
	return 0;
}
