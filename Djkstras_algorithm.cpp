#include<bits/stdc++.h>

using namespace std;

class Edge;

class Node
{
    public:
        string name;
        bool visited;
        Node *predeccor;
        vector< Edge* > adjacencylist;
        int min_distance ;
        Node(string data)
        {
            name = data;
            visited = false;
            predeccor = NULL;
            min_distance = INT_MAX;
        }
};


class Edge
{
    public:
        Node *startNode;
        Node *targetNode;
        int weight;
        Edge(int wt,Node *strt, Node *tar)
        {
            weight = wt;
            startNode = strt;
            targetNode = tar;
        }
};



class Algorithm
{   priority_queue< pair<int,Node*> > que;
    public:
        void calculateshortestpath(Node *arr[],Node *startvertex)
        {
            startvertex->min_distance = 0;
            que.push(pair<int,Node*>(startvertex->min_distance,startvertex));
            while(que.size() != 0)
            {
                pair<int,Node*> temp = que.top();
                Node *tempNode = temp.second;
                que.pop();
                for(int i=0; i<tempNode->adjacencylist.size();i++)
                {
                    Node *u = tempNode->adjacencylist[i]->startNode;
                    Node *v = tempNode->adjacencylist[i]->targetNode;
                    int newdist = u->min_distance + tempNode->adjacencylist[i]->weight;
                    if(newdist < v->min_distance)
                    {   
                        v->predeccor = u;
                        v->min_distance = newdist;
                        que.push(pair<int,Node*>(v->min_distance,v));
                    }
                }
            } 
        }

        void getshortestpath(Node *tarver)
        {
            cout << "Shortest path to vertex is.." << tarver->min_distance<<endl;
            Node *curr = tarver;
            while(curr)
            {
                cout << curr->name << endl;
                curr = curr->predeccor;
            }

        }
};




int main()
{ 
Node *n1,*n2,*n3,*n4,*n5,*n6,*n7,*n8;
n1 = new Node("a");
n2 = new Node("b");
n3 = new Node("c");
n4 = new Node("d");
n5 = new Node("e");
n6 = new Node("f");
n7 = new Node("g");
n8 = new Node("h");

Edge *e1,*e2,*e3,*e4,*e5,*e6,*e7,*e8,*e9,*e10,*e11,*e12,*e13,*e14,*e15,*e16;

e1 = new Edge(5,n1,n2);
e2 = new Edge(8,n1,n8);
e3 = new Edge(9,n1,n5);
e4 = new Edge(15,n2,n4);
e5 = new Edge(12,n2,n3);
e6 = new Edge(4,n2,n8);
e7 = new Edge(7,n8,n3);
e8 = new Edge(6,n8,n6);
e9 = new Edge(5,n5,n8);
e10 = new Edge(4,n5,n6);
e11 = new Edge(20,n5,n7);
e12 = new Edge(1,n6,n3);
e13 = new Edge(13,n6,n7);
e14 = new Edge(3,n3,n4);
e15 = new Edge(11,n3,n7);
e16 = new Edge(9,n4,n7);

n1->adjacencylist.push_back(e1);
n1->adjacencylist.push_back(e2);
n1->adjacencylist.push_back(e3);
n2->adjacencylist.push_back(e4);
n2->adjacencylist.push_back(e5);
n2->adjacencylist.push_back(e6);
n8->adjacencylist.push_back(e7);
n8->adjacencylist.push_back(e8);
n5->adjacencylist.push_back(e9);
n5->adjacencylist.push_back(e10);
n5->adjacencylist.push_back(e11);
n6->adjacencylist.push_back(e12);
n6->adjacencylist.push_back(e13);
n3->adjacencylist.push_back(e14);
n3->adjacencylist.push_back(e15);
n4->adjacencylist.push_back(e16);

Node *vertlist[9] = {n1,n2,n3,n4,n5,n6,n7,n8};
Algorithm algo;
algo.calculateshortestpath(vertlist,n1);
algo.getshortestpath(n7);

    return 0;
}
