#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;
string numberToWords(int num) {
   if (num == 0) {
       return "zero";
   }

   vector<string> ones = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
   vector<string> tens = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
   vector<string> thousands = {"", "thousand", "million"};

   string result = "";

   if (num >= 1000000) {
       // Handle millions
       int millionsDigit = num / 1000000;
       result += numberToWords(millionsDigit) + " " + thousands[2] + " ";
       num %= 1000000;
   }

   if (num >= 1000) {
       int thousandsDigit = num / 1000;
       result += numberToWords(thousandsDigit) + " " + thousands[1] + " ";
       num %= 1000;
   }

   if (num >= 100) {
       int hundreds = num / 100;
       result += ones[hundreds] + " hundred ";
       num %= 100;
   }

   if (num >= 20) {
       int tensDigit = num / 10;
       result += tens[tensDigit];
       num %= 10;
   }

   if (num > 0) {
       result += ones[num];
   }

   return result;
}

int main()
{
    int n;
    float percentage;
    //student detail's '
    string studentname, rollno;
    cout << "Enter student name : ";
    cin >> studentname;
    cout << "Enter roll number : ";
    cin >> rollno;
    //subject details
    cout << "Enter total number of subjects : ";
    cin >> n;
    string subjectname[n];
    float subjectmarks[n], subjecttotals[n], totalmarks;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the name of the subject " << i + 1 << " and marks obtained : ";
        cin >> subjectname[i] >> subjectmarks[i];
        cout << "Enter total marks " << subjectname[i] << ": ";
        cin >> subjecttotals[i];
        totalmarks += subjecttotals[i];
    }
    //result
    float overallmarks = 0;
    for (int i = 0; i < n; i++)
    {
        overallmarks += subjectmarks[i];
    }
    percentage = (overallmarks * 100 / totalmarks);
    cout << "Student Name: " << studentname << endl;
    cout << "Roll Number: " << rollno << endl;
    cout << "Subject     | Total Marks | Marks Obtained | Percentage | Grade" << endl;
    cout << "------------| ----------- | ------------- | ---------- | ------" << endl;
    //grading
    for (int i = 0; i < n; i++)
    {
        float subjectpercentage = (subjectmarks[i] * 100 / subjecttotals[i]);
        string grade;
        grade = (subjectpercentage > 90 ? "A+" : subjectpercentage > 80 ? "A" : subjectpercentage > 70 ? "B+" : subjectpercentage > 60 ? "B" : subjectpercentage > 50 ? "C+" : subjectpercentage > 40 ? "C" : subjectpercentage > 35 ? "C" : "Fail");

        cout << subjectname[i] << " | " << subjecttotals[i] << " | " << subjectmarks[i] << " | " << fixed << setprecision(2) << subjectpercentage << "% | " << grade << endl;
    }
    //obtained marks and percentage calculation
    cout << " Marks obtained : " << overallmarks << "/" << totalmarks << endl;
    cout << "Percentage: " << fixed << setprecision(2) << percentage << "%" << endl;

    string percentage_grade;
    percentage_grade = (percentage > 90 ?"Your Percentage Grade is A+" : percentage > 80 ? "Your Percentage Grade is A" : percentage > 70 ? "Your Percentage Grade is B+" : percentage > 60 ? "Your Percentage Grade is B" : percentage > 50 ? "Your Percentage Grade is C+" :percentage  > 40 ? "Your Percentage Grade is C" : percentage > 35 ? "Your Percentage Grade is C" : "What's wrong with you");
    
    
    int markso = overallmarks;
    string wordso = numberToWords(markso); // words will now hold "eighty five"

    int markst = totalmarks;
    string wordst = numberToWords(markst); // words will now hold "eighty five"

    cout << "Your Student " << studentname << " has scored " << wordso << " out of " << wordst << endl;

    return 0;
}
