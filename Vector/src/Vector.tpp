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
    void  Vector<T, Allocator>::push_back(const T& value)
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
    void Vector<T, Allocator>::resize(std::size_t n)
    {
        if(n > current_capacity)
        {
            try
            {
                T* temp = new T[n * 2];
                for(std::size_t i = 0; i < n; i++)
                {
                    if(i < current_index) temp[i] = this->arr[i];
                    else temp[i] = T();
                }
                delete [] (this->arr);
                this->arr = temp;
                this->current_index = n;
                this->current_capacity = 2 * n;
            }
            catch (const std::bad_alloc& e) {
                std::cerr << "Memory allocation failed: " << e.what() << std::endl;
                return;
            }
        }
        else
        {
            current_index = n;
        }
    }

    template <typename T, typename Allocator>
    void Vector<T, Allocator>::resize(std::size_t n, const T& value)
    {
        if(n > current_capacity)
        {
            try
            {
                T* temp = new T[n * 2];
                for(std::size_t i = 0; i < n; i++)
                {
                    if(i < current_index) temp[i] = this->arr[i];
                    else temp[i] = value;
                }
                delete [] (this->arr);
                this->arr = temp;
                this->current_index = n;
                this->current_capacity = 2 * n;
            }
            catch (const std::bad_alloc& e) {
                std::cerr << "Memory allocation failed: " << e.what() << std::endl;
                return;
            }
        }
        else
        {
            current_index = n;
        }
    }

    template <typename T, typename Allocator>
    void Vector<T, Allocator>::shrink_to_fit(void)
    {
        try
        {
            T* temp = new T[current_index];
            for(std::size_t i = 0; i < current_index; i++)
            {
                temp[i] = this->arr[i];
            }
            delete[] (this->arr);
            this->arr = temp;
            this->current_capacity = current_index;

        }
        catch (const std::bad_alloc& e) {
            std::cerr << "Memory allocation failed: " << e.what() << std::endl;
            return;
        }
    }

    template <typename T, typename Allocator>
    void Vector<T, Allocator>::reserve(std::size_t n)
    {
        if(n > current_capacity)
        {
            try
            {
                T* temp = new T[n * 2];
                for(std::size_t i = 0; i < current_index; i++)
                {
                    temp[i] = this->arr[i];
                }
                delete[] (this->arr);
                this->arr = temp;
                this->current_capacity = n * 2;
            }
            catch (const std::bad_alloc& e) {
                std::cerr << "Memory allocation failed: " << e.what() << std::endl;
                return;
            }
        }
    }

    template <typename T, typename Allocator>
    bool Vector<T, Allocator>::empty(void)
    {
        return current_index == 0;
    }

    template <typename T, typename Allocator>
    std::size_t Vector<T, Allocator>::max_size(void) {
        return std::numeric_limits<std::size_t>::max() / sizeof(T);
    }

    template <typename T, typename Allocator>
    T& Vector<T, Allocator>::at(std::size_t index) {
        if (index >= current_index) {
            throw std::out_of_range("Index out of bounds");
        }
        return arr[index];
    }

    template <typename T, typename Allocator>
    T& Vector<T, Allocator>::operator[](std::size_t index)
    {
        return arr[index];
    }

    template <typename T, typename Allocator>
    T& Vector<T, Allocator>::front(void)
    {
        return arr[0];
    }

    template <typename T, typename Allocator>
    T& Vector<T, Allocator>::back(void)
    {
        return arr[this->current_index - 1];
    }

    template <typename T, typename Allocator>
    T* Vector<T, Allocator>::data(void)
    {
        return this->arr;
    }

    template<typename T, typename Allocator>
    void Vector<T, Allocator>::clear(void)
    {
        for(std::size_t i = 0; i < current_index; i++)
        {
            this->arr[i].~T();
        }
        current_index = 0;
    }
    
    template <typename T, typename Allocator>
    void Vector<T, Allocator>::assign(std::size_t new_size, const T& value)
    {
        this->clear();

        if(new_size > current_capacity)
        {
            this->reserve(new_size);
        }

        for(std::size_t i = 0; i < new_size; i++)
        {
            this->push_back(value);
        }
    }


    template<typename T, typename Allocator>
    void Vector<T, Allocator>::assign(InputIterator first, InputIterator last)
    {
        if(first > last)
        {
            throw std::invalid_argument("Invalid range: last < first");
        }

        this->clear();

        std::size_t new_size = last - first;
        if(new_size > this->current_capacity)
        {
            this->reserve(new_size);
        }
        for(auto it = first; it != last; ++it)
        {
            this->push_back(*it);
        }
    }

    template<typename T, typename Allocator>
    void Vector<T, Allocator>::assign(std::initializer_list<T> init_list)
    {
        this->clear();
        std::size_t new_size = init_list.size();
        if(new_size > this->current_capacity)
        {
            this->reserve(new_size);
        }

        for(auto item : init_list)
        {
            this->push_back(item);
        }

    }

    template<typename T, typename Allocator>
    void Vector<T, Allocator>::move_backward(std::size_t index)
    {
        for(std::size_t i = current_index; i > index ; i--)
        {
            this->arr[i] = this->arr[i - 1];
        }
    }

    template<typename T, typename Allocator>
    typename Vector<T, Allocator>::iterator Vector<T, Allocator>::insert(const_iterator position, const T& value)
    {
        if(position > end() || position < begin())
        {
            throw std::out_of_range("Index out of bounds");
        }
        std::size_t index = (position - this->begin());
        this->reserve(current_index + 1);
        this->move_backward(index);
        this->arr[index] = value;
        current_index++;

        return iterator(position);

    }
    template<typename T, typename Allocator>
    typename Vector<T, Allocator>::iterator Vector<T, Allocator>:: insert(const_iterator position, T&& value)
    {
        if(position > end() || position < begin())
        {
            throw std::out_of_range("Index out of bounds");
        }
        std::size_t index = (position - this->begin());
        this->reserve(current_index + 1);
        this->move_backward(index);
        this->arr[index] = std::move(value);
        current_index++;

        return iterator(position);
    }

    template<typename T, typename Allocator>
    typename Vector<T, Allocator>::iterator 
    Vector<T, Allocator>::insert(const_iterator position, std::size_t n, const T& val)
    {
        for(std::size_t i = 0; i < n; i++)
        {
            this->insert(position, val);
        }
        return position;
    }

    template<typename T, typename Allocator>
    typename Vector<T, Allocator>::iterator 
    Vector<T, Allocator>::insert (const_iterator position, InputIterator first, InputIterator last)
    {
        if(position > end() || position < begin())
        {
            throw std::out_of_range("Index out of bounds");
        }
        if(first > last)
        {
            throw std::invalid_argument("Invalid range: last < first");
        }
        std::size_t add_sz = last - first;
        std::size_t index = position - begin();
        if(current_index + add_sz > current_capacity)
        {
            this->reserve(current_index + add_sz);
        }
        iterator it = first;
        for(std::size_t i = 0; i < current_index + add_sz; i++)
        {
            if(i >= index && i < index + add_sz)
            {
                this->arr[i + add_sz] = arr[i];
                this->arr[i] = *it;
                it++;
            }
        }
        this->current_index += add_sz;
        return first;
    }
    template<typename T, typename Allocator>
    typename Vector<T, Allocator>::iterator 
    Vector<T, Allocator>:: insert( const_iterator position, std::initializer_list<T> ilist )
    {
        this->insert(position, InputIterator(ilist.begin()), InputIterator(ilist.end()));
        return iterator(position);
    }
    template<typename T, typename Allocator>
    typename Vector<T, Allocator>::iterator 
    Vector<T, Allocator>:: erase(const_iterator position)
    {
        if(position >= end() || position < begin())
        {
            throw std::out_of_range("Index out of bounds");
        }
        for(std::size_t i = 0; i < current_index - 1; i++)
        {
            this->arr[i] = this->arr[i + 1];
        }
        this->current_index--;
        return iterator(position);
    }

    template<typename T, typename Allocator>
    typename Vector<T, Allocator>::iterator 
    Vector<T, Allocator>:: erase(const_iterator first, const_iterator last)
    {
        if(first >= end() || first < begin() || last <= begin() || last > end())
        {
            throw std::out_of_range("Index out of bounds");
        }   
        if(first >= last)
        {
            throw std::invalid_argument("Invalid range: last <= first");
        }
        std::size_t start = first - begin();
        std::size_t range = last - first;

        for(std::size_t i = start; i + range < current_index; i++)
        {
            this->arr[i] = this->arr[i + range];
        }
        this->current_index -= range;
        return iterator(first);
    }


    template <typename T, typename Allocator>
    Vector<T, Allocator>::~Vector()
    {
        delete[] arr;
    }

}
}
