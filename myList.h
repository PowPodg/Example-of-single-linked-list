#pragma once
#include <vector>
#include <algorithm>
#include <assert.h>
#include <fstream>
#include <typeinfo>

namespace mlst {

	typedef enum {
		LST_OK,
		LST_ERROR,
		FILE_ERROR
	} LIST_Status;

	template<typename T>
	class myList
	{
	public:
		myList();
		myList(const myList&);
		void operator = (const myList&);
		myList(myList&&);
		void operator = (myList&&);
		myList(std::initializer_list<T>);
		void operator = (std::initializer_list<T>);
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

		void Sort();
		void Sort(bool f(T a, T b));

		void Sort_1(void);
		void Sort_1(bool f(T a, T b));

		LIST_Status toFile(const std::string&);
		LIST_Status fromFile(const std::string&, T**, int&);
	private:
		//------------
		class Node
		{
		public:
			Node* pAddr_next_node;
			T Data;
			Node(T data = T(), Node* pAddr = nullptr) :Data{ data }, pAddr_next_node{ pAddr } {}
		};
		//---------------
		Node* Head;
		int Size;

	public:
		//---------------------
		class Iterator
		{
		public:
			Iterator(Node* node) :t_node(node) {}
			//----------------
			Iterator& operator++() {
				assert(t_node != nullptr);
				t_node = t_node->pAddr_next_node;
				return *this;
			}
			//----------------
			Iterator operator++(int) {
				assert(t_node != nullptr);
				auto this_cp = *this;
				t_node = t_node->pAddr_next_node;
				return this_cp;
			}
			//-----------------------
			bool operator!=(const Iterator& in) const {
				//return t_node != in.t_node;
				//return !operator==(in);
				return !(*this == in);
			}
			//------------------------
			T& operator*() const {
				assert(t_node != nullptr);
				return t_node->Data;
			}
			//-----------------------------
			bool operator==(const Iterator& in) const {
				//if (this == &in) return true;
				return t_node == in.t_node;
			}
			//-----------------------------
		private:
			Node* t_node;
		};
		//---------------------
		const Iterator begin() const {
			return Iterator(Head);
		}
		const Iterator end() const {
			return Iterator(nullptr);
		}
	};
}

#include "myList.cpp"
