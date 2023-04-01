#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int *a; 		// массив
    int n; 			// количество элементов в массиве
    int sum; 		// необходимая сумма
    
    //чтение массива
    cout << "Enter num of elements of array: " << endl;
    cin >> n;
    
    cout << "Enter the array elements (in rising order): " << endl;
    a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
        
    cout << "Enter the sum value: " << endl; 
    cin >> sum;
     
    // индексы
    int lt = 0; 		// первый, то есть левый
    int rt = n - 1; 	// второй, то есть правый
   
    while (lt != rt)
    {       
        int cursum = a[lt] + a[rt];
        if (cursum < sum)
            lt++;
        else if (cursum > sum)
            rt--;
        else // if (cursum == sum)
        {
            cout << "indexes: " << lt << " " << rt << endl;
            cout << "values: " << a[lt] << " " << a[rt] << endl;
            return 0;
        }
    }
    cout << "not found" << endl;
    return 0;
}
