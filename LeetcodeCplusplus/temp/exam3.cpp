#include <iostream>
#include <vector>

using namespace std;


int main() {
    int direction;
    cin >> direction;
    vector<vector<int>> input;
    for (int i = 0; i < 4; i++) {
        vector<int> temp;
        for (int j = 0; j < 4; j++) {
            int temp_int;
            cin >> temp_int;
            temp.push_back(temp_int);
        }
        input.push_back(temp);
    }
    if (direction == 1) {
        for (int j = 0; j < 4; j++) {
            int i = 0, current = 0, current_pos = 0;
            while (i < 4)//找第一个不是0的
            {
                if (input[i][j] != 0) {
                    current = input[i][j];
                    break;
                }
                i++;
            }
            i++;
            input[current_pos][j] = current;
            while (i < 4) {
                int temp = input[i][j];
                if (temp != 0) {
                    if (temp == current)//可以合并
                    {
                        input[current_pos][j] *= 2;
                        current = 0;
                    } else {
                        current = temp;
                        current_pos++;
                        input[current_pos][j] = current;
                    }
                }
                i++;
            }
            for (int k = current_pos + 1; k < 4; k++) {
                input[k][j] = 0;
            }
        }
    }
    if (direction == 2) {
        for (int j = 0; j < 4; j++) {
            int i = 3, current = 0, current_pos = 3;
            while (i >= 0)//找第一个不是0的
            {
                if (input[i][j] != 0) {
                    current = input[i][j];
                    break;
                }
                i--;
            }
            i--;
            input[current_pos][j] = current;
            while (i >= 0) {
                int temp = input[i][j];
                if (temp != 0) {
                    if (temp == current)//可以合并
                    {
                        input[current_pos][j] *= 2;
                        current = 0;
                    } else {
                        current = temp;
                        current_pos--;
                        input[current_pos][j] = current;
                    }
                }
                i--;
            }
            for (int k = current_pos - 1; k >= 0; k--) {
                input[k][j] = 0;
            }
        }
    }
    if (direction == 3) {
        for (int j = 0; j < 4; j++) {
            int i = 0, current = 0, current_pos = 0;
            while (i < 4)//找第一个不是0的
            {
                if (input[j][i] != 0) {
                    current = input[j][i];
                    break;
                }
                i++;
            }
            i++;
            input[j][current_pos] = current;
            while (i < 4) {
                int temp = input[j][i];
                if (temp != 0) {
                    if (temp == current)//可以合并
                    {
                        input[j][current_pos] *= 2;
                        current = 0;
                    } else {
                        current = temp;
                        current_pos++;
                        input[j][current_pos] = current;
                    }
                }
                i++;
            }
            for (int k = current_pos + 1; k < 4; k++)
                input[j][k] = 0;
        }
    }
    if (direction == 4) {
        for (int j = 0; j < 4; j++) {
            int i = 3, current = 0, current_pos = 3;
            while (i >= 0)//找第一个不是0的
            {
                if (input[j][i] != 0) {
                    current = input[j][i];
                    break;
                }
                i--;
            }
            i--;
            input[j][current_pos] = current;
            while (i >= 0) {
                int temp = input[j][i];
                if (temp != 0) {
                    if (temp == current)//可以合并
                    {
                        input[j][current_pos] *= 2;
                        current = 0;
                    } else {
                        current = temp;
                        current_pos--;
                        input[j][current_pos] = current;
                    }
                }
                i--;
            }
            for (int k = current_pos - 1; k >= 0; k--)
                input[j][k] = 0;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << input[i][j] << " ";
        }
        cout << endl;
    }
}