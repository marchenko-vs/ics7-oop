#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

#include <cmath>
#include <cstddef>
#include <cstdlib>

#include <iostream>

#include "errors.hpp"
#include "vector.h"

#define EPS 1e-6

inline static int max(int num1, int num2)
{
    if (num1 >= num2)
        return num1;

    return num2;
};

template<typename Type>
Vector<Type>::~Vector<Type>()
{
    Clear();
}

template<typename Type>
void Vector<Type>::Clear() noexcept
{
    elements_amount_ = 0;

    if (data_list_)
        data_list_.reset();
}

template<typename Type>
Vector<Type>::Vector()
{
    elements_amount_ = 0;
    NewDynMem(elements_amount_);
}

template<typename Type>
Vector<Type>::Vector(int elements_amount)
{
    time_t t_time = time(NULL);
    if (elements_amount < 0)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    
    elements_amount_ = elements_amount;
    NewDynMem(elements_amount_);
    
    if (!data_list_)
        throw MemoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    
    Iterator<Type> iter(*this);
    for (; iter; iter++)
        *iter = 0;
}

template<typename Type>
Vector<Type>::Vector(int elements_amount, Type vec, ...)
{
    time_t t_time = time(NULL);
    if (elements_amount < 1)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    
    elements_amount_ = elements_amount;
    NewDynMem(elements_amount_);
    
    if (!data_list_)
        throw MemoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    
    Iterator<Type> iter(*this);
    va_list ap;
    va_start(ap, vec);
    for (; iter; iter++)
    {
        *iter = vec;
        vec = va_arg(ap, Type);
    }
    va_end(ap);
}

template<typename Type>
Vector<Type>::Vector(int elements_amount, Type* vec)
{
    time_t t_time = time(NULL);
    if (elements_amount <= 0)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    
    elements_amount_ = elements_amount;
    NewDynMem(elements_amount_);
    
    Iterator<Type> iter(*this);
    for (int i = 0; iter; i++, iter++)
        *iter = vec[i];
}

template<typename Type>
Vector<Type>::Vector(std::initializer_list<Type> args)
{
    if (args.size() == 0)
        Vector();
    
    elements_amount_ = int(args.size());
    NewDynMem(elements_amount_);
    
    Iterator<Type> iter(*this);
    for (auto &element : args)
    {
        *iter = element;
        iter++;
    }
}

template<typename Type>
Type& Vector<Type>::GetElement(int index)
{
    time_t t_time = time(NULL);
    if (index < 0 || index >= elements_amount_)
        throw IndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    
    Iterator<Type> iter(*this);
    for (int i = 0; i < index; i++, iter++)
        ;
    
    return *iter;
}

template<typename Type>
const Type& Vector<Type>::GetElement(int index) const
{
    time_t t_time = time(NULL);
    if (index < 0 || index >= elements_amount_)
        throw IndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    
    NewDynMem(elements_amount_);
    Iterator<Type> iter(*this);
    for (int i = 0; i <= index; i++, iter++)
        ;
    
    return *iter;
}

template <typename Type>
bool Vector<Type>::operator ==(const Vector<Type>& vec) const
{
    if (elements_amount_ != vec.elements_amount_)
        return false;

    bool equal = true;

    Iterator<Type> iter1(*this);
    Iterator<Type> iter2(vec);

    for (; iter1 && equal; iter1++, iter2++)
        if (fabs(*iter1 - *iter2) > EPS)
            equal = false;

    return equal;
}

template <typename Type>
bool Vector<Type>::operator !=(const Vector<Type>& vec) const
{
    if (*this == vec)
        return false;

    return true;
}

template<typename Type>
Type Vector<Type>::GetLength(void) const
{
    time_t t_time = time(NULL);

    if (elements_amount_ < 0)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    
    Iterator<Type> iter(*this);
    double sum = 0;

    for (; iter; iter++)
        sum += *iter * *iter;
    
    return sqrt(sum);
}

template <typename Type>
Type Vector<Type>::operator *(const Vector<Type>& vec) const
{
    time_t t_time = time(NULL);
    if (elements_amount_ < 0 || vec.elements_amount_ < 0)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    
    int length_max = max(elements_amount_, vec.elements_amount_);
    Vector<Type> new_vector(length_max);
    MulVectors(new_vector, *this, vec);

    return new_vector.SumAllElements();
}

