#include<bits/stdc++.h>
#define llong long long
#define ldouble long double
#define ushort unsigned short
#define uint unsigned int
#define ulong unsigned long
#define ullong unsigned llong
using namespace std;
;
int n,a[10005],ma = -0x7fffffff;
int main(){
;
cin>>n;
;
for(int i = 1;i <= n;i++){;
cin>>a[i];
ma= max(ma,a[i]);
};
cout<<ma<<endl;
system("pause");
return 0;
};
