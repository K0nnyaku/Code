#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
ll n,m1,m2;
ll ans;
struct node {
	ll a,b;
};
ll fl;
node ni[5050],wi[5050],nc[5050],wc[5050];
bool com(node x,node y) {
	return x.a<y.a;
}
ll work(ll nei,ll wai) {
	ll xx=1,yy=1,fll=0;
	nc[1]=ni[1];
	wc[1]=wi[1];
	fll+=2;
	for(ll i=2; i<=m1; i++) {
		for( ll j=1; j<=nei; j++) {
			if(ni[i].a>nc[j].b&&j<=xx) {
				fll++;
				nc[j]=ni[i];
                break;
			} else {
				if(xx<nei) {
					xx++;
					nc[xx]=ni[i];
					fll++;
					break;
				}

			}
		}
	}
	for(ll i=2; i<=m2; i++) {
		for( ll j=1; j<=wai; j++) {
			if(wi[i].a>wc[j].b&&j<=yy) {
				fll++;
				wc[j]=wi[i];
                break;
			} else {
				if(yy<wai) {
					yy++;
					wc[yy]=wi[i];
					fll++;
					break;
				}

			}
		}
	}
	return fll;
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(ll i=1; i<=m1; i++) {
		cin>>ni[i].a>>ni[i].b;

	}
	for(ll i=1; i<=m2; i++) {
		cin>>wi[i].a>>wi[i].b;

	}
	sort(ni+1,ni+m1+1,com);
	sort(wi+1,wi+m2+1,com);
	for(ll i=0; i<=n; i++) {
		ll nei=i,wai=n-i,fl=0;
		if(nei==0) {
			ll yy=1;
	        wc[1]=wi[1];
	        fl++;
	        for(ll i=2; i<=m2; i++) {
		        for( ll j=1; j<=wai; j++) {
			        if(wi[i].a>wc[j].b&&j<=yy) {
				        fl++;
				        wc[j]=wi[i];
				        break;
			        } else {
				        if(yy<wai) {
					        yy++;
					        wc[yy]=wi[i];
					        fl++;
					        break;
				        }
                    }
			
		        }
	        }
		} else if(wai==0) {
            ll xx=1;
	        nc[1]=ni[1];
	        fl++;
	        for(int i=2; i<=m1; i++) {
		        for( int j=1; j<=nei; j++) {
			        if(ni[i].a>nc[j].b&&j<=xx) {
				        fl++;
				        nc[j]=ni[i];
				        break;
			        } else {
				        if(xx<nei) {
					        xx++;
					        nc[xx]=ni[i];
					        fl++;
					        break;
				        }
                    }
			
		        }
	        }
		} else {
			fl=work(nei,wai);
		}
		ans=max(ans,fl);
	}
	cout<<ans;
	fclose(stdin);
    fclose(stdout);
	return 0;
}

