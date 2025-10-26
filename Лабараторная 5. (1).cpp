#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_LINES = 1000;

int main() {
    string inputFile1, inputFile2, outputFile;
    string lines1[MAX_LINES], lines2[MAX_LINES];
    int count1 = 0, count2 = 0;

    cout << "First file name: ";
    cin >> inputFile1;
    cout << "Sekond file name: ";
    cin >> inputFile2;
    cout << "Ounput file name: ";
    cin >> outputFile;

    ifstream in1(inputFile1);
    ifstream in2(inputFile2);
    ofstream out(outputFile);

    if (!in1.is_open() || !in2.is_open()) {
        cout << "Error.\n";
        return 1;
    }

    //  Чтение первого файла
    string line;
    while (getline(in1, line) && count1 < MAX_LINES) {
        lines1[count1++] = line;
    }
    in1.close();

    //  Чтение второго файла
    while (getline(in2, line) && count2 < MAX_LINES) {
        lines2[count2++] = line;
    }
    in2.close();

    //  содержимое входных файлов
    cout << "\nFirst file:\n";
    for (int i = 0; i < count1; ++i)
        cout << lines1[i] << endl;

    cout << "\nSekond file:\n";
    for (int i = 0; i < count2; ++i)
        cout << lines2[i] << endl;

    //  Слияние двух упорядоченных массивов строк
    int i = 0, j = 0;
    int written = 0;

    while (i < count1 && j < count2) {
        if (lines1[i] <= lines2[j])
            out << lines1[i++] << endl;
        else
            out << lines2[j++] << endl;
        ++written;
    }

    while (i < count1) {
        out << lines1[i++] << endl;
        ++written;
    }

    while (j < count2) {
        out << lines2[j++] << endl;
        ++written;
    }

    out.close();

    //   ничего не записано — создать пустой файл
    if (written == 0) {
        ofstream emptyOut(outputFile, ios::trunc); // перезапись пустым
        emptyOut.close();
        cout << "\nOutput file is empty.\n";
    } else {
        cout << "\nThe merge is complete. The following lines were written: " << written << endl;
    }

    return 0;
}
