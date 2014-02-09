//Rory McEntee
//DS Lab 4

//I used a different example to model the my binary heap
//http://www.sanfoundry.com/cpp-program-implement-binary-heap/
//I'm going to work on implementing this in different ways.

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class Heap {

private:
    vector<int> heap;
    int leftChild(int parent);
    int rightChild(int parent);
    int parent(int child);
    void percolateUp(int index);
    void percolateDown(int index);

public:
    Heap();
    void insert(int n);
    int deleteMin();
    void print();
    int size() { return heap.size(); }

};

Heap::Heap()
{
}

//The push_back member function adds an item at the end of a vector
void Heap::insert(int element)
{
    heap.push_back(element);
    percolateUp(heap.size() - 1);
}

//The pop_back member function removes an item at the end of a vector
int Heap::deleteMin()
{
    int min = heap.front();
    heap[0] = heap.at(heap.size() - 1);
    heap.pop_back();
    percolateDown(0);
    return min;
}

void Heap::print()
{
    vector<int>::iterator pos = heap.begin();
    cout << "Heap = ";
    while ( pos != heap.end() ) {
        cout << *pos << " ";
        ++pos;
    }
    cout << endl;
}

void Heap::percolateUp(int index)
{
    while ( ( index > 0 ) && ( parent(index) >= 0 ) &&
           ( heap[parent(index)] > heap[index] ) )
    {
        int tmp = heap[parent(index)];
        heap[parent(index)] = heap[index];
        heap[index] = tmp;
        index = parent(index);
    }
}

void Heap::percolateDown(int index)
{
    int child = leftChild(index);
    if ( ( child > 0 ) && ( rightChild(index) > 0 ) &&
        ( heap[child] > heap[rightChild(index)] ) )
    {
        child = rightChild(index);
    }
    if ( child > 0 )
    {
        int tmp = heap[index];
        heap[index] = heap[child];
        heap[child] = tmp;
        percolateDown(child);
    }
}

int Heap::leftChild(int parent)
{
    int i = 2 * parent + 1;
    return ( i < heap.size() ) ? i : -1;
}

int Heap::rightChild(int parent)
{
    int i = 2 * parent + 2;
    return ( i < heap.size() ) ? i : -1;
}

int Heap::parent(int child)
{
    if (child != 0)
    {
        int i = (child - 1) >> 1;
        return i;
    }
    return -1;
}

int main()
{
    // Create the heap
    Heap *alisonHeap = new Heap();
    alisonHeap->insert(23);
    alisonHeap->insert(2354);
    alisonHeap->insert(236);
    alisonHeap->insert(495);
    alisonHeap->insert(940);
    alisonHeap->insert(738);
    alisonHeap->insert(2467);
    alisonHeap->insert(5);;

    alisonHeap->print();

    cout << "Let's clear the queue" << endl;

    // Purge the heap
    int heapSize = alisonHeap->size();
    for ( int i = 0; i < heapSize; i++ ) {
        cout << "Next object to be removed: " << alisonHeap->deleteMin() << endl;
    }
    cout << "The priority queue/heap has been emptied." << endl;

return 0;
}
