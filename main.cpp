#include <iostream>
#include <assert.h>
#include "LinkedList.h"
#include "Detail.h"

using namespace std;

/**
    Simple example of the usage of the LinkedList
*/
int main()
{
    Detail* firstDetail = new Detail();
    firstDetail->setCode('a')->setName("Detail A")->setValue(234.56)->setUnit("kg");
    Detail* secondDetail = new Detail();
    secondDetail->setCode('b')->setName("Detail B")->setValue(111.11)->setUnit("meters");
    Detail* thirdDetail = new Detail();
    thirdDetail->setCode('c')->setName("Detail C")->setValue(345.121)->setUnit("liters");
    Detail* forthDetail = new Detail();
    forthDetail->setCode('d')->setName("Detail D")->setValue(3267.11)->setUnit("square meters");

    LinkedList<Detail>* detailsList = new LinkedList<Detail>();
    detailsList->pushFront(*firstDetail);
    detailsList->pushBack(*secondDetail);
    detailsList->pushFront(*thirdDetail);
    detailsList->pushBack(*forthDetail);

    cout << "\nShould be ordered C, A, B, D:\n" << *detailsList;

    Detail * poppedBack = detailsList->popBack();
    Detail * poppedFront = detailsList->popFront();
    cout << "\nRemoved item from the back: " << *poppedBack << endl;
    cout << "\nRemoved item from the front: " << *poppedFront << endl;

    cout << "\nShould be ordered A, B:\n" << *detailsList;

    detailsList->pushBack(*thirdDetail);
    detailsList->pushBack(*forthDetail);
    // should be ordered A, B, C, D

    detailsList->deleteNode(*thirdDetail);
    // should be ordered A, B, D

    assert(!detailsList->contains(*thirdDetail));
    assert(detailsList->contains(*forthDetail));

    Detail* fifthDetail = new Detail();
    fifthDetail->setCode('e')->setName("Detail E")->setValue(88.0)->setUnit("cubic meters");

    detailsList->setValue(*fifthDetail, 0);
    cout << "\nShould be ordered E, B, D:\n" << *detailsList;

    return 0;
}
