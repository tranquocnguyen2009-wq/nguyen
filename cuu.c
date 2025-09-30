//end(List *pL)
Position end(List *l){
    return l->last+1;
}
//insert(x, p, pL)
void insert(ElementType x,Position p,List *l){
    if(p<1||p>l->last+1||l->last>=MAXLENGTH){
        return;
    }
    for(int i=l->last;i>=p;i--){
        l->elements[i]=l->elements[i-1];
    }
    l->elements[p-1]=x;
    l->last++;
}
//locate(x, pL)
Position locate(ElementType x,List *l){
    for(Position p=1;p<=l->last;p++){
        if(l->elements[p-1]==x){
            return p;
        }
    }
    return end(l);
}
//retrieve(p, pL)
ElementType retrieve(Position p,List *l){
    if(p<1||p>=l->last+1||l->last>=MAXLENGTH){
        return -99.99;
    }
    return l->elements[p-1];
}
//delete(p, L)
void delete(Position p,List *l){
    if(p<1||p>=l->last+1||l->last>=MAXLENGTH){
        return;
    }
    for(int i=p;i<l->last;i++){
        l->elements[i-1]=l->elements[i];
    }
    l->last--;
}
// next(p, L)
Position next(Position p,List *l){
    if(p<1||p>=l->last+1||l->last>=MAXLENGTH){
        return -1;
    }
    return p+1;
}
//previous(p, L)
Position previous(Position p,List *l){
    if(p<2||p>l->last+1||l->last>=MAXLENGTH){
        return -1;
    }
    return p-1;
}
//first(p, L)
Position first(List *l){
    return 1;
}
//makeNull(L)
Position makeNull(List *l){
    l->last=0;
    return end(l);
}
//printList(L)
void printList(List *l){
    for(int i=0;i<l->last;i++){
        printf("%.2lf",l->elements[i]);
        if(i<l->last-1){
            printf(", ");
        }
    }
}
//Define a Data Structure List to store integers (max: 100) and implement some basic operators:
#include<stdio.h>
#define MAXLENGTH 100
typedef int ElementType;
typedef int Position;
typedef struct{
    ElementType elements[MAXLENGTH];
    Position last;
}List;
void makeNull(List *l){
    l->last=0;
}
Position end(List *l){
    return l->last+1;
}
void insert(ElementType x,Position p,List *l){
    if(p<1||p>l->last+1||l->last>=MAXLENGTH){
        return;
    }
    for(int i=l->last;i>=p;i--){
        l->elements[i]=l->elements[i-1];
    }
    l->elements[p-1]=x;
    l->last++;
}
void delete(Position p,List *l){
    if(p<1||p>l->last+1||l->last>=MAXLENGTH){
        return;
    }
    for(int i=p;i<l->last;i++){
        l->elements[i-1]=l->elements[i];
    }
    l->last--;
}
Position locate(ElementType x,List *l){
    for(Position p=1;p<=l->last;p++){
        if(l->elements[p-1]==x){
            return p;
        }
    }
    return end(l);
}
ElementType retrieve(Position p,List *l){
    if(p<1||p>l->last+1||l->last>=MAXLENGTH){
        return -1;
    }
    return l->elements[p-1];
}
Position next(Position p,List *l){
    if(p<1||p>l->last+1||l->last>=MAXLENGTH){
        return -1;
    }
    return p+1;
}
Position first(List *l){
    return 1;
}
void printList(List *l){
    for(int i=0;i<l->last;i++){
        printf("%d",l->elements[i]);
        if(i<l->last-1){
            printf(", ");
        }
    }
    printf("\n");
}
int main(){
    List l;
    makeNull(&l);
    int n,t;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        insert(t,end(&l),&l);
    }
    printList(&l);
    insert(20,4,&l);
    printList(&l);
    delete(first(&l),&l);
    printList(&l);
    int x;
    scanf("%d",&x);
    Position p=locate(x,&l);
    printf("%d",p);
}
//Define a data structure List to store Students (max: 100)
#include<stdio.h>
#include<string.h>
#define MAXLENGTH 100
typedef struct{
    char name[60];
    int mark;
}ElementType;
typedef int Position;
typedef struct{
    ElementType elements[MAXLENGTH];
    Position last;
}List;
void makeNull(List *l){
    l->last=0;
}
Position end(List *l){
    return l->last+1;
}
void insert(ElementType x,Position p,List *l){
    if(p<1||p>l->last+1||l->last>=MAXLENGTH){
        return;
    }
    for(int i=l->last;i>=p;i--){
        l->elements[i]=l->elements[i-1];
    }
    l->elements[p-1]=x;
    l->last++;
}
void delete(Position p,List *l){
    if(p<1||p>l->last+1||l->last>=MAXLENGTH){
        return;
    }
    for(int i=p;i<l->last;i++){
        l->elements[i-1]=l->elements[i];
    }
    l->last--;
}
Position first(List *l){
    return 1;
}
Position next(Position p,List *l){
    if(p<1||p>l->last+1||l->last>=MAXLENGTH){
        return -1;
    }
    return p+1;
}
void printList(List *l){
    for(int i=0;i<l->last;i++){
        printf("%s: %d",l->elements[i].name,l->elements[i].mark);
        if(i<l->last+1){
            printf("\n");
        }
    }
    printf("---END---\n");
}
Position locate(char *name,List *l){
    for(Position p=1;p<l->last;p++){
        if(strcmp(name,l->elements[p-1].name)==0){
            return p;
        }
    }
    return end(l);
}
int main(){
    List l;
    makeNull(&l);
    ElementType s1={"Harry Potter",10};
    ElementType s2={"Hermione Granger",8};
    ElementType s3={"Draco Malfoy",7};
    ElementType s4={"Luna Lovegood", 8};
    ElementType s5={"Ron Weasley", 9};
    insert(s1,end(&l),&l);
    insert(s2,end(&l),&l);
    insert(s3,end(&l),&l);
    insert(s4,end(&l),&l);
    insert(s5,end(&l),&l);
    printList(&l);
    ElementType s6={"Ginny Weasley",6};
    insert(s6,2,&l);
    printList(&l);
    delete(3,&l);
    printList(&l);
    char s[51];
    fgets(s,51,stdin);
    s[strcspn(s,"\n")]='\0';
    Position found=locate(s,&l);
    if( found!=end(&l)){
        printf("%d",l.elements[found-1].mark);
    }
    else{
        return -1;
    }
}
//locate(x, pL)*
Position locate(ElementType x,List *l){
    Position p=*l;
    while(p->next!=NULL){
        if(p->next->element==x){
            break;
        }
        p=p->next;
    }
    return p;
}
//previous(p, L)*
Position previous(Position p,List *l){
    Position q=*l;
    while(q->next!=NULL&&q->next!=p){
        q=q->next;
    }
    return q;
}
//first(p, L)*
Position first(List *l){
    return *l;
}
//next(p, L)*
Position next(Position p,List *l){
    return p->next;
}
//printList(L)*
void printList(List *l){
    Position p=*l;
    if(p->next==NULL){
        printf("empty");
    }
    while(p->next!=NULL){
        printf("%.2lf",p->next->element);
        p=p->next;
        if(p->next!=NULL){
            printf(", ");
        }
    }
}
//retrieve(p, pL)*
ElementType retrieve(Position p,List *l){
    return p->next->element;
}
// end(List *pL)*
Position end(List *l){
    Position p=*l;
    while(p->next!=NULL){
        p=p->next;
    }
    return p;
}
// makeNull(L)*
Position makeNull(List *l){
    (*l)=(Position)malloc(sizeof(Cell));
    (*l)->element=16678;
    (*l)->next=NULL;
    return *l;
}
//insert(x, p, pL)*
void insert(ElementType x,Position p,List *l){
    Position temp=p->next;
    p->next=(Position)malloc(sizeof(Cell));
    
    p->next->element=x;
    p->next->next=temp;
}
//delete(p, L)*
void delete(Position p,List *l){
    Position temp=p->next;
    p->next=temp->next;
    free(temp);
}
//Define a Data Structure List (using pointers) to store integers (max: 100) and implement some basic operators: end(), insert(), locate, retrieve(), delete(), first(), next(), makeNull(), printList()
#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
struct Cell{
    ElementType element;
    struct Cell *next;
};
typedef struct Cell *Position;
typedef Position List;
Position end(List *l){
    Position p=*l;
    while(p->next!=NULL){
        p=p->next;
    }
    return p;
}
void  insert(ElementType x,Position p,List *l){
    Position temp=p->next;
    p->next=(Position)malloc(sizeof(struct Cell));
    p->next->element=x;
    p->next->next=temp;
}
Position locate(ElementType x,List *l){
    Position p=*l;
    while(p->next!=NULL){
        if(p->next->element==x){
            break;
        }
        p=p->next;
    }
    return p;
}
ElementType retrieve(Position p,List *l){
    return p->next->element;
}
void delete(Position p,List *l){
    Position temp=p->next;
    p->next=temp->next;
    free(temp);
}
Position first(List *l){
    return *l;
}
Position next(Position p,List *l){
    return p->next;
}
Position makeNull(List *l){
    (*l)=(Position)malloc(sizeof(struct Cell));
    (*l)->next=NULL;
    return *l;
}
void printList(List *l){
    Position p=*l;
    if(p->next==NULL){
        printf("empty");
    }
    while(p->next!=NULL){
        printf("%d",p->next->element);
        p=p->next;
        if(p->next!=NULL){
            printf(", ");
        }
    }
    printf("\n");
}
int main(){
    List l;
    makeNull(&l);
    int n,temp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        insert(temp,end(&l),&l);
    }
    printList(&l);
    Position p=l;
    for(int i=0;i<3;i++){
        p=p->next;
    }
    insert(20,p,&l);
    printList(&l);
    delete(first(&l),&l);
    printList(&l);
    int x;
    scanf("%d",&x);
    if(locate(x,&l)->next!=NULL){
        printf("%d is in L.\n", x);
    }
    else {
        printf("%d is not in L.\n", x);
    }
}
//Define a data structure List to store Students (using pointers) 
Implement some basic operators: end(), insert(), delete(), makeNull(), first(), next(), printList()
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char name[51];
    int mark;
} ElementType;
struct Cell{
    ElementType element;
    struct Cell *next;
};

