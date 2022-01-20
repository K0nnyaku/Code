#include<bits/stdc++.h>
using namespace std;

const unsigned int MAXN=200010;

unsigned int n, m1, m2;

struct BIT{
	int data[MAXN+1];
	static unsigned int lowbit(const unsigned int x){
		return x&(-x);
	}
	void insert(unsigned int pos, int val){
		pos++;
		for(unsigned int i=pos; i<=MAXN; i+=lowbit(i)){
			data[i]+=val;
		}
	}
	int query(unsigned int pos){
		pos++;
		int ans=0;
		for(unsigned int i=pos; i>0; i-=lowbit(i)){
			ans+=data[i];
		}
		return ans;
	}
}be1, be2;

typedef std::pair<unsigned int, std::pair<unsigned int, bool> > evnt;
evnt ev1[MAXN], ev2[MAXN];

//bool used[MAXN];
unsigned int rev[MAXN];


void sol(BIT &bx, evnt *ex, unsigned int nn){
	unsigned int now=0, cur=0;
	std::priority_queue<unsigned int, std::vector<unsigned int>, std::greater<unsigned int> > ava;
	//memset(used, 0, sizeof(used));
	memset(rev, 0, sizeof(rev));
	for(unsigned int i=0; i<nn; i++){
		if(ex[i].second.second==true){//insert
			if(!ava.empty()){
				cur=ava.top();
				ava.pop();
				//used[cur]=true;
				rev[ex[i].second.first]=cur;
				bx.insert(cur+1, 1);
				//cerr<<ex[i].second.first<<": "<<cur<<endl;
			}
			else{
				//used[now]=true;
				rev[ex[i].second.first]=now;
				//cerr<<ex[i].second.first<<": "<<now<<endl;
				now++;
				bx.insert(now, 1);
			}
		}
		else{//remove
			//used[rev[]]
			ava.push(rev[ex[i].second.first]);
			//cerr<<"back "<<rev[ex[i].second.first]<<endl;
		}
	}
}

unsigned int xit, xot;
int mmx=0;

int main(){
	
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	
	cin>>n>>m1>>m2;
	
	for(unsigned int i=0; i<2*m1; i+=2){
		cin>>xit>>xot;
		ev1[i]=std::make_pair(xit, std::make_pair(i/2, true));
		ev1[i+1]=std::make_pair(xot, std::make_pair(i/2, false));
	}
	std::sort(ev1, ev1+2*m1);
	sol(be1, ev1, 2*m1);
	
	//for(unsigned int i=0; i<=n; i++)cerr<<i<<": "<<be1.query(i)<<endl;
	
	for(unsigned int i=0; i<2*m2; i+=2){
		cin>>xit>>xot;
		ev2[i]=std::make_pair(xit, std::make_pair(i/2, true));
		ev2[i+1]=std::make_pair(xot, std::make_pair(i/2, false));
	}
	std::sort(ev2, ev2+2*m2);
	sol(be2, ev2, 2*m2);
	
	//for(unsigned int i=0; i<=n; i++)cerr<<i<<": "<<be2.query(i)<<endl;
	
	for(unsigned int i=0; i<=n; i++)mmx=max(mmx, be1.query(i)+be2.query(n-i));
	cout<<mmx<<endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

