#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
const ld eps=1e-9;
const ll maxn=1e5+1;
const ll inf=5e18;
const ll minf=-inf;
#define mp make_pair
#define pb push_back
#define endl "\n"
void solve(){
	ll n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	ll k;
	cin>>k;
	
	int j=0;
	int i=0;
	vector<int> res;
	deque<int> dq;
	while(j<n){
	if(arr[j]<0){
		dq.push_back(j);
	}
	if(j-i+1<k){
		j++;
	}
	else if(j-i+1==k){
		if(dq.empty())res.push_back(0);
		else res.push_back(arr[dq.front()]);
		if(!dq.empty()&&dq.front()==j-k+1)dq.pop_front();
		i++;
		j++;
	}
}
	for(auto x:res){
		cout<<x<<" ";
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}