typedef struct Cell *Position;
typedef Position List;
Position end(List *l){
    Position p=*l;
    while(p->next!=NULL){
        p=p->next;
    }
    return p;
}
void insert(ElementType x,Position p,List *l){
    Position temp=p->next;
    p->next=(Position)malloc(sizeof(struct Cell));
    p->next->element=x;
    p->next->next=temp;
}
Position locate(char *name,List *l){
    Position p=*l;
    while(p->next!=NULL){
        if(strcmp(p->next->element.name,name)==0){
            break;
        }
        p=p->next;
    }
    return p;
}
ElementType retrieve(Position p,List *l){
    return p->next->element;
}
void delete(Position p,List *l){
    Position temp=p->next;
    p->next=temp->next;
    free(temp);
}
Position first(List *l){
    return *l;
}
Position next(Position p,List *l){
    return p->next;
}
Position makeNull(List *l){
    *l=(Position)malloc(sizeof(struct Cell));
    
    (*l)->next=NULL;
    return *l;
}
void printList(List *l){
    Position p=*l;
    if(p->next==NULL){
        printf("empty");
    }
    while(p->next!=NULL){
        printf("%s: %d\n",p->next->element.name,p->next->element.mark);
        p=p->next;
    }
    printf("---END---\n");
}
int main(){
    List l;
    makeNull(&l);
    ElementType s1={"Harry Potter",10};
    ElementType s2={"Hermione Granger",8};
    ElementType s3={"Draco Malfoy",7};
    ElementType s4={"Luna Lovegood",8};
    ElementType s5={"Ron Weasley",9};
    insert(s1,end(&l),&l);
    insert(s2,end(&l),&l);
    insert(s3,end(&l),&l);
    insert(s4,end(&l),&l);
    insert(s5,end(&l),&l);
    printList(&l);
    ElementType s6={"Ginny Weasley",6};
    Position p = l;
    for(int i=0;i<1;i++){
        p=p->next;
        
    }
    insert(s6,p,&l);
    printList(&l);
    for(int i=0;i<1;i++){
        p=p->next;
    }
    delete(p,&l);
    printList(&l);
    char s[51];
    fgets(s,51,stdin);
    s[strcspn(s,"\n")]='\0';
    Position found=locate(s,&l);
    if (found->next != NULL) {
        printf("%d\n", found->next->element.mark);
    } else {
        printf("-1\n");
    }
}
//makeNull(S)
void makeNull(Stack *s){
    s->top=MAXLENGTH;
}
//empty(S) 
int empty(Stack *s){
    return s->top==MAXLENGTH;
}
//pop(S)
void pop(Stack *s){
    if(s->top==MAXLENGTH){
        printf("Error: stack is empty.\n");
        return;
    }
    s->top++;
}
//top(S) 
ElementType top(Stack *s){
    if(s->top==MAXLENGTH){
        return -90.67;
    }
    return s->elements[s->top];
}
// push(x, S)
void push(ElementType x,Stack *s){
    if(s->top==0){
        printf("Error: stack is full\n");
        return;
    }
    s->top--;
    s->elements[s->top]=x;
}
// push(x, S)*
void push(ElementType x,Stack *s){
    Cell *temp=*s;
    *s=malloc(sizeof(Cell));
    (*s)->element=x;
    (*s)->next=temp;
}
//top(S)*
ElementType top(Stack *s){
    if(*s==NULL){
        return -96.53;
    }
    return (*s)->element;
}
//makeNull(S)*
void makeNull(Stack *s){
    (*s)=NULL;
}
//pop(S)*
void pop(Stack *s){
    if(*s==NULL){
        printf("Error: stack is empty.\n");
        return;
    }
    Cell *temp=*s;
    *s=temp->next;
    free(temp);
}
//empty(S)*
int empty(Stack *s){
    return *s==NULL;
}
//Write a program to convert an integer n in binary form. n is read from stdin.
#include<stdio.h>
#define MAXLENGTH 100
typedef int ElementType;
typedef struct{
    ElementType elements[MAXLENGTH];
    int top;
}Stack;
void pop(Stack *s){
    if(s->top==MAXLENGTH){
        printf("Error: stack is empty.");
    }
    s->top++;
}
void makeNull(Stack *s){
    s->top=MAXLENGTH;
}
int empty(Stack *s){
    return s->top==MAXLENGTH;
}
void push(ElementType x,Stack *s){
    if(s->top==0){
        printf("Error: stack is full\n");
        return;
    }
    s->top--;
    s->elements[s->top]=x;
}
ElementType top(Stack *s){
    if(s->top==MAXLENGTH){
        return -97.94;
    }
    return s->elements[s->top];
}
int main(){
    Stack s;
    makeNull(&s);
    int n;
    scanf("%d",&n);
    while(n!=0){
        push(n%2,&s);
        n/=2;
    }
    while(!empty(&s)){
        printf("%d",top(&s));
        pop(&s);
    }
}
//Write a program to evaluate a postfix expression read from stdin.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXLENGTH 100
typedef double ElementType;
typedef struct{
    ElementType elements[MAXLENGTH];
    int top;
}Stack;
void pop(Stack *s){
    if(s->top==MAXLENGTH){
        printf("Error: stack is empty.");
    }
    s->top++;
}
void makeNull(Stack *s){
    s->top=MAXLENGTH;
}
int empty(Stack *s){
    return s->top==MAXLENGTH;
}
void push(ElementType x,Stack *s){
    if(s->top==0){
        printf("Error: stack is full\n");
        return;
    }
    s->top--;
    s->elements[s->top]=x;
}
ElementType top(Stack *s){
    if(s->top==MAXLENGTH){
        return -97.94;
    }
    return s->elements[s->top];
}
int main(){
    Stack s;
    makeNull(&s);
    char n[MAXLENGTH];
    scanf("%s",n);
    for(int i=0;n[i]!='\0';i++){
        if(isdigit(n[i])){
            push(n[i]-'0',&s);
        }
        else if(n[i]=='+'||n[i]=='-'||n[i]=='*'||n[i]=='/'){
            if(s.top==0){
                printf("day\n");
                
            }
            ElementType b=top(&s);
            pop(&s);
            ElementType a=top(&s);
            pop(&s);
            ElementType c;
            switch(n[i]){
                case '+':c=a+b;break;
                case '-':c=a-b;break;
                case '*':c=a*b;break;
                case '/':c=a/b;break;
            }
            push(c,&s);
        }
    }
    printf("%.2lf",top(&s));
}
//Write a program to evaluate a postfix expression read from stdin.*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef double ElementType;

