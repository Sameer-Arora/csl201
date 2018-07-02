
Node* InsertNth(Node *head, int data, int position)
{
  // Complete this method only
  // Do not write main function.
    int ct=0;
    Node* curr=head;
    while( ++ct != position ){
        curr=curr->next;
        
    }
    if( ct!= 1 ) {
    Node* temp=(Node*) malloc(sizeof(Node));
    temp->data=data;
    temp->next=curr->next;
    curr->next=temp;
    return head;
    }
    else{
    if( position == 0 ){
    Node* temp=(Node*) malloc(sizeof(Node));
    temp->data=data;
    temp->next=head;
    return temp;
        }
    else{
    Node* temp=(Node*) malloc(sizeof(Node));
    temp->data=data;
    temp->next=NULL;
    curr->next=temp;
    return head;
    }
    }
        
}