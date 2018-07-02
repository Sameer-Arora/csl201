#ifndef NUMBER_MAP_hpp
#define NUMBER_MAP_hpp

#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;


template <typename K, typename V> class Number_Map;

template <typename K, typename V>
 class key_value_num{
      public:
        key_value_num():next(NULL){}
      private:
        K key;
        V val;
        key_value_num* next;   
        friend class Number_Map<K,V>;
      
};

template <typename K, typename V>
class Number_Map{					// map interface
  public:
    Number_Map(int capacity);			// constructor
    int size() const;				// number of entries in the map
    bool empty() const;				// is the map empty?
    V& find(const K& k) ;		// find entry with key k
    void put(const K& k, const V& v);	// insert/replace pair (k,v)
    void erase(const K& k);			// remove entry with key :
   
    ////   HASH CODES    /////
    unsigned int int_casting(const K& k );         //utility function to check which type to be choosen.
    unsigned int comp_sum(const K& k );         //utility function to check which type to be choosen.
    unsigned int poly_sum(const K& k );         //utility function to check which type to be choosen.
    unsigned  int cyclic_shift(const K& k );         //utility function to check which type to be choosen.
   
    /////    HASH FUNCTIONS   /////
    int multiply(unsigned int h_code);            //utility function to check which type to be choosen.
    int divide(unsigned int h_code);            //utility function to check which type to be choosen.
    int mad(unsigned int h_code);            //utility function to check which type to be choosen.
    void  print();

    void write( ofstream& fout );               //utility function to write the data to file.

  private:
    int map_size;
    int cap;
    key_value_num<K,V>** map[12];            //one map for each combination.
    int hc;                    //hash code for map  1)int_casting 2)comp_sum  3)poly_sum  4)cyclic_shift
    int hf;                   //hash function for map 1)multiply  2)divide 3)mad
    V junk;
	int perf[12];              //performance matrix for each of the different combinations.
};


template <typename K, typename V>
  Number_Map<K,V>::Number_Map(int capacity){	
    for(int h=0;h<12;h++){
      map[h]=new key_value_num<K,V>*[capacity];
      for(int i=0;i<capacity;i++) map[h][i]=NULL;
      perf[h]=0;
  }
    cap=capacity;
    map_size=0;
    junk=-1;
    hc=0;
    hf=0;
  }


template <typename K, typename V>
 int Number_Map<K,V>::size()const{  
    return map_size;
  }

template <typename K, typename V>
void Number_Map<K,V>::write( ofstream& fout ){
      fout<<" Number_MAP:  Percentage of collisions in each combination   \n";

      fout<<"\t        multiply  divide   mad  \n";
    
    for(int i=0;i<4;i++){
      if(i==0) fout<<"int_casting ";
      else if(i==1) fout<<"comp_sum    ";
      else if(i==2) fout<<"poly_sum    ";
      else if(i==3) fout<<"cylic_shift ";

      for(int j=0;j<3;j++){
        fout<<setw(8)<< (perf[i*3+j]/(float)map_size )<<" ";
      }
      fout<<endl;
    }
      fout<<endl;
    
}

template <typename K, typename V>
 bool Number_Map<K,V>::empty()const{  
    return (map_size==0);
  }

template <typename K,typename V>
 void Number_Map <K,V> :: print()
 {  
    /*for(int h=0;h<12;h++){
      for(int j=0;j<cap;j++){

        key_value_num<K,V> *temp = map[h][j];
        while(temp != NULL)
        {
          cout<<temp ->key <<" | ";
          temp = temp->next;
        }
        
      cout<<"\n\n";
      }
   }   */
    cout<<"\t   multiply  divide   mad  \n";
    
    for(int i=0;i<4;i++){
      if(i==0) cout<<"int_casting ";
      else if(i==1) cout<<"comp_sum   ";
      else if(i==2) cout<<"poly_sum   ";
      else if(i==3) cout<<"cylic_shift ";

      for(int j=0;j<3;j++){
        cout<<setw(8)<<perf[i*3+j]<<" ";
      }
      cout<<endl;
    }
}

template <typename K, typename V>
  unsigned int Number_Map<K,V>::int_casting(const K& k){  
    unsigned int i=(unsigned int) k; 
    return i;
  }  

template <typename K, typename V>
 unsigned int Number_Map<K,V>::comp_sum(const K& k){   //component size is 4 bytes for phone numbers.
    unsigned int i=( (unsigned int)k + (unsigned int)(k>>32) );
    return i;
  }  

template <typename K, typename V>
  unsigned int Number_Map<K,V>::poly_sum(const K& k){  
    int a=33;
    unsigned int i=0;
    long long int kk=k;

    for(int j=0;j<2 ;j++){
        i= a*( (unsigned int)kk +i );
        kk=kk>>32;
      }
    
    return i;
  }  

template <typename K, typename V>
  unsigned int Number_Map<K,V>::cyclic_shift(const K& k){  
      unsigned int i=0;
      long long int kk=k;
      for(int j=0;j<2 ;j++){
        i = (i << 5) | (i >> 27); 
        i += (unsigned int) kk;
        kk=kk>>32;
         }
    
    return i;
  }  

template <typename K, typename V>
int Number_Map<K,V>::multiply(unsigned int h_code){
      double A=(sqrt(5)-1)/2.0;
      double frac= (h_code*A) -(unsigned int) (h_code*A); //cout<<"hcode "<<h_code<<" f "<<frac<<endl;
      return (int) ( frac * cap );
    }