template <typename Type>
Vector<Type> Vector<Type>::operator +(const Vector<Type>& vec) const
{
    time_t t_time = time(NULL);
    if (elements_amount_ < 0 || vec.elements_amount_ < 0)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    
    int length_max = max(elements_amount_, vec.elements_amount_);
    Vector<Type> new_vector(length_max);
    SumVectors(new_vector, *this, vec);
    
    return new_vector;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator +=(const Vector<Type>& vec)
{
    time_t t_time = time(NULL);
    if (elements_amount_ < 0 || vec.elements_amount_ < 0)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    
    SumVectors(*this, *this, vec);
    
    return *this;
}

template <typename Type>
Vector<Type> Vector<Type>::operator -(const Vector<Type>& vec) const
{
    time_t t_time = time(NULL);
    if (elements_amount_ < 0 || vec.elements_amount_ < 0)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    
    int length_max = max(elements_amount_, vec.elements_amount_);
    Vector<Type> new_vector(length_max);
    SubVectors(new_vector, *this, vec);
    
    return new_vector;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator -=(const Vector<Type>& vec)
{
    time_t t_time = time(NULL);
    if (elements_amount_ < 0 || vec.elements_amount_ < 0)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    
    SubVectors(*this, *this, vec);
    
    return *this;
}

template<typename Type>
Vector<Type>& Vector<Type>::operator *=(const Type& mult)
{
    time_t t_time = time(NULL);
    if (elements_amount_ < 0)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    
    Iterator<Type> iter(*this);
    for (; iter; iter++)
        *iter *= mult;
    
    return *this;
}

template<typename Type>
Vector<Type>& Vector<Type>::operator /=(const Type& div)
{
    time_t t_time = time(NULL);
    if (!div)
        throw ZeroDivisionError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    
    Type div_new = 1 / div;
    *this *= div_new;
    
    return *this;
}

template<typename Type>
Type Vector<Type>::SumAllElements()
{
    time_t t_time = time(NULL);
    if (elements_amount_ <= 0)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    
    Iterator<Type> iter(*this);
    Type sum = 0;
    for (; iter; iter++)
        sum += *iter;
    
    return sum;
}

template<typename Type>
double Vector<Type>::GetAngle(const Vector<Type> &vec) const
{
    time_t t_time = time(NULL);
    if (!this->GetLength() || !vec.GetLength())
        throw ZeroDivisionError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    
    double angle = (*this * vec)/(this->GetLength() * vec.GetLength());
    const double PI = 2 * acos(0.0);

    return acos(angle) * 180 / PI;
}

template<typename Type>
bool Vector<Type>::IsUnit() const noexcept
{
    if (abs(this->GetLength() - 1) < EPS)
        return true;

    return false;
}

template<typename Type>
bool Vector<Type>::IsZero() const noexcept
{
    if (this->GetLength() == 0)
        return true;

    return false;
}

template<typename Type>
Vector<Type>& Vector<Type>::operator &=(const Vector<Type>& vec)
{
    if (elements_amount_ != 3)
        return *(new Vector<Type>);
    
    double x = data_list_.get()[1] * vec.data_list_.get()[2] - data_list_.get()[2] * vec.data_list_.get()[1];
    double y = data_list_.get()[2] * vec.data_list_.get()[0] - data_list_.get()[0] * vec.data_list_.get()[2];
    double z = data_list_.get()[0] * vec.data_list_.get()[1] - data_list_.get()[1] * vec.data_list_.get()[0];
    
    *this = Vector<Type>(3, x, y, z);
    return *this;
}

template<typename Type>
Vector<Type> Vector<Type>::operator &(const Vector<Type>& vec) const
{
    if (elements_amount_ != 3)
        return Vector<Type>();
    
    double x = data_list_.get()[1] * vec.data_list_.get()[2] - data_list_.get()[2] * vec.data_list_.get()[1];
    double y = data_list_.get()[2] * vec.data_list_.get()[0] - data_list_.get()[0] * vec.data_list_.get()[2];
    double z = data_list_.get()[0] * vec.data_list_.get()[1] - data_list_.get()[1] * vec.data_list_.get()[0];
    
    Vector<Type> new_vector(3, x, y, z);
    return new_vector;
}

template<typename Type>
Vector<Type>& Vector<Type>::operator =(const Vector<Type>& vec)
{
    elements_amount_ = vec.elements_amount_;
    NewDynMem(elements_amount_);
    
    Iterator<Type> iter_new(*this);
    Iterator<Type> iter(vec);
    for (; iter_new; iter_new++, iter++)
        *iter_new = *iter;
    
    return *this;
}

template<typename Type>
Vector<Type>& Vector<Type>::operator =(std::initializer_list<Type> args)
{
    elements_amount_ = int(args.size());
    NewDynMem(elements_amount_);
    
    Iterator<Type> iter(*this);
    for (auto &element : args)
    {
        *iter = element;
        iter++;
    }
    
    return *this;
}

template<typename Type>
Vector<Type>& Vector<Type>::operator =(Vector<Type> &&vec)
{
    elements_amount_ = vec.elements_amount_;
    NewDynMem(elements_amount_);
    data_list_ = vec.data_list_;
    vec.data_list_.reset();
    
    return *this;
}

template<typename Type>
Vector<Type>::Vector(const Vector<Type> &vec)
{
    elements_amount_ = vec.elements_amount_;
    NewDynMem(elements_amount_);
    
    Iterator<Type> iter_new(*this);
    Iterator<Type> iter(vec);
    for (; iter_new; iter++, iter_new++)
        *iter_new = *iter;
}

template<typename Type>
Type& Vector<Type>::operator [](int index)
{
    return GetElement(index);
}

template<typename Type>
const Type& Vector<Type>::operator [](int index) const
{
    return GetElement(index);
}

template<typename Type>
bool Vector<Type>::SetElement(int index, const Type& num)
{
    if (index < 0 || index >= elements_amount_)
        return false;
    
    GetElement(index) = num;
    return true;
}

template<typename Type>
Vector<Type> Vector<Type>::GetUnitVector() const
{
    Vector<Type> new_vector(*this);
    Type len = this->GetLength();
    
    Iterator<Type> iter(new_vector);
    for (; iter; iter++)
        *iter /= len;
    
    return new_vector;
}

template<typename Type>
int Vector<Type>::GetSize() const
{
    return elements_amount_;
}

template<typename Type>
bool Vector<Type>::AreCollinear(const Vector<Type>& vec) const
{
    if (this->GetAngle(vec) < EPS)
        return true;
    else
        return false;
}

template<typename Type>
bool Vector<Type>::AreOrthogonal(const Vector<Type>& vec) const
{
    if (abs(this->GetAngle(vec) - 90) < EPS)
        return true;
    else
        return false;
}

template <typename Type>
void Vector<Type>::SumVectors(Vector<Type> &result, const Vector<Type>& vec1, const Vector<Type>& vec2) const
{
    Iterator<Type> iter_result(result);
    Iterator<Type> iter_vec1(vec1);
    Iterator<Type> iter_vec2(vec2);
    for (int i = 0; iter_result; i++, iter_result++, iter_vec1++, iter_vec2++)
    {
        if (i >= vec1.elements_amount_)
            *iter_result = *iter_vec2;
        else if (i >= vec2.elements_amount_)
            *iter_result = *iter_vec1;
        else
            *iter_result = *iter_vec1 + *iter_vec2;
    }
}

template <typename Type>
void Vector<Type>::SubVectors(Vector<Type> &result, const Vector<Type>& vec1, const Vector<Type>& vec2) const
{
    Iterator<Type> iter_result(result);
    Iterator<Type> iter_vec1(vec1);
    Iterator<Type> iter_vec2(vec2);

    for (int i = 0; iter_result; i++, iter_result++, iter_vec1++, iter_vec2++)
    {
        if (i >= vec1.elements_amount_)
            *iter_result = -*iter_vec2;
        else if (i >= vec2.elements_amount_)
            *iter_result = *iter_vec1;
        else
            *iter_result = *iter_vec1 - *iter_vec2;
    }
}

template <typename Type>
void Vector<Type>::MulVectors(Vector<Type> &result, const Vector<Type>& vec1, const Vector<Type>& vec2) const
{
    Iterator<Type> iter_result(result);
    Iterator<Type> iter_vec1(vec1);
    Iterator<Type> iter_vec2(vec2);
    for (int i = 0; iter_result; i++, iter_result++, iter_vec1++, iter_vec2++)
    {
        if (i >= vec1.elements_amount_ || i >= vec2.elements_amount_)
            *iter_result = 0;
        else
            *iter_result = *iter_vec1 * *iter_vec2;
    }
}

template <typename Type>
Vector<Type> Vector<Type>::operator -()
{
    Vector<Type> new_vector(*this);
    Iterator<Type> iter(new_vector);
    for (; iter; iter++)
        *iter = -*iter;
    
    return new_vector;
}

template <typename Type>
void Vector<Type>::NewDynMem(int elements_amount)
{
    data_list_.reset();
    std::shared_ptr<Type> sp_temp(new Type[elements_amount], std::default_delete<Type[]>());
    data_list_ = sp_temp;
}

#endif // _VECTOR_HPP_
