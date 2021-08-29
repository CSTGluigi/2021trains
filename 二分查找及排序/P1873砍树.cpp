#include"bits/stdc++.h"
using namespace std;
#define int long long
int a[1000005],n,c;
bool judge(int x)
{
	long long i,cnt=0;
	for(i=1;i<=n;i++)
		if(a[i]-x>0)
			cnt+=a[i]-x;
	if(cnt>=c)return 1;
	return 0;
}
signed main() {
	scanf("%lld%lld",&n,&c);	
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	sort(a+1,a+n+1);
	int le=1,ri=a[n];
	while(le<=ri)
	{
		int mid=(le+ri)>>1;
		if(judge(mid))le=mid+1;
		else ri=mid-1;
	}
	printf("%lld",ri);
	return 0;
}
