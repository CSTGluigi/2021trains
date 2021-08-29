#include"bits/stdc++.h"
using namespace std;
int a[100005],n,c;
bool judge(int x)
{
	int i,la=a[1],cnt=c-1;
	for(i=2;i<=n;i++)
		if(a[i]-la>=x)
		{
			cnt--;
			la=a[i];
		}
	if(cnt<=0)return 1;
	return 0;
}
int main() {
	scanf("%d%d",&n,&c);	
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	int le=1,ri=a[n];
	while(le<=ri)
	{
		int mid=(le+ri)>>1;
		if(judge(mid))le=mid+1;
		else ri=mid-1;
	}
	printf("%d",ri);
	return 0;
}
