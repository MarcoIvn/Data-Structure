class Persona{
  private:
    string first_name,last_name,city;
    int id,zip;
  public:
      Persona(int id = 0, int zip = 0, string fname = "", string lname = "", string city = ""){
        this->id = id;
        this->zip = zip;
        this->first_name = fname;
        this->last_name = lname;
        this->city = city;
      }

      string getCity(){
        return city;
      }
      string getLastName(){
        return last_name;
      }

/*
Agrega las sobre cargas de operadores necesarias en la clase Persona.
*/  friend ostream& operator<< (ostream&,const Persona &);

    bool operator<(const Persona &persona){
      if(zip < persona.zip){
        return true;
      }else{
        return false;
      }
    }

    bool operator>(const Persona &persona){
      if(last_name > persona.last_name){
        return true;
      }else{
        return false;
      }
    }
};

ostream& operator<< (ostream & salida, const Persona & persona){
  salida <<"id: "<<persona.id <<", ZIP: "<<persona.zip<<", First name: "<<persona.first_name<<", Last name: "<<persona.last_name<<", City: "<<persona.city;
  return salida;
}

