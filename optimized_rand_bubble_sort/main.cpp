#include <chrono>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <thread>

using namespace std;
using namespace std ::chrono;

int* sort(int* bubbleArray, int n){
    int i = 0;
    int j = 0;
    do {
    j = n - 1;
    do {
      if (bubbleArray[j - 1] > bubbleArray[j]) {
        //temp = bubbleArray[j - 1];
        //bubbleArray[j - 1] = bubbleArray[j];
        //bubbleArray[j] = temp;
        swap(bubbleArray[j - 1], bubbleArray[j]);
      } else
        j = j - 1;
    } while (j > i);
    i = i + 1;
    cout << bubbleArray[j] << " ";
  } while (i <= 5);
  return bubbleArray;
}
 


int main() {
  int i, j, n = 900000; //temp;
  int bubbleArray[n];
  int buildArray[n];
  int buildArray2[n];
  srand(time(NULL));

  //cout << "This is the randomly generated list: ";
  for (i = 0; i < 1000; i++) {
    bubbleArray[i] = rand() % 100 + 1;
    //cout << bubbleArray[i] << " ";
  }
  cout << "\n";
  cout << "\nThis is the list after being sorted by the bubble sort method: ";

  int *bubbleArray2 = bubbleArray + n / 2;
  auto start = chrono::steady_clock::now();
  //sort(bubbleArray, n);
  //thread bsort1(sort, bubbleArray, n / 2);
  //thread bsort2(sort, bubbleArray2, n / 2);

  //int i = 0;
  //int j = 0;
  for(int i = 0; i < n; i++){
    if (bubbleArray[i] <= bubbleArray2[j])
      buildArray[i] = buildArray[i];
    else
      buildArray[i] = buildArray2[j];
  }

  
  i = 0;
  j = 0;
  do {
    j = n - 1;
    do {
      if (bubbleArray[j - 1] > bubbleArray[j]) {
        //temp = bubbleArray[j - 1];
        //bubbleArray[j - 1] = bubbleArray[j];
        //bubbleArray[j] = temp;
        swap(bubbleArray[j - 1], bubbleArray[j]);
      } else
        j = j - 1;
    } while (j > i);
    i = i + 1;
    cout << bubbleArray[j] << " ";
  } while (i <= 5);
  auto end = chrono::steady_clock::now();
  cout << "Elapsed time in nanoseconds: "
       << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
       << " ns" << endl;

  return 0;
}
