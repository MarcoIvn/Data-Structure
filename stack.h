#include <iostream>
using namespace std;


template <typename T> class ArrayStack{
  private:
    T* elements;
    int size;
    int initialCapacity = 16;
    int tope = -1;
  public:
    ArrayStack(){
      size = initialCapacity;
      elements = new T[size];
      }

    ArrayStack(int initialCapacity){
      size = initialCapacity;
      elements = new T[size];
    }
    void push(T element){
      tope++;
      elements[tope] = element;
    }

    bool is_empty(){
      if(tope == -1){
        return true;
      }else{
        return false;
      }
    }

    T pop(){
      if(is_empty()){
        throw std::invalid_argument( "StackArray is empty");
      }
      T deletedElement =  elements[tope];
      tope--;
      return deletedElement;
    }

    void print(){
      for(int i = 0; i<tope+1;i++){
        cout<<elements[i]<<endl;
      }
    }

    T top(){
      if(is_empty()){
        throw std::invalid_argument( "StackArray is empty");
      }else{
        return elements[tope];
      }
    }

    int getSize(){
      return size;
    }

};