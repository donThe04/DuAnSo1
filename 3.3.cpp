#include <iostream>
#include <vector>

using namespace std;

const int N = 9;
vector<vector<int>> board(N, vector<int>(N));
int solution_count = 0;

bool isValid(int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num) return false;
    }
    for (int i = 0; i < N; i++) {
        if (board[i][col] == num) return false;
    }
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num) return false;
        }
    }
    return true;
}

void solve(int row, int col) {
    if (row == N) {
        solution_count++;
        return;
    }
    
    if (col == N) {
        solve(row + 1, 0);
        return;
    }
    
    if (board[row][col] != 0) {
        solve(row, col + 1);
    } else {
        for (int num = 1; num <= 9; num++) {
            if (isValid(row, col, num)) {
                board[row][col] = num;
                solve(row, col + 1);
                board[row][col] = 0;
            }
        }
    }
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    
    solve(0, 0);
    
    cout << solution_count << endl;
    
    return 0;
}

