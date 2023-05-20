// https://leetcode.com/problems/linked-list-cycle-ii/description/

// The logic to find position is 
// if the distance of the cycle start node is x from the head, then during the time slow pointer 
// reaches the start of the cycle, the fast pointer has already covered an extra distance x
// Now, from observation, if slow and fast pointers start from the start of the cycle,
// they meet together exactly at the complete cycle(ie, start of the cycle)
// now since the fast pointer is already at a distance x from the cycle-start node, 
// the slow and fast pointers will meet together with x distance remaining from the cycle-start node
// now the meeting node(of fast and slow) and the head both are at x ditance from the cycle-node and
// also they meet at the cycle node. So, by iterating from the meeting node and head node one by one,
// we get the node when the two pointers converge

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

class Solution
{
    public:
    bool detectLoop(Node* head)
    {
        
        Node * slow =head, *fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow)
                return true;
        }
        return false;
    
    }
    // for finding position
    struct Node *detectCycle(struct Node *head) {
        Node *fast = head, *slow = head;
        bool cycle = false;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                cycle = true;
                break;
            }
        }
        if(!cycle)
            return NULL;
        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};


// test case 
// n
// LL[1..n]
// k (node on which last node is connected)
// k = 0 signifies null

int main()
{
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        // if(ob.detectLoop(head) )
        //     cout<< "True\n";
        // else
        //     cout<< "False\n";
        Node * cyclePosition = ob.detectCycle(head);
        if(cyclePosition==NULL)
            cout<<"No cycle";
        else 
            cout <<cyclePosition->data;
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends