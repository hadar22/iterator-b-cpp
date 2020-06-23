#pragma once

#include <iostream>
#include <vector>

namespace itertools{
    template <typename T, typename B>
    class compress{
        T _m;
        B _bool;
        public:
           compress (T t,B b): _m(t), _bool(b){}
           class iterator{
               typename T::iterator _it;
               typename T::iterator _endIt;
               typename B::iterator _boolIt;

               public:
                iterator(typename T::iterator it, typename T::iterator endIt, typename B::iterator boolIt):
                    _it(it),_endIt(endIt), _boolIt(boolIt){}
                iterator &operator=(const iterator &o){
                    if(this != &o){
                        _it=o._it;
                    }
                    return *this;
                };
                iterator& operator ++(){
                do    {
                        ++_it;
                        ++_boolIt;
                    }while (_it !=_endIt && !(*_boolIt));
                
                return *this;
            }
            iterator operator ++(int){
                iterator temp = *this;
                ++(*this);
                return temp;
            }
            bool operator ==(const iterator& o) {
                return (_it == o._it);
            }
            bool operator !=(const iterator& o) {
                return (_it != o._it);
            }
            auto operator *(){
                return *_it;
            }


           };
             iterator begin(){
            return iterator(_m.begin(), _m.end(), _bool.begin());
        }
        iterator end(){
            return iterator(_m.end(), _m.end(), _bool.end());
        }
    };
}