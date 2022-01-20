#include<bits/stdc++.h>
using namespace std;
inline long long read() {
	long long x=0,w=1;
	char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')
		ch=getchar();
	if(ch=='-') {
		w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*w;
}
int T;
int n,a[10000];
struct node{
	int l,r;
}b[10000],ansss[10000];
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--) {
		n=read();
		for(int i=1; i<=2*n; i++) {
			cin>>a[i];
			if(b[a[i]].l>0)
				b[a[i]].r=i;//a[i]的都二个位置 
			else
				b[a[i]].l=i;//a[i]的都一个位置 
		}
		for(int i=1;i<=n;i++)
		cout<<b[i].l<<" "<<b[i].r<<endl; 
		if(a[1]==a[2*n]) {
			cout<<-1<<endl;
			continue;
		}
		int mq=a[1];
		int l=2,r=2*n;
		cout<<"L";
		int cnttt=1;
		while(cnttt<n) {
			if(a[b[mq].r+1]==a[l]){
				mq=a[b[a[l]].r];
				l++;
				b[mq].l=b[mq].r;
				cout<<"L";
				cnttt++;
				ansss[cnttt].l=mq;
				ansss[cnttt].r=1;
			//	cout<<1;
			}
			else if(a[b[mq].r-1]==a[l])
			{
				mq=a[b[a[l]].r];
				l++;
				b[mq].l=b[mq].r;
				cout<<"L";
				cnttt++;
					ansss[cnttt].l=mq;
					ansss[cnttt].r=1;
			//	cout<<2;
			}
			else if(a[b[mq].r-1]==a[r])
			{
				mq=a[b[a[r]].l];
				b[mq].r=b[mq].l;
				cout<<"R";
				cnttt++;
					ansss[cnttt].l=mq;
					ansss[cnttt].r=2;
			//	cout<<3;
				r--;
			}
			else if(a[b[mq].r+1]==a[r])
			{
				mq=a[b[a[r]].l];
			//	cout<<"%"<<mq<<"%";
				b[mq].r=b[mq].l;
			//	cout<<b[mq].r;
				cout<<"R";
				cnttt++;
				ansss[cnttt].l=mq;
				ansss[cnttt].r=2;
			//	cout<<4;
				r--;
			}
		}
		while(l<r){
			for(int i=1;i<cnttt;i++)
			{
				if(ansss[i].l==a[l])
				{
					cout<<"L";
					l++;
				}
				else
				{
					cout<<"R";
					r--;
				}
				
			 } 
			 cout<<"L";
		}
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
