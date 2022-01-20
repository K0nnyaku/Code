#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

FILE *fscore, *freport, *fstd, *fin, *fout;

int main(int argc, char *argv[])
{
	fscore = fopen(argv[5], "w");
	freport = fopen(argv[6], "w");
	
  int score = atoi(argv[4]);
	fstd = fopen(argv[3], "r");
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "r");
	
	if (!fout)
	{
		fprintf(fscore, "%d", 0);
		fprintf(freport, "no output");
	} else {
    double std_ans, your_ans;
    int cnt1 = 0, cnt2 = 0;
    while (fscanf(fstd, "%lf", &std_ans) > 0) {
      ++cnt1;
      if (fscanf(fout, "%lf", &your_ans) < 1) break; 
      
      long double delta1 = fabs(your_ans - std_ans);
      if (delta1 <= 1e-6) ++cnt2;
      else {
        fprintf(freport, "%.7lf\n%.7lf\n", std_ans, your_ans);
        break;
      }
    }
    if (cnt1 == cnt2) {
      fprintf(fscore, "%d", score);
      fprintf(freport, "AC");
    } else {
      fprintf(fscore, "%d", 0);
      fprintf(freport, "WA");
    }
	}
	
	fclose(fscore);
	fclose(freport);
}
