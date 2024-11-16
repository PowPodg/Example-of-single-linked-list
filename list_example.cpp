#include <iostream>
#include "myList.h"

using namespace std;
using namespace mlst;

int main()
{
	myList<int>  mlst { 1, 3, 5 };
	//Assigning new values
	mlst = { 2, 44, 11 };

	mlst.add_back(42);
	mlst.add_back(3);
	mlst.add_back(10);
	mlst.add_back(7);

	for (int i = 0; i < mlst.get_size(); i++)
	{
		cout << mlst[i] << "  ";
	}
	cout << "\n\n";
	
	mlst.Sort([](int a, int b) {return a > b; });

	cout << "Range-based for loop after sorting: " << "\n";	
	for (auto& i : mlst)
	{
		cout << i << "  ";
	}
	cout << endl;

	auto it = mlst.begin();
	it++;
	cout << "Postfix increment: " << *it << "\n\n";
	
	++it;
	cout << "Prefix increment: " << *it << "\n\n";

	//write to file
	auto zize_arr = mlst.get_size();
	string file_out = "out.bin";
	mlst.toFile(file_out);
	//read from file to T array
	int* data_arr = new int[zize_arr];
	int size_arr_f=0;
	auto res = mlst.fromFile(file_out, data_arr, zize_arr, size_arr_f);
	for (int i = 0; i < size_arr_f; i++)
	{
		cout << data_arr[i] << endl;
	}
	delete[] data_arr;
	cin.get();
}

