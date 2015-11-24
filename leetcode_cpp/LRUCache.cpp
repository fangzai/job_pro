/*
time   :  2015-5-30
author :  ht
comment:  cache的访问按照最近访问存储的数据结构设计
          就是最近访问的放在最前面
		  这个需要用到双向链表的问题
		  http://www.cnblogs.com/x1957/p/3485053.html
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<unordered_map>
#include<algorithm>
using namespace std;

class LRUCache{
private:
	list<pair<int, int>> mlist;   //双向链表
	unordered_map<int, list<pair<int, int>>::iterator> mmap;
	//通过元素映射到链表
	int mcapacity;

public:
	LRUCache(int capacity) {
		mlist.clear();
		mmap.clear();
		mcapacity = capacity;
	}

	int get(int key) {
		if (mmap.find(key) != mmap.end()) 
		{
			pair<int, int> tmp = *(mmap[key]);
			mlist.splice(mlist.begin(), mlist, mmap[key]);
			mmap[key] = mlist.begin();
			
			return mlist.front().second;
		}
		else 
		{
			return -1;
		}
	}

	void set(int key, int value) 
	{
		
		if (mmap.find(key) != mmap.end()) 
		{
			//设置的时候如果找到，原来的就删掉，直接把数据放在链表的头
			//mlist.erase(mmap[key]);
			//mlist.push_front(make_pair(key, value));
			mlist.splice(mlist.begin(), mlist, mmap[key]);
			mmap[key] = mlist.begin();
			mlist.begin()->second = value;
		}
		else 
		{
			//设置的时候如果没找到，需要判定链表的容量是否还够
			//如果满了的话，先删除醉虎一个，然后再把这个key放到头上
			//如果没有满的话，直接把这个key放在头
			if (mlist.size() == mcapacity)
			{
				mmap.erase(mlist.back().first);
				mlist.pop_back();
			}
			mlist.push_front(make_pair(key, value));
			mmap[key] = mlist.begin();
		}
	}
};
int main()
{
	return 0;
}