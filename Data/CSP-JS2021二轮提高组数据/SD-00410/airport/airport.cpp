#include<bits/stdc++.h>
using namespace std;
struct plane {
	int wait;
	int waot;
	bool in;
};
void pushplane(int ans,int time,int let,int i,plane a[]) {
	if(let>0&&a[i].in==false) {
		a[i].in=true;
		let--;
		ans++;
	}
}
void popplane(int ans,int time,int let,int i,plane a[]) {
	if(a[i].in==true)let++;
}
int changplane(int let,int wai[],int wao[],int ans,int time,int hvi[]) {
	if(let>=0&&let>=wai[time]) {
		let-=wai[time];
		ans+=wai[time];
		hvi[time]=wao[time];
		let+=hvi[time];

	} else if(let>=0&&let<wai[time]) {

		ans+=let;
		hvi[time]=let;
		let=0;
		let+=hvi[time];
	}
	return ans;
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,nei,wai,ans=0,likx=0,maxt;
	cin>>n>>nei>>wai;
	plane gn[5005],gw[5005];
	int waii[5005]= {0},waio[5005]= {0},waoo[5005]= {0},waoi[5005]= {0},hvi[5005]= {0};
	for(int i=1; i<=nei; i++) {
		cin>>gn[i].wait>>gn[i].waot;
		gn[i].in=false;
		waii[gn[i].wait]++;
		waio[gn[i].waot]++;
		maxt=max(maxt,gn[i].wait);
	}
	for(int i=1; i<=wai; i++) {
		cin>>gw[i].wait>>gw[i].waot;
		gw[i].in=false;
		waoi[gn[i].wait]++;
		waoo[gn[i].waot]++;
		maxt=max(maxt,gw[i].wait);
	}
	for(int i=0; i<=n; i++) {
		int leti=i;
		int leto=n-i;
		for(int time=1; time<=maxt; time++) {
			for(int k=1; i<=nei; i++) {
				if(gn[k].wait==time&&leti>=0&&gn[k].in==false) {
					leti--;
					gn[k].in=true;
					ans++;
				}
				if(gn[k].waot==time&&gn[k].in==true) {
					leti++;
				}
			}
			for(int k=1; k<=wai; k++) {
				if(gw[k].wait==time&&leto>=0&&gw[k].in==false) {
					leto--;
					gw[k].in=true;
					ans++;
				}
				if(gw[k].waot==time&&gn[k].in==true) leto++;
			}
		}
		likx=max(likx,ans);
	}
	cout<<(likx+n-1);
	return 0;
}
