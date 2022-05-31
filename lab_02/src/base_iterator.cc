#include "base_iterator.hpp"

BaseIterartor::BaseIterartor()
{
    index_ = 0;
    elements_amount_ = 0;
}

BaseIterartor::BaseIterartor(const BaseIterartor& iter)
{
    index_ = iter.index_;
    elements_amount_ = iter.elements_amount_;
}
