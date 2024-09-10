#ifndef __MY_INT_H__
#define __MY_INT_H__


class MyInt {
public:
    MyInt(int value = 0) : value(value) {}

    inline int getValue() const { return value; }
    inline void setValue(int v) { value = v; }

private:
    int value;
};


#endif