#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define INF 0x7fffffff
#define N 1000000

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	double a,b,c,s,c2;
	cin>>a>>b>>c;
	c2=a+b+c;
	c2/=2;
	s=sqrt(c2*(c2-a)*(c2-b)*(c2-c));
	cout<<s;
	return 0;
}


