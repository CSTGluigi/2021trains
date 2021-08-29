#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define INF 0x7fffffff
struct edge{
	ll lz,sum,l,r,mlz;//lz�Ǳ�ʾ��ǰ�������[l,r]�Ѿ�������lz�����ӽڵ�û������ 
}e[100005<<2];
ll arr[100005],mod=1e9+7;
void build(int i,int l,int r)
{
	e[i].l=l;
	e[i].r=r;
	e[i].mlz=1;
	if(l==r)
	{
		e[i].sum=arr[l]%mod;//l==rʱ�ӽڵ㣬���� 
		return;
	}
	build(i<<1,l,l+r>>1);
	build(i<<1|1,(l+r>>1)+1,r);
	e[i].sum=e[i<<1].sum%mod+e[i*2+1].sum%mod;
	e[i].sum%=mod;
}

void pushdown(ll i)//û�иı丸�ڵ��sum ����Ҫ�� 
{//ע���ڸı�lazytagʱlz��mlz���Ⱥ�˳�� 
	e[i<<1].mlz*=e[i].mlz;
	e[i<<1].mlz%=mod;
	e[i<<1].lz*=e[i].mlz;//��mlz 
	e[i<<1].lz%=mod;
	e[i<<1].lz+=e[i].lz;//��lz 
	e[i<<1].lz%=mod;
	            //���ڵ��mlz*�ӽڵ��sum 
	e[i<<1].sum=(e[i<<1].sum*e[i].mlz)%mod+(e[i].lz*(e[i<<1].r-e[i<<1].l+1))%mod;//���ڵ��lz*�ӽڵ������ 
	e[i<<1].sum%=mod;
	
	e[i<<1|1].mlz*=e[i].mlz;
	e[i<<1|1].mlz%=mod;
	e[i<<1|1].lz*=e[i].mlz;
	e[i<<1|1].lz%=mod;
	e[i<<1|1].lz+=e[i].lz;
	e[i<<1|1].lz%=mod;
	                //���ڵ��mlz*�ӽڵ��sum 
	e[i<<1|1].sum=(e[i<<1|1].sum*e[i].mlz)%mod+(e[i].lz*(e[i<<1|1].r-e[i<<1|1].l+1))%mod;//���ڵ��lz*�ӽڵ������  
	e[i<<1|1].sum%=mod;
	e[i].lz=0;
	e[i].mlz=1;
}
ll search(int i,int l,int r)
{
	if(e[i].l>=l&&e[i].r<=r)return e[i].sum;
	if(e[i].r<l||e[i].l>r)return 0;
	pushdown(i);
	ll s=0;
	if(e[i<<1].r>=l)s+=search(i<<1,l,r);
	s%=mod;
	if(e[i<<1|1].l<=r)s+=search(i<<1|1,l,r);
	return s%mod;
}
void add(int i,int l,int r,ll x)
{
	if(e[i].l>=l&&e[i].r<=r)
	{
		e[i].sum+=x*(e[i].r-e[i].l+1);
		e[i].sum%=mod;
		e[i].lz+=x;
		e[i].lz%=mod;
		return;
	}//���������ȫû�н����Ǿ�˳��pushdownһ�� 
	pushdown(i);
	if(e[i<<1].r>=l)add(i<<1,l,r,x);
	if(e[i<<1|1].l<=r)add(i<<1|1,l,r,x);
	e[i].sum=e[i<<1].sum+e[i<<1|1].sum;
	e[i].sum%=mod;
}
void mul(int i,int l,int r,ll x)
{
	if(e[i].l>=l&&e[i].r<=r)//�˷�Ҫ����lz��� 
	{
		e[i].sum*=x;
		e[i].sum%=mod;
		e[i].mlz*=x;
		e[i].mlz%=mod;
		e[i].lz*=x;
		e[i].lz%=mod;
		return;
	}//���������ȫû�н����Ǿ�˳��pushdownһ�� 
	pushdown(i);
	if(e[i<<1].r>=l)mul(i<<1,l,r,x);
	if(e[i<<1|1].l<=r)mul(i<<1|1,l,r,x);
	e[i].sum=e[i<<1].sum+e[i<<1|1].sum;
	e[i].sum%=mod;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m>>mod;
	for(int i=1;i<=n;i++)cin>>arr[i];
	build(1,1,n);
	while(m--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			ll l,r,k;
			cin>>l>>r>>k;
			mul(1,l,r,k);
		}
		else if(op==2)
		{
			ll l,r,k;
			cin>>l>>r>>k;
			add(1,l,r,k);
		}
		else
		{
			ll l,r;
			cin>>l>>r;
			cout<<search(1,l,r)%mod<<endl;
		 } 
	} 
	return 0;
}


