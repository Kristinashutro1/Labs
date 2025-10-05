#include <iostream>
using namespace std;
//A 
int strcmp(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        if (*str1 < *str2) return -1;
        if (*str1 > *str2) return 1;
        str1++;
        str2++;
    }
    if (*str1 == *str2) return 0;
    return (*str1 < *str2) ? -1 : 1;
}

//B
bool is_number_word(const char *word) {
    while (*word) {
        if (*word < '0' || *word > '9') return false;
        word++;
    }
    return true;
}


void copy_word(char *dest, const char *src) {
    while (*src && *src != ' ') {
        *dest++ = *src++;
    }
    *dest = '\0';
}


void rearrange(char *input) {
    char number[300][300], others[300][300];
    int n_count = 0, o_count = 0;

    char *ptr = input;
    while (*ptr) {
        char word[300];
        int i = 0;
        while (*ptr && *ptr != ' ') {
            word[i++] = *ptr++;
        }
        word[i] = '\0';

        if (is_number_word(word)) {
            copy_word(number[n_count++], word);
        } else {
            copy_word(others[o_count++], word);
        }

        if (*ptr == ' ') ptr++;
    }

    
    int pos = 0;
    for (int i = 0; i < n_count; ++i) {
        int j = 0;
        while (number[i][j]) input[pos++] = number[i][j++];
        input[pos++] = ' ';
    }
    for (int i = 0; i < o_count; ++i) {
        int j = 0;
        while (others[i][j]) input[pos++] = others[i][j++];
        if (i != o_count - 1) input[pos++] = ' ';
    }
    input[pos] = '\0';
}


int main() {
    //A
    char str1[100], str2[100];
    cout << "First string: ";
    cin.getline(str1, 100);
    cout << "Sekond string: ";
    cin.getline(str2, 100);

    int result = strcmp(str1, str2);
    cout << "Comparison result: " << result << endl;
    //B
    char input[301];
    cout << "Enter string  (max 300 symbol): ";
    cin.getline(input, 301);

    rearrange(input);
    cout << "Converted string: " << input << endl;
    return 0;
}