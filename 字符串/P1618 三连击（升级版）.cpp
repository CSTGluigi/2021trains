#include"bits/stdc++.h"
using namespace std;
int main()
{
	int a[9]={1,2,3,4,5,6,7,8,9},f=0;
	double d,b,c,s,s1,s2,s3,sab,sac;

	scanf("%lf%lf%lf",&d,&b,&c);
		sab=b/d;
	sac=c/d;
	s1=a[0]*100+a[1]*10+a[2];
	s2=a[3]*100+a[4]*10+a[5];
	s3=a[6]*100+a[7]*10+a[8];
	if(fabs(s1*sab-s2)<1e-6&&fabs(s1*sac-s3)<1e-6)
	{
		f=1;
		printf("%.0f %.0f %.0f\n",s1,s2,s3);
	}
	while(next_permutation(a,a+9))
	{
		s1=a[0]*100+a[1]*10+a[2];
		s2=a[3]*100+a[4]*10+a[5];
		s3=a[6]*100+a[7]*10+a[8];
		if(fabs(s1*sab-s2)<1e-6&&fabs(s1*sac-s3)<1e-6)
		{
			f=1;
			printf("%.0f %.0f %.0f\n",s1,s2,s3);
		}
	}
	if(f==0)printf("No!!!");
	return 0;
}

