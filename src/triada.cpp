/*
 * разработал Галбур Сергей
 * ------------------------
 * Программа для подсчета количества триад
 * a^2 + b^2 = c^2
 * для диапазона чисел от 1 до n.
 *
*/
#include <iostream>
#include "triada.h"
#include "console.h"
#include "math.h"
#include <ctime>// заголовочный файл с прототипом функции clock()
using namespace std;



void triads_for_one_c(int n,int st[], int &triads);

int main() {

    //ввод диапазона чисел
    cout << "Input N" << endl;
    int n;
    cin >> n;

    int triads=0;//количество триад a^2 + b^2 = c^2

    unsigned int start_time =  clock();//фиксируем время начала выполнения

    //строим вспомогательные массивы
    int * pw;
    pw = new int[n];//содержит степени натуральных чисел от 1 до n
    int * st;
    st = new int [n];//содержит шаг приращения степени от предыдущего n
    st[0] = pw[0] = 1;
    for(int i = 1; i < n ; i++){
        pw[i] = (i+1)*(i+1);
        st[i] = st[i-1] + 2;
    }

    //подсчитываем количество триад
    for(int i = 1; i <= n; i++){
      triads_for_one_c(i, st, triads);

    }

    //вывод результата
    cout << " triads = " << triads << endl;
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << "runtime: " << search_time << " ms";
    return 0;
}

//подсчет количества триад для кокретного числа c в выражении a^2 + b^2 = c^2
void triads_for_one_c(int c,int st[], int &triads){
    int s = 0;
    int local_triad = 0;
    for (int i = c-1 ; i > 0 ; i--){

        s = s + st[i];

        if (sqrt(s) == floor(sqrt(s))){

            triads++;
            local_triad++;
        }
    }    
}
