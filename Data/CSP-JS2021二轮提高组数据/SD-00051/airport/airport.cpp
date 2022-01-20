#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct node{
	int s,e;
};
node a[300001],b[300001];
struct ode{
	int xh,sz,fl;
};
ode pre[300001];
int n,m1,m2,maxa=-0x7ffffff,cnt,pos;
int gn[100001],gj[100001],tp[300001]={0};
priority_queue<int,vector<int>,greater<int> > q;
priority_queue<int,vector<int>,greater<int> > que;
bool cmp(node c,node d)
{
	return c.s<d.s;
}
bool cmp2(ode c,ode d)
{
	return c.sz<d.sz;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&a[i].s,&a[i].e);
	}
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&b[i].s,&b[i].e);	
	}
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	for(int i=1;i<=m1;i++)
	{
		pre[i].sz=a[i].s;
		pre[i].xh=i;
		pre[i].fl=0;
		pre[m1+i].sz=a[i].e;
		pre[m1+i].xh=i;
		pre[m1+i].fl=1;
	}
	sort(pre+1,pre+(2*m1)+1,cmp2);
	for(int i=1;i<=2*m1;i++)
	{
		if(pre[i].fl==1)
		{
			a[pre[i].xh].e=i;
			continue;
		}
		if(pre[i].fl==0)
		{
			a[pre[i].xh].s=i;
			continue;
		}
	}
	memset(pre,0,sizeof(pre));
	for(int i=1;i<=n;i++)
	{
		q.push(a[1].e);
		cnt=1;
		pos=2;
		for(int j=a[1].s+1;j<=2*m1;j++)
		{
			if(!q.empty())
		{
		int tmp=q.top();
		if(tmp==j)
		{
			q.pop();
			cnt--;
		}
		}
		if(b[pos].s==j&&q.size()<i)
		{
			cnt++;
			q.push(a[pos].e);
			gn[i]++;
			pos++;
		}
	}
	while(!q.empty())
	{
		q.pop();
	}
	}
	//
	for(int i=1;i<=m2;i++)
	{
		pre[i].sz=b[i].s;
		pre[i].xh=i;
		pre[i].fl=0;
		pre[m2+i].sz=b[i].e;
		pre[m2+i].xh=i;
		pre[m2+i].fl=1;
	}
	sort(pre+1,pre+(2*m2)+1,cmp2);
	for(int i=1;i<=2*m2;i++)
	{
		if(pre[i].fl==1)
		{
			b[pre[i].xh].e=i;
			continue;
		}
		if(pre[i].fl==0)
		{
			b[pre[i].xh].s=i;
			continue;
		}
	}
	memset(pre,0,sizeof(pre));
	memset(tp,0,sizeof(tp));
	for(int i=1;i<=n;i++)
	{
		que.push(b[1].e);
		cnt=1;
		pos=2;
		for(int j=b[1].s+1;j<=2*m2;j++)
		{
			if(!que.empty())
		{
		int tmp=que.top();
		if(tmp==j)
		{
			que.pop();
			cnt--;
		}
		}
		if(b[pos].s==j&&que.size()<i)
		{
			cnt++;
			que.push(b[pos].e);
			gj[i]++;
			pos++;
		}
	}
	while(!que.empty())
	{
		que.pop();
	}
	}
	for(int i=0;i<=n;i++)
	{
		maxa=max(maxa,gn[i]+gj[n-i]);
	}
	printf("%d\n",maxa);
	cout<<gn[0]<<" "<<gj[2]<<endl;
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
2 4 6 20 30 40 50 21 22 41 42 1 19 2 18 3 4 5 6 7 8 9 10
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

