#pragma once

#include <iostream>
#include <vector>
namespace itertools{
    class range{
        int _begin, _end;

        public:
          range(int b, int e):_begin(b),_end(e){}

          class iterator{
                int _num;
              public:
              iterator(int n): _num(n){}
             iterator(const iterator& o)=default;
             iterator &operator=(const iterator& o){
                 if(this != &o){
                     this->_num=o._num;
                 }
                 return *this;
             };

              int operator *() {
                  return _num;
              }
             
              bool operator ==(const iterator& o){
                  return(_num == o._num);
              }
              bool operator !=(const iterator& o){
                  return(_num != o._num);
              }
              iterator &operator ++(){
                  ++_num;
                  return *this;
              }
              iterator operator ++(int){
                  iterator temp=*this;
                  ++_num;
                  return temp;
              }
          };
          iterator begin(){
              return iterator(_begin);
          }
          iterator end(){
              return iterator(_end);
          }
       
    };
}
