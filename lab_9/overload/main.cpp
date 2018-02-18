#include <iostream>
#include <fstream>
#include "funcs.h"

using namespace std;

int main() {
    ifstream in("input.txt");
    while (1) {
        if (in.eof())
            break;

        bool isDigit = false;
        char buf[100],data[100];
        fill(data, data+100,0);
        in >> buf;

        if (isdigit(buf[0])) {
            changingWayOfStore(buf, data);
            isDigit = true;
        } else strcpy(data, buf);

        if (palindrome(data)) printMax(data,isDigit);
        else if (growSeq(data)) afterGrow(data,isDigit);
        else cout << data << " ";
    }

    in.close();
    return 0;
}