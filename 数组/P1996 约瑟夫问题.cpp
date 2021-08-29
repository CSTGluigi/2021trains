#include"bits/stdc++.h"
using namespace std;
int a[1000];
int main()
{
	int n,m,l=0,s=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	a[i]=i;
	for(int i=1;l!=n;i++)
	{
		if(i>n-l)i=1;
		if(s>m)s=1;
		if(s==m)
		{
			s++;
			printf("%d ",a[i]);
			for(int j=i;j<=n-l;j++)
			a[j]=a[j+1];
			l++;
			i--;
		}
		else s++;
	}
	return 0;
}

