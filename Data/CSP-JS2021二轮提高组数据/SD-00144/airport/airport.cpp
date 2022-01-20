#include<bits/stdc++.h>
using namespace std;
#define udm unordered_map
template<typename type>
bool update(type &todo,const type &standard){
	if(todo<standard){
		todo=standard;
		return 1;
	}
	return 0;
}
int n,m1,m2;
vector<pair<int,int> > a,b;
vector<vector<int> > ina,inb;
vector<int> f,g;

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m1>>m2;
	a.resize(m1);
	b.resize(m2);
	ina.resize(n+1);
	inb.resize(n+1);
	f.resize(n+1);
	g.resize(n+1);
	for(int i=0;i<m1;i++)
		cin>>a[i].first>>a[i].second;
	for(int i=0;i<m2;i++)
		cin>>b[i].first>>b[i].second;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	ina[1].push_back(0);
	for(int i=1;i<m1;i++){
		for(int j=1;j<=n;j++){
			if(ina[j].size()){
				if(a[i].first>a[ina[j].back()].second){
					ina[j].push_back(i);
					break;
				}
			}
			else{
				ina[j].push_back(i);
				break;
			}
		}
	}
	inb[1].push_back(0);
	for(int i=1;i<m2;i++){
		for(int j=1;j<=n;j++){
			if(inb[j].size()){
				if(b[i].first>b[inb[j].back()].second){
					inb[j].push_back(i);
					break;
				}
			}
			else{
				inb[j].push_back(i);
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+ina[i].size();
		g[i]=g[i-1]+inb[i].size();
	}
	int answer(0);
	for(int i=0;i<=n;i++)
		update(answer,f[i]+g[n-i]);
	cout<<answer<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
