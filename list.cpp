#include "list.hpp"



template <typename T> Node<T>& Iterator<T>::operator* () 
{
	return *current;
}
template <typename T> Iterator<T>::Iterator(Node<T>* first) : current(first) {}
template <typename T> Iterator<T>::Iterator<T>()
{
	//current = new Node<T>();
	current = nullptr;
}
//template <typename T> Iterator<T>::Iterator<T>(Iterator& iterator)
//{
//
//}
template <typename T> Iterator<T>::Iterator<T>(Iterator& iterator)
{
	current = iterator.current;
}
template <typename T> Node<T>* Iterator<T>::operator++ ()
{
	if (current->next != nullptr)
	{
		current->data = current->data - countDifferentDigits(current->data);
		current = current->next;
	}
	return current;
}
template <typename T> Node<T> Iterator<T>::operator++ (int)
{
	Node<T> copy =  *current ;
	++(*this);
	return copy;
}




template <typename T>  Iterator<T>:: ~Iterator()
{
	current = nullptr;
}
template <typename T>  void Iterator<T>::swap(Iterator& other)
{
	Node<T>* w = current;
	current = other.current;
	other.current = w;
}
template <typename T> Iterator<T>& Iterator<T>::operator =(const Iterator<T>&& other)
{
	if (this == &other)
		return *this;

	current = other.current;
	return *this;
}
template <typename T> Iterator<T>& Iterator<T>::operator =(const Iterator<T>& other)
{
	if (this == &other)
		return *this;

	current = other.current;
	return *this;
}



//template <class T> Const_Iterator<T>:: Const_Iterator<T>()
//{
//	current = new Node<T>();
//}
//template <class T> Const_Iterator<T>::Const_Iterator<T>(Const_Iterator& iterator)
//{
//	current = iterator.current;
//}
//template <typename T> Node<T>* Const_Iterator<T>::operator++ ()
//{
//	if (current->next != nullptr)
//	{
//		current->data = current->data - countDifferentDigits(current->data);
//		current = current->next;
//	}
//	return current;
//}
//template <class T> Const_Iterator<T>::Const_Iterator(Node<T>* first) : current(first) {}
//template <class T> Node<T>& Const_Iterator<T>::operator* () { return current; }
//template <class T>  Const_Iterator<T>:: ~Const_Iterator()
//{
//	current = nullptr;
//}
//template <class T>  void Const_Iterator<T>::swap(Const_Iterator& other)
//{
//	Node<T>* w = current;
//	current = other.current;
//	other.current = w;
//}
//template <class T> Const_Iterator<T>& Const_Iterator<T>::operator =( Const_Iterator<T>&& other)
//{
//	if (this == &other)
//		return *this;
//
//	current = other.current;
//	return *this;
//}
//template <class T> Const_Iterator<T>& Const_Iterator<T>::operator =( Const_Iterator<T>& other)
//{
//	if (this == &other)
//		return *this;
//
//	current = other.current;
//	return *this;
//}



// ---------------------------------------------------------лист
template <typename T>  size_t DigitalList<T>::size()
{
	int count = 0;
	Node<T>* current_el = m_list;
	while (current_el != nullptr)
	{
		count++;
		current_el = current_el->next;
	}
	return count;
}
template <typename T> void DigitalList<T>::Add(T value)
{


	if (size() != m_max_size)
	{
		if (m_list != nullptr)
		{
			Node<T>* new_el = new Node<T>();
			(*new_el).data = value;
			(*new_el).next = nullptr;

			Node<T>* current_el = m_list;
			while (current_el->next != nullptr)current_el = current_el->next;
			current_el->next = new_el;

		}
		else
		{
			m_list = new Node<T>();
			m_list->data = value;
		}
	}
	if (size() == 1) iterator = Iterator<T>(m_list);
}

template <typename T> size_t DigitalList<T>::max_size() { return m_max_size; }

