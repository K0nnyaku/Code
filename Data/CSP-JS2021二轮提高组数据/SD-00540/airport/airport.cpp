#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 100010
using namespace std;
struct node{
	int st,ed;
};
node ta[N],tb[N];
int tima[N],timb[N],sta[N],stb[N],li[N];
int n,ma,mb;
int maxtimb=0,maxtima=0;
int top=0;
void fuck(){
	sort(li+1,li+top+1);
	for(int i=1;i<=ma;i++){
		ta[i].st=lower_bound(li+1,li+top+1,ta[i].st)-li;
		ta[i].ed=lower_bound(li+1,li+top+1,ta[i].ed)-li;
	}
	for(int i=1;i<=mb;i++){
		tb[i].st=lower_bound(li+1,li+top+1,tb[i].st)-li;
		tb[i].ed=lower_bound(li+1,li+top+1,tb[i].ed)-li;
	}
}
int find_a(int x){
	int now=0,ans=0;
	for(int i=1;i<=maxtima;i++){
		if(tima[i]==1){
			if(now+1<=x){
				now++;
				ans++;
				tima[sta[i]]=-1;
			}
		}
		else if(tima[i]==-1) now--;
	}
	return ans;
}
int find_b(int x){
	int ans=0,now=0;
	for(int i=1;i<=maxtimb;i++){
		if(timb[i]==1&&now+1<=x){
			ans++;
			now++;
			timb[stb[i]]=-1;
		} 
		else if(timb[i]==-1) now--;
	}
	return ans;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&ma,&mb);
	for(int i=1;i<=ma;i++){
		scanf("%d%d",&ta[i].st,&ta[i].ed);
		li[++top]=ta[i].st;
		li[++top]=ta[i].ed;
	} 
	for(int i=1;i<=mb;i++){
		scanf("%d%d",&tb[i].st,&tb[i].ed);
		li[++top]=tb[i].st;
		li[++top]=tb[i].ed;
	} 
	fuck();
	for(int i=1;i<=ma;i++){
		int st=ta[i].st,ed=ta[i].ed;
		sta[st]=ed;
		tima[st]=1;
		maxtima=max(maxtima,ed);
	}
	for(int i=1;i<=mb;i++){
		int st=tb[i].st,ed=tb[i].ed;
		stb[st]=ed;
		timb[st]=1;
		maxtimb=max(maxtimb,ed);
	}
	int final=0;
	for(int i=0;i<=n;i++){
		int j=n-i;
		final=max(final,find_a(i)+find_b(j));
	}
	printf("%d",final);
	fclose(stdin);
	fclose(stdout);
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
*/
/*
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
*/
/*
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
// 32
