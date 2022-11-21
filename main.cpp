#include <cstddef>
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <string>
using namespace std;
#include "persona.h"
#include "hashtablev.h"
//#include "stack.h"

//Marco Iván Pacheco Martinez
//Andrew Williams Steven Ponce

Stack<Persona> sortStackAscending(Stack<Persona> &originalStack){
  Stack<Persona> tempStack;
  while(!originalStack.is_empty()){
    Persona temp = originalStack.pop();
    while(!tempStack.is_empty() && tempStack.peek() > temp){
      originalStack.push(tempStack.pop());
    }
    tempStack.push(temp);
  }
  return tempStack;
} // O(n^2)




int main(int argc, char**argv){
  string name;
  cout<<"Ingresa el nombre del archivo: "<<endl;
  cin>>name;

  string filename = name;
  Hashtable<string,int> htable;
  Stack<Persona> original_stack;
  Queue<Persona> queuePrior;
  ifstream archivo(filename); 
  string linea; 
  char delimitador = ','; 
  getline(archivo ,linea);
  while(getline(archivo,linea)){
    stringstream stream(linea);
    string id,first_name,last_name,ZIP,city;
    string gender,dob,phone,email,state;
    getline(stream, id,delimitador);
    getline(stream, first_name, delimitador);
    getline(stream, last_name, delimitador);
    getline(stream, gender, delimitador);
    getline(stream, dob, delimitador);
    getline(stream, phone, delimitador);
    getline(stream, email, delimitador);
    getline(stream, ZIP, delimitador);
    getline(stream, city, delimitador);
    getline(stream, state, delimitador);
    Persona person(stoi(id),stoi(ZIP),first_name,last_name,city);
    original_stack.push(person);
    queuePrior.enqueue(person);
    if(htable.contains(city)){
      int habitants = htable.get_or_default(city,0);
      habitants++;
      htable.put(city,habitants);
    }else{
      htable.put(city,1);
    }
    //htable.put(city,(htable.get_or_default(city,0))+1);
  }
  cout<<"Archivo Leido"<<endl; 
  int res;
  int val = 1;
  bool cond = true;
  Stack<Persona> sortedStack;   
  LinkedList<string> sortedKeys = htable.keys(); //O(n^2)
  while(val == 1){  
    Queue<Persona> copyQueue = queuePrior;
    cout<<"1- Censo poblacional de cada ciudad"<<endl;
    cout<<"2- Ordenar a todos los habitantes de acuerdo a su last_name"<<endl;
    cout<<"3- Imprimir a todos los habitantes utilizando el valor de ZIP y la prioridad menor"<<endl;
    cout<<"4- Salir"<<endl;
    cin>>res;
    switch(res){
      case 1:
        // Complejidad Tabla Hash : O(1),  Complejidad print de la tabla Hash con ordenamiento  O(n^2)
        for(int i = 0; i<sortedKeys.size();i++){
          cout<<"Ciudad: "<<sortedKeys.get(i)<<"| Habitantes: "<<htable.get_or_default(sortedKeys.get(i),0)<<endl;
        } 
        break;
      case 2:
        //Complejidad total: O(n^2)
        if(cond == true){
          sortedStack= sortStackAscending(original_stack);  // Pila Tarda 30 minutos aproximadamente
          cond = false;
        }
        sortedStack.print();
        break;
      case 3:
        //Complejidad Total: //O(n)
        while(!copyQueue.is_empty()){   //Queue  Imprime 1 dato cada 50 segundos aproximadamente
          cout<<copyQueue.dequeueMin()<<endl;
        } 
        break;
      case 4:
        val = 0;
      default:
        val = 0;
        break;
    }
  }
        
  
  cout << argv[0] << endl;
  cout << argv[1] << endl;
  cout << "finito" << endl;  
}