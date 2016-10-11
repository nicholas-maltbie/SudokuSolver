template< typename T >
class LinkedList{
public:
   LinkedList(){ first = new __Node(0, 0); last = first; numItems = 0; }
   bool isEmpty(){ return numItems == 0; }
   void append(T* item);
   void insert(T* item);
   T* remove();
private:
   class __Node{
   public: 
      __Node(T* i, __Node* n = 0): item(i), next(n){ }
      T* getItem(){  return item; }
      __Node* getNext(){ return next; }
      void setItem(T* item){ this->item = item; }
      void setNext(__Node* next){ this->next = next; }
   private:
      T* item;
      __Node* next;
   };
   __Node* first;
   __Node* last;
   int numItems;
};

   template< typename T >
   void LinkedList<T>::append(T* item){ 
     __Node* node = new __Node(item);
     last->setNext(node);
     last = node;
     numItems++;
   }
   template< typename T >
   void LinkedList<T>::insert(T* item){
     __Node* node = new __Node(item, first->getNext());
     first->setNext(node);
     numItems++;
   }
   template< typename T >
   T* LinkedList<T>::remove(){
     __Node* node = first->getNext();
     first->setNext(node->getNext());
     numItems--;
     if (isEmpty()) last = first;
     T* item = node->getItem();
     delete node;
     return item;
   }
template< typename T >
class Stack{
public:
   bool isEmpty(){ return stack.isEmpty(); }
   void push(T* item){ stack.insert(item); }
   T* pop(){ stack.remove(); }
private:
   LinkedList<T> stack;
};

template< typename T >
class Queue{
public:
   bool isEmpty(){ return queue.isEmpty(); }
   void enqueue(T* item){ queue.append(item); }
   T* dequeue(){ queue.remove(); }
private:
   LinkedList<T> queue;
};
