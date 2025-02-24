#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	//字符串比较先比较每一位大的就是大然后比较结束如果前面都一样比长度长度大的大
	//贪心除最后一位以外应该都一样最后是它的下一位然后都是z
	string s;cin>>s;
	int len=s.size();
	char temp=s[len-1];
	if(temp=='a'){
		for(int i=0;i<len-1;i++){
			cout<<s[i];
		}
		return 0;
	}
	s[len-1]=temp-1;
	while(m>len){
		s+='z';
		m--;
	}
	len=s.size();
	for(int i=0;i<len;i++){
		cout<<s[i];
	}
	return 0;
}
