#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 100010;
const int inf = 1e8 + 7;

struct flight{
	int arr, leave;
}fl1[maxn],fl2[maxn];
int br1[maxn], br2[maxn], cnt1 = 0, cnt2 = 0;
bool cmp(flight a, flight b){
	return a.arr < b.arr;
}
struct segment{
	int l,r,val;
}seg[maxn*2];
void buildTree(int x, int l, int r){
	int lch = x * 2;
	int rch = x * 2 + 1;
	seg[x].l = l;
	seg[x].r = r;
	if(l == r){
		seg[x].val = 0;
		return ;
	}
	int mid = (l + r) >> 1;
	buildTree(lch, l, mid);
	buildTree(rch, mid + 1, r);
	seg[x].val = min(seg[lch].val,seg[rch].val);
	return ;
}
void modify(int x, int pos, int k){
	int lch = x * 2;
	int rch = x * 2 + 1;
	if(seg[x].l >= pos && seg[x].r <= pos){
		seg[x].val = k;
		return ;
	}
	if(seg[lch].r >= pos){
		modify(lch,pos,k);
	}
	else{
		modify(rch,pos,k);
	}
	seg[x].val = min(seg[lch].val, seg[rch].val);
	return ;
}
int query(int x, int l, int r){
	int lch = x * 2;
	int rch = x * 2 + 1;
	if(l <= seg[x].l && r >= seg[x].r){
		return seg[x].val;
	}
	int ans = inf;
	if(seg[lch].r >= l){
		ans = min(ans,query(lch,l,r));
	}
	if(seg[rch].l <= r){
		ans = min(ans,query(rch,l,r));
	}
	return ans;
}

int n,m1,m2;
int pre_br1[maxn],pre_br2[maxn];

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	buildTree(1,1,m1+m2);
	for (int i = 1;i <= m1; i ++){
		scanf("%d%d",&fl1[i].arr, &fl1[i].leave);
	}
	sort(fl1 + 1, fl1 + m1 + 1, cmp);
	for (int i = 1;i <= m2; i ++){
		scanf("%d%d",&fl2[i].arr, &fl2[i].leave);
	}
	sort(fl2 + 1, fl2 + m2 + 1, cmp);
	for (int i = 1; i <= m1; i ++){
		int l = 1, r = cnt1, ans = -1;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(query(1, l, mid) <= fl1[i].arr){
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		if(ans == -1){
			++cnt1;
			modify(1,cnt1,fl1[i].leave);
			br1[cnt1]++;
		}
		else{
			br1[ans]++;
			modify(1,ans,fl1[i].leave);
		}
	}
	for (int i = 1; i <= 100000; i ++){
		seg[i].val = 0;
	}
	for (int i = 1; i <= m2; i ++){
		int l = 1, r = cnt2, ans = -1;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(query(1, l, mid) <= fl2[i].arr){
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		if(ans == -1){
			++cnt2;
			modify(1,cnt2,fl2[i].leave);
			br2[cnt2]++;
		}
		else{
			br2[ans]++;
			modify(1,ans,fl2[i].leave);
		}
	}

	for (int i = 1; i <= cnt1; i ++){
		pre_br1[i] = pre_br1[i - 1] + br1[i];
	}
	for (int i = 1; i <= cnt2; i ++){
		pre_br2[i] = pre_br2[i - 1] + br2[i];
	}
	int ans = 0;
	for (int i = 0; i <= n; i ++){
		ans = max(pre_br1[i] + pre_br2[n - i], ans);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
