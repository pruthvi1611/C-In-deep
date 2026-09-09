#include <iostream>

int main() {
    int size = 0;

    std::cout << "Enter array size: ";
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Array size must be a positive integer.\n";
        return 1;
    }

    int* arr = new int[size];

    std::cout << "Enter " << size << " integer value(s):\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    long long sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }

    double average = static_cast<double>(sum) / size;

    std::cout << "Sum: " << sum << '\n';
    std::cout << "Average: " << average << '\n';

    delete[] arr;
    arr = nullptr;

    return 0;
}
