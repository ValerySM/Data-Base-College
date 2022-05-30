//Author: Valery Sokolov Morgenshteyn
//ID: 336424221
#include "College.h"


bool College::expendStudentArray() {
    if (collegeStudent == NULL) {
        collegeStudent = new Student *[1];
        if (!collegeStudent) {
            return false;
        }
        numberStudents++;
        return true;
    }
    Student **temp;
    temp = new Student *[numberStudents + 1];
    if (!temp) {
        return false;
    }
    memcpy(temp, collegeStudent, sizeof(Student *) * numberStudents);
    delete[] collegeStudent;
    collegeStudent = temp;
    numberStudents++;
    return true;

}

College::College() {
    this->collegeStudent = NULL;

    numberStudents = 0;

}

College::~College()
{

    delete this->collegeStudent;
}

bool College::addStudent() {
    char bufferName[21];
    int type;
    long newId = 0;
    Student *studentToAdd = NULL;
    cout << "Pleas enter student ID" << endl;
    cin >> newId;
    for (int i = 0; i < numberStudents; i++) {
        if (newId == collegeStudent[i]->getId()) {
            return false;
        }
    }

    cout << " Enter new name " << endl;
    cin >> bufferName;
    cout << " Enter which student you " << endl <<
         "0 for student in mehina" << endl <<
         "1 for student bechalors" << endl <<
         "2 for master student" << endl;
    cin >> type;
    if (type == 0) {
        bool is_short;
        cout << "Enter 1 for short mehina or 0 for long mehina?" << endl;
        cin >> is_short;
        studentToAdd = new Student0(bufferName, newId, is_short);
    } else if (type == 1) {
        int yesrOfStudy = 0;
        cout << "Enter which year you study " << endl;
        cin >> yesrOfStudy;
        studentToAdd = new Student1(bufferName, newId, yesrOfStudy);

    } else if (type == 2) {
        char manheName[21], tizaName[21];
        cout << " Enter your manhe and tiza names" << endl;
        cout << "Manhe name: ";
        cin >> manheName;
        cout << endl << "Tiza name: ";
        cin >> tizaName;
        studentToAdd = new Student2(bufferName, newId, tizaName, manheName);
    }
    if (!expendStudentArray()) {
        return false;
    }
    collegeStudent[numberStudents - 1] = studentToAdd;
    return true;

}

bool College::addGrade() {
    char newCourse[21];
    int newGrade = 0;
    int newId = 0;
    char newLecture[21];
    Student1 *currentStudent;

    
    cout << "Pleas enter ID, course name,lecture name and your grade:  " << endl;
    
    cout << "ID: " << endl;
    cin >> newId;
    cout << "Course name: " << endl;
    cin >> newCourse;
    cout << "Lecture name: " << endl;
    cin >> newLecture;
    cout << "Grade: " << endl;
    cin >> newGrade;

    for (int i = 0; i < numberStudents; i++) {
        if (collegeStudent[i]->getId() == newId) {
            if (typeid(*collegeStudent[i]) == typeid(Student1)) {
                currentStudent = (Student1 *) collegeStudent[i];

            } else {
                return false;
            }

            for (int j = 0; j < currentStudent->courseCount; j++) {
                if (strcmp(currentStudent->studentCourse[j].name, newCourse) == 0) {
                    delete currentStudent->studentCourse[j].lecturer;
                    currentStudent->studentCourse[j].lecturer = new char[strlen(newLecture) + 1];
                    strcpy(currentStudent->studentCourse[j].lecturer, newLecture);
                    currentStudent->studentCourse[j].grade = newGrade;
                    return true;

                }

            }
            if (currentStudent->studentCourse == NULL) {
                currentStudent->studentCourse = new Course[1];
                if (!currentStudent->studentCourse) {
                    return false;
                }
                currentStudent->courseCount++;

            } else {
                Course *temp;
                temp = new Course[currentStudent->courseCount + 1];
                if (!temp) {
                    return false;
                }
               // memcpy(temp, currentStudent->studentCourse, sizeof(Course) * currentStudent->courseCount);
                for (int k = 0; k < currentStudent->courseCount; k++) {
                    temp[k] = currentStudent->studentCourse[k];



                }
                delete[] currentStudent->studentCourse;
                currentStudent->studentCourse = temp;
                currentStudent->courseCount++;

            }
            currentStudent->studentCourse[currentStudent->courseCount - 1] = Course(newCourse, newLecture, newGrade);
            return true;
        }


    }

}

void College::printAll() {
    for (int i = 0; i < numberStudents; i++) {

        collegeStudent[i]->print();
    }
}

void College::printExellent() {
    int count = 0;
    for (int i = 0; i < numberStudents; i++) {
        if (collegeStudent[i]->is_Excellent()) {
            
            count++;
        }
       
    }
    cout << count << " exellents students" << endl;
}

void College::findTypes(Student **stArr, int len, int &type0, int &type1, int &type2) {

    type0 = type1 = type2 = 0;
    for (int i = 0; i < len; i++) {
        if (typeid(*stArr[i]) == typeid(Student0))
            type0++;
        else if (typeid(*stArr[i]) == typeid(Student1))
            type1++;
        else if (typeid(*stArr[i]) == typeid(Student2))
            type2++;
    }
   
}


int College::supervisor() {
    char chekLectureName[21];

    cout << "Pleas enter name of lecture" << endl;
    cin >> chekLectureName;
    for (int i = 0; i < numberStudents; i++) {
        if (typeid(*collegeStudent[i]) == typeid(Student2)) {
            
            if (strcmp(chekLectureName, ((Student2*)collegeStudent[i])->supervisor)==0) {
                cout << collegeStudent[i]->name << '\n';

            }
        }


    }
    return 0;
}
void College::menu() {

    bool run = true;//do we want another iteration?
    int option;//the choosen option for the menu.
    while (run) {//while we still want to run:
        
        
        cout << endl;
        cout << "Please choose one of the following options:\n Press\n"
            << "----------------------------------------------------------------------"<<endl;
        cout << "1. Add student \n";
        cout << "2. Add grade\n";
        cout << "3. Print all\n";
        cout << "4. Print excellent\n";
        cout << "5. Types of student\n";
        cout << "6. Supervisor\n";
        cout << "7. Quit\n";
        cout << "Selection: " << endl << endl;
        cout<<"----------------------------------------------------------------------"<<endl;
        cin >> option;
        cout << endl;
        
            

            
            switch (option) {
            case 1:
                addStudent();
                
                break;
            case 2:
                addGrade();
                
                break;
            case 3:
                printAll();
                
                break;
            case 4:
                printExellent();
                
                break;
            case 5:
                int type0, type1, type2;

                findTypes(this->collegeStudent, this->numberStudents, type0, type1, type2);
                cout << type0 << " students in mehina" << endl;
                cout << type1 << " students in first toar" << endl;
                cout << type2 << " students in second toar" << endl;
                break;
            case 6:
                supervisor();
                
                break;
            case 7:
                run = false;
                cout << "Have a nice day!"<<endl;
                break;
            default:
                cout << "Wrong option. Please try again!"<<endl;

                break;
            }
       }
        system("pause");
        
    }

