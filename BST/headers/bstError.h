// NO EXTERNAL SOURCE FILE FOR THIS
#ifndef BST_ERROR_H
#define BST_ERROR_H

#include <exception>
#include <string>
#include "bst.h"


class BSTerror : public std::exception {
private:
    std::string message;

public:
    BSTerror(std::string msg) : message(msg) {}

    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};


/**
 * @param value the value which is not found.

 * @note The error message is :
 * @note "Couldn't find the value : `value`"
 */
class BSTvalueNotFound : public BSTerror {
public:
    BSTvalueNotFound(int value)
        : BSTerror("Couldn't find the value : " + std::to_string(value)) {}
};


/**
 * @param value the value which already exist.

 * @note BSL should have no duplicate values.
 * @note This error occur when you try to insert the same value which already exist.

 * @note The error message is :
 * @note "Same value already exists : `value`"
 */
class BSTsameValueExist : public BSTerror {
public:
    BSTsameValueExist(int value)
        : BSTerror("Same value already exists : " + std::to_string(value)) {}
};


#endif //BST_ERROR_H