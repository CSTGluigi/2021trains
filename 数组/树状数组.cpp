//洛谷p3372   线段树    
//要求实现   区间加减及求值 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define maxn 100006
#define int long long
int d[maxn],d1[maxn],di[maxn],n,m;//d是差分数组，d1是对差分数组的树状数组  di是当前树状数组的值乘以它的位置 
int lowbit(int x){return x&(-x);}//取当前数2进制最低位代表的数字 
void add(int pos,int val)
{
	for(int i=pos;i<=n;i+=lowbit(i))//因为是差分数组所以在l位置加了k后要在后面所有的位置都加上k来实现区间的加减 
	{
		d1[i]+=val;
		di[i]+=val*pos;//维护这个是为了求和的时候用公式 Σa[i] (i从1到k) = Σ(k+1) * d[i] - i * d[i] (i从1到k) 
	}
}
int sum(int pos)
{
	int ans=0;
	for(int i=pos;i;i-=lowbit(i))
	{
		ans+=(pos+1)*d1[i]-di[i];//直接套公式遍历一遍 
	}
	return ans;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int res=0;
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
		int t=d[i];
		d[i]=d[i]-res;//直接求差分 
		res=t;
	}
	for(int i=1;i<=n;i++)
	add(i,d[i]);//构建初始的对差分数组的树状数组 
	while(m--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int l,r,k;
			cin>>l>>r>>k;
			add(l,k);
			add(r+1,-k);//前面操作对r+1后面的增加是多余的所以要减去 
		}
		else 
		{
			int l,r;
			cin>>l>>r;
			cout<<sum(r)-sum(l-1)<<endl;//公式 
		}
	}
	return 0;
}

