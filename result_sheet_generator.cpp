#include <iostream>
#include <iomanip>
using std::endl;

// student data
std::string studentNames[10] = {};
int studentMarks[10][3] = {};
short studentCount {0};

// statistics
int minMark[3] = {};
int maxMark[3] = {};
float average[3] = {};

// options
int main_menu();
void add_row_marks();
void print_mark_sheet();
void print_grade_sheet();
void print_summery_sheet();

int main(){

    while (true) {

        // choose option
        int option {main_menu()};
        
        // execute option
        switch (option) {

            case 1: add_row_marks(); break;
            case 2: print_mark_sheet(); break;
            case 3: print_grade_sheet(); break;
            case 4: print_summery_sheet(); break;
            case 5: return 0;

        }
        
    }
    
    return 0;

}

// is_number ?
bool is_number(std::string str){
    
    for (short i {0}; i < str.length(); i++){
        char ch {str[i]};
        if (ch < '0' || ch > '9') return false; 
    }
    
    return true;
    
}

// main menu
int main_menu(){

    std::cout << "\n#######################################\n"
    << "       Result sheet generation         \n"
    << "#######################################\n\n"
    << "[1] Add new student marks\n"
    << "[2] Print mark sheet\n"
    << "[3] Print grade sheet\n"
    << "[4] Print summery sheet\n"
    << "[5] Exit\n\n";

    bool validOpt {true};
    short option {0};

    do {
    
        if (validOpt == true) std::cout << "Choose an option [1-5]: ";
        else std::cout << "Invalid option. Choose an option [1-5]: ";
        
        // input option and check if input is a number
        // is input is a number then convert it to int,
        // otherwise set to invalid option
        std::string x;
        std::getline(std::cin, x);
        is_number(x) ? option = std::stoi(x) : option = -1;
        
        validOpt = false;

    } while(option < 1 || option > 5);

    return option;

}

// add new student marks
void add_row_marks(){

    std::cout << "\n#######################################\n"
    << "       [1] Add new student marks       \n"
    << "#######################################\n\n";
    
    // input name
    std::cout << "Enter student name: ";
    getline(std::cin, studentNames[studentCount]);
    
    // input marks
    bool validMark {true};
    
    for (int sbj {0}; sbj < 3;) {
        
        // mark is obtained
        // if the mark is invalid, a warning is displayed
        // and the mark has to be re-entered
        int mark {0};
        
        if (validMark == false) std::cout << "Mark is invalid. ";
        if (sbj == 0) std::cout << "Enter marks for 'Maths': ";
        else if (sbj == 1) std::cout << "Enter marks for 'Pysics': ";
        else if (sbj == 2) std::cout << "Enter marks for 'ICT': ";

        // input option and check if input is a number
        // is input is a number then convert it to int,
        // otherwise set to invalid mark
        std::string x;
        std::getline(std::cin, x);
        is_number(x) ? mark = std::stoi(x) : mark = -1;

        if (mark < 0 || mark > 100) {
            validMark = false;
            continue;
        }
        
        // add marks after validation
        studentMarks[studentCount][sbj] = mark;
        
        // update min max marks
        if (studentCount > 0) {

            minMark[sbj] = std::min(mark, 
            minMark[sbj]);

            maxMark[sbj] = std::max(mark, 
            maxMark[sbj]);

        } else {
            minMark[sbj] = mark;
            maxMark[sbj] = mark;
        }
        
        sbj++;
        validMark = true;

    }

    studentCount++;
    
}

// print mark sheet
void print_mark_sheet(){

    std::cout << "\n#######################################\n"
    << "            [2] Mark sheet             \n"
    << "#######################################\n\n" 
    << "+-----------------------------------------------------+\n"
    << "| ID |       Name       |  Maths  | Physics |   ICT   |\n"
    << "+-----------------------------------------------------+\n";

    for (int stdt {0}; stdt < studentCount; stdt++){
        
        std::cout << "|" << std::setw(4) << std::left << stdt + 1 << std::right << "|"
        << std::setw(18) << std::left << studentNames[stdt] << std::right << "|"
        << std::setw(9) << std::left << studentMarks[stdt][0] << std::right << "|"
        << std::setw(9) << std::left << studentMarks[stdt][1] << std::right << "|"
        << std::setw(9) << std::left << studentMarks[stdt][2] << std::right << "|" << endl;

    }

    std::cout << "+-----------------------------------------------------+\n";

}

// get grade
std::string get_grade(int mark){

    std::string grade {"F"};

    switch (mark){
        case 0 ... 19: grade = "F"; break;
        case 20 ... 29: grade = "D"; break;
        case 30 ... 39: grade = "D+"; break;
        case 40 ... 49: grade = "C"; break;
        case 50 ... 59: grade = "C+"; break;
        case 60 ... 69: grade = "B"; break;
        case 70 ... 79: grade = "B+"; break;
        case 80 ... 89: grade = "A"; break;
        case 90 ... 100: grade = "A+";
    }

    return grade;

}

// print grade sheet
void print_grade_sheet(){

    std::cout << "\n#######################################\n"
    << "            [3] Grade sheet            \n"
    << "#######################################\n\n"
    << "+-----------------------------------------------------+\n"
    << "| ID |       Name       |  Maths  | Physics |   ICT   |\n"
    << "+-----------------------------------------------------+\n";

    for (int stdt {0}; stdt < studentCount; stdt++){
        
        std::cout << "|" << std::setw(4) << std::left << stdt + 1 << std::right << "|"
        << std::setw(18) << std::left << studentNames[stdt] << std::right << "|"
        << std::setw(9) << std::left << get_grade(studentMarks[stdt][0]) << std::right << "|"
        << std::setw(9) << std::left << get_grade(studentMarks[stdt][1]) << std::right << "|"
        << std::setw(9) << std::left << get_grade(studentMarks[stdt][2]) << std::right << "|" << endl;

    }

    std::cout << "+-----------------------------------------------------+\n";

}

void print_summery_sheet(){
    
    // calculate average
    for (int stdt {0}; stdt < studentCount; stdt++){
        average[0] += studentMarks[stdt][0] / 1.0 / studentCount;
        average[1] += studentMarks[stdt][1] / 1.0 / studentCount;
        average[2] += studentMarks[stdt][2] / 1.0 / studentCount;
    }

    std::cout << "\n#######################################\n"
    << "           [4] Summery sheet           \n"
    << "#######################################\n\n"
    << "+----------------------------------------+\n"
    << "|          |  Maths  | Physics |   ICT   |\n"
    << "+----------------------------------------+\n"

    << "|Min       |" << std::setw(9) << std::left << minMark[0]
    << "|" << std::setw(9) << std::left << minMark[1]
    << "|" << std::setw(9) << std::left << minMark[2] << std::right << "|" << endl
    
    << "|Max       |" << std::setw(9) << std::left << maxMark[0]
    << "|" << std::setw(9) << std::left << maxMark[1]
    << "|" << std::setw(9) << std::left << maxMark[2] << std::right << "|" << endl
    
    << "|Average   |" << std::setw(9) << std::left << average[0] 
    << "|" << std::setw(9) << std::left << average[1]
    << "|" << std::setw(9) << std::left << average[2] << std::right << "|" << endl
    << "+----------------------------------------+\n";

}
