#ifndef _ITERATOR_HPP_
#define _ITERATOR_HPP_

#include <ctime>

#include <memory>

#include "base_iterator.hpp"
#include "errors.hpp"

template<class Type>
class Vector;

template<typename Type>
class Iterator : public BaseIterartor
{
private:
    std::weak_ptr<Type> pointer_;

protected:
    Type* GetCurrentPointer() const;

public:
    Iterator(const Iterator<Type>& iter);
    Iterator(const Vector<Type>& vec);

    Type& operator*();
    Type* operator->();

    const Type& operator*() const;
    const Type* operator->() const;

    operator bool() const;

    Iterator<Type>& operator=(const Iterator<Type>& iter);
    Iterator<Type>& operator+=(int n);
    Iterator<Type> operator+(int n) const;
    Iterator<Type>& operator++();
    Iterator<Type> operator++(int);
    Iterator<Type>& operator-=(int n);
    Iterator<Type> operator-(int n) const;
    Iterator<Type>& operator--();
    Iterator<Type> operator--(int);
    
    bool operator<=(const Iterator<Type>& b) const;
    bool operator<(const Iterator<Type>& b) const;
    bool operator>=(const Iterator<Type>& b) const;
    bool operator>(const Iterator<Type>& b) const;
    bool operator==(const Iterator<Type>& b) const;
    bool operator!=(const Iterator<Type>& b) const;

    bool Check(int line) const;
};

template<class Type>
Type* Iterator<Type>::GetCurrentPointer() const
{
    std::shared_ptr<Type> copy_ptr = pointer_.lock();
    return copy_ptr.get() + index_;
}

template<class Type>
Iterator<Type>::Iterator(const Vector<Type>& vec)
{
    index_ = 0;
    elements_amount_ = vec.elements_amount_;
    pointer_ = vec.data_list_;
    index_ = 0;
}

template<class Type>
Iterator<Type>::Iterator(const Iterator<Type>& iter)
{
    pointer_ = iter.pointer_;
    index_ = iter.index_;
    elements_amount_ = iter.elements_amount_;
}

template<class Type>
Type& Iterator<Type>::operator*()
{
    Check(__LINE__);
    
    std::shared_ptr<Type> copy_ptr = pointer_.lock();
    return *GetCurrentPointer();
}

template<class Type>
const Type& Iterator<Type>::operator*() const
{
    Check(__LINE__);
    
    std::shared_ptr<Type> copy_ptr = pointer_.lock();
    return *GetCurrentPointer();
}

template<class Type>
Type* Iterator<Type>::operator->()
{
    Check(__LINE__);
    
    return GetCurrentPointer();
}

template<class Type>
const Type* Iterator<Type>::operator->() const
{
    Check(__LINE__);
    
    return GetCurrentPointer();
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator=(const Iterator<Type>& iter)
{
    Check(__LINE__);
    
    pointer_ = iter.pointer_;
    return *this;
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator+=(int n)
{
    Check(__LINE__);
    pointer_ += n;
    
    return *this;
}

template<class Type>
Iterator<Type> Iterator<Type>::operator+(int n) const
{
    Check(__LINE__);
    Iterator<Type> iter(*this);
    iter += n;
    
    return iter;
}

template<class Type>
Iterator<Type> Iterator<Type>::operator++(int)
{
    Check(__LINE__);
    ++(*this);
    
    return *this;
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator++()
{
    Check(__LINE__);
    ++index_;
    
    return *this;
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator-=(int n)
{
    Check(__LINE__);
    index_ -= n;
    
    return *this;
}

template<class Type>
Iterator<Type> Iterator<Type>::operator-(int n) const
{
    Check(__LINE__);
    
    Iterator<Type> iter(*this);
    iter -= n;
    
    return iter;
}

template<class Type>
Iterator<Type> Iterator<Type>::operator--(int)
{
    Check(__LINE__);
    --(*this);
    
    return *this;
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator--()
{
    Check(__LINE__);
    --index_;
    
    return *this;
}

template<class Type>
bool Iterator<Type>::operator<=(const Iterator<Type>& b) const
{
    Check(__LINE__);
    
    return pointer_ <= b.pointer_;
}

template<class Type>
bool Iterator<Type>::operator<(const Iterator<Type>& b) const
{
    Check(__LINE__);
    
    return pointer_ < b.pointer_;
}

template<class Type>
bool Iterator<Type>::operator>=(const Iterator<Type>& b) const
{
    Check(__LINE__);
    
    return pointer_ >= b.pointer_;
}

template<class Type>
bool Iterator<Type>::operator>(const Iterator<Type>& b) const
{
    Check(__LINE__);
    
    return pointer_ > b.pointer_;
}

template<class Type>
bool Iterator<Type>::operator==(const Iterator<Type>& b) const
{
    Check(__LINE__);
    
    return pointer_ == b.pointer_;
}

template<class Type>
bool Iterator<Type>::operator!=(const Iterator<Type>& b) const
{
    Check(__LINE__);
    
    return pointer_ != b.pointer_;
}

template<class Type>
Iterator<Type>::operator bool() const
{
    Check(__LINE__);
    
    if (index_ >= elements_amount_ || index_ < 0 || (elements_amount_ == 0))
        return false;
    else
        return true;
}

template<class Type>
bool Iterator<Type>::Check(int line) const
{
    if (!pointer_.expired())
        return true;
    
    time_t t_time = time(NULL);
    throw DeletedObjectError(__FILE__, typeid(*this).name(), line, ctime(&t_time));
    return false;
}

#endif // _ITERATOR_HPP_
