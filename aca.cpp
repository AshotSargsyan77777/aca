#include <iostream>

void my_malloc(std::size_t size, void** ptr) {
    *ptr = malloc(size);
    if (!(*ptr)) {
        *ptr = nullptr;
    }
}
int main() {
    int* ptr;
    my_malloc(5 * sizeof(int), (void**)&ptr);
    if (!ptr) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "Memory allocated successfully!" << std::endl;
    }
}


