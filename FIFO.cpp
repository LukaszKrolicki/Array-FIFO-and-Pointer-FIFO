#include <iostream>
using namespace std;

//Array implementation
class ArrayFifo{
private:
    int *items;
    int capacity;
    int size; //current size of array
    int head;
    int tail;
public:
    ArrayFifo(int c);
    bool empty();
    bool full();
    void enqueue(int x);
    int peek();
    void dequeue();
    void clear();

    friend ostream& operator<<(ostream& out, ArrayFifo& a);
    ~ArrayFifo();
};

ArrayFifo::ArrayFifo(int c){
    items=new int[c];
    capacity=c;
    size=0;
    head=0;
    tail=-1;
}

bool ArrayFifo::empty(){
    if(size==0){
        return true;
    }else{
        return false;
    }
}

bool ArrayFifo::full(){
    if(size==capacity){
        return true;
    }
    else{
        return false;
    }
}

void ArrayFifo::enqueue(int x){
    if(full())
    {
        cout<<"full"<<endl;
    }
    else{
        if (tail<capacity-1){
            tail=tail+1;
        }else{
            tail=(tail+1)%capacity;
        }

        items[tail]=x;
        size++;
    }
}

int ArrayFifo::peek(){
    if(empty()){
        cout<<"empty: ";
        return 420;
    }
    else{
        return items[head];
    }
}

void ArrayFifo::dequeue(){
    if(empty())
    {
        cout<<"Array empty"<<endl;
    }
    else{
        if (head<capacity-1){
            head++;
        }else{
            head=(head+1)%capacity;
        }

        size--;
    }
}

void ArrayFifo::clear(){
    if(empty())
    {
        cout<<"Array empty"<<endl;
    }
    else{
        head=0;
        tail=-1;
        size=0;
    }
}
ArrayFifo::~ArrayFifo(){
    clear();
}

ostream& operator<<(ostream& out, ArrayFifo& a){
    for(int i=0; i<a.size;i++)
    {
        if(a.head+i>=a.capacity){
            out<<a.items[abs(a.capacity-(a.head+i))]<<" ";
        }
        else{

        out<<a.items[a.head+i]<<" ";
        }
    }
}


//Pointer Implementation
class Element{
private:
    int v;
    Element* next;
public:
    Element(int x, Element* next);
    int getValue();
    Element* getNext();
    void setNext(Element* p);
};

Element::Element(int x, Element* next){
    v=x;
    this->next=next;
}
int Element::getValue(){
    return v;
}
Element* Element::getNext(){
    return next;
}
void Element::setNext(Element* p){
    next=p;
}

class LinkedFifo{
private:
    Element* head;
    Element* tail;
public:
    LinkedFifo();
    bool empty();
    void enqueue(int x);
    int peek();
    void dequeue();
    void clear();

    friend ostream& operator<<(ostream& out, LinkedFifo* f);
    ~LinkedFifo();
};

LinkedFifo::LinkedFifo(){
    head=nullptr;
    tail=nullptr;
}

LinkedFifo::~LinkedFifo(){
 clear();
}

bool LinkedFifo::empty(){
    if(head==nullptr){
        return true;
    }
    else{
        return false;
    }
}

void LinkedFifo::enqueue(int x){
    Element* e = new Element(x,nullptr);
    if(empty()==false)
    {
        tail->setNext(e);
    }else
    {
        head = e;
    }
    tail=e;
}

int LinkedFifo::peek(){
    if(empty()){
        cout<<"empty: ";
        return 420;
    }
    else{
        return head->getValue();
    }
}

void LinkedFifo::dequeue(){
    if(empty()){
        cout<<"empty"<<endl;
    }
    else{
        Element* x = head->getNext();
        delete head;
        head = x;

    }
}

void LinkedFifo::clear(){
    while(empty()==false){
        dequeue();
    }
}

ostream& operator<<(ostream& out, LinkedFifo* f){
    if(f->empty()){
        cout<<"empty"<<endl;
    }
    else{
        while(f->head->getNext()!=nullptr){
            out<< f->head->getValue()<<" ";
            f->head= f->head->getNext();
        }
        out<< f->head->getValue()<<" ";
    }
}


int main(){
    //Example
    ArrayFifo a(6);
    a.enqueue(1);
    a.enqueue(2);
    a.enqueue(3);
    a.enqueue(4);
    a.enqueue(5);
    a.enqueue(6);
    a.enqueue(7);
    cout<<a;
    cout<<endl;
    cout<<"Peek1: ";
    cout<< a.peek()<<endl;
    a.dequeue();
    cout<<"Peek2: ";
    cout<< a.peek()<<endl;
    a.dequeue();
    cout<<"Peek3: ";
    cout<< a.peek()<<endl;
    a.dequeue();
    cout<<"Peek4: ";
    cout<< a.peek()<<endl;
    cout<<a;
    cout<<endl;
    a.enqueue(69);
    cout<<"Peek4: ";
    cout<< a.peek()<<endl;
    a.dequeue();
    cout<<"Peek5: ";
    cout<< a.peek()<<endl;
    cout<<a;
    cout<<endl;
    a.dequeue();
    cout<<"Peek6: ";
    cout<< a.peek()<<endl;
    cout<<a;
    cout<<endl;

    cout<<"Peek6: ";
    cout<< a.peek()<<endl;
    a.enqueue(70);
    a.enqueue(71);
    cout<<a;
    cout<<endl;
    cout<<"Peek6: ";
    cout<< a.peek()<<endl;
    a.dequeue();
    cout<<"Peek69: ";
    cout<< a.peek()<<endl;
    cout<<a;

    cout<<endl<<endl<<endl;

    LinkedFifo* f = new LinkedFifo();
    cout<<"Peek: ";
    cout<< f->peek()<<endl;
    f->enqueue(1);
    f->enqueue(2);
    f->enqueue(3);
    cout<<f;
    cout<<endl;
    cout<<"Peek: ";
    cout<< f->peek()<<endl;
    f->dequeue();
    cout<<"Peek: ";
    cout<< f->peek()<<endl;
    f->dequeue();
    cout<<"Peek: ";
    cout<< f->peek()<<endl;
    f->dequeue();
    cout<<"Peek: ";
    cout<< f->peek()<<endl;
    f->dequeue();
    cout<<"Peek: ";
    cout<< f->peek()<<endl;

    f->enqueue(1);
    f->enqueue(2);
    f->enqueue(3);


    cout<<"Peek: ";
    cout<< f->peek()<<endl;
    cout<<f;
    cout<<endl;
    f->clear();
    cout<<"Peek: ";
    cout<< f->peek()<<endl;

    cout<<f;
}
