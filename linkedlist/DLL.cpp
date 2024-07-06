#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;
    public:
    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};
Node* convertArrToDLL(vector<int> &arr){
    Node* head =new Node(arr[0]);
    Node* prev =head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=prev->next;
    }
    return head;
}
void print(Node* head){
    while(head!= NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
Node* deleteHead(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* prev=head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;
    delete(prev);
    return head;
}
Node* deleteTail(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* tail =head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node* prev =tail->back;
    tail->back=nullptr;
    prev->next=nullptr;
    delete(tail);
    return head;

}
Node* deleteKthElement(Node* head,int k){
    if(head==NULL){
        return NULL;
    }
    int cnt=0;
    Node* kNode=head;
    while (kNode!=NULL)
    {
        /* code */
        cnt++;
        if(cnt==k) break;
        kNode=kNode->next;

    }
    Node* prev =kNode->back;
    Node* front =kNode->next;
    if(prev==NULL && front==NULL){
        return NULL;
    }
    else if(prev==NULL){
        return deleteHead(head);
    }
    else if(front==NULL){
        return deleteTail(head);
    }
    prev->next=front;
    front->back=prev;
    kNode->back=nullptr;
    kNode->next=nullptr;
    return head;
    
}
Node* insertBeforeHead(Node* head,int val){
    Node* newHead=new Node(val,head,nullptr);
    head->back=newHead;
    return newHead;
}
Node* insertBeforeTail(Node* head,int val){
    Node* tail= head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node* prev= tail->back;
    Node* newNode =new Node(val,tail,prev);
    prev->next=newNode;
    tail->back=newNode;
    return head;
}
Node* insertBeforeKthElement(Node* head,int k,int val){
    if(k==1){
        return insertBeforeHead(head,val);
    }
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k)break;
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* newNode=new Node(val,temp,prev);
    prev->next=newNode;
    temp->back=newNode;
    return head;

}
int main(){
vector<int> arr ={12,4,2,7};
Node* head =convertArrToDLL(arr);
head=insertBeforeKthElement(head,1,198);
print(head);
return 0;
}