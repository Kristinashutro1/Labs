#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_SIZE = 100;

int main() {
    double arr[MAX_SIZE];
    int n;
    int mode;
    double minRange, maxRange;
    double a, b;

    cout << "Enter number of elements (1 - " << MAX_SIZE << "): ";
    cin >> n;
    if (n <= 0 || n > MAX_SIZE) {
        cout << "Error \n";
        return 1;
    }

    cout << "Method of filling an array:\n";
    cout << "1 - keyboard input\n";
    cout << "2 - random\n";
    cin >> mode;

    cout << "Enter (min max): ";
    cin >> minRange >> maxRange;

   

    if (mode == 1) {
        cout << "Enter elements:\n";
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
    } else if (mode == 2) {
        srand(time(0));
        cout << "Random:\n";
        for (int i = 0; i < n; ++i) {
            arr[i] = minRange + (rand() % 1000) / 1000.0 * (maxRange - minRange);
            cout << arr[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Error\n";
        return 1;
    }

    

    //  Максимальный элемент
    double maxVal = arr[0];
    for (int i = 1; i < n; ++i)
        if (arr[i] > maxVal)
            maxVal = arr[i];
    cout << "max: " << maxVal << endl;

    // Сумма до последнего положительного
    int lastPos = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (arr[i] > 0) {
            lastPos = i;
            break;
        }
    }

    double sum = 0;
    for (int i = 0; i < lastPos; ++i)
        sum += arr[i];
    cout << "Sum: " << sum << endl;

    //  Сжатие массива
    cout << "Enter [a,b]: ";
    cin >> a >> b;

    int writeIndex = 0;
    for (int i = 0; i < n; ++i) {
        if (!(fabs(arr[i]) >= a && fabs(arr[i]) <= b)) {
            arr[writeIndex] = arr[i];
            ++writeIndex;
        }
    }

    // Заполнение оставшихся элементов нулями
    for (int i = writeIndex; i < n; ++i)
        arr[i] = 0;

    cout << "New:\n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
