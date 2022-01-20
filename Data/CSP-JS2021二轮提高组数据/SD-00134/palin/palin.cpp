#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#define MAX 500005
#define INF 9999999
using namespace std;

int t,n,w;
int vis[MAX],arr[MAX],chu[MAX];
string s;

vector<int> match[MAX];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		s.clear();
		memset(vis,0,sizeof(vis));
		memset(chu,0,sizeof(chu));
		memset(match,0,sizeof(match));
		int f=1;
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++) {
			scanf("%d",&arr[i]);
			match[arr[i]].push_back(i);
		}
		int l=1,r=2*n;
		for(int i=1;i<=n;i++){
			cout<<endl;
			f=1;
			w=match[arr[l]][1]==i ? match[arr[l]][2] : match[arr[l]][1];
			for(int j=1;j<w;j++)
				if(!vis[j]&&chu[j]!=0){
					for(int k=j+1;k<w;k++) 
						if(!chu[k]) {
							f=0;
							break;
						}
					break;
				}
					
			if(f==1)
				for(int j=2*n;j>w;j--)
					if(!vis[j]&&chu[j]!=0){
						for(int k=j-1;k>w;k--)
							if(!chu[k]) {
								f=0;
								break;
							}
						break;
					}
			if(f==1) {
				vis[l]=1;
				l++;
				s+='L';
				chu[w]=2*n-i+1;
			}
			else {
				if(vis[r]) {
					cout<<"-1\n";
					f=0;
					break;
				}
				f=1;
				w=match[arr[r]][1]==i ? match[arr[r]][2] : match[arr[r]][1];
			for(int j=1;j<w;j++)
				if(!vis[j]&&chu[j]!=0){
					for(int k=j+1;k<w;k++) 
						if(!chu[k]) {
							f=0;
							break;
						}
					break;
				}
					
			if(f==1)
				for(int j=2*n;j>w;j--)
					if(!vis[j]&&chu[j]!=0){
						for(int k=j-1;k>w;k--)
							if(!chu[k]) {
								f=0;
								break;
							}
						break;
					}
					
				if(f==0) {
					printf("-1\n");
					break;
				}
				else {
					vis[r]=1;
					chu[w]=2*n-i+1;
					r--;
					s+='R';
				}
			}
		}
		if(f){
			cout<<s;
			for(int i=1;i<=n;i++) {
				if(chu[l]<chu[r]) printf("L");
				else if(chu[l]>chu[r]) printf("R");
				else printf("L");
			}
			cout<<endl;
		}
	}
	return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#define MAX 500005
#define INF 9999999
using namespace std;

int t,n,w;
int vis[MAX],arr[MAX],chu[MAX];
string s;

vector<int> match[MAX];

bool pd(int x){
	for(int i=1;i<x;i++){
		if(!vis[i]&&chu[i]!=0){
			for(int j=i+1;j<x;j++){
				if(chu[j]==0) return 0;
			}
		}
	}
	for(int i=2*n;i>w;i--){
		if(!vis[i]&&chu[i]!=0){
			for(int j=i-1;j>w;j--) {
				if(chu[j]==0) return 0;
			}
		}
	}
	return 1;
}
int main(){
	scanf("%d",&t);
	while(t--){
		int f=1;
		s.clear();
		memset(vis,0,sizeof(vis));
		memset(chu,0,sizeof(chu));
		memset(match,0,sizeof(match));
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++) {
			scanf("%d",&arr[i]);
			match[arr[i]].push_back(i);
		}
		int l=1,r=2*n;
		for(int i=1;i<=n;i++){
			int f=1;
			w=match[arr[l]][1]==i ? match[arr[l]][2] : match[arr[l]][1];
			if(pd(w)==1){
				vis[l]=1;
				l++;
				s+='L';
				chu[w]=2*n-i+1;
			}
			else {
				if(vis[r]==1) {
					cout<<"-1\n";
					f=0;
					break;
				}
				f=1;
				w=match[arr[r]][1]==2*n-i+1 ? match[arr[r]][2] : match[arr[r]][1];
				if(pd(w)==1){
					vis[r]=1;
					chu[w]=2*n-i+1;
					r--;
					s+='R';
				}
				else {
					cout<<"-1\n";
					f=0;
					break;
				}
			}
		}
		if(f==1){
			cout<<s;
			for(int i=1;i<=n;i++) {
				if(chu[l]<chu[r]) printf("L");
				else if(chu[l]>chu[r]) printf("R");
				else printf("L");
			}
			cout<<endl;
		}
		for(int i=1;i<=2*n;i++) cout<<chu[i]<< " ";
	}
	return 0;
}
*/
