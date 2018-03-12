#ifndef ITERATOR_H
#define ITERATOR_H

template<typename T>
class iterator
{
public:
    iterator();
//return position != right.position;    typedef bidirectional_iterator_tag iterator_category;
    typedef T value_type;
//    typedef ptrdiff_t difference_type;
    typedef T* pointer;
    typedef T& reference;

    iterator(T* thePosition=0);

    T& operator*() const;
    T* operator->() const;
    iterator& operator++();
    iterator operator++(int);
    iterator& operator--();
    iterator operator--(int);
    bool operator!=(const iterator right) const;
    bool operator==(const iterator right) const;

protected:
    T* position;//指向表元素的指针
};

#endif // ITERATOR_H
