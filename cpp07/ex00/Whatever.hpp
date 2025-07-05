#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template< typename T >
void swap(T &v1, T &v2){
    T temp = v1;
    v1 = v2;
    v2 = temp;
}

template< typename T >
const T min(T &v1, T &v2){
  if (v1 < v2)
      return v1;
  return v2;
}

template< typename T >
const T max(T &v1, T &v2){
    if (v1 > v2)
        return v1;
    return v2;
}


#endif
