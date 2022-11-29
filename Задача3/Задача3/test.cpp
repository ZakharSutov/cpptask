#include <iostream>
#include "BufferList.h"

int main()
{
	BufferList* BL = new BufferList();
	BufferList::ListIterator itr(BL);
	BL->addElem(1, itr);
	itr.next();
	BL->addElem(3, itr);
	BL->addElem(2, itr);
	itr.start();
	while (!itr.finish())
	{
		itr.next();
		std::cout << itr.getElement() << std::endl;
	}
	Iterator* itr2 = BL->getIterator();
	itr2->next();
	std::cout << itr2->getElement() << std::endl;
	Iterator* itr3 = BL->findElem(3);
	BL->deleteElem(*itr3);
	itr.start();
	while (!itr.finish())
	{
		itr.next();
		std::cout << itr.getElement() << std::endl;
	}
	std::cout << "Size: " << BL->getSize() << std::endl;
	std::cout << "isEmpty: " << BL->isEmpty() << std::endl;
	BL->makeEmpty();
	std::cout << "isEmpty: " << BL->isEmpty() << std::endl;
	itr.start();
	while (!itr.finish())
	{
		itr.next();
		std::cout << itr.getElement() << std::endl;
	}
	
}