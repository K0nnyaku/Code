#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
typedef long long ll;
using namespace std;
ll read(){
   ll x=0,f=1;char c=getchar();
   while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
   while(isdigit(c))x=x*10+c-'0',c=getchar();
   return x*f;
}
int n,m1,m2;
const int N=2e5;
pair<ll,ll> a[N],b[N];
ll ca[N],cb[N];
priority_queue<ll,vector<ll>,greater<ll> > q1;
priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > q2;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout); 
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++)
		a[i].first=read(),a[i].second=read();
	for(int i=1;i<=m2;i++)
		b[i].first=read(),b[i].second=read(); 
	sort(a+1,a+1+m1);
	sort(b+1,b+1+m2);
	while(!q1.empty())q1.pop();
	while(!q2.empty())q2.pop();
	for(int i=1;i<=m1;i++)
		q1.push(i);
	for(int i=1;i<=m1;i++){
		while(!q2.empty()&&q2.top().first<a[i].first){
			q1.push(q2.top().second),q2.pop();
		}
		ll x=q1.top();
		ca[x]++;
		q1.pop();
		q2.push(make_pair(a[i].second,x));
	}
	while(!q1.empty())q1.pop();
	while(!q2.empty())q2.pop();
	for(int i=1;i<=m2;i++)
		q1.push(i);
	for(int i=1;i<=m2;i++){
		while(!q2.empty()&&q2.top().first<b[i].first){
			q1.push(q2.top().second),q2.pop();
		}
		ll x=q1.top();
		cb[x]++;
		q1.pop();
		q2.push(make_pair(b[i].second,x));
	}
	for(int i=1;i<=m1;i++)
		ca[i]+=ca[i-1];
	for(int i=1;i<=m2;i++)
		cb[i]+=cb[i-1];
	long long ans=0;
	for(int i=n;i>=0;i--)
		ans=max(ans,ca[i]+cb[n-i]);
	cout<<ans<<endl;
	return 0;
}
/*
3 5 4 
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16

2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
10 100 100
13 956
463 517
281 586
540 636
103 573
890 893
45 639
23 320
305 667
556 775
630 716
529 1000
173 741
174 276
6 51
724 763
291 663
334 401
250 511
373 710
467 696
265 449
317 432
92 955
14 707
411 860
603 643
251 874
190 705
9 310
285 539
408 615
861 951
319 413
368 714
264 688
271 670
43 353
792 872
240 770
2 348
325 687
253 750
464 509
543 704
963 989
4 998
148 198
698 899
532 929
50 149
41 168
255 802
246 768
252 656
237 363
146 151
70 119
364 477
578 936
771 809
551 952
434 903
535 609
607 948
446 828
311 313
758 937
62 122
11 614
909 947
898 918
201 862
178 421
176 269
38 420
513 754
67 175
254 360
740 912
134 225
141 922
87 111
553 751
234 331
329 452
783 810
55 162
136 322
762 977
387 856
314 815
653 935
442 817
36 212
362 949
30 637
737 832
53 999
159 531
431 796
215 385
63 718
395 647
289 298
488 545
7 438
596 876
611 628
1 699
61 278
286 367
196 220
25 645
772 914
323 328
537 984
465 501
445 672
19 709
581 953
126 550
88 326
969 994
184 245
247 346
284 660
339 407
338 584
599 703
199 224
959 974
365 826
496 519
34 980
73 835
624 712
171 209
419 466
40 934
189 476
559 646
577 804
816 821
376 435
392 572
793 852
306 495
457 593
206 340
127 512
161 260
273 855
669 897
95 892
824 849
72 524
48 86
576 585
5 927
487 561
676 819
107 734
143 781
642 674
28 129
514 695
137 294
94 978
390 957
147 261
482 652
12 403
571 941
399 961
681 789
83 181
230 853
564 764
542 732
394 654
283 827
106 790
486 993
56 480
105 931
910 991
379 469
479 689
104 414
612 800
798 850
785 799
185 337
15 973
791 807
610 728
396 923
277 884
69 79

*/














