#include "LinearProbing.h"

template<class T>
int LP_HashTable<T>::hash(int key) const
{
	return key % CAPACITY;
}

template<class T>
void LP_HashTable<T>::findIndex(int key, bool & found, int & i) const
{
	int count = 0;

	assert(key >= 0);

	i = hash(key);
	while (count < CAPACITY && Table[i].key != -1 && Table[i].key != key)
	{
		count++;
		i = (i + 1) % CAPACITY;
	}

	found = Table[i].key == key;
}

template<class T>
void LP_HashTable<T>::insert(const T & entry)
{
	bool exists;
	int index;

	assert(entry.key >= 0);

	findIndex(entry.key, exists, index);
	if (exists) Table[index] = entry;
	else
	{
		assert(size() < CAPACITY);
		index = hash(entry.key);
		while (Table[index].key != -1)
			index = (index + 1) % CAPACITY;
		Table[index] = entry;
		usedSize++;
	}
}

template<class T>
void LP_HashTable<T>::find(int key, bool & found, T & result) const
{
	int index;
	assert(key >= 0);
	findIndex(key, found, index);
	if (found) result = Table[index];
}

template<class T>
int LP_HashTable<T>::size() const
{
	return usedSize;
}

template<class T>
LP_HashTable<T>::LP_HashTable()
{
}

template<class T>
LP_HashTable<T>::~LP_HashTable()
{
}
