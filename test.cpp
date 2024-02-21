#include <iostream>
template <typename T>
class SharedPointer
{
private:
    T *_ptr;
    size_t *_count;

public:
    SharedPointer(T *ptr = nullptr) : _ptr(ptr)
    {
        if(ptr==nullptr)*_count=0;
        else *_count=1;
    }

    SharedPointer &operator=(const SharedPointer &smptr)
    {
        if (this == &smptr)
        {
            return *this;
        }
        if (_ptr&&--*_count == 0)
        {
            delete _ptr;
            delete _count;
        }
        _ptr = smptr._ptr;
        smptr._count++;
        _count = smptr._count;
        return *this;
    }

    ~SharedPointer()
    {
        if (_ptr&&--*_count == 0)
        {
            delete _ptr;
            delete _count;
        }
    }
};