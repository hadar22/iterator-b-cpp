#pragma once

#include <iostream>
#include <vector>

namespace itertools{
    template<typename F, typename K>
    class filterfalse {
        F _f;
        K _m;
      

    public:
        filterfalse(F f, K m): _f(f), _m(m){}

        class iterator{
            typename K::iterator _it;
            typename K::iterator _end;
            F _f;
        public:
             iterator(typename K::iterator it, typename K::iterator end, F f)
                : _it(it), _end(end), _f(f){

                while (_it != _end && _f(*_it))
                    ++_it;
            }
            iterator(const iterator& o) = default;

            iterator& operator=(const iterator& o){
                if(this != &o) {
                    _it = o._it;
                    _end = o._end;
                    _f = o._f;
                }
                return *this;
            };
            iterator& operator ++(){
                do{
                    ++_it;
                } while (_it != _end && _f(*_it));
                return *this;
            }
            iterator operator ++(int){
                iterator tmp = *this;
                ++(*this);
                return tmp;
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
            return iterator(_m.begin(), _m.end(), _f);
        }
        iterator end(){
            return iterator(_m.end(), _m.end(), _f);
        }
    };
};