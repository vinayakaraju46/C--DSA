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
  int size;

public:
	LinkedList()
	{ 
		head = NULL;
	  size = 0;

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
  
  LinkedList<T> &insertend(const T &value)
  {	size++ ;
    Node<T> *newNode = new Node<T>(value);
    Node<T> *actualNode = head;
    
    while (actualNode->nextNode != NULL)
    {
      actualNode = actualNode->nextNode;
    }
    actualNode->nextNode = newNode;
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

int sizeoflist(void)
{
  return size;
}


int main()
{
  
  LinkedList<int> L;
  int N,item,enditem;
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
  cout << "End insert" << endl;
  cin >> enditem ;
  L.insertend(enditem);
  cout << "" << endl;
  L.traverse();
  cout << "size of list..." << L.sizeoflist() << endl; 
  return 0;
}