typedef struct Node {
    ElementType element;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void makeNull(Stack* s) {
    while (s->top != NULL) {
        Node* temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
}

int empty(Stack* s) {
    return s->top == NULL;
}

void push(ElementType x, Stack* s) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: memory allocation failed\n");
        return;
    }
    newNode->element = x;
    newNode->next = s->top;
    s->top = newNode;
}

void pop(Stack* s) {
    if (empty(s)) {
        printf("Error: stack is empty\n");
        return;
    }
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
}

ElementType top(Stack* s) {
    if (empty(s)) {
        printf("Error: stack is empty\n");
        return -97.94;
    }
    return s->top->element;
}

int main() {
    Stack s;
    makeNull(&s);
    char n[100];
    scanf("%s", n);
    
    for (int i = 0; n[i] != '\0'; i++) {
        if (isdigit(n[i])) {
            push(n[i] - '0', &s);
        } else if (n[i] == '+' || n[i] == '-' || n[i] == '*' || n[i] == '/') {
            if (empty(&s)) {
                printf("Error: insufficient operands\n");
                return 1;
            }
            ElementType b = top(&s);
            pop(&s);
            if (empty(&s)) {
                printf("Error: insufficient operands\n");
                return 1;
            }
            ElementType a = top(&s);
            pop(&s);
            ElementType c;
            switch (n[i]) {
                case '+': c = a + b; break;
                case '-': c = a - b; break;
                case '*': c = a * b; break;
                case '/': 
                    if (b == 0) {
                        printf("Error: division by zero\n");
                        return 1;
                    }
                    c = a / b; 
                    break;
            }
            push(c, &s);
        }
    }
    
    if (!empty(&s)) {
        printf("%.2lf\n", top(&s));
    } else {
        printf("Error: empty stack\n");
    }
    
    makeNull(&s); // Clean up
    return 0;
}
//Write a program to convert an integer n in binary form. n is read from stdin.*
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node {
    ElementType element;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void makeNull(Stack* s) {
    while (s->top != NULL) {
        Node* temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
}

int empty(Stack* s) {
    return s->top == NULL;
}

void push(ElementType x, Stack* s) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: memory allocation failed\n");
        return;
    }
    newNode->element = x;
    newNode->next = s->top;
    s->top = newNode;
}

