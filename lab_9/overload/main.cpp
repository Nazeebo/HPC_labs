#include <iostream>
#include <fstream>
#include "funcs.h"

using namespace std;

int main() {
    ifstream in("input.txt");
    while (1) {
        if (in.eof())
            break;

        char buf[100];
        char *data = new char[100];
        in >> buf;

        if (isdigit(buf[0])) {
            delete[] data;
            int data[100];
            getSequence(buf, data);
        } else strcpy(data, buf);

        if (palindrome(data)) printMax(data);
        else if (growSeq(data)) afterGrow(data);
        else cout << data << " ";
    }

    in.close();
    return 0;
}