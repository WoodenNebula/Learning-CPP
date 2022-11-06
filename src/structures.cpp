#include <iostream>

struct Student{
public:
    int rollNo, grade;
    const char* name;

    Student(int rollNo, const char * name, int grade)
        :rollNo(rollNo), name(name), grade(grade)
    {
    }
};

void Log(Student* student)
{
    std::cout << "Roll No. "<< student->rollNo << ", "
        << student->name << " of Grade " << student->grade << '\n'; 
}

int main()
{
    Student somin(1, "Somin Upadhayaya", 12) , surab(2, "Surab Parajuli", 12), oscar(3, "Oscar Thapa", 12);
    Student *grade12[] = {&somin, &surab, &oscar};

    for(int i = 0; i < 3; i++)
        Log(grade12[i]);
}