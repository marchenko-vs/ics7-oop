#include "base_vector.hpp"

BaseVector::BaseVector()
{
    elements_amount_ = 0;
}

BaseVector::BaseVector(const BaseVector& base)
{
    elements_amount_ = base.elements_amount_;
}

int BaseVector::GetSize() const
{
    return elements_amount_;
}

bool BaseVector::IsEmpty() const
{
    return elements_amount_ == 0;
}