void pop(Stack* s) {
    if (empty(s)) {
        printf("Error: stack is empty\n");
        return;
    }
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
}

ElementType top(Stack* s) {
    if (empty(s)) {
        printf("Error: stack is empty\n");
        return -97; // Changed to integer since ElementType is int
    }
    return s->top->element;
}

int main() {
    Stack s;
    makeNull(&s);
    int n;
    scanf("%d", &n);
    
    if (n == 0) {
        printf("0");
    } else {
        while (n != 0) {
            push(n % 2, &s);
            n /= 2;
        }
        while (!empty(&s)) {
            printf("%d", top(&s));
            pop(&s);
        }
    }
    
    makeNull(&s); // Clean up
    return 0;
}
//enqueue(x, Q)
void enqueue(ElementType x,Queue *q){
    if((q->front==0&&q->rear==MAXLENGTH-1)||(q->rear+1)%MAXLENGTH==q->front){
        printf("Error: Queue is full, cannot enqueue.\n");
        return;
    }
    if(q->front==-1){
        q->front=0;
        q->rear=-1;
    }
    q->rear=(q->rear+1)%MAXLENGTH;
    q->elements[q->rear]=x;
}
//makeNull(Q)
void makeNull(Queue *q){
    q->front=-1;
    q->rear=-1;
}
//dequeue(Q)
void dequeue(Queue *q){
    if(q->front==-1){
        printf("Error: Queue is empty, cannot dequeue.\n");
        return;
    }
    if(q->front==q->rear){
        q->rear=-1;
        q->front=-1;
        return;
    }
    q->front=(q->front+1)%MAXLENGTH;
}
//empty(Q)
int empty(Queue *q){
    return q->front==-1;
}
// front(Q)
ElementType front(Queue *q){
    if(q->front==-1){
        return 93.94;
    }
    return q->elements[q->front];
}
//makeNull(Q)*
void makeNull(Queue *q){
    Position temp=malloc(sizeof(Cell));
    temp->next=NULL;
    q->front=temp;
    q->rear=temp;
}
//empty(Q)*
int empty(Queue *q){
    return q->front->next==NULL;
}
//front(Q)*
ElementType front(Queue *q){
    if(q->front->next==NULL){
        return 95.66;
    }
    return q->front->next->element;
}
//dequeue(Q)*
void dequeue(Queue *q){
    if(q->front->next==NULL){
        printf("Error: Queue is empty, cannot dequeue.\n");
        return;
    }
    Position temp=q->front;
    q->front=temp->next;
    free(temp);
}
//enqueue(x,Q)*
void enqueue(ElementType x,Queue *q){
    q->rear->next=malloc(sizeof(Cell));
    q->rear->next->element=x;
    q->rear->next->next=NULL;
    q->rear=q->rear->next;
}
//Define a Data Structure Queue (using circular array) to store integers (max: 100) and implement some basic operators:
#include<stdio.h>
#define MAXLENGTH 20
typedef int ElementType;
typedef struct{
    ElementType elements[MAXLENGTH];
    int front,rear;
}Queue;
void makeNull(Queue *q){
    q->front=-1;
    q->rear=-1;
}
int empty(Queue *q){
    return q->front==-1;
}
ElementType front(Queue *q){
    if(empty(q)){
        return -1;
    }
    return q->elements[q->front];
}
ElementType dequeue(Queue *q){
    if(q->front==-1){
        return 0;
    }
    ElementType temp=q->elements[q->front];
    if(q->front==q->rear){
        q->rear=-1;
        q->front=-1;
    }
    else{
        q->front=(q->front+1)%MAXLENGTH;
    }
    return temp;
}
void enqueue(ElementType x,Queue *q){
    if((q->front==0&&q->rear==MAXLENGTH-1)||(q->rear+1)%MAXLENGTH==q->front){
        return;
    }
    if(empty(q)){
        q->front=0;
        q->rear=-1;
        
    }
    q->rear=(q->rear+1)%MAXLENGTH;
    q->elements[q->rear]=x;
}
int main(){
    Queue q;
    makeNull(&q);
    int n;
    scanf("%d",&n);
    enqueue(n,&q);
    while(!empty(&q)){
        n=dequeue(&q);
        printf("%d\n",n);
        for(int i=2;i<=n/2;i++){
        if(n%i==0){
            enqueue(i,&q);
           }
        }
    }
}
//Define a Data Structure Queue (using pointers) to store integers and implement some basic operators:
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType; 

