
#include<iostream>

using namespace std;


template<class T>
class Node
{
    public:
    T data;
    Node<T> *left;
    Node<T> *right;
    Node(const T &value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

template<class T>
class BTree
{
    public:
    Node<T> *root;

    BTree()
    {
        root = nullptr;
    }

    Node<T> *insert(const T &value)
    {
        root = insertNode(value,root);
    }
    
    Node<T> *insertNode(const T &value,Node<T> *node)
    {   Node<T> *newNode = new Node<T>(value);
        if(node == NULL)
        {
            return newNode;
        }

        if(value < node->data)
        {
            node->left = insertNode(value,node->left);
        }
        if(value > node->data)
        {
            node->right = insertNode(value,node->right);
        }
        return node;

    }

    Node<T> *remove(const T &value)
    {
        root = removeNode(value,root);
    }


    Node<T> *removeNode(const T &value, Node<T> *node)
    {   Node<T> *tempNode;
        if(node == NULL)
        {
            return NULL;
        }
        else if(value < node->data)
        {
            node->left = removeNode(value,node->left);
        }
        else if(value > node->data)
        {
            node->right = removeNode(value,node->right);
        }
        else
        {
            if(node->left == NULL & node->right == NULL) 
            {
                cout << "removing the leaf node.." << endl;
                delete node;
                return NULL;
            }

            else if(node->left == NULL & node->right != NULL )
            {
                cout << "removing the node with one right child.." << endl;
                tempNode = node->right;
                delete node;
                return tempNode;
            }

            else if(node->left != NULL & node->right == NULL)
            {
                cout << "removing the node with one leftchild.." << endl;
                tempNode = node->left;
                delete node;
                return tempNode;
            }
            else
            {
                cout << "removing the node with two children..." << endl;
                tempNode = getrightmostofleft(node->left);
                node->data = tempNode->data;
                node->left = removeNode(tempNode->data,node->left);
            }
            
            }
        return node;
    }



    Node<T> *getrightmostofleft(Node<T> *node)
    {
        if(node->right)
        {
            return getrightmostofleft(node->right);
        }
        return node;
    }



    void display(void)
    {
        traverseinorder(root);
    }
    void traverseinorder(Node<T> *node)
    {
        if(node->left)
        {
            traverseinorder(node->left);
        }
        cout << node->data << endl;

        if(node->right)
        {
            traverseinorder(node->right);
        }
    }



};










int main()
{
BTree<int> bin;
int N,item,del;
cout << "enter the number of elements in a tree..." << endl;
cin >> N;
cout << " " << endl;
for(int i=0;i<N;i++)
{   
    cin >> item;
    bin.insert(item);
}
cout << " " << endl;
bin.display();
cout << "Enter the element that you wanna remove from the tree" << endl;
cin >> del;
bin.remove(del);
cout << "Tree after deletion " << endl;
bin.display();

    return 0;




}
