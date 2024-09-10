#ifndef __MY_VECTOR__
#define __MY_VECTOR__
#include <initializer_list>
#include <iostream>
#include <cstdio> // size_t

class MyVector {
public:
    // power of 2 recommended (2, 4, 8, ...)
    MyVector(int size = 8);
    MyVector(std::initializer_list<int> init);

    MyVector& push(int value);
    int pop_back();
    bool contains(int value) const;

    bool is_empty() const            { return !count;      }
    const int* begin() const         { return arr;         }
    const int* end() const           { return arr + count; }
    int* begin()                     { return arr;         }
    int* end()                       { return arr + count; }
    int& operator[](size_t idx)      { return arr[idx];    }
    int operator[](size_t idx) const { return arr[idx];    }
    size_t get_count() const         { return count;       }
    size_t get_size() const          { return size;        }

private:
    int* arr;
    size_t size;
    size_t count;

    void resize(size_t new_size);

    //for initializing only
    size_t power_of_2_minimum(size_t num) const;

//friend:
    friend std::ostream& operator<<(std::ostream& os, const MyVector& v);
};

#endif
