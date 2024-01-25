class DynamicArray
{
    int *arr;
    int capacity;
    int length;

public:
    DynamicArray(int capacity)
    {
        this->capacity = capacity;
        length = 0;
        arr = new int[capacity];
    }

    // return index
    int get(int i)
    {
        return arr[i];
    }

    void set(int i, int n)
    {
        arr[i] = n;
    }

    void pushback(int n)
    {
        if (length == capacity)
        {
            resize();
        }
        arr[length] = n;
        length++;
    }

    int popback()
    {
        if (length > 0)
        {

            length--;
        }
        return arr[length];
    }

    void resize()
    {
        capacity = capacity * 2;
        int *newarr = new int[capacity];
        for (int i = 0; i < length; i++)
        {
            newarr[i] = arr[i];
        }
        delete[] arr;
        arr = newarr;
    }

    int getSize()
    {
        return length;
    }

    int getCapacity()
    {
        return capacity;
    }
};