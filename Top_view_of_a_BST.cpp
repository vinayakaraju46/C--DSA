#include<iostream>
#include<bits/stdc++.h>
#include<map>

using namespace std;

template<class T> // Node of a tree
class Node
{
    public:
    T data;
    Node<T> *left;
    Node<T> *right;
    int height;
    Node(const T &val)
    {
        data = val;
        left = NULL;
        right = NULL;
        height = 0;
    }
};


template<class T>
class LNode // Node of a linkedList (queue represented as stack..)
{
    public:
    Node<T> *value;
    LNode<T> *next;
    LNode(Node<T> *node)
    {
        value = node;
        next = NULL;
    }
};

template<class T>
class Queuee // Queue 
{
    public:
    LNode<T> *head,*tail;
    int size;
    Queuee()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    Queuee<T> &push(Node<T> *node)
    {   size++;  
        LNode<T> *newNode = new LNode<T>(node);
        if(head == NULL)
        {
            tail = head = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        return *this;        
    }

    LNode<T> *pop()
    {   size--;
        LNode<T> *curr;
        curr = head;
        head = head->next;
        return curr;
    }

    int sos()
    {
        return size;
    }

    void displayque()
    {
        LNode<T> *actualNode = head;
        while(actualNode)
        {   Node<T> *curr = actualNode->value;
            cout << curr->data << endl;
            actualNode = actualNode->next; 
        }
    }
};






template<class T>
class Bintree // Binary Search Tree
{
    public:
    Node<T> *root;
    map< int,int > dict;
    vector<int> arr;
    
    int size;
    Bintree()
    {
        root = NULL;
        size = 0;
    }

    Bintree<T> &insert(const T &val)
    {
        root = insertNode(val, root);
    }

    Node<T> *insertNode(const T &val, Node<T> *node)
    {
        if(node == NULL)
        {
            return new Node<T>(val);
        }
        else if(val < node->data)
        {
            node->left = insertNode(val, node->left);
            node->left->height = node->height - 1;
        }
        else if(val > node->data)
        {
            node->right = insertNode(val, node->right);
            node->right->height = node->height + 1;
        }
        return node;
    }

 
    void TopView() // member function to print the top view of a binary tree
    {   map<int,int>::iterator itr;
        Queuee<int> que;
        que.push(root);
        while(que.sos() != 0)
        {
            LNode<T> *temp = que.pop();
            Node<T> *curr = temp->value;
            dict.insert(pair<int,int>(curr->height,curr->data));
            if(curr->left)
            {
                que.push(curr->left);
            }
            if(curr->right)
            {
                que.push(curr->right);
            }

        }
        for(itr=dict.begin();itr!=dict.end();++itr)
        {
            cout << itr->second << endl;
        }
        
    }


    void display()
    {
        traverseinorder(root);
    }

    void traverseinorder(Node<T> *node)
    {
        if(node->left)
        {
            traverseinorder(node->left);
        }
        cout << "data:" <<node->data << "and Height:" << node->height << endl ;
        if(node->right)
        {
            traverseinorder(node->right);
        }
    }

};





int main()
{
Bintree<int> tree;
int n,elem;
cout << "Enter the number of elements in a tree.." << endl;
cin >> n;
for(int i=0; i<n; i++)
{
    cin >> elem;
    tree.insert(elem);
}

tree.display();
tree.TopView();




    return 0;
}
