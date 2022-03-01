#include <iostream>
#include <math.h>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
using namespace std;
int main ()
{
    int m, n;
    cout << "\n========SOAL NO 2========\n" << endl;
    cout << "INPUT:" << endl;
    cout << "Masukkan baris matriks(m): ";
    cin >> m;
    cout << "Masukkan kolom matriks(n): ";
    cin >> n;
    int matriks[m][n];
    string input;
    const char *angka;
    angka = input.c_str();
    getline(cin, input);
    int max = -999;
    int temp = 0;
    for (int i = 0; i < m; i++)
    {
        cout << "Masukkan nilai tiap kolom pada baris ke-" << i + 1 << " (Ex:1 10 3 -11): ";
        getline(cin, input);
        angka = input.c_str();
        for (int j = 0, k = 0; j < input.size(); j+=2, k++){
            if(angka[j] == '-'){
                int j_temp = j, counter = 1, times = 1, x = 1;
                j_temp++;
                while (angka[j_temp + counter] != ' ' && angka[j_temp + counter] != '\0')
                {
                    times *= 10;
                    counter++;
                }
                temp = 0;
                while (x <= counter)
                {
                    temp += ((angka[j + x] - '0') * times);
                    times /= 10;
                    x++;
                }
                matriks[i][k] = temp * -1;
                j += counter;
            }

            else if (angka[j + 1] != ' ' && angka[j + 1] != '\0')
            {
                int j_temp = j, counter = 1, times = 1, x = 1;
                while (angka[j_temp + counter] != ' ' && angka[j_temp + counter] != '\0')
                {
                    times *= 10;
                    counter++;
                }
                temp = 0;
                while (x <= counter)
                {
                    temp += ((angka[j_temp] - '0') * times);
                    times /= 10;
                    j_temp++;
                    x++;
                }
                matriks[i][k] = temp;
                j += (counter-1);
            }
            else matriks[i][k] = angka[j] - '0';
            (matriks[i][k] >= max) ? max = matriks[i][k] : max = max;
        }
    }
    cout << endl;
    cout << "MATRIKS: \n\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++){
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "OUTPUT:" << endl;
    cout << "Nilai Maksimum Pada Matriks: " << max << endl << endl;
}