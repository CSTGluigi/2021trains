#include"bits/stdc++.h"
using namespace std;
int n,f,y,flag=0;
bool judge(double x)
{
	int i;
	double cnt=n;
	for(i=1;i<=y;i++)
		if(cnt<0)break;
		else cnt=cnt-f+cnt*x;
    if(cnt==0)flag=1;
	if(cnt<=0)return 1;
	return 0;
}
int main() {
	scanf("%d%d%d",&n,&f,&y);	
	double le=0,ri=1000;
	while(le<=ri)
	{
		double mid=(le+ri)*1.0/2;
		if(judge(mid/100))le=mid+0.00001;
		else ri=mid-0.00001;
        if(flag==1)
        {
            printf("%.1f",mid);
			return 0;
        }
	}
	if(ri>=-0.05&&ri<=0.05)
	{
		printf("0.0");
		return 0;
	}
	printf("%.1lf",ri);
	return 0;
}
