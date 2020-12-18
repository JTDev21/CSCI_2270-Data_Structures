#include <string>
using namespace std;

const int MAXSIZE = 5;

class QueArrCir
{
    private:
        int head, tail, queSize;
        string a[MAXSIZE];
    public:
        QueArrCir();

        bool isEmpty();
        bool isFull();
        void enque(string newItem);
        string deque();
};