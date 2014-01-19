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

#endif

