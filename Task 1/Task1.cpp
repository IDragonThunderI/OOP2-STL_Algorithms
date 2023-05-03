#include <iostream>
#include <list>
#include <algorithm>
#include "..\Misc\ATD-time.h"
using namespace std;

void print(const list<TIME> container)
{
	if (container.empty())
		cout << "\nEmpty!!!\n";
	else
		for (typename list<TIME>::const_iterator i = container.begin(); i != container.end(); i++)
			(*i).print();
	cout << "\n";
}

const bool descendingSortComp(const TIME& left, const TIME& right)
{
	return left > right;
}

TIME sumMaxAndMin(const list<TIME> container)
{
	return *max_element(container.begin(), container.end()) + *min_element(container.begin(), container.end());
}

int main()
{
	system("chcp 1251 > nul");
	cout << "/* ЗАДАЧА №1 */\n\n";

	list<TIME> list1{ TIME(), TIME(1, 20, 30, 400), TIME(4, 30, 20, 100), TIME(23, 59, 60, 0), TIME(128, 256, 512, 1024) };
	print(list1);

	TIME minElem = *min_element(list1.begin(), list1.end());
	list1.push_back(minElem);
	print(list1);

	list1.erase(remove(list1.begin(), list1.end(), TIME(24, 0, 0, 0)), list1.end());
	print(list1);

	list1.sort(descendingSortComp);
	print(list1);

	list1.sort();
	print(list1);

	list<TIME>::iterator foundElemPos = find(list1.begin(), list1.end(), TIME(4, 30, 20, 100));
	cout << "Позиция элемента   "; (*foundElemPos).print();
	cout << "в списке: " << distance(list1.begin(), foundElemPos) + 1 << "\n";

	list<TIME> list2(list1.size(), sumMaxAndMin(list1));
	transform(list1.begin(), list1.end(), list2.begin(), list1.begin(), plus<TIME>());
	print(list1);

	return 0;
}