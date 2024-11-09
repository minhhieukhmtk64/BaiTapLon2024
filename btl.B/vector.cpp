#include <bits/stdc++.h>
using namespace std;

template <class T>
class Vector
{
private:
    int size, space;
    T *elem;

    void Expand(int newspace)
    {
        if (newspace <= space)
            return;
        else
        {
            T *odd = elem;
            elem = new T[newspace];
            for (int i = 0; i < size; i++)
            {
                elem[i] = odd[i];
            }
            if (odd != NULL)
                delete[] odd;
            space = newspace;
        }
    }

public:
    Vector()
    {
        size = space = 0;
        elem = NULL;
    }
    Vector(int n)
    {
        size = n;
        space = n;
        elem = new T[n];
    }

    Vector(const Vector &v) : size(v.size), space(v.space), elem(new T[v.space])
    {
        for (int i = 0; i < size; i++)
        {
            elem[i] = v.elem[i];
        }
    }

    ~Vector() { delete[] elem; }

    Vector<T> &operator=(const Vector &p)
    {
        if (this == &p)
            return *this;
        delete[] elem;
        this->size = p.size;
        this->space = p.space;
        this->elem = new T[p.space];
        for (int i = 0; i < p.size; i++)
        {
            this->elem[i] = p.elem[i];
        }
        return *this;
    }

    int getSize()
    {
        return size;
    }

    int getSpace()
    {
        return space;
    }

    T getElem(int i)
    {
        return elem[i];
    }

    bool Empty()
    {
        return size == 0;
    }

    T &operator[](int i)
    {
        return elem[i];
    }

    void Push_Back(T val)
    {
        if (size == space)
        {
            if (size == 0)
            {
                Expand(1);
            }
            else
                Expand(2 * size);
        }
        elem[size] = val;
        size++;
    }

    void Pop_Back()
    {
        if (size == 0)
            return;
        size--;
    }

    void Insert(T val, int pos)
    {
        if (size == space)
        {
            if (size == 0)
                space = 1;
            else
                Expand(2 * size);
        }
        for (int i = size; i > pos; i--)
        {
            elem[i] = elem[i - 1];
        }
        elem[pos] = val;
        size++;
    }

    void Erase(int pos)
    {
        for (int i = pos; i < size - 1; i++)
        {
            elem[i] = elem[i + 1];
        }
        size--;
    }

    void Clear()
    {
        size = 0;
    }

    class Iterator
    {
        private:
            T *ptr;

        public:
            Iterator() : ptr(nullptr) {}

            Iterator(T *p)
            {
                ptr = p;
            }

            bool operator==(Iterator *other)
            {
                return ptr == other->ptr;
            }

            bool operator!=(Iterator *other)
            {
                return ptr != other->ptr;
            }

            Iterator operator++()
            {
                ptr = ptr + 1;
                return *this;
            }

            Iterator operator++(int)
            {
                Iterator tmp = *this;
                ptr = ptr + 1;
                return tmp;
            }

            T &operator*()
            {
                return *ptr;
            }
    };

    Iterator begin()
    {
        return elem;
    }
    
    Iterator end()
    {
        return elem + size;
    }
};