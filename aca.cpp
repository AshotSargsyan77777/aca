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

// խնդիր 41
// #include <iostream>
// #include <cstdlib>
// #include <ctime>

// int main(int argc, char* argv[]) {
//     if (argc != 3) {
//         std::cout << "ogtagorcum " << argv[0] << " <x> <y>\n";
//         return 1;
//     }

//     int x = std::atoi(argv[1]);
//     int y = std::atoi(argv[2]);

//     if (x <= 0 || y <= 0) {
//         std::cout << "x y petq e linen drakan amboxj tver";
//         return 1;
//     }

//     int** arr = new int*[x];
//     std::srand(std::time(nullptr));

//     for (int i = 0; i < x; i++) {
//         arr[i] = new int[y];
//         for (int j = 0; j < y; j++) {
//             arr[i][j] = std::rand() % 100;
//         }
//     }

//     for (int i = 0; i < x; i++) {
//         for (int j = 0; j < y; j++) {
//             std::cout << arr[i][j] << " ";
//         }
//         std::cout << "\n";
//     }

//     for (int i = 0; i < x; i++) {
//         delete[] arr[i];
//     }
//     delete[] arr;

//     return 0;
// }


//խնդիր 38
// #include <iostream>
// #include <cstdlib>

// struct MyClass {
//     static void* operator new(std::size_t size) {
//         std::cout << "operator new" << std::endl;
//         return std::malloc(size);
//     }

//     static void operator delete(void* ptr) {
//         std::cout << "operator delete" << std::endl;
//         std::free(ptr);
//     }
// };

// int main() {
//     MyClass* obj = new MyClass;
//     delete obj;
//     return 0;
// }

//խնդիր 38
// #include <iostream>
// #include <cstdlib>
// #include <ctime>

// struct MyClass {
//     int value;

//     static void* operator new[](std::size_t size) {
//         std::cout << "operator new[]\n";
//         return std::malloc(size);
//     }

//     static void operator delete[](void* ptr) {
//         std::cout << "operator delete[]\n";
//         std::free(ptr);
//     }
// };

// int main() {
//     std::srand(std::time(nullptr));

//     int n = 10;                     
//     MyClass* arr = new MyClass[n];  
//     for (int i = 0; i < n; ++i)
//         arr[i].value = std::rand() % 100;

//     for (int i = 0; i < n; ++i)
//         std::cout << arr[i].value << " ";
//     std::cout << std::endl;

//     delete[] arr; 
//     return 0;
// }



#include <iostream>
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "ogtagorcum " << argv[0] << " <x> <y>\n";
        return 1;
    }

    int x = std::atoi(argv[1]);
    int y = std::atoi(argv[2]);

    if (x <= 0 || y <= 0) {
        std::cout << "x ev y petq e linen drakan amboxj tver\n";
        return 1;
    }

    
    int** arr = (int**) std::malloc(x * sizeof(int*));
    if (!arr) {
        std::cout << "chhajoxvec\n";
        return 1;
    }

    std::srand(std::time(nullptr));

    for (int i = 0; i < x; i++) {
        arr[i] = (int*) std::malloc(y * sizeof(int));
        if (!arr[i]) {
            std::cout << "chhajoxvec\n";
            
            for (int k = 0; k < i; k++)
                std::free(arr[k]);
            std::free(arr);
            return 1;
        }
        for (int j = 0; j < y; j++)
            arr[i][j] = std::rand() % 100; 
    }

    
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++)
            std::cout << arr[i][j] << " ";
        std::cout << "\n";
    }

    
    for (int i = 0; i < x; i++)
        std::free(arr[i]);
    std::free(arr);

    return 0;
}





