/*
time   :  2015-5-24
author :  ht
comment:  构造前缀树
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class TrieNode {
private:
	TrieNode *next[26];
	bool ed;
public:
	// Initialize your data structure here.
	TrieNode() {
		//每棵树可能有26个分支
		memset(next, 0, sizeof(TrieNode *) * 26);
		ed = false;
	}
	TrieNode *insert(char ch) {
		int p = ch - 'a';
		return next[p] = new TrieNode();
	}
	TrieNode *get(char ch) {
		int p = ch - 'a';
		return next[p];
	}
	void seted(bool val) {
		ed = val;
	}
	bool geted() {
		return ed;
	}
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string s) {
		TrieNode *r = root;
		for (int i = 0; i < s.length(); ++i) {
			TrieNode *p = r->get(s[i]);
			if (!p) {
				p = r->insert(s[i]);
			}
			r = p;
		}
		r->seted(true);
	}

	// Returns if the word is in the trie.
	bool search(string key) {
		TrieNode *r = root;
		for (int i = 0; i < key.length(); ++i) {
			r = r->get(key[i]);
			if (!r) return false;
		}
		return r->geted();
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode *r = root;
		for (int i = 0; i < prefix.length(); ++i) {
			r = r->get(prefix[i]);
			if (!r) return false;
		}
		return true;
	}

private:
	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main()
{
	Trie trie;
	trie.insert("helloworld");
	trie.insert("hellowory");
	bool result;
	result = trie.search("hellowory");
	if (result)
		cout << "In that trie!" << endl;
	return 0;
}