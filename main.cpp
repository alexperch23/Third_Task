#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

const int sizeData = 16;

void coutFile(vector <float> &data, fstream &file) {
    string path;
    cout << "Введите название файла (без расширения .txt): ";
    cin >> path;
    file.open(path + ".txt", ios::in);
    if (!file.is_open()) { // Проверка на наличие нужного файла
        cout << "Данного файла не существует.";
        system("pause");
        return;
    }
    else {
        float ptr;
        while (!file.eof()) {
            file >> ptr;
            data.push_back(ptr);
        }
    }
    cout << "Файл считан" << endl;
    file.close();
}

float* analiz(vector <vector<float>> data) {
    float max = 0;
    int indexTime = -1;
    for (int j = 0; j < data[0].size(); j++) {
        float sum = 0;
        for (int i = 0; i < data.size(); i++) {
            sum += data[i][j];
        }
        if (sum > max) {
            max = sum;
            indexTime = j;
        }
    }
    float *outData = new float[2]; // Массив для возвращения данных из функции
    outData[0] = max; // Макс кол-во посетителей
    outData[1] = indexTime + 1; // Время
    return outData;
}

int  main() {
    /*setlocale(LC_ALL, "Russian"); // Компилятор не хочет видеть кирилицу, добавил два варианта на всякий случай
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);*/
    fstream file;
    vector <vector<float>> vect(5);
    for (int i = 0; i < vect.size(); i++)
        coutFile(vect[i], file);
    float *inData = new float[2]; // Массив для получения данных из функции
    inData = analiz(vect);
    int time = 0;
    for (int i = 0; i < inData[1]; i++) { // Цикл для прибавления нужного времени
        time += 30;
    }
    cout << "Наибольшее количество посетителей было в промежуток времени от " << (float)(time - 30) / 60 << " до " << (float)time / 60
         << " часов с начало рабочего дня.\nОбщее количесто посетителей в этой време было: " << inData[0] << endl;

    system("pause");
    return 0;
}