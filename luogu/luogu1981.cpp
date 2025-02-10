#include<bits/stdc++.h>
using namespace std;
int main(){
	stack<long long> a;
	stack<char> b;
	string s,us;
	long long head,tail,n=0;
	head=0;
	cin>>s;
	long long o=0;
	long long l=s.size();
	for(long long i=0;i<l;i++){
		if(s[i]=='+'||s[i]=='*'||i==l-1){
			tail=i;
			long long u1=0;
			if(i==l-1){
				for(long long j=head;j<=tail;j++){
					u1=u1*10;
					u1=u1+(s[j]-'0');
				}
			}
			else{
				for(long long j=head;j<tail;j++){
					u1=u1*10;
					u1=u1+(s[j]-'0');
				}
			}
			if(!b.empty()&&!a.empty()&&b.top()=='*'){
				long long u2=a.top();
				a.pop();
				u1=(u1*u2)%10000;
				b.pop();
			}
			head=i+1;
			a.push(u1);
			b.push(s[i]);
			n++;
		}
	}
	long long ks=0;
	while(!a.empty()&&!b.empty()){
		ks=(ks+a.top())%10000;
		a.pop();
		b.pop();
	}
	cout<<ks;
	return 0;
}
