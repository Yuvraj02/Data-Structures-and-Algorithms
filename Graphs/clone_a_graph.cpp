#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct Node {
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

 Node* cloneGraph(Node* node) {
        
        map<Node*, Node*> m;
        Node *newNode = new Node();
        
        newNode->val = node->val;
        
        m[node] = newNode;
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()){
            
            Node *front = q.front();
            q.pop();
            
            for(auto nbr : front->neighbors){
                
                if(m[nbr]==NULL){
                    
                    newNode = new Node();
                    newNode->val = nbr->val;
                    m[nbr] = newNode;
                    q.push(nbr);
                }
                
                m[front]->neighbors.push_back(m[nbr]);
                
            }
            
        }
       return m[node]; 
    }


int main(){



    return 0;
}