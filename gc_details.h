template <class T>
class PtrDetails
{
  public:
    unsigned refcount;
    T *memPtr;
    bool isArray;
    unsigned arraySize;

    PtrDetails(T *ptr, int size=0)
    {
        this->memPtr = ptr;
        this->refcount = 1;
        this->arraySize = size;
        this->isArray = false; // Create default that is overridden if size is set.
        
        if (size > 0) {
            this->isArray = true;
        }
    }
};
template <class T>
bool operator==(const PtrDetails<T> &ob1,
                const PtrDetails<T> &ob2)
{
    return (ob1.memPtr == ob2.memPtr);
}