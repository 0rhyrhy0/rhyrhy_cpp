#ifndef BST_H
#define BST_H

/* Manage all the Nodes as BST class object. */
class BST {
public:
    BST(int v=0) :
        value(v),
        parent(nullptr),
        left(nullptr), 
        right(nullptr)
    {}

    ~BST();

    /**
     * @return The largest Node of the BST.
     */
    BST* largest();

    /**
     * @return The smallest Node of the BST.
     */
    BST* smallest();

    /**
     * @param value The value you're finding.
     * @return The `BST*` who have the `value`.
     * @throw `BSTvalueNotFound` if `value` is not found.
     */
    BST* find(int value);

    /**
     * @param value The value you're inserting.
     * @note Insert `value`.
     */
    BST* insert(int value);
    /** 
     * @note Execute `insert(value)`, then return `*this`.
        */
    BST& operator+ (int value);


    /**
     * @param value The value you're deleting.
     * @throw `BSTvalueNotFound` if `value` is not found.
     * @note Delete `value`.
     */
    BST* remove(int value);

    /** @note Show the whole tree. */
    void show() const;

    /** @return The height of the Node. */
    int calcHeight() const;

    /** @return The Nodes count of this BST. */
    int countNodes() const;

private:
    int value;
    BST* parent;
    BST* left;
    BST* right;

    /** @note Inner function for `show()` */
    void showHelper() const;
};


#endif // BST_H