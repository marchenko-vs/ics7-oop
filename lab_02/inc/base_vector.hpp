#ifndef _BASE_VECTOR_HPP_
#define _BASE_VECTOR_HPP_

class BaseVector
{
protected:
    int elements_amount_ = 0;

public:
    BaseVector();
    explicit BaseVector(const BaseVector&);
    virtual ~BaseVector() = default;
    
    virtual void Clear() = 0;
    bool IsEmpty() const;
    int GetSize() const;
};

#endif // _BASE_VECTOR_HPP_
