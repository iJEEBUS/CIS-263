#include <iostream>
#include "bst.h"
using namespace std;

int main() {
    int key[15] = {20, 10, 3, 35, 2, 62, 39, 21, 1, 78, 16, 11, 50, 76, 28};
    BinarySearchTree t;
    int i;
    cout<<"inserting ";
    for (i=0;i<15;i++)
    {
        t.insert(key[i]);
        cout<<key[i]<<" ";
    }
    cout<<endl<<"Level-Order: ";
    t.levelorder();
    t.makeEmpty();
    t.levelorder();
    return 1;
}