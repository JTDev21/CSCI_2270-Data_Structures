#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

struct studentData {
    std::string studentName;
    int homework;
    int recitation;
    int quiz;
    int exam;
    double average;
};

char calcLetter(double avg)
{
    char letter;
    if(avg >= 90)
    {
        letter = 'A';
    }
    else if(80 <= avg && avg <= 89.9)
    {
        letter = 'B';
    }
    else if(70 <= avg && avg <= 79.9)
    {
        letter = 'C';
    }
    else if(60 <= avg && avg <= 69.9)
    {
        letter = 'D';
    }
    else if(avg <= 60)
    {
        letter = 'F';
    }
    return letter;
}

void printList(const studentData students[], int length)
{
    for(int i = 0; i < length; i++)
    {
        std::cout << students[i].studentName << " earned " << students[i].average << " which is an " << calcLetter(students[i].average) << std::endl;
    }
}

void addStudentData(studentData students[], std::string studentName, int homework, int recitation, int quiz, int exam, int length)
{
    students[length].studentName = studentName;
    students[length].homework = homework;
    students[length].recitation = recitation;
    students[length].quiz = quiz;
    students[length].exam = exam;
    students[length].average = (homework + recitation + quiz + exam) / 4.0;
}

int main(int argc, char* argv[])
{
    std::string filename = argv[1];
    std::string output_filename = argv[2];
    std::string lowerBound_Letter = argv[3];
    std::string upperBound_Letter = argv[4];

    std::ifstream myFile;
    myFile.open(filename);
    if(!myFile.is_open())
    {
        std::cout << "Failed to open the file." << std::endl;
    }

    std::string line, column;
    std::string data[5];

    int length = 0;
    studentData students[10];

    while(std::getline(myFile, line))
    {
        std::stringstream strm(line);
        if(!line.empty())
        {
            int i = 0;
            std::string data[5];
            while(std::getline(strm, column, ','))
            {
                data[i] = column;
                i++;
            }
            std::string studentName = data[0];
            int homework = std::stoi(data[1]);
            int recitation = std::stoi(data[2]);
            int quiz = std::stoi(data[3]);
            int exam = std::stoi(data[4]);

            addStudentData(students, studentName, homework, recitation, quiz, exam, length);
            length++;
        }
    }
    printList(students, length);
    myFile.close();

    std::ofstream w_file;
    w_file.open(output_filename);
    for(int i = 0; i < length; i++)
    {
        char letterGrade = calcLetter(students[i].average);

        if((int)upperBound_Letter[0] <= (int)letterGrade && (int)letterGrade <= (int)lowerBound_Letter[0])
        {
            w_file << students[i].studentName << "," << students[i].average << "," << letterGrade << std::endl;
        }
    }
    w_file.close();
    return 0;
}