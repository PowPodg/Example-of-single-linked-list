#include <assert.h>
#include <iostream>
#include "myList.cpp"

using namespace std;

int main()
{
	myList<int>  mlst;
	mlst.add_back(42);
	mlst.add_back(3);
	mlst.add_back(10);
	mlst.add_back(7);

	for (int i = 0; i < mlst.get_size(); i++)
	{
		cout << mlst[i] << "  ";
	}
	cout << "\n\n";

	auto it = mlst.begin();
	it++;
	cout << "Postfix increment: " << *it << "\n\n";
	
	++it;
	cout << "Prefix increment: " << *it << "\n\n";

	cout << "Range-based for loop: " << "\n";
	for (auto& i : mlst)
	{
		cout << i << endl;
	}

	cin.get();
}

