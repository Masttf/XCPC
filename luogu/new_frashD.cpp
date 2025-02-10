#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int row1[maxn],row2[maxn],col1[maxn],col2[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//题意为插入线段有四种插法行头行尾列头列尾然后问你所能围成的最大面积方块
	int n,m,q;cin>>n>>m>>q;
	int a,ty,x;
	for(int i=1;i<=q;i++){
		cin>>a>>ty>>x;
		if(ty==1) row1[x]=a;
		else if(ty==2) row2[x]=a;
		else if(ty==3) col1[x]=a;
		else col2[x]=a;
	}
	
	return 0;
}
