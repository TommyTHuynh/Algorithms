#pragma once
#include <cassert>
#include <iomanip>

using namespace std;

const int CAPACITY = 51;

template <class T>
class LP_HashTable
{
private:
	class LP_HashEntry
	{
	public:
		int key;
		T data;
		LP_HashEntry(int k, T v)
		{
			key = k;
			data = v;
		}
	};
	int hash(int key) const;
	void findIndex(int key, bool &found, int &i) const;
	T Table[CAPACITY];
	int usedSize;
public:
	LP_HashTable<T>();
	~LP_HashTable<T>();
	void insert(const T &entry);
	void find(int key, bool &found, T &result) const;
	int size() const;
};


