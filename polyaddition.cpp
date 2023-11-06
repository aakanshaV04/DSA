#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coef;
    int exp;
    struct node *next;
};

struct node *create(struct node *head,int coeff,int exp){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coef=coeff;
    newnode->exp=exp;
    newnode->next=NULL;

    if(head==NULL){
        head=newnode;
    }
    else if(exp >head->exp){
        newnode->next=head;
        head=newnode;
    }
    else{
        struct node *ptr;
        ptr=head;
        struct node *ptr2=head;
        while( ptr!=NULL && exp < ptr->exp){
            ptr2=ptr;
            ptr=ptr->next;
        }
        ptr2->next=newnode;
        newnode->next=ptr;
    }
    return head;
}
void display(struct node *head){
    struct node *ptr=head;
    
   
    while(ptr->next!=NULL){
        printf("%dx^%d +",ptr->coef,ptr->exp);
        ptr=ptr->next;
    }
    printf("%dx^%d ",ptr->coef,ptr->exp);
    
}
struct node *add(struct node *head1,struct node *head2,struct node *res){
    struct node *ptr1=head1;
    struct node *ptr2=head2;
    struct node *ptr3=res;
    while(ptr1!=NULL && ptr2!=NULL){
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        if(ptr1->exp > ptr2->exp){
            newnode->coef=ptr1->coef;
            newnode->exp=ptr1->exp;
            ptr1=ptr1->next;
            
        }
        else if(ptr1->exp < ptr2->exp){
            newnode->coef=ptr2->coef;
            newnode->exp=ptr2->exp;
            ptr2=ptr2->next;
        }
        else{
            ptr1->coef=ptr1->coef+ptr2->coef;
            newnode->coef=ptr1->coef;
            newnode->exp=ptr1->exp;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        newnode->next=NULL;
        if(res==NULL){
            res=newnode;
            ptr3=res;
        }
        else{
            ptr3->next=newnode;
            ptr3=ptr3->next;
        }
    }
    while(ptr1!=NULL){
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->coef=ptr1->coef;
        newnode->exp=ptr1->exp;
        newnode->next=NULL;
        ptr3->next=newnode;
        ptr3=ptr3->next;

        ptr1=ptr1->next;
    }
    while(ptr2!=NULL){
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->coef=ptr2->coef;
        newnode->exp=ptr2->exp;
        newnode->next=NULL;
        ptr3->next=newnode;
        ptr3=ptr3->next;
        ptr2=ptr2->next;
    }
    return res;
    
    
}



int main(){
    struct node *head1=NULL;
    struct node *head2=NULL;
    struct node *res=NULL;
    int n;
   
    printf("Number of terms in 1st polynomial : ");
    scanf("%d",&n);
    printf("\n");
   
    
    printf("\n");
    while(n--){
        int coeff,exp;
        printf("Enter the coefficient and Exponent value : ");
        scanf("%d %d",&coeff,&exp);
        
        head1=create(head1,coeff,exp);
    }
    printf("\n");
    printf("First Polynomial:   ");
    display(head1);
    printf("\n\n");
   
    
    printf("\n");
    int n1;
    printf("Number of terms in 2nd polynomial : ");
    scanf("%d",&n1);
    while(n1--){
        int coeff,exp;
        printf("Enter the coefficient and Exponent value : ");
        scanf("%d %d",&coeff,&exp);
        
        head2=create(head2,coeff,exp);
    }
    printf("\n");
    printf("Second Polynomial is ");
    display(head2);
    printf("\n\n");
    res=add(head1,head2,res);
    printf("\n");
    
   
    
    printf("\n");
    printf("Sum of Polynomials is: ");
    display(res);
    printf("\n\n\n");
    

}
