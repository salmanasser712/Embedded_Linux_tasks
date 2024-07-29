#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include <stdexcept>
#include <memory>
#include <iterator>
#include <iostream>

namespace ara {
namespace core {

template <typename T, typename Allocator = std::allocator<T>>
class Vector {
    public:
    using iterator = T*;                                         // Define an iterator type as a pointer to T
    using const_iterator = const T*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    explicit Vector(size_t capacity = 10);
    explicit Vector(size_t capacity, T value);
    Vector(std::initializer_list<T> init_list);
    Vector(const Vector& other);                                 // Copy Constructor
    Vector(Vector&& other) noexcept;                             // Move Constructor

    iterator begin(void); 
    iterator end(void);
    const_iterator cbegin(void);
    const_iterator cend(void);

    reverse_iterator rbegin(void);
    reverse_iterator rend(void);
    const_reverse_iterator crbegin(void);
    const_reverse_iterator crend(void);
    

    void push_back(const T& value);
    void pop_back(void);


    std::size_t size(void);
    std::size_t capacity(void);
    std::size_t max_size(void);
    void resize(std::size_t n);
    void resize(std::size_t n, const T& value);
    void shrink_to_fit(void);
    void reserve(std::size_t n);
    bool empty(void);

    T& at(std::size_t index);
    T& operator[](std::size_t index);
    T& front(void);
    T& back(void);
    T* data(void);
    void assign(std::size_t size, T value);

    void clear(void);
    // Templated assign method to assign a range of elements
    void assign(T* first, T* last);



    ~Vector();


    private:
    T* arr;
    std::size_t current_capacity;
    std::size_t current_index;
};

} // namespace core
} // namespace ara

#include "Vector.tpp"

#endif