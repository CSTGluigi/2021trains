#include"bits/stdc++.h"
using namespace std;
char a[60];
int main()
{
	int n;
	scanf("%d",&n);
	scanf(" %s",a+1);
	for(int i=1;a[i]!=0;i++)
	if(a[i]+n<='z')a[i]=a[i]+n;
	else a[i]=a[i]+n-'z'+'a'-1;
	printf("%s",a+1);
	return 0;
}

