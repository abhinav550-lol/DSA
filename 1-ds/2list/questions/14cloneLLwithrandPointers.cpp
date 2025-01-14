
//Approach 2 sc -> o(n) tc -> o(n)

class apporach2
{
    private:
    void copyOrginalList(Node* &head,Node* &tail,int val){
        Node* n = new Node(val);
        if(head == NULL && tail == NULL ){
            head = n;
            tail = n;
        }else{
         tail -> next = n;
         tail = n;
        }
    }
    public:
    Node *copyList(Node *orignalHead)
    {
        if(orignalHead==NULL) return nullptr;
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* t = orignalHead;
        while(t!=NULL){
            copyOrginalList(cloneHead,cloneTail,t->data);
            t = t-> next;
        }
        
        map <Node* , Node*>mappedNodes;
        Node* m1 = orignalHead;
        Node* m2 = cloneHead;
        while(m1!=NULL){
         mappedNodes[m1]=m2;
         m1 = m1 -> next;
         m2 = m2 -> next;
        }
        Node* c1 = orignalHead;
        Node* c2 = cloneHead;
        while(c1 != NULL && c2 != NULL){
            c2->arb = mappedNodes[c1->arb];
            c1 = c1 -> next;
            c2 = c2 -> next;
        }
        return cloneHead;
    }
};

//Approach 3  sc -> o(1) tc -> o(n)
class approach3
{
    private:
    void cloneOrignalList(Node* &head,Node* &tail,int val){
        Node* n = new Node(val);
        if(head==NULL){
            head = n;
            tail = n;
        }else{
            tail->next = n;
            tail = n;
        }
    }
    void insertCloneInMid(Node* &oHead, Node* &cHead){
        Node* t1 = oHead;
        Node* t2 = cHead;
        while(t2!=NULL && t1!=NULL){
            Node* next1 = t1 ->next;
            Node* next2 = t2 -> next;
            t1->next = t2;
            t2->next = next1;
            
            t1 = next1;
            t2 = next2;
        }
    }
    void revertLists(Node* &orignalHead, Node* &cloneHead){
        Node* prev = orignalHead;
        Node* curr = cloneHead;
        while(curr->next!=NULL){
            Node* next = curr -> next;
            curr -> next = next -> next;
            prev-> next = next;
            
            curr = next -> next;
            prev = next;
        }
        curr->next = NULL;
        prev->next = NULL;
    }
    public:
    Node *copyList(Node *orignalHead)
    {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* t = orignalHead;
        while(t!=NULL){
            cloneOrignalList(cloneHead,cloneTail,t->data);
            t= t-> next;
        }
        insertCloneInMid(orignalHead,cloneHead);
        t = orignalHead;
        while(t!=NULL){
            if(t->arb!=NULL && t-> next = NULL){
            t->next->arb = t->arb->next;
            }
            t = t-> next -> next;
        }
        revertLists(orignalHead,cloneHead);
        return cloneHead;
    }
};