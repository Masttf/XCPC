#include<bits/stdc++.h>
using namespace std;
struct people{
	string name;
	int age;
	int grade;
}s[1000000];
int main(){
	int n;cin>>n;
	people s;
	for(int i=1;i<=n;i++){
		cin>>s.name>>s.age>>s.grade;
		s.age++;
		s.grade*=1.2;
		if(s.grade>600)s.grade=600;
		cout<<s.name<<' '<<s.age<<' '<<s.grade<<'\n';
	}
	return 0;
}
