/*
Author: Zakaria Rahman
Date: November 9th, 2025
Description: This program collects user inputs and validates if they enter the correct input.
             Also, it demonstrates file handling by writing to a file. Additionally, it shows the usage 
             of selection statements like if else statements and switch case statements. Furthermore, 
             it also demonstrates the use of repetition structures such as the for loop, do...while loop,
             and while loop.
Course: ITCS 2530 (C++ Programming 1)
*/

// header files
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // Welcome Message
    cout << left << setfill('-') << setw(133) << "" << endl;
    cout << "Welcome to the Math Aptitude Analyzer! Let's see how confident you are with math."
    << " Please enter the following information as prompted." << endl;;
    cout << left << setfill('-') << setw(133) << "" << endl << endl;


    // Declare Variables and Initializing some of them
    string name;
    string favoriteMathSubject;
    int problemsSolvedPerWeek= 0;
    int confidenceLevel = 0;
    double hoursSpentStudyingPerWeek = 1.0;
    double estimatedProblemsPerHour = 0.0;

    // variables for switch case and if/else demonstration and loops
    int result = 0;
    int userAnswer;
    int noOfCorrectAnswers = 0;
    char grade;
    int testScore;

    int randomNum1;
    int randomNum2;
    char userChoiceMathOperator;

    string studentLastName;
    string studentID;
    string reportCardFeedback;
    char teacherChoiceContinue;

    // File handling
    ofstream outputFile;
    ofstream outputReportFile;
    
    // Prompts for user inputs
    cout << "Enter your full name: ";
    getline(cin, name);
    cout << endl;

    cout << "Enter your favorite Math subject: ";
    getline(cin, favoriteMathSubject); 
    cout << endl;


    cout << "Enter number of Math Problems you solved per week : ";
    // Input Validation and using while loop for entering again
    while (!(cin >> problemsSolvedPerWeek)){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter a whole number: " << endl;
    }
    cout << endl;

    cout << "On a scale of 1 to 10, how confident are you in Math? (1 being least and 10 being most): ";
    // Input Validation
    if (!(cin >> confidenceLevel)){
        cout << "\nInvalid input. Please restart/re-run the program with correct data type for input." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cout << endl;

    cout << "Enter number of hours you spend studying Math per week: ";
    // Input Validation
    if (!(cin >> hoursSpentStudyingPerWeek)){
        cout << "\nInvalid input. Please restart/re-run the program with correct data type for input." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cout << endl;

    // Calculations
    estimatedProblemsPerHour = static_cast<double> (problemsSolvedPerWeek) / hoursSpentStudyingPerWeek;

    cout << endl;

    // 5 questions quiz to evaluate user's basic math knowledge
    cout << "Please answer this following math problems: \n" << endl;

    // Seeding the random number generator once
    srand(time(0));

    for (int i = 1; i <= 5; i++){
        randomNum1 = (rand() % 100) + 1;
        randomNum2 = (rand() % 100) + 1;

        cout << "Enter a math operator (+, -, *, / or %):  ";
        cin >> userChoiceMathOperator;
        cout << endl;

        // Validating user input
        // Letting the user enter correct math operator 

        switch(userChoiceMathOperator) {
            case '+':
            result = randomNum1 + randomNum2;
            break;
        case '-':
            result = randomNum1 - randomNum2;
            break;
        case '*':
            result =randomNum1 * randomNum2;
            break;
        case '/':
            result = randomNum1 / randomNum2;
            break;
        case '%':
            result = randomNum1 % randomNum2;
            break;
        default:
            cout << "Invalid Operator. Moving to the next iteration." << endl;
            continue;
        }

        cout << randomNum1 << " " << userChoiceMathOperator << " " << randomNum2 << " = ";
        cin >> userAnswer;
        cout << endl;

        if (userAnswer == result) {
            cout << "Correct! Well Done!" << endl;
            noOfCorrectAnswers++;
        } else {
            cout << "Wrong Answer! Nice Try!" << endl;
        }

        cout << endl;

    }

    cout << endl;
    cout << "----- Quiz Feedback -----\n" << endl;

    // Using if/else blocks with compound boolean conditions
    if (noOfCorrectAnswers >= 4 && confidenceLevel >= 7) {
        cout << "Great! Your confidence matches your performance." << endl;
        cout << "You can try more advance problems!" << endl;
    }
    else if (noOfCorrectAnswers >= 3 && confidenceLevel >= 5) {
        cout << "Good work! Keep on practicing to improve." << endl;
        cout << "Solving more problems increases your confidence level." << endl;
    }
    else if (noOfCorrectAnswers >= 3 && confidenceLevel < 5) {
        cout << "Your performance is okay, but your confidence is low." << endl;
        cout << "Focus on building your confidence through consistent practice." << endl;
    }
    else if (noOfCorrectAnswers < 3 && confidenceLevel >=5) {
        cout << "You feel confident, but your performance shows the opposite." << endl;
        cout << "Practice fundamental concepts to match your confidence level." << endl;
    }
    else{
        cout << "Focus on basic concepts and fundamentals of Math." << endl;
        cout << "Practice regularly to improve your skills and confidence level." << endl;
    }

    cout << endl;
    
    // Building a report card for students from their teacher

    cout << "----- Building a report card for student -----" << endl;
    cout << endl;
    outputReportFile.open("StudentsReportCard.txt");


    if (!outputReportFile.is_open()){
        cout << "Error opening the file." << endl;
        return -1;
    }

    do {
        cout << "Enter student's last name: ";
        cin >> studentLastName;
        cout << endl;

        cout << "Enter student's ID number: ";
        cin >> studentID;
        cout << endl;

        cout << "Please enter the student's grade (A, B, C, D, E): ";
        cin >> grade;
        cout << endl;

        cout << "Please enter the student's last test score: ";
        cin >> testScore;
        cout << endl;

        if (grade == 'A' || testScore >= 90){
            reportCardFeedback = "Excellent work! Keep up the high performance.";
        }
        else if (grade == 'B' || testScore >= 80){
            reportCardFeedback = "Good job! You are doing well, but there is room for improvement.";
        }
        else if (grade == 'C' || testScore >= 70) {
            reportCardFeedback = "Fair performance. Focus on improving weaker areas.";
        }
        else {
            reportCardFeedback = "Needs improvement. Consider extra practice and studying.";
        }  

        outputReportFile << left << setw(15) << studentLastName << setw(15) << studentID << right << setw(5) << grade << setw(8) << testScore << right << setw(90) << reportCardFeedback << endl;

        cout << "Please, enter 'N' or 'n' to quit, any other key to continue: ";
        cin >> teacherChoiceContinue;
        cout << endl;
        
    } while (teacherChoiceContinue != 'N' && teacherChoiceContinue != 'n');

    outputReportFile.close();

    // Opening the output file
    outputFile.open("report.txt");
    if (!outputFile.is_open()){
        cout << "Error opening the file." << endl;
        return -1;
    }

    // Writing to the output file with different formatting styles
    outputFile << fixed << showpoint << setprecision(2);

    outputFile << left << setfill(' ') << setw(50) << "Name:" << right << setw(20) << setfill(' ') << name << endl;
    outputFile << left << setfill(' ') << setw(50) << "Favorite Math Subject:" << right << setw(20) << setfill(' ') << favoriteMathSubject << endl;
    outputFile << left << setfill(' ') << setw(50) << "Confidence Level:" << right << setw(20) << setfill(' ') << confidenceLevel << endl;
    outputFile << left << setfill(' ') << setw(50) << "# of Hours Studying Math:" << right << setw(20) << setfill(' ') << hoursSpentStudyingPerWeek << endl;
    outputFile << left << setfill(' ') << setw(50) << "Estimated Problems Solved Per Hour:" << right << setw(20) << setfill(' ') << estimatedProblemsPerHour << endl;

    outputFile.close();


    return 0;
}
