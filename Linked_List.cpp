#include<iostream>

using namespace std;

template<class T>
class Node
{
public:
	T data;
	Node *nextNode;
	Node(const T &value)
	{
		data = value;
		nextNode = NULL;
	}
};

template<class T>
class LinkedList
{
private:
	Node<T> *head;	

public:
	LinkedList()
	{ 
		head = NULL;

	}

	LinkedList<T> &insert(const T &value)
	{   Node<T> *newNode = new Node<T>(value) ;
		if(!head)
		{
			head = newNode;
		}
		else
		{
			newNode->nextNode = head;
			head = newNode;
		}
		return *this;
	}


	LinkedList<T> &deleteem(const T &value)
	{	
		Node<T> *currentNode = head;
		Node<T> *previousNode = NULL;

		while (currentNode->data != value)
		{
			previousNode = currentNode;
			currentNode = currentNode->nextNode;
		}
		if (previousNode == NULL)
		{
			head = currentNode->nextNode;
		}
		else
		{
			previousNode->nextNode = currentNode->nextNode;
		}
		return *this;

	}

	LinkedList<T> &traverse(void)
	{
		Node<T> *actualNode = head;
		while(actualNode)
		{
			cout << actualNode->data << endl;
			actualNode = actualNode->nextNode;

		}
		return *this;
	}
};




int main()
{

	LinkedList<int> L;
    int N,item;
    cout << "Enter the number of elements in a List...." << endl;
    cout << "" << endl;
    cin >> N;
    cout << "" << endl;
    for(int i=0; i<N; i++)
    {
    	cin >> item;
    	L.insert(item);
    }
    cout << "" << endl;
    L.traverse();
	return 0;
}
