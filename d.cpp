#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n),b(n);
	for(auto &i:a)cin >> i;
	for(auto &i:b)cin >> i;

	int ans = 0;
	for(int bit = 0;bit<29;bit++){
		vector<int> c;
		for(int i = 0;i<n;i++){
			c.push_back(b[i]&((1<<(bit+1))-1));
		}
		sort(c.begin(),c.end());
		ll now = 0;
		for(auto &i:a){
			int x = i&((1<<(bit+1))-1);
			now += lower_bound(c.begin(),c.end(),(1<<(bit+1))-x)-lower_bound(c.begin(),c.end(),(1<<(bit))-x);
		}
		for(auto &i:a){
			int x = i&((1<<(bit+1))-1);
			now += lower_bound(c.begin(),c.end(),(1<<(bit+2))-x)-lower_bound(c.begin(),c.end(),((1<<(bit+1))+(1<<(bit)))-x);
		}
		if(now%2)ans += 1<<bit;
	}
	cout<<ans<<endl;
}
