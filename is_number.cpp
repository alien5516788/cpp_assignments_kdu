#include<iostream>
using std::endl;

bool is_number(std::string str){
    
    for (short i {0}; i < str.length(); i++){
        
        char ch {str[i]};
        if (ch < '0' || ch > '9') return false;
        
    }
    
    return true;
    
}

int main(){
    
    // test
    while (true){
        
        std::string x;
        std::getline(std::cin, x);
        std::cout << is_number(x) << endl;
        
    }
    
    return 0;
    
}
