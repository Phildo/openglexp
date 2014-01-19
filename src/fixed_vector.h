#ifndef _FIXED_VECTOR_H_
#define _FIXED_VECTOR_H_

template <typename T, int N>
class FixedVector
{
  private:
    char elements[(N * sizeof(T))];
    int size;
  public:
    FixedVector();
    ~FixedVector();

    T& make();
    void pop();
    void remove(int i);
    T const& operator[](int i) const;
};

template <typename T, int N>
FixedVector<T, N>::FixedVector():size(0)
{
}

template <typename T, int N>
FixedVector<T, N>::~FixedVector()
{
  //for(int i = 0; i < size; i++) 
    //((T*)(&elements[i]))->~T();
}

template <typename T, int N>
T& FixedVector<T, N>::make()
{
  //return *(new(&elements[size++ * sizeof(T)]) T());
}

template <typename T, int N>
void FixedVector<T, N>::pop()
{
  //(T*)(&elements[(size-- - 1) * sizeof(T)])->~T();
}

template <typename T, int N>
void FixedVector<T, N>::remove(int i)
{
  //(T*)(&elements[i * sizeof(T)])->~T(); memmove((&elements[i * sizeof(T)]),(&elements[(size-- - 1) * sizeof(T)]), sizeof(T));
}

template <typename T, int N>
T const& FixedVector<T, N>::operator[](int i) const
{
  //return *((T*)(&elements[i * sizeof(T)]));
}

#endif

