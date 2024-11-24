#pragma once
#include "myList.h"

using namespace std;

namespace mlst {

	template<typename T>
	myList<T>::myList()
	{
		Size = 0;
		Head = nullptr;
	}
	//------------------------
	template<typename T>
	myList<T>::myList(const myList& ml)
	{
		for (auto& i : ml)
		{
			this->add_back(i);
		}
	}
	template<typename T>
	void myList<T>::operator=(const myList& ml)
	{
		for (auto& i : ml)
		{
			this->add_back(i);
		}
	}
	//-------------------------------
	template<typename T>
	myList<T>::myList(myList&& pml)
	{
		*this = pml;
		pml.clear_all();
	}
	//------------------------
	template<typename T>
	void myList<T>::operator=(myList&& pml)
	{
		for (auto& i : pml)
		{
			this->add_back(i);
		}
		pml.clear_all();
	}
	//-------------------------------------
	template<typename T>
	myList<T>::myList(initializer_list<T> lst)
	{
		for (auto& i : lst)
		{
			this->add_back(i);
		}
	}
	template<typename T>
	void myList<T>::operator=(initializer_list<T> lst)
	{
		clear_all();
		for (auto& i : lst)
		{
			this->add_back(i);
		}
	}
	//--------------------
	template<typename T>
	template<typename ...Arg>
	myList<T>::myList(const Arg & ...in)
	{
		(this->add_back(in), ...);
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
		Head = new Node(data, Head);
		Size++;
	}
	//---------------------------------------
	template<typename T>
	LIST_Status myList<T>::insert_index(T data, const int index)
	{
		if (index == 0)
		{
			add_front(data);
			return LST_OK;
		}
		else if (index > 0 && index < this->Size)
		{
			Node* node_temp = Head;
			int ind = index - 1;
			while (ind)
			{
				node_temp = node_temp->pAddr_next_node;
				ind--;
			}
			node_temp->pAddr_next_node = new Node(data, node_temp->pAddr_next_node);
			Size++;
			return LST_OK;
		}
		else if (index < 0 || index >= this->Size)
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
		else if (index > 0 && index < this->Size)
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
		else if (index < 0 || index >= this->Size)
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
		if (index >= 0)
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
	//----------------------------------------
	template<typename T>
	void myList<T>::Sort()
	{
		vector<T> temp_arr(Size);
		int cnt = 0;
		for (auto& i : *this)
		{
			temp_arr.at(cnt) = i;
			++cnt;
		}
		sort(temp_arr.begin(), temp_arr.end());
		cnt = 0;
		for (auto& i : *this)
		{
			i = temp_arr.at(cnt);
			++cnt;
		}
	}
	//----------------------------------------
	template<typename T>
	void myList<T>::Sort(bool f(T a, T b))
	{
		vector<T> temp_arr(Size);
		int cnt = 0;
		for (auto& i : *this)
		{
			temp_arr.at(cnt) = i;
			++cnt;
		}
		sort(temp_arr.begin(), temp_arr.end(), f);
		cnt = 0;
		for (auto& i : *this)
		{
			i = temp_arr.at(cnt);
			++cnt;
		}
	}
	//--------------------------------
	template<typename T>
	void myList<T>::Sort_1(void)
	{
		T* temp_arr = new T[Size];
		int cnt = 0;
		for (auto& i : *this)
		{
			temp_arr[cnt] = i;
			++cnt;
		}
		sort(temp_arr, &temp_arr[Size]);
		cnt = 0;
		for (auto& i : *this)
		{
			i = temp_arr[cnt];
			++cnt;
		}

		delete[] temp_arr;
		temp_arr = nullptr;
	}
	//--------------------------------------
	template<typename T>
	void myList<T>::Sort_1(bool f(T a, T b))
	{
		T* temp_arr = new T[Size];
		int cnt = 0;
		for (auto& i : *this)
		{
			temp_arr[cnt] = i;
			++cnt;
		}
		sort(temp_arr, &temp_arr[Size], f);
		cnt = 0;
		for (auto& i : *this)
		{
			i = temp_arr[cnt];
			++cnt;
		}

		delete[] temp_arr;
		temp_arr = nullptr;
	}
	//----------------------------------------------------------------
	template<typename T>
	LIST_Status myList<T>::toFile(const std::string& file_name)
	{
		int sz = sizeof(T);
		ofstream out_f;
		out_f.open(file_name, ios_base::binary);
		if (out_f.is_open())
		{
			auto tp = typeid(T).name();
			string fin(tp);

			if (strstr(fin.c_str(), "std::basic_string") != 0)
			{
				for (auto& it : *this)
				{
					string st = " "; st = it;
					size_t sz_st = st.size();
					out_f.write((char*)&sz_st, sizeof(sz_st));
					out_f.write(&st[0], sz_st);
				}
			}
			else
			{
				if (sz <= sizeof(int64_t))
				{
					for (auto& it : *this)
					{
						out_f.write((char*)&sz, sz);
						out_f.write((char*)&it, sz);
					}
				}
				else
				{
					//for user objects ......Not yet implemented!!
					out_f.close();
					return FILE_ERROR;
				}
			}
			out_f.close();
		}
		else return FILE_ERROR;
		return LST_OK;
	}
	//------------------------------------------------
	template<typename T>
	LIST_Status myList<T>::toFile_async(const std::string& file_name)
	{
		LIST_Status res = FILE_ERROR;
		auto async_to_file = std::async(std::launch::async, [&]() {
			res = toFile(file_name);
			});
		async_to_file.get();
		return res;
	}
	//---------------------------
	template<typename T>
	LIST_Status myList<T>::fromFile(const std::string& file_name, T* data_o, const int& size_arr, int& index)
	{
		int sz_var = sizeof(T);
		index = 0;
		ifstream in_f;
		in_f.open(file_name, ios_base::binary);
		in_f.seekg(0);
		if (in_f.is_open()) {
			auto tp = typeid(T).name();
			string fin(tp);
			if (strstr(fin.c_str(), "std::basic_string") != 0)
			{
				while (!in_f.eof()) {
					int sz = 0;
					in_f.read((char*)&sz, sizeof(sz));
					string data_read(sz, ',');
					in_f.read(&data_read[0], sz);
					for (size_t i = 0; i < sz; i++)
					{
						data_o[index] += data_read[i];
					}
					++index;
				}
				if (index > 2) index -= 1;
				if (index > size_arr)return FILE_ERROR;
			}
			else
			{
				if (sz_var <= sizeof(int64_t))
				{
					while (!in_f.eof()) {
						int sz = 0;
						in_f.read((char*)&sz, sizeof(sz));
						in_f.read((char*)&data_o[index], sz);
						++index;
					}
					if (index > 2) index -= 1;
					if (index > size_arr)return FILE_ERROR;
				}
				else
				{
					//for user objects ......Not yet implemented!!
					in_f.close();
					return FILE_ERROR;
				}
			}
			in_f.close();
		}
		else return FILE_ERROR;
		return LST_OK;
	}
	//-------------------------------------------------------
	template<typename T>
	LIST_Status myList<T>::fromFile_async(const std::string& file_name)
	{
		LIST_Status res = FILE_ERROR;
		int sz_var = sizeof(T);
		ifstream in_f;
		in_f.open(file_name, ios_base::binary);

		auto async_from_file = std::async(std::launch::async, [&]()
			{
				if (in_f.is_open()) {
					auto tp = typeid(T).name();
					string fin(tp);
					if (strstr(fin.c_str(), "std::basic_string") != 0)
					{
						while (!in_f.eof()) {
							int sz = 0;
							in_f.read((char*)&sz, sizeof(sz));
							string data_read(sz, ',');
							in_f.read(&data_read[0], sz);
							T data_temp = T();
							if (sz)
							{
								for (size_t i = 0; i < sz; i++)
								{
									data_temp += data_read[i];
								}
								this->add_back(data_temp);
							}
						}
					}
					else
					{
						if (sz_var <= sizeof(int64_t))
						{
							while (!in_f.eof()) {
								int sz = 0;
								T data_temp = T();
								in_f.read((char*)&sz, sizeof(sz));
								if (sz)
								{
									in_f.read((char*)&data_temp, sz);
									this->add_back(data_temp);
								}
							}
						}
						else
						{
							in_f.close();
							//for user objects ......Not yet implemented!!
							res = FILE_ERROR;
						}
					}
					in_f.close();
					res = LST_OK;
				}
				else res = FILE_ERROR;
			});
		async_from_file.get();
		return res;
	}
}
//--------------------------------------------------------

