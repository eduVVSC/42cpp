#ifndef ITER_HPP    
# define ITER_HPP    

#include <string> 
#include <iostream>
#include <cctype>

template < typename T >
void iter(T *begAdress, int length , void (*func)(T *a)){
    if (begAdress == NULL || func == NULL)
        return ;
    for(int i = 0; i < length; i++){
        func(begAdress);
        begAdress++;
    }
}


template < typename T >
void iter(T *begAdress, int length , void (*func)(T &a)){
    if (begAdress == NULL || func == NULL)
        return ;
    for(int i = 0; i < length; i++){
        func(begAdress);
        begAdress++;
    }
}


// do the handle for const
#endif