typedef struct CellTag {
    ElementType element;
    struct CellTag *next;
} Cell;

typedef Cell *Position;

typedef struct {
    Position front, rear;
} Queue;


void makeNull(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}


int empty(Queue *q) {
    return q->front == NULL;
}


ElementType front(Queue *q) {
    if (q->front == NULL) {
        printf("Error: Queue is empty, cannot get front.\n");
        exit(1);
    }
    return q->front->element;
}


ElementType dequeue(Queue *q) {
    if (q->front == NULL) {
        printf("Error: Queue is empty, cannot dequeue.\n");
        exit(1);
    }
    Position temp = q->front;
    ElementType result = temp->element;
    q->front = temp->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return result; 
}


void enqueue(ElementType x, Queue *q) {
    Position newNode = malloc(sizeof(Cell));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    newNode->element = x;
    newNode->next = NULL;
    if (q->front == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int main() {
    Queue q;
    int n;
    makeNull(&q);
    scanf("%d", &n);
    if (n <= 0) {
        printf("n phai la so nguyen duong!\n");
        return 1;
    }
    enqueue(n, &q);
    while (!empty(&q)) {
        n = dequeue(&q);
        printf("%d\n", n);
        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                enqueue(i, &q);
            }
        }
    }
    return 0;
}
//Define a Data Structure Queue (using circular array) to store strings (max: 50 characters) and implement some basic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENGTH 100
typedef struct {
    char data[50];
} ElementType;

