#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
ll  fp(ll x,ll m,ll k){
	ll res=1;
	x%=k;
	while(m)
	{
		if(m&1)res=res*x%k;
		m>>=1;
		x=x*x%k;
	}
	return res%k;
} 
int main()
{
	long long x,m,k;
	scanf("%lld%lld%lld",&x,&m,&k);
	printf("%lld^%lld mod %lld=%lld",x,m,k,fp(x,m,k));
}

