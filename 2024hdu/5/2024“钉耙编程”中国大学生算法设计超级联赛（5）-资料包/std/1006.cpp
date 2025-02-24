#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("cancat.in","r",stdin);
	//freopen("cancat.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if((a&-a)==(b&-b)&&(b&-b)==(c&-c))printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
