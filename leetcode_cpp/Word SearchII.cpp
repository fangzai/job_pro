/*
time   :  2015-5-29
author :  ht
comment:  word search的第二个版本
		  加了一些限制，主要就是优化搜索速度 有了字典树
*/
#include<iostream>
#include<cmath>
#include<string>
#include<stack>
#include<vector>
#include<unordered_set>
#include<set>
using namespace std;
/*
 * 我的word search里面用的是暴力搜索的方法
 * 这个题目提示要用prefix tree,这样的话就可以省下很搜索路径了
 */
 class Solution {
 public:
	 //这里是构造prefix的数据结构
     struct TriNode {
         TriNode *ch[26];
         bool isWord;
         TriNode() : isWord(false) { for (auto &a : ch) a = NULL;}
     } *root;
     
     void insert(string word)
	 {
		 //构建prefix tree
        TriNode *p = root;
        for (auto &a : word) 
		{
            int i = a - 'a';
            if (p->ch[i] == NULL) p->ch[i] = new TriNode();
            p = p->ch[i];
        }
         p->isWord = true;
     }
     
	 bool isPrefix(string word)
	 {
		 //搜索word是否是一个前缀
		 TriNode *p = root;
		 for (auto &a : word)
		 {
			 int i = a - 'a';
			 if (p->ch[i] == NULL) return false;
			 p = p->ch[i];
		 }
		 return true;
	 }

	 bool isWord(string word)
	 {
		 TriNode *p = root;
		 for (auto &a : word)
		 {
			 int i = a - 'a';
			 if (p->ch[i] == NULL) return false;
			 p = p->ch[i];
		 }
		 //搜索 word是否在字典中
		 return p->isWord;
	 }

	 Solution()
	 {
		 root = new TriNode();
	 }
     
	 bool isValid(vector<vector<char>> &board, vector<vector<bool>> &visit, int x, int y)
	 {
         int m = board.size(), n = board[0].size();
         if (x < 0 || x >= m || y < 0 || y >= n || visit[x][y]) return false;
         return true;
     }
     
     void dfs(vector<vector<char>> &board, vector<vector<bool>> &visit, set<string> &st, string &s, int x, int y) 
	 {
		 int dx[4] = { 1, 0, -1, 0 };
		 //比我的可真是简单多了
		 int dy[4] = { 0, 1, 0, -1 };
		 visit[x][y] = true;
		 int xx, yy;
		 for (int i = 0; i < 4; ++i) 
		 {
			 xx = x + dx[i]; yy = y + dy[i];
			 //检查一下下标是否符合
			 if (isValid(board, visit, xx, yy))
			 {
				 s.push_back(board[xx][yy]);
				 if (isWord(s))
					 st.insert(s);
				 if (isPrefix(s))  //主要就是节省在这个地方，如果不是前缀的那么就没有必要往下搜索了
					 dfs(board, visit, st, s, xx, yy);
				 s.pop_back();
			 }
		 }
		 visit[x][y] = false;
    }
    
	 vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
	 {
		 vector<string> res;
		 if (board.empty() || board[0].empty() || words.empty())
			 return res;
		 for (auto &word : words)
			 insert(word);
		 
		 int m = board.size(), n = board[0].size();
		
		 vector<vector<bool>> visit(m, vector<bool>(n, false));
		 string s;
		 set<string> st;
		 for (int i = 0; i < m; ++i) 
		 {
			 for (int j = 0; j < n; ++j) 
			 {
				 s.push_back(board[i][j]);
				 if (isWord(s)) 
					 st.insert(s);
				 if (isPrefix(s)) 
					 dfs(board, visit, st, s, i, j);
				 s.pop_back(); //把board[i][j]字符给倒出来
			 }
		 }
		 for (auto &word : st) 
			 res.push_back(word);
		 return res;
     }
 };

int main()
{
	vector<vector<char>> board = { { 'o', 'a', 'a', 'n' }, { 'e', 't', 'a', 'e' }, { 'i', 'h', 'k', 'r' }, { 'i', 'f', 'l', 'v' } };
	vector<string> words = { "oath", "pea", "eat", "rain" };
	Solution mine;
	vector<string>result;
	result = mine.findWords(board,words);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
	return 0;
}