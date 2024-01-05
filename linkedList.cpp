#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    public:
    Node(int val, Node* next1){
        data = val;
        next = next1;
    }

    public:
    Node(int val){
        data = val;
        next = nullptr;
    }
};

void printLinkedList(Node *head){
    cout << "Node is: ";
    while(head){
        cout << head->data << " ";
        head=head->next;
    }
    cout << endl;
}

Node* convertArrayToLinkedList(vector<int> arr){
    if(arr.size() == 0) return NULL;
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        mover->next = new Node(arr[i]);
        mover = mover->next;
    }
    return head;
}

int lengthOfLinkedList(Node* head){
    int cnt = 0;
    Node* temp = head; 
    while(temp){
        temp=temp->next;
        cnt++;
    }
    cout << "Length of the Linked List is: ";
    return cnt;
}

bool checkIfValueIsPresent(Node* head, int val){
    Node* temp = head;
    while(temp){
        if(temp->data == val) return true;
        temp = temp->next;
    }
    return false;
}

Node* deleteHeadOfLinkedList(Node* head){
    if(!head || !head->next) return NULL;
    head=head->next;
    return head;
}

Node* deleteTailOfLinkedList(Node* head){
    if(!head || !head->next) return NULL;
    Node* temp = head;
    while(temp->next->next){
        temp=temp->next;
    }
    temp->next = NULL;
    return head;
}

Node* removeKthInLinkedList(Node* head, int k){
    if(!head) return NULL;
    if(k==1) return head->next;
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* removeElementLinkedList(Node* head, int val){
    if(!head) return NULL;
    if(head->data == val) return head->next;
    Node* temp = head;
    Node* prev = NULL;
    while(temp){
        if(temp->data == val){
            prev->next = prev->next->next;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* insertHeadOfLinkedList(Node* head, int val){
    Node* temp = new Node(val);
    temp->next = head;
    return temp;
}

Node* insertTailOfLinkedList(Node* head, int val){
    if(!head) return new Node(val);
    Node* temp = head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next = new Node(val);
    return head;
}

Node* insertKthLinkedList(Node* head, int val, int k){
    if(!head) {
        if(k==1){
            return new Node(val);
        }else {
            return NULL;
        }
    }
    if(k==1) {
        Node* newNode = new Node(val);
        newNode->next = head;
        return newNode;
    }
    
    int cnt = 0;
    Node* temp = head;
    while(temp){
        cnt++;
        if(cnt == k-1){
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

Node* insertBeforeValueLinkedList(Node* head, int el, int val){
    if(!head){
        return NULL;
    }
    if(head->data == val){
        Node* newNode = new Node(el);
        newNode->next = head;
        return newNode;
    }
    Node* temp = head;
    while(temp){
        if(temp->next->data == val){
            Node* newNode = new Node(el);
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

Node* addTwoLinkedList(Node* l1, Node* l2){
    Node* t1 = l1;
    Node* ans = new Node(0);
    Node* currentNode = ans;
    Node* t2 = l2;
    int carry = 0;
    while(t1 || t2){
        int sum = carry;
        if(t1) {
            sum+= t1->data;
            t1=t1->next;
        }
        if(t2){
            sum +=t2->data;
            t2=t2->next;
        }
        currentNode->next = new Node(sum%10);
        carry = sum/10;
        currentNode=currentNode->next;
    }
    if(carry){
        currentNode->next = new Node(carry);
    }
    
    return ans->next;
}

Node* groupOddEven(Node* head){
    if(!head || !head->next) return head;
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;
    while(even && even->next){
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd=odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

Node* sort012(Node* head){
    if(!head) return NULL;
    Node* zero = new Node(-1);
    Node* zeroHead = zero;
    
    Node* one = new Node(-1);
    Node* oneHead = one;
    
    Node* two = new Node(-1);
    Node* twoHead = two;

    Node* temp = head;
    while(temp){
        if(temp->data == 0){
            zero->next = temp;
            zero = zero->next;
        }else if(temp->data == 1){
            one->next = temp;
            one = one->next;
        }else {
            two->next = temp;
            two = two->next;
        }
        temp=temp->next;
    }

    zero->next = oneHead->next ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = NULL;
    return zeroHead->next;

}

int main(){
    int x;
    cin>>x;
    cout << "x is:" << x << endl;
    // Node* head = new Node(1);
    // head->next = new Node(2);
    // head->next->next = new Node(3);
    // printLinkedList(head);

    Node* head1 = convertArrayToLinkedList({1,0,0,1,1,0,2,1,2,0});
    Node* head2 = convertArrayToLinkedList({2,4,6,8,10});
    // printLinkedList(head);
    // cout << lengthOfLinkedList(head) << endl;
    // cout << checkIfValueIsPresent(head, 7) << endl;
    // head = deleteTailOfLinkedList(head);
    // printLinkedList(head);
    // head = deleteKthInLinkedList(head, 2);
    // printLinkedList(head);
    // head = insertBeforeValueLinkedList(head, 100, 3);


    printLinkedList(sort012(head1));
}