#pragma once
typedef enum {
	LST_OK,
	LST_ERROR,
} LIST_Status;

template<typename T>
class myList
{
public:
	myList();
	~myList();

	void add_back(T data);
	void add_front(T data);
	LIST_Status insert_index(T data, const int index);
	LIST_Status delete_index(const int index);
	void del_front();
	void del_back();
	void clear_all();
	int get_size() { return Size; }
	T& operator [](const int index);
private:
	//------------
	template<typename T>
	class Node
	{
	public:
		Node* pAddr_next_node;
		T Data;

		Node(T data = T(), Node* pAddr = nullptr) :Data{ data }, pAddr_next_node{ pAddr } {}
	};
	//---------------
	Node<T>* Head;
	int Size;
};

