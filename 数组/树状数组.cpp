//���p3372   �߶���    
//Ҫ��ʵ��   ����Ӽ�����ֵ 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define maxn 100006
#define int long long
int d[maxn],d1[maxn],di[maxn],n,m;//d�ǲ�����飬d1�ǶԲ���������״����  di�ǵ�ǰ��״�����ֵ��������λ�� 
int lowbit(int x){return x&(-x);}//ȡ��ǰ��2�������λ��������� 
void add(int pos,int val)
{
	for(int i=pos;i<=n;i+=lowbit(i))//��Ϊ�ǲ������������lλ�ü���k��Ҫ�ں������е�λ�ö�����k��ʵ������ļӼ� 
	{
		d1[i]+=val;
		di[i]+=val*pos;//ά�������Ϊ����͵�ʱ���ù�ʽ ��a[i] (i��1��k) = ��(k+1) * d[i] - i * d[i] (i��1��k) 
	}
}
int sum(int pos)
{
	int ans=0;
	for(int i=pos;i;i-=lowbit(i))
	{
		ans+=(pos+1)*d1[i]-di[i];//ֱ���׹�ʽ����һ�� 
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
		d[i]=d[i]-res;//ֱ������ 
		res=t;
	}
	for(int i=1;i<=n;i++)
	add(i,d[i]);//������ʼ�ĶԲ���������״���� 
	while(m--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int l,r,k;
			cin>>l>>r>>k;
			add(l,k);
			add(r+1,-k);//ǰ�������r+1����������Ƕ��������Ҫ��ȥ 
		}
		else 
		{
			int l,r;
			cin>>l>>r;
			cout<<sum(r)-sum(l-1)<<endl;//��ʽ 
		}
	}
	return 0;
}

