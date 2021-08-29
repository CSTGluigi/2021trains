#include"bits/stdc++.h"
using namespace std;
int a[100005],l,n,k;
bool judge(int x)
{
	int cnt=0,la=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]-la>=x)
			cnt+=(a[i]-la)/x;
		la=a[i];
		if(cnt>k)return 0;
	}
	return 1;
}
int main() {
	scanf("%d%d%d",&l,&n,&k);	
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	int le=1,ri=l;
	while(le<=ri)
	{
		int mid=(le+ri)>>1;
		if(judge(mid))ri=mid-1;
		else le=mid+1;
	}
	printf("%d",le);
	return 0;
}
