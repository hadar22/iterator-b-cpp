#pragma once

#include <iterator>

namespace itertools{
    typedef struct {
        template <typename T>
        T operator() (T a , T b) const{
            return a+b;
        }
    }function;
    template <typename T , typename F=function>
    class accumulate{
        T _m;
        F _func;
       
          public:
          explicit accumulate(T t, F f=function()):_m(t),_func(f){}

       class iterator{
               accumulate m_accu;
              decltype(_m.begin()) _it;
              typename std::decay<decltype(*(_m.begin()))>::type _ans;

              public :
                iterator( accumulate& s,decltype(_m.begin()) it ):
                    m_accu(s), _it(it){
                        if(it!= m_accu._m.end()){
                            _ans=*it;
                        }
                    }
                iterator(const iterator &o)=default;
             
                iterator operator++(){
                 ++_it;
                 if(_it!=m_accu._m.end()){
                     _ans=m_accu._func(_ans,*(_it));
                 }
                 return *this;
                }
                

                bool operator ==(const iterator& o){
                  return(_it==o._it);
              }
              bool operator !=(const iterator& o){
                  return(_it!=o._it);
              }
                auto operator *(){
                return _ans;
            }
          };
     
          
           const iterator begin() {
            return iterator(*this,_m.begin());
        }
        const iterator end() {
            return iterator(*this,_m.end());
        }
    };
   
    
    
} 
