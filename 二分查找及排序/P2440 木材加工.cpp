#include"bits/stdc++.h"
using namespace std;
int a[500005],n,k;
bool judge(int x)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=x)cnt+=a[i]/x;
		if(cnt>=k)return 1;
	} 
	return 0;
}
int main() {
	int s=0,ma=0;
	scanf("%d%d",&n,&k);	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		s+=a[i];
		ma=max(ma,a[i]);
	}

	if(k==s)
	{
		printf("1");
		return 0;
	}
	if(k==1)
	{
		printf("%d",ma);
		return 0;
	}
	int le=1,ri=ma;
	while(le<=ri)
	{
		int mid=(le+ri)>>1;
		if(judge(mid))le=mid+1;
		else ri=mid-1;
	}
	printf("%d",ri);
	return 0;
}
