#pragma GCC optimize("O2")
#include<bits/stdc++.h>
#define ll   long long
#define pb   emplace_back
#define mp   make_pair
#define orz  1000000007
#define fi   first
#define se   second
using namespace std;
char a[12][12],c[12][12];
int main(){
	for(int i=0;i<9;++i)scanf("%s",a[i]);
	for(int i=0;i<9;++i){
		for(int j=0;j<9;++j)c[i][j]='*';
	}
	for(int i=3;i<=5;++i){
		for(int j=3;j<=5;++j)if(a[i][j]=='8')c[i][j]='8';
	}
	for(int i=0;i<9;++i)printf("%s\n",c[i]);
    return 0;
}

