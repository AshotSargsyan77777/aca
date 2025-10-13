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


#include <iostream>
#include <iomanip>
int main(){
    double celsius;
    double fahrenheit;
    double kelvin;
    std::cout << "celsius";
    std::cin>>celsius;
    fahrenheit = (celsius * 9.0 / 5.0) + 32;
    kelvin = celsius + 273.15; 
    std::cout      <<fahrenheit<< "F"<<std::endl;
    std::cout    <<kelvin<<"K"<<std::endl;
    return 0;
}