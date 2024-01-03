#include<iostream>
#include<string>
#include <algorithm>
#include <vector>
using namespace std;

struct Pair
{
	int key;
	string val;
	Pair(int key, string val)
	{
		this->key = key;
		this->val = val;
	}
};

class Hash
{
public:
	Hash():size(0),capacity(4),extendRatio(2),loadThres(2.0/3.0)
	{
		buckets.resize(capacity);
	}

	int hashFunc(int key)
	{
		return key % capacity;
    }

	double loadFactor()
	{
		return (double)size / (double)capacity;
	}

	void Extend()
	{
		vector<vector<Pair*>> tmp = this->buckets;
		this->buckets.clear();
		capacity *= this->extendRatio;
		this->buckets.reserve(capacity);
		size = 0;
		for (auto bucket : tmp)
		{
			for (Pair* pair : bucket)
			{
				Add(pair->key, pair->val);
				delete pair;
			}
		}
	}

	void Add(int key, string val)
	{
		if (loadFactor() > loadThres)
		{
			Extend();
		}

		int index = hashFunc(key);

		for (Pair* pair : buckets[index])
		{
			if (pair->key == key)
			{
				pair->val = val;
				return;
			}
		}

		buckets[index].push_back(new Pair(key, val));
		size++;

	}

	void remove(int key)
	{
		int index = hashFunc(key);
		auto& bucket = buckets[index];
		for (int i=0;i<bucket.size();i++)
		{
			if (bucket[i]->key == key)
			{
				Pair* pair = bucket[i];
				bucket.erase(bucket.begin() + i);
				delete pair;
				size--;
				return;
			}
		}
	}

	string Getval(int key)
	{
		int index = hashFunc(key);

	}

	void print()
	{
		for (auto bucket : buckets)
		{
			for (Pair* pair : bucket)
			{
				cout << pair->key << "  " << pair->val << endl;
			}
		}
	}

	~Hash()
	{
		for (auto& bucket : buckets)
		{
			for (Pair* pair : bucket)
			{
				delete pair;
			}
		}
	}


private:

	int size;
	int capacity;
	int extendRatio;
	double loadThres;
	vector <vector<Pair*>> buckets;

};






int main()
{
	Hash h;
	h.Add(10, "zhangsna");
	h.print();
	
}