#include <iostream>
#include <set>
#include <algorithm>
#include "../Misc/ATD-time.h"
using namespace std;

template<typename T>
void print(const T container)
{
	if (container.empty())
		cout << "\nEmpty!!!\n";
	else
		for (typename T::const_iterator i = container.begin(); i != container.end(); i++)
			(*i).print();
	cout << "\n";
}

TIME sumMaxAndMin(const multiset<TIME> container)
{
	return *max_element(container.begin(), container.end()) + *min_element(container.begin(), container.end());
}

int main()
{
	system("chcp 1251 > nul");
	cout << "/* ЗАДАЧА №3 */\n\n";

	multiset<TIME> multiset1{ TIME(), TIME(1, 20, 30, 400), TIME(4, 30, 20, 100), TIME(23, 59, 60, 0), TIME(128, 256, 512, 1024) };
	print(multiset1);

	TIME minElem = *min_element(multiset1.begin(), multiset1.end());
	multiset1.insert(minElem);
	print(multiset1);

	multiset1.erase(TIME(24, 0, 0, 0));
	print(multiset1);

	multiset<TIME, greater<TIME>> multiset2;
	for (multiset<TIME>::iterator i = multiset1.begin(); i != multiset1.end(); i++)
		multiset2.insert(*i);
	print(multiset2);

	print(multiset1);

	multiset<TIME>::iterator foundElemPos = find(multiset1.begin(), multiset1.end(), TIME(4, 30, 20, 100));
	cout << "Позиция элемента   "; (*foundElemPos).print();
	cout << "в множестве: " << distance(multiset1.begin(), foundElemPos) + 1 << "\n";

	multiset<TIME> multiset3;
	for (multiset<TIME>::iterator i = multiset1.begin(); i != multiset1.end(); i++)
		multiset3.insert(*i + sumMaxAndMin(multiset1));
	print(multiset3);

	return 0;
}