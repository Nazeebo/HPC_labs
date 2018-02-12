#include <set>
#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    set<int> s;
    int n, data;
    fscanf(input, "%d", &n);
    for (int i = 1; i <= n; i++) {
        fscanf(input, "%d", &data);
        s.insert(data);
    }
    set<int>::iterator it;
    int tmp, m, count;
    fscanf(input, "%d", &m);
    for (int i = 1; i <= m; i++) {
        fscanf(input, "%d", &n);
        count = 0;
        for (int j = 1; j <= n; j++) {
            fscanf(input, "%d", &tmp);
            it = s.find(tmp);
            if (it != s.end())count++;
        }
        fprintf(output, "%d\n", count);
    }
    fclose(input);
    fclose(output);
    return 0;
}
