
struct HashEntry
{
    int key;
    int value;
    HashEntry (const int keyin, const int valuein): key(keyin), value(valuein)
    {};
};

class HashTable
{
    HashEntry **hash;
    int size;
public:
    HashTable (const int size = 10000)
    {
        this->size = size;
        hash = new HashEntry*[size];
        for (int i =0; i < size; i++)
        {
            hash[i] = NULL:
        }
    }

    int func(const int x)
    {
        return x;
    }
    void put(int key, int value)
    {
        int idx = func(key);
        while (hash[idx] != NULL && hash[idx]->key != key)
            idx = probNext(idx);
        if (hash[idx] != NULL)
            delete hash[idx];
        hash[idx] = new HashEntry(key, value);
    }

    int getVal(int key)
    {
        int idx = func(key);
        while (hash[idx] != NULL && hash[idx]->key != key)
            idx = probNext(idx);
        if (hash[idx] == NULL)
            return -1;
        return hash[idx]->value;
    }

    ~HashTable ()
    {
        for (int i = 0; i < size; i ++)
            if (hash[i] != NULL)
                delete hash[i];
        delete[] hash;
    }
};