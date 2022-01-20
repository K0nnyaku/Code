#include<algorithm>
#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
int x;
int n;
int qw = 0;
int a[500005];
int vis[500005];
int dir[500005];
bool p[500005];
int h[500005];
int le[500005];
int ri[500005];
void check(int l,int r,int sum,int u)
{
	if(a[l] == a[r] && sum < n)return;
	if(u == 0){
		h[sum] = a[l];
	}
	else{
		h[sum] = a[r];
	}
	
	if(sum == n && qw == 0){
		
		int kk = n,tt = n;
		if(u == 0)l += 1;
		else r -= 1;
		for(int j = l,k = r;j <= k;){
			if(a[j] == h[kk]){
				j++;
				kk--;
				p[++tt] = 0;
				continue;
			}
			if(a[k] == h[kk]){
				k--;
				kk--;
				p[++tt] = 1;
				continue;
			}
		}
		for(int j = 1;j <= 2 * n;j++){
			if(p[j] == 0)cout<<"L";
			else cout<<"R";
		}
		qw = 1;
		return;
	}
	if(u == 0 && qw == 0){
		//cout<<l<<" "<<r<<endl;
		int q = dir[l];
		//cout<<a[r]<<" "<<a[q - 1]<<" "<<a[q + 1]<<endl;
		if(a[l + 1] <= a[r]){
			if(a[le[q]] == a[l + 1] || a[ri[q]] == a[l + 1]){
				le[ri[q]] = le[q];
				ri[le[q]] = ri[q];
				p[sum] = u;
				check(l + 1,r,sum + 1,0);
			}
			if(a[le[q]] == a[r] || a[ri[q]] == a[r]){
				le[ri[q]] = le[q];
				ri[le[q]] = ri[q];
				p[sum] = u;
				check(l + 1,r,sum + 1,1);
			}	
		}
		else{
			if(a[le[q]] == a[r] || a[ri[q]] == a[r]){
				le[ri[q]] = le[q];
				ri[le[q]] = ri[q];
				p[sum] = u;
				check(l + 1,r,sum + 1,1);
			}
			if(a[le[q]] == a[l + 1] || a[ri[q]] == a[l + 1]){
				le[ri[q]] = le[q];
				ri[le[q]] = ri[q];
				p[sum] = u;
				check(l + 1,r,sum + 1,0);
			}
		}	
	}
	if(u == 1 && qw == 0){
		int q = dir[r];
		if(a[l] <= a[r - 1]){
			if(a[le[q]] == a[l] || a[ri[q]] == a[l]){
				le[ri[q]] = le[q];
				ri[le[q]] = ri[q];
				p[sum] = u;
				check(l,r - 1,sum + 1,0);
			}
			if(a[le[q]] == a[r - 1] || a[ri[q]] == a[r - 1]){
				le[ri[q]] = le[q];
				ri[le[q]] = ri[q];
				p[sum] = u;
				check(l,r - 1,sum + 1,1);
			}
		}
		else{
			if(a[le[q]] == a[r - 1] || a[ri[q]] == a[r - 1]){
				le[ri[q]] = le[q];
				ri[le[q]] = ri[q];
				p[sum] = u;
				check(l,r - 1,sum + 1,1);
			}
			if(a[le[q]] == a[l] || a[ri[q]] == a[l]){
				le[ri[q]] = le[q];
				ri[le[q]] = ri[q];
				p[sum] = u;
				check(l,r - 1,sum + 1,0);
			}
		}	
	}
	
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>x;
	for(int i = 1;i <= x;i++){
		scanf("%d",&n);
		
		for(int j = 1;j <= n * 2;j++){
			scanf("%d",&a[j]);
			le[j] = j - 1;
			ri[j] = j + 1;
			if(vis[a[j]] == 0)vis[a[j]] = j;
			else{
				dir[j] = vis[a[j]];
				dir[vis[a[j]]] = j;	
			}
		}
		if(a[1] <= a[n * 2]){
			qw = 0;
			check(1,n * 2,1,0);
			if(qw == 0)check(1,n * 2,1,1);
			if(qw == 0)cout<<"-1";
			cout<<endl;
		}
		else{
			qw = 0;
			check(1,n * 2,1,1);
			if(qw == 0)check(1,n * 2,1,0);
			if(qw == 0)cout<<"-1";
			cout<<endl;
		}
		for(int j = 1;j <= 2 * n;j++)vis[j] = 0;
	}
	return 0;
}
