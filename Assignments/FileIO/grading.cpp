/*
Programmer: Ben Himes
Course: CSCI 111
Assignment: A Gradebook Program Using Structure and File IO
File: main.cpp

Program Description:
This program reads student grade records from an input text file,
computes each student's average test score and letter grade,
sorts students in descending order by average,
and writes a formatted report to an output text file.
It also calculates class statistics such as max, min, class average,
and percentages of letter grades.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student
{
    string firstName;
    string lastName;
    double test1;
    double test2;
    double test3;
    double test4;
    double average;
    char letterGrade;
};

/*
Algorithm:
1. Prompt the user for the input file name.
2. Open the input file.
3. Read student records into a vector of Student structures.
4. For each student:
   a. Compute the average of 4 test scores.
   b. Determine the letter grade based on the average.
5. Sort the students in descending order by average score.
6. Prompt the user for the output file name.
7. Open the output file.
8. Write a formatted report of all students to the output file.
9. Calculate class statistics:
   a. maximum average
   b. minimum average
   c. class average
   d. percentages of A, B, C, D, and F grades
10. Write the statistics to the output file.
11. Close all files.
*/

double calculateAverage(const Student& s)
{
    return (s.test1 + s.test2 + s.test3 + s.test4) / 4.0;
}

char calculateLetterGrade(double average)
{
    if (average >= 90.0)
        return 'A';
    else if (average >= 80.0)
        return 'B';
    else if (average >= 70.0)
        return 'C';
    else if (average >= 60.0)
        return 'D';
    else
        return 'F';
}

void computeStudentResults(Student& s)
{
    s.average = calculateAverage(s);
    s.letterGrade = calculateLetterGrade(s.average);
}

bool compareByAverageDescending(const Student& a, const Student& b)
{
    return a.average > b.average;
}

double findClassAverage(const vector<Student>& students)
{
    if (students.empty())
        return 0.0;

    double sum = 0.0;
    for (const Student& s : students)
        sum += s.average;

    return sum / students.size();
}

double findMaxAverage(const vector<Student>& students)
{
    if (students.empty())
        return 0.0;

    double maxAvg = students[0].average;
    for (const Student& s : students)
    {
        if (s.average > maxAvg)
            maxAvg = s.average;
    }

    return maxAvg;
}

double findMinAverage(const vector<Student>& students)
{
    if (students.empty())
        return 0.0;

    double minAvg = students[0].average;
    for (const Student& s : students)
    {
        if (s.average < minAvg)
            minAvg = s.average;
    }

    return minAvg;
}

void countLetterGrades(const vector<Student>& students,
                       int& countA, int& countB, int& countC, int& countD, int& countF)
{
    countA = countB = countC = countD = countF = 0;

    for (const Student& s : students)
    {
        switch (s.letterGrade)
        {
            case 'A': countA++; break;
            case 'B': countB++; break;
            case 'C': countC++; break;
            case 'D': countD++; break;
            case 'F': countF++; break;
        }
    }
}

double percentage(int count, int total)
{
    if (total == 0)
        return 0.0;

    return (static_cast<double>(count) / total) * 100.0;
}

int main()
{
    string inputFileName;
    string outputFileName;

    cout << "Enter input file name: ";
    cin >> inputFileName;

    ifstream inFile(inputFileName);

    if (!inFile)
    {
        cout << "Error: Could not open input file.\n";
        return 1;
    }

    vector<Student> students;
    Student temp;

    while (inFile >> temp.firstName >> temp.lastName
                  >> temp.test1 >> temp.test2 >> temp.test3 >> temp.test4)
    {
        computeStudentResults(temp);
        students.push_back(temp);

        if (students.size() >= 50)
            break;
    }

    inFile.close();

    sort(students.begin(), students.end(), compareByAverageDescending);

    cout << "Enter output file name: ";
    cin >> outputFileName;

    ofstream outFile(outputFileName);

    if (!outFile)
    {
        cout << "Error: Could not open output file.\n";
        return 1;
    }

    outFile << fixed << setprecision(2);

    outFile << "GRADE REPORT\n";
    outFile << "===============================================================\n";
    outFile << left
            << setw(15) << "First Name"
            << setw(15) << "Last Name"
            << setw(8)  << "Test1"
            << setw(8)  << "Test2"
            << setw(8)  << "Test3"
            << setw(8)  << "Test4"
            << setw(10) << "Average"
            << setw(8)  << "Grade" << '\n';
    outFile << "===============================================================\n";

    for (const Student& s : students)
    {
        outFile << left
                << setw(15) << s.firstName
                << setw(15) << s.lastName
                << setw(8)  << s.test1
                << setw(8)  << s.test2
                << setw(8)  << s.test3
                << setw(8)  << s.test4
                << setw(10) << s.average
                << setw(8)  << s.letterGrade << '\n';
    }

    double classAvg = findClassAverage(students);
    double maxAvg = findMaxAverage(students);
    double minAvg = findMinAverage(students);

    int countA, countB, countC, countD, countF;
    countLetterGrades(students, countA, countB, countC, countD, countF);

    int total = static_cast<int>(students.size());

    outFile << "\nCLASS STATISTICS\n";
    outFile << "===============================================================\n";
    outFile << "Number of students: " << total << '\n';
    outFile << "Class average:      " << classAvg << '\n';
    outFile << "Highest average:    " << maxAvg << '\n';
    outFile << "Lowest average:     " << minAvg << '\n';
    outFile << '\n';

    outFile << "Letter Grade Distribution\n";
    outFile << "---------------------------------------------------------------\n";
    outFile << "A: " << countA << " (" << percentage(countA, total) << "%)\n";
    outFile << "B: " << countB << " (" << percentage(countB, total) << "%)\n";
    outFile << "C: " << countC << " (" << percentage(countC, total) << "%)\n";
    outFile << "D: " << countD << " (" << percentage(countD, total) << "%)\n";
    outFile << "F: " << countF << " (" << percentage(countF, total) << "%)\n";

    outFile.close();

    cout << "Report written successfully to " << outputFileName << '\n';

    return 0;
}