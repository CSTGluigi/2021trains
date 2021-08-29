#include"bits/stdc++.h"
using namespace std;
int a[100005],n,m,f;
bool judge(int x)
{
	int i,s=0,d=1;
	for(i=1;i<=n;i++)
	{
		if(a[i]>x)
		{
			f=0;	
			return 1;
		}
		if(s+a[i]>x)
		{
			s=a[i];
			d++;
		}
		else s+=a[i];
	}
	if(d<m)f=1;
	else if(d>m)f=0;
	else if(d==m)f=3;
	if(d==m&&s<=x)return 1;
	return 0;
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",a+i);
	int l=1,r=1e9;
	while(l<=r)
	{
		int mid=l+r>>1,b;
		judge(mid);
		if(f==3||f==1)r=mid-1;
		else l=mid+1;
	}
	printf("%d",l);
	return 0;
}