template <typename T> DigitalList<T>::DigitalList()
{

}
template <typename T> DigitalList<T>::DigitalList(const DigitalList& a)
{
	Node<T>* current_node = a.m_list;
	while (current_node != nullptr)
	{
		// можно сделать быстрее
		//1
		Add(current_node->data);
		current_node = current_node->next;
	}
}
template <typename T> DigitalList<T>::DigitalList(DigitalList&& a)
{
	Node* current_node = a.m_list;
	while (current_node != nullptr)
	{
		
		Add(current_node->data);
		current_node = current_node->next;
	}
}
template <typename T> void DigitalList<T>::Clear()
{
	if (m_list != nullptr)
	{
		Node<T>* del;
		Node<T>* current_el = m_list->next;
		while (current_el->next != nullptr)
		{
			del = current_el;
			current_el = current_el->next;
			delete (del);
		}
		delete (current_el);
		delete(m_list);
		m_list = nullptr;
	}
}
template <typename T> DigitalList<T>::~DigitalList()
{
	//Clear();
}
template <typename T> DigitalList<T>& DigitalList<T>::operator = (const DigitalList& other) //доделать
{
	if (this == &other)
		return *this;

	Clear();
	Node<T>* current_node = other.m_list;
	while (current_node != nullptr)
	{
		Add(current_node->data);
		current_node = current_node->next;
	}
	return *this;
}
template <typename T> DigitalList<T>& DigitalList<T>::operator =(const DigitalList&& other)
{
	//сделать 
	if (this == &other)
		return *this;

	Clear();
	Node* current_node = other.m_list;
	while (current_node != nullptr)
	{
		Add(current_node->data);
		current_node = current_node->next;
	}
	return *this;
}
template <typename T> Iterator<T> DigitalList<T>::begin()
{
	iterator = Iterator<T>(m_list);
	return iterator;
}
template <typename T> void DigitalList<T>::Print() 
{
	if (m_list != nullptr)
	{
		
		Node<T>* current_el = m_list;
		while (current_el != nullptr)
		{
			std::cout << current_el->data << " ";
			current_el = current_el->next;
			
		}
		
		std::cout << "\n";
	}
}

template <typename T> Iterator<T> DigitalList<T>::end() {
	iterator = Iterator<T>(m_list);
	//Iterator<T> w = iterator; 
	
	Node<T>& cur = *iterator;
	while (cur.next != nullptr)
	{
		cur = *cur.next; 
	}
	return iterator;

}

//
//template <typename T> Const_Iterator<T> DigitalList<T>::cbegin()
//{
////	if (const_iterator != nullptr) const_iterator = Const_Iterator<T>(m_list);
//	//// auto w = const_iterator;
//	//return *iterator;
//}
//template <typename T>Const_Iterator<T> DigitalList<T>::cend()
//{
//	return end();
//	
//	/*iterator = Iterator<T>(m_list);
//	Iterator<T> w = iterator;
//
//	Node<T>* cur = w.Get_current();
//
//	while (cur->next != nullptr)
//	{
//		cur = cur->next;
//	}
//	return cur;*/
//}

template <typename T> bool DigitalList<T>::operator == (DigitalList& other)
{
	if (this == &other)
		return true;
	if (size() != other.size()) return false;
	
	bool result = true;
	Node* current_node = m_list;
	while (current_node != nullptr)
	{
		if (Find(current_node->data) != other.Find(current_node->data)) return false;
		current_node = current_node->next;
	}
	return result;
}
template <typename T> bool DigitalList<T>::operator != ( DigitalList& other) // доделать 
{
	return !(*this == other);
}

template <typename T> void DigitalList<T>::swap(DigitalList& other)
{
	std::exchange(other.m_list, m_list);
}

template <typename T> bool DigitalList<T>::Empty()// доделать
{
	if (m_list != nullptr) return false;
	else false;
}

template <typename T> void swap(DigitalList<T>& a, DigitalList<T>& b)
{
	a.swap(b);
}


