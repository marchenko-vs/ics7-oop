#ifndef _CONST_ITERATOR_HPP_
#define _CONST_ITERATOR_HPP_

#include <cstdlib>

#include <memory>

#include "base_iterator.hpp"
#include "iterator.hpp"

template<typename Type>
class ConstIterator : public BaseIterartor
{
private:
    std::weak_ptr<Type> pointer_;

protected:
    Type* GetCurrentPointer() const;

public:
    ConstIterator(const ConstIterator<Type>& iter);
    ConstIterator(const Vector<Type>& vec);

    const Type& operator*() const;
    const Type* operator->() const;
    operator bool() const;

    ConstIterator<Type>& operator=(const Iterator<Type>& iter);

    ConstIterator<Type>& operator+=(int n);
    ConstIterator<Type> operator+(int n) const;
    ConstIterator<Type>& operator++();
    ConstIterator<Type> operator++(int);

    ConstIterator<Type>& operator-=(int n);
    ConstIterator<Type> operator-(int n) const;
    ConstIterator<Type>& operator--();
    ConstIterator<Type> operator--(int);

    bool operator<=(const ConstIterator<Type>& b) const;
    bool operator<(const ConstIterator<Type>& b) const;
    bool operator>=(const ConstIterator<Type>& b) const;
    bool operator>(const ConstIterator<Type>& b) const;
    bool operator==(const ConstIterator<Type>& b) const;
    bool operator!=(const ConstIterator<Type>& b) const;

    bool Check(int line) const;
};

template<class Type>
Type* ConstIterator<Type>::GetCurrentPointer() const
{
    std::shared_ptr<Type> copy_ptr = pointer_.lock();
    return copy_ptr.get() + index_;
}

template<class Type>
ConstIterator<Type>::ConstIterator(const Vector<Type>& vec)
{
    index_ = 0;
    elements_amount_ = vec.elements_amount_;
    pointer_ = vec.data_list;
    index_ = 0;
}

template<class Type>
ConstIterator<Type>::ConstIterator(const ConstIterator<Type>& iter)
{
    pointer_ = iter.pointer_;
    index_ = iter.index_;
    elements_amount_ = iter.elements_amount_;
}

template<class Type>
const Type& ConstIterator<Type>::operator*() const
{
    Check(__LINE__);

    std::shared_ptr<Type> copy_ptr = pointer_.lock();
    return *GetCurrentPointer();
}

template<class Type>
const Type* ConstIterator<Type>::operator->() const
{
    Check(__LINE__);

    return GetCurrentPointer();
}

//template<class Type>
//ConstIterator<Type>& ConstIterator<Type>::operator=(const ConstIterator<Type>& iter)
//{
//    check(__LINE__);

//    ptr = iter.ptr;
//    return *this;
//}

template<class Type>
ConstIterator<Type>& ConstIterator<Type>::operator+=(int n)
{
    Check(__LINE__);
    pointer_ += n;

    return *this;
}

template<class Type>
ConstIterator<Type> ConstIterator<Type>::operator+(int n) const
{
    Check(__LINE__);
    ConstIterator<Type> iter(*this);
    iter += n;

    return iter;
}

template<class Type>
ConstIterator<Type> ConstIterator<Type>::operator++(int)
{
    Check(__LINE__);
    ++(*this);

    return *this;
}

template<class Type>
ConstIterator<Type>& ConstIterator<Type>::operator++()
{
    Check(__LINE__);
    ++index_;

    return *this;
}

//template<class Type>
//Iterator<Type>& Iterator<Type>::operator-=(int n)
//{
//    Check(__LINE__);
//    index -= n;

//    return *this;
//}

template<class Type>
ConstIterator<Type> ConstIterator<Type>::operator-(int n) const
{
    Check(__LINE__);

    ConstIterator<Type> iter(*this);
    iter -= n;

    return iter;
}

template<class Type>
ConstIterator<Type> ConstIterator<Type>::operator--(int)
{
    Check(__LINE__);
    --(*this);

    return *this;
}

template<class Type>
ConstIterator<Type>& ConstIterator<Type>::operator--()
{
    Check(__LINE__);
    --index_;

    return *this;
}

template<class Type>
bool ConstIterator<Type>::operator<=(const ConstIterator<Type>& b) const
{
    Check(__LINE__);

    return pointer_ <= b.pointer_;
}

template<class Type>
bool ConstIterator<Type>::operator<(const ConstIterator<Type>& b) const
{
    Check(__LINE__);

    return pointer_ < b.pointer_;
}

template<class Type>
bool ConstIterator<Type>::operator>=(const ConstIterator<Type>& b) const
{
    Check(__LINE__);

    return pointer_ >= b.pointer_;
}

template<class Type>
bool ConstIterator<Type>::operator>(const ConstIterator<Type>& b) const
{
    Check(__LINE__);

    return pointer_ > b.pointer_;
}

template<class Type>
bool ConstIterator<Type>::operator==(const ConstIterator<Type>& b) const
{
    Check(__LINE__);

    return pointer_ == b.pointer_;
}

template<class Type>
bool ConstIterator<Type>::operator!=(const ConstIterator<Type>& b) const
{
    Check(__LINE__);

    return pointer_ != b.pointer_;
}

template<class Type>
ConstIterator<Type>::operator bool() const
{
    Check(__LINE__);

    if (index_ >= elements_amount_ || index_ < 0 || (elements_amount_ == 0))
        return false;
    else
        return true;
}

template<class Type>
bool ConstIterator<Type>::Check(int line) const
{
    if (!pointer_.expired())
        return true;

    time_t t_time = time(NULL);
    throw DeletedObjectError(__FILE__, typeid(*this).name(), line, ctime(&t_time));

    return false;
}

#endif // _CONST_ITERATOR_HPP_
