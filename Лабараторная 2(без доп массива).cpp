#include <iostream>
#include <ctime> 
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;



int main () {
  int MaxSize = 100;
  int Min;
 int arr[100];
 int size;
 int choice;
  cout <<" enter the number of elements (1 - " << MaxSize << "): " ;
  cin >> size; 
  if (size < 1 || size > 100) { 
    cout << "error" << endl;
    return 1;
  }
   cout << "fillig method (1 - on one's own, 2 - randomly)";
   cin >> choice;
    if(choice == 1) {
        cout << "enter" << size << "elements";
        for ( int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    } 
    else {
  if( choice == 2) 

        {int Min;
        cout << "enter the minimum value of elements:" ;
        cin >> Min;
        int Max;
        cout << "enter the maximum value of elements:" ;
        cin >> Max;

          {if (Min > Max) {
            cout << "error"<< endl;
            return 1;
          }
          srand (time(0));
          for (int i = 0; i < size; i++){
          arr[i] = rand()%(Max-Min+1) + Min;
          } }   }
     
    else {
        cout << "error" << endl;
        return 1;
    } }
    for (int i = 0; i < size; i++)
    cout << arr[i] << " " << endl; 
    
      

    int ME = arr[0];
    for (int i = 1; i < size; i++){
    if (arr[i] > ME) 
     ME = arr[i]; }
     cout << "Maxsimum = " << ME << endl;

    int Last = -1;
    for (int i = size - 1; i >= 0; i--){
    if (arr[i] > 0) 
       Last = i;
      break;  }
      int Sum = 0;
      if (Last > 0) {
        for (int i = 0; i < Last; i++)
        Sum+=arr[i]; 
      }
      cout << "Sum = " << Sum << endl;

      int a, b;
     cout << " a, b" << endl;
     cin >> a >> b;


    for (int i = 0; i < size; i++) {
        if (! (abs(arr[i]) < a || abs(arr[i]) > b)) {
            for (int j = i; j < size; j++){
               arr[j] = arr[j + 1];
            }
            arr[size - 1] = 0;
        }
    }

    
     for ( int i = 0; i < size; i++)
     cout << arr[i] << " " ;
    






    return 0;
}

