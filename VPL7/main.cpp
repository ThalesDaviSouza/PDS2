#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

class Basic
{
  private:
    static int actualId;
    static int count;
    int id;

  public:
    Basic(){
      ++actualId;
      ++count;
      this->id = actualId;
      printObject();
    }
    Basic(int id){
      if(id >= 0){
        cout << "ERRO";
      }
      else{
        this->id = id;
        ++count;
      }
      printObject();
    }

    ~Basic(){
      --count;
    }

    void printObject(){
      cout << this->id << " " << this << endl; 
    }

    int getId(){
      return this->id;
    }

    static int getObjectsCount(){
      return count;
    }

    static bool isValidId(int id){
      return id < 0;
    }
};

bool compObjects(Basic& a, Basic& b){
  return a.getId() < b.getId();
}

int Basic::actualId = 0;
int Basic::count = 0;

int main()
{ 
  char input;
  int id, i, count;
  list<Basic> lista;
  Basic *aux;
  
  do{
    cin >> input;
    
    switch(input){
      case 'A':
        lista.emplace_front();
        break;

      case 'C':
        cin >> id;
        if(Basic::isValidId(id)){
          lista.emplace_front(id);
        }
        else{
          cout << "ERRO" << endl;
        }
        break;

      case 'R':
        if(Basic::getObjectsCount() > 0){
          lista.sort(compObjects);
          lista.front().printObject();
          lista.pop_front();
        }
        else{
          cout << "ERRO" << endl;
        }

        break;

      case 'N':
        cout << Basic::getObjectsCount() << endl;
        break;
      
      case 'P':
        cin >> i;
        if(Basic::getObjectsCount() >= i && i > 0){
          lista.sort(compObjects);
          
          count = 1;
          for(Basic& obj : lista){
            if(count == i){
              aux = &obj;
            }
            count++;
          }

          aux->printObject();
        }
        else{
          cout << "ERRO" << endl;
        }
        break;

      case 'L':
        lista.sort(compObjects);
        for(Basic& obj: lista){
          obj.printObject();
        }
        break;

      default:
        input = 'E';
    }

  }while(input != 'E');
 
  return 0;
}
