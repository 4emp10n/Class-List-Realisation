#include <iostream>

using namespace std;

template <class T>
class List
{
public:
	List();
	~List();

	void push_back(T data);
	int GetSize()
	{
		return size;
	}
	void pop_front();
	void clear();
	void push_front(T data);
	void insert(T data, int index);
	void removeAt(int index);
	T& operator [](const int index);
private:
	template <class T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int size;
	Node<T>* head;
};

template<class T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}

template <class T>
List<T> :: ~List()
{
	clear();
}

template<class T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	size++;
}

template<class T>
void List<T>::pop_front()
{
	Node<T>* current = head;
	head = head->pNext;
	delete current;
	size--;
}

template<class T>
void List<T>::clear()
{
	while (size)
	{
		pop_front();
	}
}

template<class T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	size++;

}

template<class T>
void List<T>::insert(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* newNode = new Node<T>(data, previous->pNext);
		previous->pNext = newNode;
		size++;
	}

	
	
}

template<class T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node <T>* temp = previous->pNext;
		previous->pNext = temp->pNext;

		delete temp;
		size--;
	}	
	
}

template<class T>
T& List<T>::operator[](const int index)
{
	Node<T>* current = this->head;
	int counter = 0;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

int main()
{
	List <int> lst;
	int size;
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		lst.push_back(rand() % 10);
	}

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}
	
	cout << endl;
	lst.insert(2, 2);
	cout << lst.GetSize() << endl << endl;
	

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}


	cout << endl;
	lst.removeAt(0);
	cout << lst.GetSize() << endl << endl;


	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	



	

	return 0;
}


