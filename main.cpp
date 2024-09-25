#include <iostream>
#include <vector>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <chrono>  // For time measurement

// Function prototypes
std::vector<int> generateRandomArray(int size);
void quickSort(std::vector<int>& arr, int low, int high);
bool linearSearch(const std::vector<int>& arr, int target);
bool binarySearch(const std::vector<int>& arr, int target, int low, int high);

int main() {
    int size = 10000;
    std::vector<int> arr = generateRandomArray(size);

    // Time for QuickSort
    auto start = std::chrono::high_resolution_clock::now();
    quickSort(arr, 0, size - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time taken to sort the array: " << duration.count() << " seconds\n";

    int target = 50000;  // Example target to search for

    // Time for Linear Search
    start = std::chrono::high_resolution_clock::now();
    bool foundLinear = linearSearch(arr, target);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Time taken for linear search: " << duration.count() << " seconds\n";

    // Time for Binary Search
    start = std::chrono::high_resolution_clock::now();
    bool foundBinary = binarySearch(arr, target, 0, size - 1);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Time taken for binary search: " << duration.count() << " seconds\n";

    return 0;
}

// QuickSort algorithm
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to generate random array
std::vector<int> generateRandomArray(int size) {
    std::vector<int> arr(size);
    srand(static_cast<unsigned>(time(0))); // Seed the random number generator
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100000; // Random numbers between 0 and 99999
    }
    return arr;
}

bool binarySearch(const std::vector<int>& arr, int target, int low, int high) {
    if (low > high) {
        return false;
    }
    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
        return true;
    } else if (arr[mid] > target) {
        return binarySearch(arr, target, low, mid - 1);
    } else {
        return binarySearch(arr, target, mid + 1, high);
    }
}

bool linearSearch(const std::vector<int>& arr, int target) {
    for (int num : arr) {
        if (num == target) {
            return true;
        }
    }
    return false;
}
