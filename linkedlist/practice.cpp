#include<bits/stdc++.h>
using namespace std;
class Node{
public:
int data;
Node* next;
public:
Node(int data1, Node* next1){
    data=data1;
    next=next1;
}
public:
Node(int data1){
    data=data1;
    next=nullptr;
}
};
Node* convertArrToLL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* mover =head;
    for(int i=1;i<arr.size();i++){
        Node* temp =new Node(arr[i]);
        mover -> next=temp;
        mover =temp;
    }
    return head;
}
int lengthOfLL(Node* head){
    int cnt=0;
    Node* temp=head;
    while(temp){
         temp=temp->next;
        cnt++;
    }
    return cnt;
}
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
Node* removesHead(Node* head){
    if(head==NULL)return head;
    Node* temp =head;
    head=head->next;
    delete temp;
    return head;
}
Node* removeTail(Node* head){
    if (head==NULL ||head->next ==NULL)return NULL;
    
    Node* temp =head;
    while(temp->next->next !=NULL){
        temp=temp->next;

    }
    delete temp->next;
    temp->next=nullptr;
    return head;
    

}
Node* removek(Node* head,int k){
    if(head==NULL) return head;
    if(k==1){
        Node* temp =head;
        head=head->next;
        free(temp);
        return head;
    }
    int cnt=0;
    Node* temp=head;
    Node* prev =NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
Node* removeel(Node* head,int el){
    if(head==NULL) return head;
    if(head->data==el){
        Node* temp =head;
        head=head->next;
        free(temp);
        return head;
    }
    Node* temp=head;
    Node* prev =NULL;
    while(temp!=NULL){
      
        if(temp->data==el){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
Node* insertHead(Node* head,int val){
    return new Node(val,head);
}
Node* insertTail(Node* head,int val){
    if(head==NULL){
        return new Node(val);
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;

    }
    Node* newNode =new Node(val);
    temp->next=newNode;
    return head;
}
Node* insertPosition(Node* head,int el,int k){
    if(head==NULL){
        if(k==1){
            return new Node(el);
        }
        else{
            return head;
        }
    }
    if(k==1){
        return new Node(el,head);

    }
    int cnt=0;
    Node* temp =head;
    while(temp!=NULL){
        cnt++;
        if(cnt==(k-1)){
           Node* x= new Node(el,temp->next);
           temp->next=x;
           break;
        }
        temp=temp->next;
    }

    return head;

}
Node* insertBeforeValue(Node* head,int el,int val){
    if(head==NULL){
        return NULL;
    }
    if(head->data==val){
        return new Node(el,head);

    }
    
    Node* temp =head;
    while(temp->next!=NULL){
       
        if(temp->next->data==val){
           Node* x= new Node(el,temp->next);
           temp->next=x;
           break;
        }
        temp=temp->next;
    }

    return head;

}
int main(){
    vector<int> arr ={2,4,5,7};
  Node* head = convertArrToLL(arr);
//  Node* temp =head;
//  while(temp){
//     cout<<temp->data<<" ";
//     temp =temp ->next;
//  }
// cout<<endl;
// cout<<"length of linked list is"<<lengthOfLL(head)<<endl;

// // head=removesHead(head);
// // print(head);
// head=removeTail(head);
// print(head);
// head=removek(head,4);
// print(head);
// head=removeel(head,7);
// print(head);
// head=insertTail(head,12);

// head=insertHead(head,3);
// print(head);
// head=insertPosition(head,100,3);
// print(head);
head=insertBeforeValue(head,134,5);
print(head);
} 