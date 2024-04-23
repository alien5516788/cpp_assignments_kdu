#include <iostream>
using std::endl;

int main(){
    
    int date, month, year;
    
    // input date
    std::cout << "Input the date: ";
    std::cin >> date;
    
    if (date < 1 || date > 31) {
        std::cout << "Invalid date"; return -1;
    }
    
    // input month
    std::cout << "Input the month: ";
    std::cin >> month;
    
    if (month < 1 || month > 12) {
        std::cout << "Invalid month"; return -1;
    }
    
    // input year
    std::cout << "Input the year: ";
    std::cin >> year;
    
    if (year < 1) {
        std::cout << "Invalid year"; return -1;
    }
    
    // option 1
    std::cout << (date < 10 ? "0" : "" ) << date << '.' 
        << (month < 10 ? "0" : "" ) << month << '.' 
        << year << endl;
    
    // option 2
    std::cout << (date < 10 ? "0" : "") << date << '.' 
        << (month < 10 ? "0" : "" ) << month << '.' 
        << (year % 100 < 10 ? "0" : "") << (year < 100 ? year % 10 : year % 100) << endl;
    
    // option 3
    std::string dSuffix = "st";
    std::string mName = "January";
    
    switch (date) {
            
        case 1:
        case 21:
        case 31: dSuffix = "st"; break;
        case 2:
        case 22: dSuffix = "nd"; break;   
        case 3:
        case 23: dSuffix = "rd"; break;  
        case 4 ... 20:
        case 24 ... 30: dSuffix = "th"; break;
            
    }
    
    switch (month) {
            
        case 1: mName = "January"; break;
        case 2: mName = "February"; break;
        case 3: mName = "March"; break;
        case 4: mName = "April"; break;
        case 5: mName = "May"; break;
        case 6: mName = "June"; break;
        case 7: mName = "July"; break;
        case 8: mName = "August"; break;
        case 9: mName = "September"; break;
        case 10: mName = "Octotber"; break;
        case 11: mName = "November"; break;
        case 12: mName = "December"; break;
            
    }
    
    std::cout << date << " " + dSuffix << " " + mName << " " << year << endl; 
    
    return 0;
    
}
