#include <iostream>
using std::endl;

void sort_array(int* arr, const int len){
    
    for (int i {0}; i < len; i++){
        
        for (int j{i + 1}; j < len; j++){
            
            int* i1 {(arr + i)};
            int n1 {*i1};
            
            int* i2 {(arr + j)};
            int n2 {*i2};
            
            *i1 = std::min(n1, n2);
            *i2 = std::max(n1, n2);
            
        }
        
    }
    
}

void print_array(int* arr, const int len){
    
    for (int i {0}; i < len; i++){
        std::cout << *(arr + i) << " "; 
    }
    
    std::cout << endl;
    
}

int main(){
    
    // test
    int arr[10] = {2, 6, 1, 0, 34, 2141, 89, 0, 5, 5};
    
    print_array(arr, 10);
    sort_array(arr, 10);
    print_array(arr, 10);
    
    return 0;
    
}
