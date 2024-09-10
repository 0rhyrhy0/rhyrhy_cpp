#include "../headers/MyVector.h"
#include <algorithm> // copy, min

MyVector::MyVector(int size) : size(size), count(0) {
    arr = new int[size];
}

MyVector::MyVector(std::initializer_list<int> init)
    : size(power_of_2_minimum(init.size())), count(init.size())
{
    arr = new int[size];
    std::copy(init.begin(), init.end(), arr);
}

void MyVector::resize(size_t new_size) {
    if(size == new_size) return;

    int* new_arr = new int[new_size];
    std::copy(arr, arr + std::min(size, new_size), new_arr); // copy proper amount
    delete[] arr;
    arr = new_arr;
    size = new_size;

    if (count > new_size) {
        count = new_size;
    }
}

MyVector& MyVector::push(int value) {
    if(count == size) {
        resize(size*2);
    }

    arr[count++] = value;

    return *this;
}

int MyVector::pop_back() {
    int value = arr[--count];

    if ( (size > 4) && (count <= size/2) ) {
        resize(size/2);
    }

    return value;
}

bool MyVector::contains(int value) const {
    for(int num : *this) {
        if(num == value) {
            return true;
        }
    }

    return false;
}

size_t MyVector::power_of_2_minimum(size_t num) const {
    size_t ans = 4;
    while(ans < num) {
        ans <<= 1;
    }
    return ans;
}