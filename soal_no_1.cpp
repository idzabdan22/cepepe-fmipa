#include <iostream>
#include <math.h>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
using namespace std;
int main ()
{
    string input;
    cout << "\n========SOAL NO 1========\n" << endl;
    cout << "INPUT:" << endl;
    cout << "Masukkan vector angka (Ex:1,-2,30,-104,5) = "; 
    getline(cin, input);
    const char *angka = input.c_str();
    cout << "\nVECTOR: ";
    cout << "[" << angka << "]" << endl;
    int vec_sum = 0, counter_arr = 0, temp = 0, j_temp, counter = 1, times = 1, x = 1;
    for(int j = 0; j < input.size(); j+=2) 
    {
        if(angka[j] == '-'){
            j_temp = j, counter = 1, times = 1, x = 1;
            j_temp++;
            while (angka[j_temp + counter] != ',' && angka[j_temp + counter] != '\0')
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
            j += counter;
            counter_arr++;
        }

        else if (angka[j + 1] != ',' && angka[j + 1] != '\0')
        {
            j_temp = j, counter = 1, times = 1, x = 1;
            while (angka[j_temp + counter] != ',' && angka[j_temp + counter] != '\0')
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
            j += (counter-1);
            counter_arr++;
        }
        else counter_arr++;
    }

    int vector[counter_arr];
    for (int j = 0, k = 0; j < input.size(); j += 2, k++)
    {
        if(angka[j] == '-'){
            j_temp = j, counter = 1, times = 1, x = 1;
            j_temp++;
            while (angka[j_temp + counter] != ',' && angka[j_temp + counter] != '\0')
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
            vector[k] = temp * -1;
            j += counter;
        }

        else if (angka[j + 1] != ',' && angka[j + 1] != '\0')
        {
            j_temp = j, counter = 1, times = 1, x = 1;
            while (angka[j_temp + counter] != ',' && angka[j_temp + counter] != '\0')
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
            vector[k] = temp;
            j += (counter-1);
        }
        else vector[k] = angka[j] - '0';
        vec_sum += vector[k];
    }
    cout << endl;
    cout << "OUTPUT:" << endl;
    cout << "Hasil: [";
    for(int i = 0; i < counter_arr; i++) (i!=counter_arr-1) ? cout << vector[i] << "/" << vec_sum << ", " : cout << vector[i] << "/" << vec_sum << "";
    cout << "]";
}