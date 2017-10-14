#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int heap[100000+1];
int index = 0;
int temp = 0;
map<int, int> valdex;
int n = 0;
int val = 0;
int leftChild = 0;
int rightChild = 0;
// here I implement a min heap
void insertVal(int val) {
    //if(n == 0) {
    heap[++n] = val;
    valdex[val] = n;
    index = n;
    //}
    if(n == 1) return;
    while(index > 1) {
        // if(heap[index] > heap[index - 1]) return;
        if(heap[index] < heap[index/2]) {
            valdex[heap[index]] = (index)/2;
            valdex[heap[(index)/2]] = index;
            temp = heap[index];
            heap[index] = heap[(index)/2];
            heap[(index)/2] = temp;
            index /= 2; 
        }
        else return;        
    }
    return;
}

void deleteVal(int val) {
    index = valdex[val];
    valdex.erase(val);
    valdex[heap[n]] = index;
    // valdex[val] = heap[n-1]; 

        heap[index] = heap[n--];
    // map<int, int>::iterator it = valdex.find(val);
    // valdex.erase(it);
    while(true) {
        leftChild = 2 * index;
        rightChild = 2 * index + 1;
        if(leftChild <= n) {
            if(rightChild <= n) {
                if(heap[index] > heap[leftChild] || heap[index] > heap[rightChild])
                {
                    int swapIndex = (heap[leftChild] < heap[rightChild]) ? leftChild : rightChild;
                    if(heap[index] < heap[swapIndex]) break;
                    else {
                        valdex[heap[swapIndex]] = index;
                        valdex[heap[index]] = swapIndex;
                        temp = heap[index];
                        heap[index] = heap[swapIndex];
                        heap[swapIndex] = temp;
                        index = swapIndex;
                    }
                }
                else break;
            }
            else {
                if(heap[index] < heap[leftChild]) break;
                else {
                    valdex[heap[leftChild]] = index;
                    valdex[heap[index]] = leftChild;
                    temp = heap[index];
                    heap[index] = heap[leftChild];
                    heap[leftChild] = temp;
                    index = leftChild;
                }
            }
        }
        else break;
    }
    return;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q = 0;
    // int n = 0;
    int action = 0;
    // int val = 0;
    int result = 0;
    cin >> q;
    for(int i = 0; i < q; ++i) {
        cin >> action;
        if(action == 1) {
            cin >> val;
            insertVal(val);
        }
        else if(action == 2) {
            cin >> val;
            deleteVal(val);
        }
        else if(action == 3) {
            cout << heap[1] << endl;
        }
    }
    return 0;
}

