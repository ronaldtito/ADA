#include <iostream>
#include <vector>
#include <stdio.h>
#include <ctime>
#include <algorithm> // swap
#include <stdlib.h> //rand function

using namespace std;



// Generador de Numeros
template <class T>
void numberGenerator(vector<T>& arr, int size) {
    for (int i = 0; i < size; i++) {
        arr.push_back(rand() % 1000000000);
    }
}

template <class T>
class Sorts {
public:

    //---------- Heap Sort -----------
    void heapify(vector<T>& List, int size, int root) { // root posicion del padre index 
        int largest = root;
        int left = 2 * root + 1;
        int right = 2 * root + 2;

        if (left < size && List[left] > List[largest])
            largest = left;

        if (right < size && List[right] > List[largest])
            largest = right;

        if (largest != root) {
            swap(List[root], List[largest]);
            heapify(List, size, largest);
        }
    }

    void heapSort(vector<T> List, int size) {
        //---Create MaxHeap
        for (int i = size / 2 - 1; i >= 0; i--)
            heapify(List, size, i);

        for (int i = size - 1; i >= 0; i--) {
            swap(List[i], List[0]);
            heapify(List, size - 1, 0);
        }
    }



    //------- Merge Sort ---------
    void merge(vector<T>& List, int const left, int const mid, int const right) {
        int const sizeL = mid - left + 1;
        int const sizeR = right - mid;

        int *Left= new int[sizeL] ; 
        int *Right= new int[sizeR];

        //copy 
        for (int i = 0; i < sizeL; i++)
            Left[i] = List[left + i];
        for (int i = 0; i < sizeR; i++)
            Right[i] = List[mid + 1 + i];

        int i = 0;
        int j = 0;
        int index =  left;

        while (i < sizeL && j < sizeR) {
            if (Left[i] < Right[j]) {
                List[index] = Left[i];
                i++;
            }
            else {
                List[index] = Right[j];
                j++;
            }
            index++;
        }

        while (i < sizeL) {
            List[index] = Left[i];
            i++;
            index++;
        }
        while (j < sizeR) {
            List[index] = Right[j];
            j++;
            index++;
        }
    }

    void mergeSort(vector<T> & List, int left, int right) {
        if (left < right ) {
            int mid = left + (right - left) / 2;

            mergeSort(List,left,mid);
            mergeSort(List, mid +1, right);
            merge(List,left,mid,right);
        }
    }

    // --------------Quick Sort ------------------
    int LeftandRight(vector<T>& List, int left, int right) {
        int pivot = List[right];

        int pos = (left - 1);

        for (int i = left; i < right; i++) {
            if (List[i] <= pivot) {
                pos++;
                swap(List[i], List[pos]);
            }
        }
        swap(List[pos+1], List[right]);
        return right;
    }

    void quickSort(vector<T> &List, int left, int right){
        if (left < right) {
            int pivot = LeftandRight(List,left, right);

            quickSort(List, left, pivot - 1);
            quickSort(List, pivot + 1, right);
        }


    }

    //---------- Radix Sort ----------------
    
    int getMax(vector<T> List, int n) {
        int max = List[0];
        for (int i = 1; i < n; i++)
            if (List[i] > max)
                max = array[i];
        return max;
    }

    void countingSort(vector<T> List, int const size, int place) {
        const int max = 10;
        int output[size];
        int count[max];

        for (int i = 0; i < max; ++i)
            count[i] = 0;

        for (int i = 0; i < size; i++)
            count[(List[i] / place) % 10]++;

        for (int i = 1; i < max; i++)
            count[i] += count[i - 1];

        for (int i = size - 1; i >= 0; i--) {
            output[count[(List[i] / place) % 10] - 1] = List[i];
            count[(List[i] / place) % 10]--;
        }

        for (int i = 0; i < size; i++)
            List[i] = output[i];
    }

    void radixSort(vector<T> &List, int size) {
        int max = getMax(List, size);

        for (int place = 1; max / place > 0; place *= 10)
            countingSort(List, size, place);
    }

    //----------------- Shell Sort ---------------
    void shellSort(vector<T>& List, int size) {
        int interval = size/2;

        while (interval > 0) {
            
            for (int i = interval; i < size; i++) {
                int value = List[i];
                int inner = i;

                while (inner > interval -1 && List[inner-interval] >= value)  {
                    List[inner] = List[inner - interval];
                    inner -= interval;
                }
                List[inner] = value;
            }
            interval = (interval - 1) / 3;
        }

    }
    //----------------- Bucket Sort --------------
   /* void bucketSort(vector<T>& List, int size) {
        vector<float> bucket;
        bucket.reserve(size);
        for (int i = 0; i < size; i++) 
            bucket[int(size * List[i])].push_back(List[i]);

        for (int i = 0; i < size; i++)
            sort(bucket[i].begin(), bucket.end());

        int index = 0;
        for (int i = 0; i < size; i++)
        {
            while (!bucket[i].empty()){
                List[index++] = *(bucket[i].begin());
                bucket[i].erase(bucket[i].begin());
            }
        }
    }*/
};



void Print(vector<int> &List) {
    for (vector<int>::iterator it = List.begin(); it != List.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    vector<vector<int > > Listas;
    vector<int> Lista1, Lista2, Lista3, Lista4, Lista5, Lista6;

    Listas.push_back(Lista1);
    Listas.push_back(Lista2);
    Listas.push_back(Lista3);
    Listas.push_back(Lista4);
    Listas.push_back(Lista5);
    Listas.push_back(Lista6);

    int n = 10;
    numberGenerator(Lista1, n);

    // copy Lists
    for (int i = 1; i < Listas.size();i++){
        for (vector<int>::iterator it = Lista1.begin(); it != Lista1.end(); it++){
            Listas[i].push_back(*it);
        }
    }

    Sorts<int> Ordena;
    Ordena.heapSort(Listas[0],n);
    Ordena.mergeSort(Listas[1],0,n-1);
    Ordena.quickSort(Listas[2],0,n-1);
    Ordena.radixSort(Listas[3], n);
    Ordena.shellSort(Listas[4], n);
  //  Ordena.bucketSort(Listas[5], n);

    Print(Listas[0]);
    Print(Listas[1]);
    Print(Listas[2]);
    Print(Listas[3]);
    Print(Listas[4]);
    Print(Listas[5]);

}
