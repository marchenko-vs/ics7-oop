#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <cmath>
#include <cstdarg>
#include <cstdlib>

#include <iostream>
#include <memory>
#include <stdexcept>

#include "base_vector.hpp"
#include "iterator.hpp"

template<typename Type>
class Vector: public BaseVector
{
private:
    std::shared_ptr<Type> data_list_;

protected:
    Type SumAllElements();
    void SumVectors(Vector<Type> &result, const Vector<Type>& vec1, const Vector<Type>& vec2) const;
    void SubVectors(Vector<Type> &result, const Vector<Type>& vec1, const Vector<Type>& vec2) const;
    void MulVectors(Vector<Type> &result, const Vector<Type>& vec1, const Vector<Type>& vec2) const;
    void NewDynMem(int);

public:
    friend class Iterator<Type>;
    
    Vector();
    explicit Vector(int elements_amount);
    Vector(int elements_amount, Type* vec);
    Vector(int elements_amount, Type vec, ...);
    Vector(std::initializer_list<Type> args);
    explicit Vector(const Vector<Type> &vec);
    Vector(Vector<Type>&& vec);
    ~Vector();
    
    Vector<Type>& operator =(const Vector<Type>& vec);
    Vector<Type>& operator =(Vector<Type> &&vec);
    Vector<Type>& operator =(std::initializer_list<Type> args);

    bool IsZero() const noexcept;
    bool IsUnit() const noexcept;

    bool AreCollinear(const Vector<Type>&) const;
    bool AreOrthogonal(const Vector<Type>&) const;

    int GetSize() const;
    Type GetLength() const;
    Type& GetElement(int index);
    const Type& GetElement(int index) const;
    Vector<Type> GetUnitVector() const;
    double GetAngle(const Vector<Type>&) const;

    bool SetElement(int index, const Type& vec);

    Type& operator [](int index);
    const Type& operator [](int index) const;
    Vector<Type>& operator *=(const Type& mult);
    Vector<Type>& operator /=(const Type& div);
    Vector<Type> operator -();
    Type operator *(const Vector<Type>& vec) const;
    Vector<Type>& operator &=(const Vector<Type>& vec);
    Vector<Type> operator &(const Vector<Type>& vec) const;
    Vector<Type> operator +(const Vector<Type>&) const;
    Vector<Type>& operator +=(const Vector<Type>&);
    Vector<Type> operator -(const Vector<Type>&) const;
    Vector<Type>& operator -=(const Vector<Type>&);
    bool operator ==(const Vector<Type>&) const;
    bool operator !=(const Vector<Type>&) const;

    void Clear() noexcept override;
};

template<typename Type>
std::ostream& operator <<(std::ostream& os, const Vector<Type>& vec)
{
    Iterator<Type> iter(vec);
    
    if (!iter)
    {
        os << "Vector is empty.";

        return os;
    }
    
    os << '(' << *iter;

    for (iter++; iter; iter++)
        os << ", " << *iter ;

    os << ')';
    
    return os;
}

#endif // _VECTOR_H_
