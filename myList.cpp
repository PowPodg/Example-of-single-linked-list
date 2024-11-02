#include "myList.h"

template<typename T>
myList<T>::myList()
{
	Size = 0;
	Head = nullptr;
}
//----------------------
template<typename T>
myList<T>::~myList()
{
	clear_all();
}
//----------------------------
template<typename T>
void myList<T>::add_back(T data)
{
	if (Head == nullptr)
	{
		Head = new Node(data);
	}
	else {
		Node* temp_node = Head;
		while (temp_node->pAddr_next_node != nullptr)
		{
			temp_node = temp_node->pAddr_next_node;
		}
		temp_node->pAddr_next_node = new Node(data);
	}
	Size++;
}
//---------------------------------------
template<typename T>
void myList<T>::add_front(T data)
{
	Head = new Node(data,Head);
	Size++;
}

//---------------------------------------
template<typename T>
LIST_Status myList<T>::insert_index(T data, const int index)
{
	if (index==0)
	{
		add_front(data);
		return LST_OK;
	}
	else if (index>0)
	{
		Node* node_temp = Head;
		int ind = index-1;
		while(ind)
		{
			node_temp = node_temp->pAddr_next_node;
			ind--;
		}
		node_temp->pAddr_next_node = new Node(data, node_temp->pAddr_next_node);
		Size++;
		return LST_OK;
	}
	else if (index<0)
	{
		return LST_ERROR;
	}	
}
//------------------------------------------------------------
template<typename T>
LIST_Status myList<T>::delete_index(const int index)
{
	if (index == 0)
	{
		del_front();
		return LST_OK;
	}
	else if (index > 0)
	{
		Node* node_temp = Head;
		int ind = index - 1;
		while (ind)
		{
			node_temp = node_temp->pAddr_next_node;
			ind--;
		}
		Node* node_del = node_temp->pAddr_next_node;
		node_temp->pAddr_next_node = node_del->pAddr_next_node;
		delete node_del;
		Size--;
		return LST_OK;
	}
	else if (index < 0)
	{
		return LST_ERROR;
	}
}
//--------------------------------------
template<typename T>
void myList<T>::del_front()
{
	Node* temp_node = Head;
	Head = Head->pAddr_next_node;
	delete temp_node;
	Size--;
}
//----------------------------------
template<typename T>
void myList<T>::del_back()
{
	delete_index(Size - 1);
}
//------------------------------
template<typename T>
void myList<T>::clear_all()
{
	while (Size)
	{
		del_front();
	}
}
//---------------------------------------
template<typename T>
T& myList<T>::operator[](const int index)
{
	if(index>=0)
	{
		int count = 0;
		Node* temp_node = Head;
		while (temp_node != nullptr)
		{
			if (count == index)
			{
				return temp_node->Data;
			}
			temp_node = temp_node->pAddr_next_node;
			count++;
		}
	}
}
