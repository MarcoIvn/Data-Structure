#include "lista.h"
#include <vector>
#include<algorithm>
template<typename K, typename T> /* K key, T value*/
class HashPair{
  public:
    K key;
    T value;
    HashPair(K key, T value ){
      this->key = key;
      this->value  = value;
    }
    HashPair(){
    }
};
template<typename K, typename T> 
class Hashtable{
    private:
        int size;
        LinkedList<HashPair<K,T> * > *tabla; 
        int fh(K key) const{
          hash<K> khash;
          return khash(key)% size;
        }
    public:
      Hashtable(int size = 20){
        this->size = size;
        tabla = new LinkedList<HashPair<K,T>*>[size];
        for(int i = 0; i < size; i++)
          tabla[i] = LinkedList<HashPair<K,T>*>();
      }

  bool put(K key, T value){
    int posicion =  fh(key);
    LinkedList<HashPair<K,T>*> lista = tabla[posicion];
    int indice = -1;
    for(int i = 0;i<lista.size();i++){
        if(lista.get(i)->key == key){
            indice = i;
        }
    }
    if(indice >= 0){
        lista.get(indice)->value = value;
    }else{
        tabla[posicion].addLast(new HashPair<K,T>(key,value));
    }
    return (indice >= 0)? 0:1;
  } //O(n)


  T get_or_default(K key, T default_value) const{
    int posicion = fh(key);
    LinkedList<HashPair<K,T>*> lista = tabla[posicion];
    int i = 0;
    while(lista.get(i)->key != key){
      i++;
    }
    if(i >= lista.size()){
      throw -1;
    }else if(lista.get(i)->key == key){
      return lista.get(i)->value;
    }else{
      return default_value;
    }
  } //O(n)


  bool contains(K key)const{
    int posicion = fh(key);
    LinkedList<HashPair<K,T>*> lista = tabla[posicion];
    int indice = -1;
    for(int i = 0;i<lista.size();i++){
      if(lista.get(i)->key == key){
        indice = i;
      }
    }
    return (indice == -1) ? 0:1;
  }

  
  bool is_empty() const{
    LinkedList<HashPair<K,T>*> lista;
    for(int i = 0;i<size;i++){
      lista = tabla[i];
      for(int j = 0;j<lista.size();j++){
        if(lista.get(j) != NULL){
          return false;
        }
      }
    }
    return true;
  }

  LinkedList<K> keys()const{ 
    LinkedList<K> vk;
    for(int i = 0;i<size;i++){
      for(int j =0; j<tabla[i].size(); j++){
        vk.addLast(tabla[i].get(j)->key);
      }
    }
    vk.bubbleSort();
    return vk;
  } //O(n^2)

  /*vector<K> keys() const{
    vector<K> vk;
    for(int i = 0;i<size;i++){
      for(int j =0; j<tabla[i].size(); j++){
        vk.push_back(tabla[i].get(j)->key);
      }
    }
    sort(vk.begin(),vk.end());
    return vk;
  }*/


  bool remove(K key){
    int posicion = fh(key);
    LinkedList<HashPair<K,T>*> lista = tabla[posicion];
    int indice = -1;
    for(int i = 0;i<lista.size();i++){
      if(lista.get(i)->key == key){
        indice = i;
      }
    }
    if(indice >= 0){
      tabla[posicion].remove(indice);
      return true;
    }else{
      return false;
    }
  }

  int getSize() const{
    int pairsNum = 0;
    for(int i =0; i<size; i++){
      for(int j =0; j<tabla[i].size(); j++){
        pairsNum++;
      } 
    }
    return pairsNum;
  }

  void print(){
    for(int i =0; i<size; i++){
      for(int j =0; j<tabla[i].size(); j++){
        cout <<"i: " <<i << " k: " << tabla[i].get(j)->key  << " value: " << tabla[i].get(j)->value<<endl;
      }
    }
  }

      
};