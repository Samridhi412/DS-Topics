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
bool canFormPallindrome(string& x){
	
}
string solution (string &S) {
	int n=S.length();
	string res="T";
	for (int i=1;i<=n;i++){
string x=S.substr(0,i);
if(canFormPallindrome (x)){
res+="T";
} else{
res+="F";
}
}
return res;
}