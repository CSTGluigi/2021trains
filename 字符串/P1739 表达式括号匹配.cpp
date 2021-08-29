#include"bits/stdc++.h"
using namespace std;
stack<char> x;
int main()
{
	
	while(1)
	{
		char a;
		scanf("%c",&a);
		if(a=='@')break;
		if(a=='(')
		x.push(a);
		else if(a==')')
		{
			if(x.size()==0)
			{
				printf("NO");
				return 0;
			}
			else x.pop();
		}
	}
	if(x.size()==0)printf("YES");
	else printf("NO");
	return 0;
}