template <typename K, typename V>
int Number_Map<K,V>::divide(unsigned int h_code){
      return (h_code % cap );
    }

template <typename K, typename V>
int Number_Map<K,V>::mad(unsigned int h_code){
    int a=cap-(cap/2);       //cout<<"a "<<a<<endl;
    int b=cap-(cap/3);       //cout<<"b "<<b<<endl;
    return ( (unsigned int)abs(a*h_code + b ) % cap ) ;
    }

template <typename K, typename V>
V&  Number_Map<K,V>::find(const K& k) {//reuturn value associated with the key.All these we need to calculate the hash value.
    unsigned int code,id;
    switch(hc){
      case 0:code=int_casting(k);break;
      case 1:code= comp_sum(k);break;
      case 2:code= poly_sum(k); break;
      case 3:code= cyclic_shift(k); break;
      default:break;
    }
     switch(hf){
      case 1: id=divide(code)  ;break;
      case 2:  id=mad(code) ;break;
      case 0:  id=multiply(code) ;break;
      default:break;
    }

    key_value_num<K,V>*temp= map[hc*3+hf][id];
    while(temp!=NULL){
      if(temp->key==k) return temp->val;
      temp=temp->next;
    }
    cout<<"KEY NOT FOUND IN THE MAP: ";
    return junk;
}    

template <typename K, typename V>
 void Number_Map<K,V>::put(const K& k, const V& v){  
   unsigned int code,id;
  for(int h=0;h<12;h++){
     switch(h){
      case 0:code=int_casting(k); id=multiply(code) ;break;
      case 1:code=int_casting(k);id=divide(code); break;
      case 2:code=int_casting(k);id=mad(code); break;
      case 3:code= comp_sum(k); id=multiply(code) ;break;
      case 4:code= comp_sum(k);id=divide(code); break;
      case 5:code= comp_sum(k);id=mad(code); break;
      case 6:code= poly_sum(k); id=multiply(code) ; break;
      case 7:code= poly_sum(k); id=divide(code); break;
      case 8:code= poly_sum(k); id=mad(code); break;
      case 9:code= cyclic_shift(k); id=multiply(code) ; break;
      case 10:code= cyclic_shift(k); id=divide(code); break;
      case 11:code= cyclic_shift(k); id=mad(code); break;
      default:break;
    }
    if(map[h][id]!=NULL) (perf[h])++;  //cout<<"perf "<<perf[h]<<endl;

      key_value_num<K,V>*te= map[h][id];
      while(te!=NULL){
        if(te->key==k) { te->val=v; return ; }
        te=te->next;
      }
      
      key_value_num<K,V>* temp =new key_value_num<K,V>;
      temp->key=k;            //cout<<"key "<<code<<" "<<id<<" "<<k<<" "<<v<<" "<<endl;
      temp->val=v;
      temp->next=map[h][id];
      map[h][id]=temp;
  }
  
  int min=10000000;

  for(int h=0;h<12;h++){
      if( min>perf[h] ) { min=perf[h]; hc=(h/3); hf=(h%3); }
        //cout<<setw(8)<<perf[h]<<" ";
      }
  map_size++;    
      //cout<<endl;
    
   // cout<<"hc "<<hc<< " hf "<<hf<<endl;


  }  


template <typename K, typename V>
 void Number_Map<K,V>::erase(const K& k){  
    unsigned int code,id;
    
  for(int h=0;h<12;h++){
     switch(h){
      case 0:code=int_casting(k); id=multiply(code) ;break;
      case 1:code=int_casting(k);id=divide(code); break;
      case 2:code=int_casting(k);id=mad(code); break;
      case 3:code= comp_sum(k); id=multiply(code) ;break;
      case 4:code= comp_sum(k);id=divide(code); break;
      case 5:code= comp_sum(k);id=mad(code); break;
      case 6:code= poly_sum(k); id=multiply(code) ; break;
      case 7:code= poly_sum(k); id=divide(code); break;
      case 8:code= poly_sum(k); id=mad(code); break;
      case 9:code= cyclic_shift(k); id=multiply(code) ; break;
      case 10:code= cyclic_shift(k); id=divide(code); break;
      case 11:code= cyclic_shift(k); id=mad(code); break;
      default:break;
    }
    key_value_num<K,V>* curr=map[h][id];
    key_value_num<K,V>* prev=NULL;
    
    while(curr!=NULL){
      if(curr->key==k){
          break;
      }
      prev=(prev==NULL)?map[h][id]:curr;
      curr=curr->next;

    }

    if(prev){
      if(curr==NULL) { cout<<"Key not in the map can't erase.\n " ;return; }
      key_value_num<K,V>* temp=curr->next;
      prev->next=temp;
      delete curr;
      perf[h]--;
    }
    else{
      delete curr;
      map[h][id]=NULL;
    }
  }  
  int min=10000000;

  for(int h=0;h<12;h++){
      if( min>perf[h] ) { min=perf[h]; hc=(h/3); hf=(h%3); }
       // cout<<setw(8)<<perf[h]<<" ";
      }
  map_size--;    
      //cout<<endl;
    
    //cout<<"hc "<<hc<< " hf "<<hf<<endl;

}

#endif