typedef struct {
	ElementType elements[MAXLENGTH];
    int front, rear;
} Queue;


void enqueue(ElementType x, Queue *pQ) {
    if ((pQ->rear + 1) % MAXLENGTH == pQ->front) {
        printf("Error: full queue.\n");
        return;
    }
    
    pQ->rear = (pQ->rear + 1) % MAXLENGTH;
    pQ->elements[pQ->rear] = x;
    
    if (pQ->front == -1)
        pQ->front = 0;
}

ElementType front(Queue *pQ) {
	return pQ->elements[pQ->front];
}


void dequeue(Queue *pQ) {
    if (pQ->front == pQ->rear)
        pQ->front = pQ->rear = -1;
    else
        pQ->front = (pQ->front + 1) % MAXLENGTH;
}

int empty(Queue *pQ) {
    return pQ->front == -1;
}

void makeNull(Queue *pQ) {
    pQ->front = pQ->rear = -1;
}

int main() {
	Queue Q;
	makeNull(&Q);

	ElementType d;
	char c[50];
	
	while (1) {
	    scanf("%s", c);
        if (strcmp(c, "DONE") == 0)
        break;
        
        if (strcmp(c, "ADD") == 0) {
            scanf("%s", d.data);
            enqueue(d, &Q);
        } else if (strcmp(c, "PRINT") == 0) {
            if (empty(&Q)) {
                printf("Queue is empty, cannot print.\n");
                continue;
            }
            printf("Print %s\n", front(&Q).data);
            dequeue(&Q);
        } else if (strcmp(c, "CANCEL") == 0) {
            if (empty(&Q)) {
                printf("Queue is empty, cannot cancel.\n");
                continue;
            }
            printf("Delete %s\n", front(&Q).data);
            dequeue(&Q);
        }
    }

	return 0;
}
//Define a Data Structure Queue (using circular array) to store strings (max: 50 characters) and implement some basic*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char data[50];
} ElementType;


