#include <iostream>
template <typename T> struct Node
{
public:
	T data;
	Node* next = nullptr;
public: Node(T value) : data(value) { };
public: Node() { };
};
template <typename T> class Iterator
{
	
private:
	Node<T>* current = nullptr;
public:
	Node<T>& operator* ();
	Iterator<T>(Node<T>* first);
	Iterator<T>(Iterator& iterator);
	
	int countDifferentDigits(int num) {
		int count = 0;
		bool digits[10] = { false };

		while (num > 0) {
			int digit = num % 10;
			if (!digits[digit]) {
				digits[digit] = true;
				count++;
			}
			num /= 10;
		}
	return count;
	}
	~Iterator();
	void swap(Iterator& other);

	Iterator& operator =(const Iterator& other);
	Iterator<T>();

	Node<T>* operator++ ();
	Iterator& operator =(const Iterator&& other); 
	 
	Node<T> operator++ (int);
};

template <class T> class DigitalList
{
private:
	Node<T>* m_list;
	size_t m_max_size = 20;
public:
	
	Iterator<T> iterator;
	
	//какой-то кал
	void Clear();
	void Print();
	void Add(T value);
	//void Get();


		//реализация

	DigitalList();
	DigitalList(const DigitalList& a);
	DigitalList(DigitalList&& a);  
	DigitalList& operator =(const DigitalList& other);
	DigitalList& operator =(const DigitalList&& other);
	~DigitalList();
	Iterator<T> begin();
	Iterator<T> end();
	/*Const_Iterator<T> cbegin();
	Const_Iterator<T> cend();*/

	bool operator == (DigitalList& other);
	bool operator != (DigitalList& other);

	void swap(DigitalList& other);
	size_t size();
	size_t max_size();
	bool Empty();
};



//
//
//
//struct Node
//{
//	int data = 0;
//	Node* next = nullptr;
//};
//
//
//const size_t max_size = 20;
//class Iterator
//{};
////class Iterator
////{
////private:
////	Node* now_node;
////public:
////	////CopyConstructible
////	//Iterator(Node* iterator) : now_node(iterator) {}
////
////	//Iterator( Iterator&& iterator);//T(rv) 
////	//Iterator(Iterator& iterator);//T(rv) 
////	//Iterator& operator =(const Iterator&& other); //T u = rv;
////	//Iterator& operator =(const Iterator& other); //T u = rv;
////	////f
////	//// Destructible,
////	//~Iterator();
////	////f
////	////Swappable
////	//void swap(Iterator& other);
////	//f
////
////	Node* Get();
////	Node* operator ++(int);
////	Node* operator --(int);
////	Iterator(Node*& m_list);
////};
//template <typename T>
//class DigitalList
//{
//	
//	//typedef const Iterator const_iterator;
//
//	private:
//		Node* m_list = nullptr;
//		T d;
//		//Iterator m_iterator = Iterator(m_list);
//	public:
//		
//		
//		void Add(int value);
//		int Find(int value);
//		void Clear();
//
//		DigitalList(); 
//		DigitalList(const DigitalList& a);
//		DigitalList(DigitalList&& a);  //н value крадём
//		DigitalList& operator =(const DigitalList& other);
//		DigitalList& operator =(const DigitalList&& other);
//		~DigitalList();
//		/*Iterator begin();
//		Iterator end();*/
//		/*const_iterator cbegin() const;
//		const_iterator cend()const;*/
//		bool operator == ( DigitalList& other);
//		bool operator != ( DigitalList& other);
//		void swap(DigitalList& other);
//		//swap2
//		size_t Size();
//		size_t Max_size();
//		bool Empty();
//		
//
//	
//	
//};
