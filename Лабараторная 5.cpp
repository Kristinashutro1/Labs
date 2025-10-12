#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void merge(const string& f1, const string& f2, const string& outputF) {
    ifstream in1(f1), in2(f2);
    ofstream out(outputF);

     

    string line1, line2;
    bool read1 = false, read2 = false;
    
     
    if (getline(in1, line1)) read1 = true;
    if (getline(in2, line2)) read2 = true;

    while (read1 || read2) {
        if (!read2 || (read1 && line1 <= line2)) {
            out << line1 << endl;
            if (getline(in1, line1)) {
                read1 = true;
            } else {
                read1 = false;
            }
        } else {
            out << line2 << endl;
            if (getline(in2, line2)) {
                read2 = true;
            } else {
                read2 = false;
            }
        }
    }

    in1.close();
    in2.close();
    out.close();
}
    

int main () {
    string f1 = "input1.txt";
    string f2 = "input2.txt";
    string outputF = "merged.txt";
    merge(f1, f2, outputF);
    cout << "result is in file: " << outputF << endl;
    return 0;
}