typedef struct Node {
    ElementType element;
    struct Node* next;
} Node;

typedef Node* Position;

typedef struct {
    Position front, rear;
} Queue;


void makeNull(Queue *Q) {
    Q->front = NULL;
    Q->rear = NULL;
}


int empty(Queue *Q) {
    return Q->front == NULL;
}


void enqueue(ElementType x, Queue *Q) {
    Position newNode = (Position)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    newNode->element = x;
    newNode->next = NULL;
    if (empty(Q)) {
        Q->front = newNode;
        Q->rear = newNode;
    } else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
}


ElementType dequeue(Queue *Q) {
    ElementType emptyStr = {""};
    if (empty(Q)) {
        return emptyStr; 
    }
    Position temp = Q->front;
    ElementType result = temp->element;
    Q->front = temp->next;
    if (Q->front == NULL) {
        Q->rear = NULL;
    }
    free(temp);
    return result;
}


ElementType front(Queue *Q) {
    ElementType emptyStr = {""};
    if (empty(Q)) {
        return emptyStr; 
    }
    return Q->front->element;
}

int main() {
    Queue Q;
    char command[50];
    ElementType x;
    makeNull(&Q);
    while (1) {
        scanf("%s", command);
        if (strcmp(command, "DONE") == 0) {
            break;
        }
        
        if (strcmp(command, "ADD") == 0) {
            scanf("%s", x.data); 
            enqueue(x, &Q);
        } else if (strcmp(command, "PRINT") == 0) {
            if (empty(&Q)) {
                printf("Queue is empty, cannot print.\n");
            } else {
                ElementType result = dequeue(&Q);
                printf("Print %s\n", result.data);
            }
        } else if (strcmp(command, "CANCEL") == 0) {
            if (empty(&Q)) {
                printf("Queue is empty, cannot cancel.\n");
            } else {
                ElementType result = dequeue(&Q);
                printf("Delete %s\n", result.data);
            }
        } else {
            printf("Unknown command: %s\n", command);
        }
    }
    
    return 0;
}
