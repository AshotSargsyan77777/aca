//խնդիր 40
// #include <iostream>

// void my_malloc(std::size_t size, void** ptr) {
//     *ptr = malloc(size);
//     if (!(*ptr)) {
//         *ptr = nullptr;
//     }
// }
// int main() {
//     int* ptr;
//     my_malloc(5 * sizeof(int), (void**)&ptr);
//     if (!ptr) {
//         std::cout << "voch" << std::endl;
//     } else {
//         std::cout << "azat" << std::endl;
//     }
// }


#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    int x, y;
    std::cout << "mutqagrir x y ";
    std::cin >> x >> y;

    int** arr = new int*[x];

    std::srand(std::time(nullptr));

    for (int i = 0; i < x; i++) {
        arr[i] = new int[y];
        for (int j = 0; j < y; j++) {
            arr[i][j] = std::rand() % 100;
        }
    }

    std::cout << "";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }

    
    for (int i = 0; i < x; i++) {
        delete[] arr[i]; 
    }
    delete[] arr;

    return 0;
}




