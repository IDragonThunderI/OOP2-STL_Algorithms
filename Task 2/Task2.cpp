#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "..\Misc\ATD-time.h"
using namespace std;

void print(const unordered_map<int, TIME> container)
{
	if (container.empty())
		cout << "\nEmpty!!!\n";
	else
		for (typename unordered_map<int, TIME>::const_iterator i = container.begin(); i != container.end(); i++)
		{
			cout << (*i).first << " - ";
			(*i).second.print();
		}
	cout << "\n";
}

const bool descendingSortComp(const pair<int, TIME>& left, const pair<int, TIME>& right)
{
	return left.first > right.first;
}

const bool ascendingSortComp(const pair<int, TIME>& left, const pair<int, TIME>& right)
{
	return left.first < right.first;
}

const bool mappedTypeCompPred(const pair<int, TIME>& left, const pair<int, TIME>& right)
{
	return left.second < right.second;
}

void sortMap(unordered_map<int, TIME>& container, const bool(*comp)(const pair<int, TIME>&, const pair<int, TIME>&) = ascendingSortComp)
{
	vector<pair<int, TIME>> buf;
	for (unordered_map<int, TIME>::iterator i = container.begin(); i != container.end(); i++)
		buf.push_back(*i);
	sort(buf.begin(), buf.end(), comp);

	container.clear();
	for (size_t i = 0; i < buf.size(); i++)
		container.insert(buf.at(i));
}

TIME sumMaxAndMin(const unordered_map<int, TIME>& container)
{
	return (*max_element(container.begin(), container.end(), mappedTypeCompPred)).second +
		(*min_element(container.begin(), container.end(), mappedTypeCompPred)).second;
}

int main()
{
	system("chcp 1251 > nul");
	cout << "/* ЗАДАЧА №2 */\n\n";

	unordered_map<int, TIME> map1{ {0, TIME()} , {1, TIME(1, 20, 30, 400)}, {2, TIME(4, 30, 20, 100)}, {3, TIME(23, 59, 60, 0)}, {4, TIME(128, 256, 512, 1024)} };
	print(map1);

	TIME minElem = (*min_element(map1.begin(), map1.end(), mappedTypeCompPred)).second;
	map1.insert(pair<int, TIME>(5, minElem));
	print(map1);

	map1.erase(3);
	print(map1);

	sortMap(map1, descendingSortComp);
	print(map1);

	sortMap(map1);
	print(map1);

	unordered_map<int, TIME>::iterator findElemPos = map1.find(2);
	cout << "Позиция элемента   " << (*findElemPos).first << " - "; (*findElemPos).second.print();
	cout << "в словаре: " << distance(map1.begin(), findElemPos) + 1 << "\n";

	TIME sum = sumMaxAndMin(map1);
	for (unordered_map<int, TIME>::iterator i = map1.begin(); i != map1.end(); i++)
		(*i).second = (*i).second + sum;
	print(map1);

	return 0;
}