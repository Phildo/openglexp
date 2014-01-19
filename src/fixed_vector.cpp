#include "fixed_vector.h"

template <typename T, int N>
FixedVector<T, N>::FixedVector():size(0)
{
}

template <typename T, int N>
FixedVector<T, N>::~FixedVector()
{
  for(int i = 0; i < size; i++) 
    (&elements[i])->~T();
}

template <typename T, int N>
T& FixedVector<T, N>::make()
{
  return *(new(&elements[size++ * sizeof(T)]) T());
}

template <typename T, int N>
void FixedVector<T, N>::pop()
{
  (T*)(&elements[(size-- - 1) * sizeof(T)])->~T();
}

template <typename T, int N>
void FixedVector<T, N>::remove(int i)
{
  (T*)(&elements[i * sizeof(T)])->~T(); memmove((&elements[i * sizeof(T)]),(&elements[(size-- - 1) * sizeof(T)]), sizeof(T));
}

template <typename T, int N>
T const& FixedVector<T, N>::operator[](int i) const
{
  return *((T*)(&elements[i * sizeof(T)]));
}

