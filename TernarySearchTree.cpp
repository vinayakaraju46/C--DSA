#include<iostream>
#include<bits/stdc++.h>

using namespace std;

template<class T>
class Node
{
    public:
        char character;
        Node<T> *left;
        Node<T> *right;
        Node<T> *middle;
        int keyval;
        Node(const T &val)
        {
            character = val;
            left = NULL;
            right = NULL;
            middle = NULL;
            keyval = 0;
        }
};

template<class T>
class TernarySearchTree
{
    public:
        Node<T> *root;
        int size;
        TernarySearchTree()
        {
            root = NULL;
        }

        TernarySearchTree<T> &insert(string key,const T &val)
        {
            root = insertNode(key,val,root,0);
            
        }

        Node<T> *insertNode(string key,const T &val,Node<T> *node,int ind)
        {
            char c = key[ind];

            if(node == NULL)
            {
                node = new Node<T>(c);
            }
            if( c < node->character)
            {
                node->left = insertNode(key,val,node->left,ind);
            }
            else if( c > node->character)
            {
                node->right =insertNode(key,val,node->right,ind);
            }
            else if(ind < key.length()-1)
            {
                node->middle = insertNode(key,val,node->middle,ind+1);
            }
            else
            {
                node->keyval = val;
            }
            return node;
            
        }

        int getval(string key)
        {
            Node<T> *node = getvalNode(root,key,0);
            if(node == NULL)
            {
                return -1;
            }
            return node->keyval;
        }

        Node<T> *getvalNode(Node<T> *node, string key,int ind)
        {
            if(node == NULL)
            {
                return NULL;
            }
            char c = key[ind];
            if(c < node->character)
            {
                return getvalNode(node->left,key,ind);
            }
            else if(c > node->character)
            {
                return getvalNode(node->right,key,ind);
            }
            if(ind < key.length()-1)
            {
                return getvalNode(node->middle,key,ind+1);
            }
            else
            {
                return node;
            }
            
            
        }

};




int main()
{

TernarySearchTree<char> tt;
string sttr,getsttr;
int value;
int n;
cout << "Enter the number of team value pairs.." << endl;
cin >> n;
for(int i=0; i<n;i++)
{
    cin >> sttr;
    cin >> value;
    tt.insert(sttr,value);
}

cout << "Enter the retrieval key.." << endl;
cin >> getsttr;
int x;
x = tt.getval(getsttr);
cout << x;




    return 0;
}
