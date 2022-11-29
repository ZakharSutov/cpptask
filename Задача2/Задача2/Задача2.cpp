
#include <iostream>
#include "RingBuffer.h"
#include "Iterator.h"

using namespace std;
int main()
{
    RingBuffer* a = new RingBuffer(5);
    a->addElement(1);
    a->addElement(2);
    a->addElement(3);
    a->addElement(4);
    a->addElement(5);
    cout << a->getElem() << endl;
    cout << a->seeElem() << endl;
    RingBuffer* b = new RingBuffer(*a);
    a->doEmptyQueue();
    if (a->checkEmpty()) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    Iterator iter = Iterator(b);
    while (!iter.finish()) {
        iter.next();
        cout << iter.getValue() << endl;
    }
    cout << endl;
    iter.start();
    while (!iter.finish()) {
        iter.next();
        cout << iter.getValue() << endl;

    }
}
