template <class T>
class List
{
private:
    T *array;
    int size;
    int length;

    void IncreaseSize();
    void SwapValues(int firstIndex, int secondIndex);

public:
    List();
    List(int size);
    ~List();

    void Display();
    T Get(int index);
    void Insert(int index, T value);
    T Delete(int index);
    List<T> Union(List<T> *listA);
    List<T> Intersection(List<T> *listA);
    List<T> Difference(List<T> *listA);
};