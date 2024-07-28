#include "Vector.h"

namespace ara {
namespace core {
    template <typename T, typename Allocator>
    Vector<T, Allocator>::Vector(size_t capacity)
    {
        try {
            this->arr = new T[capacity];
            this->current_capacity = capacity;
            this->current_index = 0;
        } 
        catch (const std::bad_alloc& e) {
            std::cerr << "Memory allocation failed: " << e.what() << std::endl;
            return;
        }
    }

    template <typename T, typename Allocator>
    Vector<T, Allocator>::Vector(std::initializer_list<T> init_list) : arr(new T[init_list.size()])
    {
        try {
            this->current_index = init_list.size();
            this->current_capacity = init_list.size();
            this->arr = new T[init_list.size()];

            std::size_t i = 0;
            for (const T& item : init_list) {
                this->arr[i++] = item;
            }
        } 
        catch (const std::bad_alloc& e) {
            std::cerr << "Memory allocation failed: " << e.what() << std::endl;
            return;
        }
    }

    template <typename T, typename Allocator>
    Vector<T, Allocator>::Vector(size_t capacity, T value)
    {
        try {
            this->current_index = 0;
            this->current_capacity = capacity;
            this->arr = new T[capacity];

            for ( ; current_index < capacity; current_index++) {
                this->arr[current_index] = value;
            }
        } 
        catch (const std::bad_alloc& e) {
            std::cerr << "Memory allocation failed: " << e.what() << std::endl;
            return;
        }
    }

    template <typename T, typename Allocator>
    Vector<T, Allocator>::Vector(const Vector& other)
    {
        try
        {
            this->arr = new T[other.current_capacity];
            this->current_index = other.current_index;
            this->current_capacity = other.current_capacity;
            for(std::size_t i = 0; i < current_index; i++)
            {
                this->arr[i] = other.arr[i];
            }
        }
        catch (const std::bad_alloc& e) {
            std::cerr << "Memory allocation failed: " << e.what() << std::endl;
            return;
        }
    }
    template <typename T, typename Allocator>
    Vector<T, Allocator>::Vector(Vector&& other) noexcept
    {
        this->arr = other.arr;
        this->current_capacity = other.current_capacity;
        this->current_index = other.current_index;

        other.current_index = 0;
        other.current_capacity = 0;
        other.arr = nullptr;
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::iterator Vector<T, Allocator>::begin(void)
    {
        return this->arr;
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::iterator Vector<T, Allocator>::end(void)
    {
        return this->arr + current_index;
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::const_iterator Vector<T, Allocator>::cbegin(void)
    {
        return arr;
    }
    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::const_iterator Vector<T, Allocator>::cend(void)
    {
        return this->arr + current_index;
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::reverse_iterator Vector<T, Allocator>::rbegin(void) {
        return reverse_iterator(end());
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::reverse_iterator Vector<T, Allocator>::rend(void) {
        return reverse_iterator(begin());
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::const_reverse_iterator Vector<T, Allocator>::crbegin(void)
    {
        return const_reverse_iterator(cend());
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::const_reverse_iterator Vector<T, Allocator>::crend(void)
    {
        return const_reverse_iterator(cbegin());
    }

    template <typename T, typename Allocator>
    void  Vector<T, Allocator>::push_back(T value)
    {
        if(current_index >= current_capacity)
        {
            try
            {
                T *temp = new T[2 * current_capacity];
                for(std::size_t i = 0; i < current_index; i++)
                {
                    temp[i] = arr[i];
                }
                delete[] arr;
                current_capacity *= 2;
                arr = temp;
            } 
            catch (const std::bad_alloc& e) {
                std::cerr << "Memory allocation failed: " << e.what() << std::endl;
                return;
            }
        }

        arr[current_index++] = value;
    }

    template <typename T, typename Allocator>
    void Vector<T, Allocator>::pop_back(void)
    {
        if(current_index == 0)
        {
            throw std::out_of_range("Vector Empty");
            return;
        }
        current_index--;
    }

    template <typename T, typename Allocator>
    std::size_t Vector<T, Allocator>::size(void)
    {
        return current_index;
    }

    template <typename T, typename Allocator>
    std::size_t Vector<T, Allocator>::capacity(void)
    {
        return this->current_capacity;
    }

    template <typename T, typename Allocator>
    bool Vector<T, Allocator>::empty(void)
    {
        return current_index == 0;
    }

    template <typename T, typename Allocator>
    T& Vector<T, Allocator>::operator[](std::size_t index)
    {
        if(index >= current_index)
        {
            throw std::out_of_range("Out of bounds");
        }
        return arr[index];
    }
    


    template <typename T, typename Allocator>
    Vector<T, Allocator>::~Vector()
    {
        delete[] arr;
    }

}
}
