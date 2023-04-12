#include <iostream>
#include <fstream>

int main()
{
    int n;
    std::ifstream file("input.txt");
    file >> n;

    int* arr = new int[n];
    int* arrhelp = new int[n];

    for (int i = 0; i < n; i++) {
        file >> arr[i];
        arrhelp[i] = arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        arr[i] = arrhelp[i + 1];
    }

    arr[n - 1] = arrhelp[0];

    int n1;
    file >> n1;

    int* arr1 = new int[n1];
    int* arrhelp1 = new int[n1];

    for (int i = 0; i < n1; i++) {
        file >> arr1[i];
        arrhelp1[i] = arr1[i];
    }

    for (int i = 1; i < n1; i++) {
        arr1[i] = arrhelp1[i - 1];
    }

    arr1[0] = arrhelp1[n1 - 1];

    std::ofstream file1("output.txt");

    file1 << n1 << std::endl;

    for (int i = 0; i < n1; i++) {
        file1 << arr1[i] << " ";
    }

    file1 << std::endl;
    file1 << n << std::endl;

    for (int i = 0; i < n; i++) {
        file1 << arr[i] << " ";
    }

    delete[] arr;
    delete[] arrhelp;
    delete[] arr1;
    delete[] arrhelp1;

    return 0;
}