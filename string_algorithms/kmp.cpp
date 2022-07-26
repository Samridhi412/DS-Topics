#include<bits/stdc++.h>
using namespace std;
void preprocess(int lps[],string& pat,int m){
	lps[0]=0;
	int l=0;
	int i=1;
	while(i<m){
		if(pat[i]==pat[l]){
			l++;
			lps[i]=l;
			i++;
		}
		else{
			if(l!=0){
				l=lps[l-1];
			}
			else{
				lps[i]=0;
				i++;
			}
		}
	}
}
void kmp(string& text,string& pat){
	int n=text.size();
	int m=pat.size();
	int lps[m];
	pat=pat+'#';
	preprocess(lps,pat,m+1);
	for(auto x:lps){
		cout<<x<<" ";
	}
	cout<<endl;
	int count=0;
	int prev=0;
	int l;
	for(int i=0;i<n;i++){
		l=prev;
		while(l>0&&text[i]!=pat[l]){
			l=lps[l-1];
		}
		if(text[i]==pat[l]){
			l++;
		}
		prev=l;
		if(l==m){
			cout<<"pattern found at index"<<i-m+1<<endl;
			count++;
		}
	}
	
	cout<<count<<endl;
}
int main(){
	string text,pat;
	getline(cin,text);
	getline(cin,pat);
	kmp(text,pat);
	return 0;
}