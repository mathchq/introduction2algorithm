#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T>
class insert_sort
{
private:
    T *arr;
    int length;

public:
    insert_sort() 
    { 
        arr = NULL;
        length = 0;
    }

    ~insert_sort() 
    {
        if(arr != NULL)
            delete[] arr;
    }

    bool initialize(int n);
    bool ascend()
    {
        for (int i = 0; i < length; ++i)
        {
            arr[i] = i;
            /* code */
        }
    }
    bool descend()
    {
        for (int i = 0; i < length; ++i)
        {
            arr[i] = length - i;
            /* code */
        }
    }
    bool show();
    bool sort(bool ascend = true);
    int sort2(bool ascend = true);
};

template <typename T>
bool insert_sort<T>::sort(bool ascend)
{
    T key;
    int i, j;
    for (i = 1; i < length; ++i)
    {
        key = arr[i];
        for(j = i - 1; j >= 0 && key < arr[j]; j--)
            arr[j+1] = arr[j];
        arr[j+1] = key;
        cout << "step " << i << endl;
        show();
        cout << endl;
    }
}

template <typename T>
bool envalue( T &dst, const T tmp)
{
    dst = tmp;
}


int global_counter;

void start()
{
    global_counter = 0;
}

template <typename T>
T counter(const T &t)
{
    global_counter++;
    return t;
}

int get_value()
{
    return global_counter;
}

template <typename T>
int insert_sort<T>::sort2(bool ascend)
{
    T key;
    int i, j;
    start();
    for (i = counter(1); i < counter(length); i = counter(i) + 1)
    {
        key = counter(arr[i]);
        cout << "step " << i << " :"<< endl;
        for(j = counter(i - 1); j >= counter(0) && key < counter(arr[j]); j = counter(j) - 1)
        {
            arr[j+1] = counter(arr[j]);
            arr[j] = -1;
            show();
        }
        arr[j+1] = counter(key);
        show();
    }
    // cout << "total base operation:" << get_value() << endl;
    return get_value();
}

template <typename T>
bool insert_sort<T>::show()
{
    cout << '\t';
    for(int i = 0; i < length; i++)
        cout << this->arr[i] << "\t";
    cout << endl;
}

template <typename T>
bool insert_sort<T>::initialize(int n)
{
    this->length = n;
    this->arr = new T[length];
    srand(time(NULL));
    for(int i = 0; i < length; i++)
        this->arr[i] = rand() % 107;
}

int test1(int n = 6)
{
    insert_sort<int> sort;
    sort.initialize(n);
    cout << "input list: " << endl;
    sort.show();
    return sort.sort2();
}

int best(int n = 6)
{
    // cout << "------the best situation------" << endl;
    insert_sort<int> sort;
    sort.initialize(n);
    sort.ascend();
    // cout << "input list: " << endl;
    // sort.show();
    // cout << endl;
    return sort.sort2();
}

int worst(int n = 6)
{
    // cout << "------the worst situation------" << endl;
    insert_sort<int> sort;
    sort.initialize(n);
    sort.descend();
    // cout << "input list: " << endl;
    // sort.show();
    // cout << endl;
    return sort.sort2();
}

void statistic(int min = 1, int max = 100, int times = 10)
{
    int *cnt_best = new int[max-min+2];
    int *cnt_worse = new int[max-min+2];
    int *cnt_general = new int[max-min+2];
    for( int i = min; i <= max; i++)
    {
        cnt_best[i] = 0;
        cnt_worse[i] = 0;
        cnt_general[i] = 0;
        for(int j = 0; j < times; j++)
        {
            cnt_best[i] += best(i);
            cnt_worse[i] += worst(i);
            cnt_general[i] += test1(i);
        }
    }
    cout << "id\tbest\tworse\tgerneral"<< endl;
    for( int i = min; i <= max; i++)
    {
        cout << i << '\t' << cnt_best[i] <<'\t'  << cnt_worse[i] << '\t' << cnt_general[i] << endl;
    }
    delete[] cnt_best;   
    delete[] cnt_worse;   
    delete[] cnt_general;   
}

int main(int argc, char const *argv[])
{
    /* code */
    int n = atoi(argv[1]);
    test1(n);
    // best(n);
    // worst(n);
    // statistic(1,100,atoi(argv[1]));
    return 0;
}

