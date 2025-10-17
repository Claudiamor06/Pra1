#include <ostream>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;
    int max;
    int n;
    static const int MINSIZE = 2;

    void resize(int new_size);

public:
    ListArray();
    ~ListArray();

    T operator[](int pos);
    friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
        for (int i = 0; i < list.n; ++i) {
            out << list.arr[i] << " ";
        }
        return out;
    }

};

