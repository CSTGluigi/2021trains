#include<bits/stdc++.h>
using namespace std;
#define maxn 1000050
int m,n,a[maxn];
int ler(int x)
{
	int l=1,r=m,an=l;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(a[mid]>=x)r=mid-1;
		else l=mid+1;
		if(a[mid]<x)an=mid;
		else if(a[mid]==x)return 0;
	}
	return abs(a[an]-x);
}
int rer(int x)
{
	int l=1,r=m,an=r;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(a[mid]<=x)l=mid+1;
		else r=mid-1;
		if(a[mid]>x)an=mid;
		else if(a[mid]==x)return 0;
	}
	return abs(a[an]-x);
}
int main()
{
	long long ans=0;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	scanf("%d",a+i);
	sort(a+1,a+1+m);
	for(int i=1;i<=n;i++)
	{
		int ls,ai,b;
		scanf("%d",&ls);
		ai=ler(ls);
		b=rer(ls);
		ans+=min(ai,b);
	}
	printf("%lld",ans);
    return 0;
}
