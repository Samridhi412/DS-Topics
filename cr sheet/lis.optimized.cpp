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
// 5 4 11 1 16 8
#define endl "\n"
void lis(int* values,int n){
	vector<int> temp;
	int len=0;
	temp.push_back(values[0]);
	len++;
	for(int i=1;i<n;i++){
		if(values[i]>temp.back()){
			temp.push_back(values[i]);
			len++;
		}
		int ind=lower_bound(temp.begin(),temp.end(),values[i])-temp.begin();
		temp[ind]=values[i];
	}
	cout<< len;
}
void solve(){
	int n;
	cin>>n;
	int values[n];
	for(int i=0;i<n;i++){
		cin>>values[i];
	}
	lis(values,n);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}