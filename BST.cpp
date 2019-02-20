#include<iostream>

using namespace std;

template<class T>
class Node
{
public:
	T data;
	Node *right;
	Node *left;
	Node(const T &value)
	{
		data = value;
		right = NULL;
		left = NULL;
	}
};

template<class T>
class Bintree
{
private:
		Node<T> *head;
public:
	Bintree()
	{
		head = NULL;
	}

	Bintree<T> &insert(const T &value)
	{	Node<T> *newNode = new Node<T>(value);
		if(head == NULL)
		{	
			head = newNode;
			return *this;
		}

		if (head!=NULL)
		{
			head->right = newNode;
			return *this;
		}
	}

	Bintree<T> &traverse(void)
	{
		cout << head->data << endl;
		cout << head->right->data << endl;
	}


};








int main()
{

Bintree<int> b;
b.insert(0);
b.insert(2);
b.traverse();



	return 0;
}
