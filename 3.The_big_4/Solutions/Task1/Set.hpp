class Set {
    int* elements;

    int numElements;
    int capacity;

    void resize();

public:
    Set();
    Set(Set const& other);
    Set& operator= (Set const& other);
    ~Set();

    bool addElement(int const element);
    bool deleteElement(int const element);
    void setUnion(Set const& other);
    void setIntersection(Set const& other);
    void print();
};