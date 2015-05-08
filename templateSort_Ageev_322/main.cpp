#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>


using std::random_access_iterator_tag;
using std::output_iterator_tag;
using std::iterator;

template <class T, typename ToComp>
void mySort(iterator<random_access_iterator_tag, T> first, iterator<std::random_access_iterator_tag, T> last, std::function<ToComp> func)
{
    for(int i = 1; i <= last - first; ++i)
    {
        auto curr = *(first + i);
        int prev = i - 1;
        while(prev >= 0 && less(curr, *(first + prev)))
        {
            *(first + prev + 1) = (*first + prev);
            *(first + prev) = curr;
            prev--;
        }
    }
}

bool myfunction (int i,int j) { return (i<j); }

struct myclass
{
    bool operator() (int i,int j) { return (i<j);}
} myobject;

int main()
{
    int myints[] = {32,71,12,45,26,80,53,33};
    std::vector<int> myvector (myints, myints+8);
    
    mySort(myvector.begin(), myvector.end(), myfunction);
    
    return 0;
}
