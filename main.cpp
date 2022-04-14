#include <iostream>
#include "bTree.h"

int main() {
    bTree t;

    key k;
    key q;

    k.s = 'c';
    k.n = 10;

    q.s = 'c';
    q.n = 10;

    for (int i = 0; i < 5; ++i) {
        t.insert(q);
        t.insert(k);
        q.n += 3;
        k.n -= 3;
    }

//    std::cout  << " ------------------------------------------------------------------------" << std::endl;
//    t.print();

    q.n += 1;
    k.n -= 1;

    for (int i = 0; i < 5; ++i) {
        t.insert(q);
        t.insert(k);
        q.n -= 3;
        k.n += 3;
    }

//    std::cout  << " ------------------------------------------------------------------------" << std::endl;
//    t.print();

    q.n += 1;
    k.n -= 1;

    for (int i = 0; i < 5; ++i) {
        t.insert(q);
        t.insert(k);
        q.n += 3;
        k.n -= 3;
    }

//    std::cout  << " ------------------------------------------------------------------------" << std::endl;
//    t.print();

    k.n = 10;
    t.del(k);
//    std::cout  << " ------------------------------------------------------------------------" << std::endl;
//    t.print();
    t.del(k);
    std::cout  << " ------------------------------------------------------------------------" << std::endl;
    t.print();

    t.inorderWalkR();

//    k.n = 1112;
//    k.s = 'c';
//    t.del(k);
//    std::cout  << " ------------------------" << std::endl;
//    t.print();
    return 0;
}
