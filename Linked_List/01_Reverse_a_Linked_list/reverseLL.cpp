// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};



class Solution{
    public:
    struct Node* reverseListIterative(struct Node *head)
    {
        Node * p = head, *q = NULL, *r;
        while(p){
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        return q;
    }
    struct Node* reverseList(struct Node * &head)
    {
        if(head==NULL || head->next==NULL)
            return head;
        Node *temp = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }
    
};
    


void printList(struct Node *head){
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

int main(){
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int T,n,l,firstdata;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        
        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        
        Solution ob;
        head = ob. reverseList(head);
        
        printList(head);
        cout << endl;
    }
    return 0;
}
