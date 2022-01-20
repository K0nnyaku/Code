#include<bits/stdc++.h>
using namespace std;
int T,n,a[1000001],ans[1000001],t[1000001],e[1000001];
bool flag;
void print(){
	int l=1,r=(n<<1);
	for(int i=1;i<=(n<<1);i++){
		if(ans[l]==i){
			putchar('L');
			l++;
		}else{
			putchar('R');
			r--;
		}
	}
	putchar('\n');
}
bool work1(){
	int k=e[1];
	ans[1]=1;
	ans[k]=(n<<1);
	int l1=2,r1=(n<<1)-(k==(n<<1));
	int l2=k-1,r2=k+1;
	for(int i=1;i<n;i++){
		if(a[l1]==a[l2]&&l1<l2){
			ans[l1]=i+1;
			ans[l2]=n-i;
			l1++;
			l2--;
		}else if(a[l1]==a[r2]&&l1<=l2&&r2<=r1){
			ans[l1]=i+1;
			ans[r2]=n-i;
			l1++;
			r2++;
		}else if(a[r1]==a[r2]&&r1>r2){
			ans[r1]=i+1;
			ans[r2]=n-i;
			r1--;
			r2++;
		}else if(a[r1]==a[l2]&&r1>=r2&&l2>=l1){
			ans[r1]=i+1;
			ans[l2]=n-i;
			r1--;
			l2--;
		}else{
			return false;
		}
	}
	return true;
}
bool work2(){
	int k=e[(n<<1)];
	ans[(n<<1)]=1;
	ans[k]=(n<<1);
	int l1=1+(k==1),r1=(n<<1)-1;
	int l2=k-1,r2=k+1;
	for(int i=1;i<n;i++){
		if(a[l1]==a[l2]&&l1<l2){
			ans[l1]=i+1;
			ans[l2]=n-i;
			l1++;
			l2--;
		}else if(a[l1]==a[r2]&&l1<=l2&&r2<=r1){
			ans[l1]=i+1;
			ans[r2]=n-i;
			l1++;
			r2++;
		}else if(a[r1]==a[r2]&&r1>r2){
			ans[r1]=i+1;
			ans[r2]=n-i;
			r1--;
			r2++;
		}else if(a[r1]==a[l2]&&r1>=r2&&l2>=l1){
			ans[r1]=i+1;
			ans[l2]=n-i;
			r1--;
			l2--;
		}else{
			return false;
		}
	}
	return true;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=(n<<1);i++){
			t[i]=0;
		}
		for(int i=1;i<=(n<<1);i++){
			scanf("%d",&a[i]);
			if(t[a[i]]==0){
				t[a[i]]=i;
			}else{
				e[i]=t[a[i]];
				e[t[a[i]]]=i;
			}
		} 
		flag=work1();
		if(flag){
			print();
			continue;
		}
		flag=work2();
		if(flag){
			print();
			continue;
		}
		printf("-1\n");
	}
	return 0;
}
