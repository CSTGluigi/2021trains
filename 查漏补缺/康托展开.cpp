#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define maxn 1000006
#define int long long
int d1[maxn],n,m;
int lowbit(int x){return x&(-x);}
void add(int pos,int val)
{
	for(int i=pos;i<=n;i+=lowbit(i))
	{
		d1[i]+=val;
	}
}
int sum(int pos)
{
	int ans=0;
	for(int i=pos;i>0;i-=lowbit(i))
	{
		ans+=d1[i];
	}
	return ans;
}
ll mod=998244353; 
int jc[1000006];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	jc[1]=1;
	jc[0]=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	add(i,1);
	for(int i=2;i<=n;i++)jc[i]=(jc[i-1]*(i%mod))%mod;
	ll ans=1;
	for(int i=1;i<=n;i++)
	{
		int ls;
		cin>>ls;
		int ls1=sum(ls)-1;
		ans=ans+((ls1%mod)*(jc[n-i]%mod))%mod;
		ans%=mod;
		add(ls,-1);
	}
	cout<<ans;
	return 0;
}


