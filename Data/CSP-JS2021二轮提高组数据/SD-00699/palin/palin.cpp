#include <bits/stdc++.h>
using namespace std;
int t,n[105],a[105][1005],l[105]={0},r[105],ans[105][1005];
char an[105][1005];

void chan(int h,char x[],char y[]){
	for(int i=0;i<n[h]*2;i++){
		x[i] = y[i];
	}
}

void bi(int h,int mn[],char lo[]){
	if(ans[h][0]==-1){
		chan(h,an[h],lo);
		return;
	}
	for(int i=0;i<2*n[h];i++){
		if(ans[h][i]==mn[i]) continue;
		if(mn[i]<ans[h][i]) return;
		if(mn[i]>ans[h][i]) chan(h,an[h],lo);
	}
}

void con(int h,int j[],int st,char lo[]){
	if(st==n[h]-1){
		bi(h,j,lo);
		return;
	}
	if(st<n[h]-1 && st<=n[h]/2-1){
		j[st] = a[h][l[h]];
		lo[st] = 'L';
		con(h,j,st+1,lo);
		j[st] = a[h][r[h]];
		lo[st] = 'R';
		con(h,j,st+1,lo);
	}
	
	else if(st<n[h]-1 && st>n[h]/2-1){
		int gh = j[2*n-1-st];
		if(a[h][l[h]]!=gh && a[h][r[h]]!=gh){
			return;
		}
		else(){
			if(a[h][l[h]]==gh){
				j[st] = a[h][l[h]];
				lo[st] = 'L';
			}
			con(h,j,st+1);
			if(a[h][r[h]]==gh){
				j[st] = a[h][r[h]];
				lo[st] = 'R';
			}
			con(h,j,st+1);
		}
	}
}

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin >> t;
	for(int i=0;i<t;i++) ans[i][0] == -1;
	for(int i=0;i<t;i++){
		cin >> n[i];
		r[i] = 2*n;
		for(int l=0;l<n[i];l++){
			cin >> a[i][l];
		}
	}
	for(int i=0;i<t;i++){
		int lk[1005];
		char hj[1005];
		con(i,lk,st,hj);
	}
	for(int i=0;i<t;i++){
		for(int l=0;l<2*n[i];i++){
			cout << an[l];
		}
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
