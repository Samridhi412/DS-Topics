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
#define d 256
int naive(string text,string pat){
	int count=0;
	int n=text.size();
	int m=pat.size();
	int j;
	for(int i=0;i<=n-m;i++){
		for(j=0;j<m;j++){
			if(text[i+j]!=pat[j]){
				break;
			}
		}
		if(j==m){
			cout<<"pattern found at index"<<i<<endl;
			count++;
		}
	}
	return count;
}
void compute_lps(string pat,int* lps,int m){
	int len=0;
	lps[0]=0;
	int i=1;
	while(i<m){
		if(pat[i]==pat[len]){
			len++;
			lps[i]=len;
			i++;
		}
		else{
			if(len!=0)len=lps[len-1];
			else{
				lps[i]=0;
				i++;
			}
		}
	}
}
int kmp(string text,string pat){
	int n=text.size();
	int m=pat.size();
	int lps[m];
	int count=0;
	compute_lps(pat,lps,m);
	int i=0,j=0;
	while(i<n){
		while(j<m&&text[i]==pat[j]){
			i++;
			j++;
		}
		if(j==m){
			cout<<"pattern found at index"<<i-j<<endl;
			j=lps[j-1];
			count++;
		}
		else{
			if(j!=0){
				j=lps[j-1];
			}
			else{
				i=i+1;
			}
		}
	}
	return count;
	
}
int rabin_karp(string text,string pat){
	int n=text.size();
	int m=pat.size();
	int p=0;
	int t=0;
	int h=1;
	int q=101;
	int count=0;
	for(int i=0;i<m-1;i++){
		h=(h*d)%q;
	}
	for(int i=0;i<m;i++){
		p=(d*p+pat[i])%q;
		t=(d*t+text[i])%q;
	}
	int j;
	for(int i=0;i<=n-m;i++){
		if(p==t){
			bool flag=true;
			for(j=0;j<m;j++){
				if(text[i+j]!=pat[j]){
					flag=false;
					break;
				}
				// if(flag)cout<<i<<" ";
			}
			if(flag){
				count++;
				cout<<"pattern found at index"<<i<<endl;
			}
		}
		if(i<n-m){
			t=(d*(t-text[i]*h)+text[i+m])%q;
			if(t<0){
				t=t+q;
			}
		}
	}
	return count;
}
void compute_zarr(string concat,int n,int* z_arr){
	int l=0,r=0;
	int k=1;
	z_arr[0]=0;
	while(k<n){
		if(k>r){
			l=k;
			r=k;
			while(r<n&&concat[r]==concat[r-l])r++;
			z_arr[k]=r-l;
			r--;
		}
		else{
			int k1=k-l;
			if(z_arr[k1]<r-k+1){
				z_arr[k]=z_arr[k1];
			}
			else{
				l=k;
				while(r<n&&concat[r]==concat[r-l])r++;
				z_arr[k]=r-l;
				r--;
			}
		}
	}
	
}
int z_algo(string text,string pat){
	int n=text.size();
	int m=pat.size();
	int count=0;
	string concat=pat+"$"+text;
	int len=concat.size();
	int z_arr[len];
	compute_zarr(concat,len,z_arr);
	for(int i=0;i<len;i++){
		if(z_arr[i]==m){
			count++;
			cout<<"pattern found at index"<<i-m-1<<endl;
		}
	}
	return count;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string text,pat;
	getline(cin,text);
	getline(cin,pat);
	// cin>>text>>pat;
	// cout<<naive(text,pat)<<endl;
	// cout<<kmp(text,pat)<<endl;
	// cout<<rabin_karp(text,pat)<<endl;
	cout<<z_algo(text,pat)<<endl;
	return 0;
}