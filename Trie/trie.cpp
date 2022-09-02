// INSERT WORDS IN TRIE--> struct or class 
#include<iostream>
using namespace std;
struct node{
	node* links[26];
	bool flag=false;
	bool containsKey(char ch){
		return (links[ch-'a']!=NULL);
	}
	void put(char ch,node* nn){
		links[ch-'a']=nn;
	}
	node* get(char ch){
		return links[ch-'a'];
	}
	bool setEnd(){
		flag=true;
	}
	bool isEnd(){
		return flag;
	}
};
class Trie{
	node* root;
public:
	Trie(){
		root=new node();
	}
	//tc: O(len of word)
	void insert(string word){
		node* nn=root;
		for(int i=0;i<word.size();i++){
			if(!nn->containsKey(word[i])){
				nn->put(word[i],new node());
			}
			//move to reference trie
			nn->get(word[i]);
		}
		nn->setEnd();
	}
	bool search(string word){
		node* nn=root;
		for(int i=0;i<word.size();i++){
			if(!nn->containsKey(word[i])){
				return false;
			}
			nn=nn->get(word[i]);
		}
		return nn->isEnd();
	}
	bool startswith(string word){
		node* nn=root;
		for(int i=0;i<word.size();i++){
			if(!nn->containsKey(word[i])){
				return false;
			}
			nn=nn->get(word[i]);
		}
		return true;
	}
};