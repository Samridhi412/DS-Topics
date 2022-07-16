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
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<int>res;
	int k;
	cin>>k;
	int i=0;
	int j=0;
	deque<int> dq;
	while(j<n){
		while(!dq.empty()&&dq.front()==j-k)dq.pop_front();
		while(!dq.empty()&&arr[dq.back()]<arr[j]){
			dq.pop_back();
		}
		dq.push_back(j);
		if(j>=k-1){
			res.push_back(arr[dq.front()]);
		}
	j++;
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