#include"bits/stdc++.h"
using namespace std;
struct jq{
	int a,b;
	double ti;
}ji[100005];
int n,p,c[100005];
bool judge(double x)
{
	int i;
	double cnt=p*x;
	for(i=1;i<=n;i++)
		if(x>ji[i].ti)
			cnt-=(x-ji[i].ti)*ji[i].a;
	if(cnt>=0)return 1;
	return 0;
}
bool cmp(jq x,jq y)
{
	if(x.b!=y.b)return x.ti<y.ti;
	return x.a<y.a;
}
int main() {
	scanf("%d%d",&n,&p);	
	double le=0,ri=1e20,s=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&ji[i].a,&ji[i].b);
		ji[i].ti=ji[i].b*1.0/(ji[i].a);
		s+=ji[i].a;
	}
	if(p>=s)
	{
		printf("-1");
		return 0;
	}
	while(le<=ri)
	{
		double mid=(le+ri)*1.0/2;
		if(judge(mid))le=mid+0.00001;
		else ri=mid-0.00001;
	}
	printf("%lf",ri);
	return 0;
}
