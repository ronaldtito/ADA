#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm> // swap
#include <stdlib.h> //rand function

using namespace std;


// mayor o menor ------ uso cuidadoso 
template <class T, bool operador>
class Comparator
{
public:
    inline bool operator() (T a ,T b)
    {return operador ? a<b : a>b;}
};


// Generador de Numeros
template <class T>
void numberGenerator(vector<T> &arr, int size){
    for (int i = 0; i < size; i++){
        arr.push_back(rand()%10000000);
    }
}

template <class T>
class Sorts{
    public:

    //---------- Heap Sort -----------
    void heapify(vector<T> &List, int size, int root){ // root posicion del padre index 
        int largest = root;
        int left  = 2*root+1;
        int right = 2*root+2;

        if(left < size && List[left] > List[largest])
            largest = left;
        
        if(right < size && List[right] > List[largest])
            largest = right;

        if (largest != root ){
            swap(List[root],List[largest]);
            heapify(List,size,largest);
        }
    }

    void heapSort(vector<T> List, int size){
            //---Create MaxHeap
            for(int i = size/2-1 ; i >= 0 ; i --)
                heapify(List,size,i);

            for(int i = n-1 ; i >= 0 ; i--){
                swap(List[i],List[0]);
                heapify(List,size-1,0)
            }
    }
    


    //------- Merge Sort ---------
    void mergeSort(){
        
    }
};


main(){

}
