#include<bits/stdc++.h>
using namespace std;

string a;
int main()
{
    int s=0,l;
    getline(cin,a);
    l=a.length();
    for(int i=0;i<l;i++)
    {
        if(a[i]==' '){
            s++;
            continue;
        }
        if(a[i]>='a'&&a[i]<='c'){
            s+=a[i]+1-'a';
            continue;
        }
        if(a[i]>='d'&&a[i]<='f'){
            s+=a[i]+1-'d';
            continue;
        }
        if(a[i]>='g'&&a[i]<='i'){
            s+=a[i]+1-'g';
            continue;
        }
        if(a[i]>='j'&&a[i]<='l'){
            s+=a[i]+1-'j';
            continue;
        }
        if(a[i]>='m'&&a[i]<='o'){
            s+=a[i]+1-'m';
            continue;
        }
        if(a[i]>='p'&&a[i]<='s'){
            s+=a[i]+1-'p';
            continue;
        }
        if(a[i]>='t'&&a[i]<='v'){
            s+=a[i]+1-'t';
            continue;
        }
        if(a[i]>='w'&&a[i]<='z'){
            s+=a[i]+1-'w';
        }
    }
    printf("%d",s);
    return 0;
}

