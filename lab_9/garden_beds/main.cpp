#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
public:
    Graph(unsigned int count) {
        size = count;
        components = 0;
        used.resize(count + 2);
        adj_matrix.resize(count + 2);
        for (auto &str : adj_matrix) {
            str.resize(count + 2);
        }
        for (int i = 0; i <= count; i++) {
            used[i] = false;
            for (int j = 0; j <= count; j++)
                adj_matrix[i][j] = 0;
        }
    };

    void bfs() {
        queue<int> q;

        for (int i = 1; i <= size; i++) {
            if (!used[i]) {
                components++;
                q.push(i);
                while (!q.empty()) {
                    int current = q.front();
                    q.pop();

                    for (int j = 1; j <= size; j++) {
                        if (adj_matrix[current][j] && !used[j]) {
                            q.push(j);
                            used[j] = true;
                        }
                    }
                }
            }
        }

    };

    void add_pare(int a, int b) {
        adj_matrix[a][b] = 1;
        adj_matrix[b][a] = 1;
    };

    int getComponents() {
        return components;
    }

    void printMatr() {
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= size; j++)
                cout << adj_matrix[i][j] << " ";
            cout << endl;
        }
    }

private:
    vector<bool> used;
    vector<vector<int>> adj_matrix;
    int components, size;
};

void printMatrix(vector<vector<int>> matrix, unsigned int n, unsigned int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    unsigned int n, m, count = 0;
    fscanf(in, "%d%d\n", &n, &m);
    vector<vector<int> > matrix;
    matrix.resize(n + 1);
    for (auto &str : matrix)str.resize(m + 1);
    char data;
    for (int i = 0; i < n; i++) {
        matrix[i][m] = 0;
        for (int j = 0; j < m; j++) {
            if (i == 0) matrix[n][i] = 0;
            fscanf(in, "%c", &data);
            switch (data) {
                case '.': {
                    matrix[i][j] = 0;
                    break;
                }
                case '#': {
                    matrix[i][j] = ++count;
                    break;
                }
            }
        }
        fscanf(in, "\n");
    }
    Graph graph(count);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (matrix[i][j] != 0) {
                if (matrix[i + 1][j] != 0) graph.add_pare(matrix[i][j], matrix[i + 1][j]);
                if (matrix[i][j + 1] != 0) graph.add_pare(matrix[i][j], matrix[i][j + 1]);
            }

    graph.bfs();
    fprintf(out, "%d", graph.getComponents());

    return 0;
}