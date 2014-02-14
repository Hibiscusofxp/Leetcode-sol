
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
            hash[i] = nullptr:
        }
    }

    int func(const int x)
    {
        return x;
    }

    int probNext(const int x)
    {
        return x + 1;
    }

    void put(int key, int value)
    {
        int idx = func(key) % size;;
        while (hash[idx] != nullptr && hash[idx]->key != key)
            idx = probNext(idx) % size;
        if (hash[idx] != nullptr)
            delete hash[idx];
        hash[idx] = new HashEntry(key, value);
    }

    int getVal(int key)
    {
        int idx = func(key) % size;
        while (hash[idx] != nullptr && hash[idx]->key != key)
            idx = probNext(idx) % size;
        if (hash[idx] == nullptr)
            return -1;
        return hash[idx]->value;
    }

    ~HashTable ()
    {
        for (int i = 0; i < size; i ++)
            if (hash[i] != nullptr)
                delete hash[i];
        delete[] hash;
    }
};