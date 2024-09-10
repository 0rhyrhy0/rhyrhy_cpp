#include "../headers/headers.h"

int main()
{
    try {
        BST* root = new BST(8);
        root->insert(4)->insert(12);
        root->insert(2)->insert(6)
            ->insert(10)->insert(14);
        root->show();
        cout << "Height : " << root->calcHeight() << endl;
        cout << "Nodes  : " << root->countNodes() << endl;
        delete root;

        cout << "===============================" << endl;

        BST* root2 = new BST(8);
        *root2 + 4 + 12 + 2 + 6 + 10 + 14;
        root2->show();
        cout << "Height : " << root2->calcHeight() << endl;
        cout << "Nodes  : " << root2->countNodes() << endl;
        delete root2;
    } catch (exception& e) {
        cerr << e.what() << endl;
    }
}