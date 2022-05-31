#ifndef _BASE_ITERATOR_HPP_
#define _BASE_ITERATOR_HPP_

class BaseIterartor
{
protected:
    int index_ = 0;
    int elements_amount_ = 0;

public:
    BaseIterartor();
    explicit BaseIterartor(const BaseIterartor&);
    virtual ~BaseIterartor() = default;
};

#endif // _BASE_ITERATOR_HPP_
