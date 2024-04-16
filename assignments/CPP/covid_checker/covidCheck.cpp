/*
Class: CSE 130 | programming in C and C++
Language: C++

Program discription: 
This program is a covid symptom checker. 
Print the following table that shows the symptoms for COVID-19, Cold, and Flu.
• Ask the user to enter the number of patients he/she wants to check.
• Generate Symptoms Randomly for each patient.
• Seven Symptoms: Each Symptom has value ["present", "absent"].
• After generating Symptoms randomly for all patients please check each patient if he/she
has COVID-19, Cold, or Flu.
• If the patient’s symptoms do not match with symptoms of COVID-19, Cold, or Flu then
he/she has other illness.
• A final report stating:
1. How many patients have COVID-19
2. How many patients have Cold
3. How many patients have Flu
4. How many patients have other illness
5. The percentage of each illness 


Guide: * Present + Present - NO
==============================================================
Symptoms | COVID-19 | Cold | Flu |
==============================================================
Fever | * | + | * |
Cough | * | + | * |
Shortness of Breath | * | - | - |
Runny Nose | + | * | + |
Headaches | + | + | * |
Sneezing | - | * | - |
Fatigue | + | + | * |
==============================================================

Enter the number of patients? 100
Thank you...
========================================
Symptoms Checker....
2 patients have symptoms of COVID-19
8 patients have symptoms of Cold
8 patients have symptoms of Flu
82 patients may have some other illness
========================================
Percentage of each illness:
COVID-19: [2%]++
Cold: [8%]++++++++
Flu: [8%]++++++++
Other illness:[82%]+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
+++++++++++++++++++


Author: Richard Douglas
Start date: 04/15/2024
Last edit: 04/15/2024
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// list of all symptoms
vector<string> allSymptoms = {"Fever", "Cough", "Shortness of Breath", "Runny Nose", "Headaches", "Sneezing", "Fatigue"};
vector<string> frequency = {"Present", "Present", "Present", "Absent"};
// using typename S to print elements of a vector. This was helpful for debugging.
template <typename S>
void print_vector(const vector<S>& vector,
                 string sep = ", "){
    int vectorSize = vector.size();
    // Iterating vector by using index
    if (vectorSize>0){
        cout << '[';
        for (int i = 0; i < vectorSize - 1; i++) {
            // Printing the element at index 'i' of vector
            cout << vector[i] << sep;
        };
        cout << vector[vectorSize-1] << ']' << endl;
    }else{
        cout << "[]" << endl;
    }
}

// class for symptom checker

class SymptomChecker{
    public:
    // function to check symptoms
    void checkSymptoms(vector<string>& vector);
    private:
    
};
void SymptomChecker::checkSymptoms(vector<string>& vector){

};

// class for patient
class Patient{
    public:
    // function to print symptoms
    void printSymptoms();
    // function to print diagnosis 
    void printDiagnosis();
    // function to get symptoms
    map<string, string> getSymptoms();
    // function to set symptoms
    void setSymptoms();
    string diagnosis;
    // vector of symptoms
    map <string, string> symptoms;
    string name;
    
};

void Patient::printSymptoms() {
    for(auto& [key, value] : symptoms){
        cout << key << ": " << value << endl;
    }
}

// function to reandomly set symptoms
void Patient :: setSymptoms(){
    int symptomFrequency;
    for(int i = 0; i < 7; i++){
        // random num mod 3 sets idx of frequency to assign to hash map...
        symptomFrequency = rand() % 4;
        symptoms[allSymptoms[i]] = frequency[symptomFrequency];    
    }
};

// function to access symptoms
map<string, string> Patient::getSymptoms() {
    return symptoms;
}

// Main function block
int main() {
    // hash map for covid 
    map<string, string> covidSymptoms;
    covidSymptoms["Fever"] = "Present";
    covidSymptoms["Cough"] = "Present";
    covidSymptoms["Shortness of Breath"] = "Present";
    covidSymptoms["Runny Nose"] = "Present";
    covidSymptoms["Headaches"] = "Present";
    covidSymptoms["Sneezing"] = "Absent";
    covidSymptoms["Fatigue"] = "Present";
    // hash map for cold
    map<string, string> coldSymptoms;
    coldSymptoms["Fever"] = "Present";
    coldSymptoms["Cough"] = "Present";
    coldSymptoms["Shortness of Breath"] = "Absent";
    coldSymptoms["Runny Nose"] = "Present";
    coldSymptoms["Headaches"] = "Present";
    coldSymptoms["Sneezing"] = "Present";
    coldSymptoms["Fatigue"] = "Present";
    // hash map for flu
    map<string, string> fluSymptoms;
    fluSymptoms["Fever"] = "Present"; //
    fluSymptoms["Cough"] = "Present"; //
    fluSymptoms["Shortness of Breath"] = "Absent";//
    fluSymptoms["Runny Nose"] = "Present";//
    fluSymptoms["Headaches"] = "Present";//
    fluSymptoms["Sneezing"] = "Absent";//
    fluSymptoms["Fatigue"] = "Present";//
    vector<Patient> patients;
    SymptomChecker symptomChecker;
    int fluCases = 0;
    int coldCases = 0;
    int covidCases = 0;
    int otherCases = 0;
    int numPatients;
    cout << "Enter the number of patients? ";
    cin >> numPatients;

    // loop to add patients with random symptoms (length according to numPatients value)
    for (int i = 0; i < numPatients; i++) {
        Patient newPatient;
        newPatient.setSymptoms();
        patients.push_back(newPatient);
    }
    
    for(int i = 0; i < numPatients; i++) {
        int diagnosis = 0;
        if (diagnosis == 0){  
            for(auto& [key, value] : covidSymptoms) {
                if(patients[i].symptoms[key] != value) {
                    diagnosis = 0;
                    break;}
                diagnosis = 1;
            }
        }
        if (diagnosis == 0){
            for(auto& [key, value] : coldSymptoms) {
                if(patients[i].symptoms[key] != value) {
                    diagnosis = 0;
                    break;}            
                diagnosis = 2;
            }
        }
        if (diagnosis == 0) {
            for(const auto& [key, value] : fluSymptoms) {
                if(patients[i].symptoms[key] != value) {
                    diagnosis = 0;
                    break;}
                diagnosis = 3;
            }           
        }
        switch(diagnosis){
            case 1:
                patients[i].diagnosis = "COVID-19";
                covidCases++;
                break;
            case 2:
                patients[i].diagnosis = "Cold";
                coldCases++;
                break;
            case 3:
                patients[i].diagnosis = "Flu";
                fluCases++;
                break;
            case 0:
                patients[i].diagnosis = "Other illness";
                otherCases++;
                break;
        }
    }
    double percentCovid = ((float)covidCases/(float)numPatients) * 100;
    double percentCold = ((float)coldCases/(float)numPatients) * 100;
    double percentFlu = ((float)fluCases/(float)numPatients) * 100;
    double percentOther = ((float)otherCases/(float)numPatients) * 100;
    /*
    ========================================
Symptoms Checker....
2 patients have symptoms of COVID-19
8 patients have symptoms of Cold
8 patients have symptoms of Flu
82 patients may have some other illness
========================================
Percentage of each illness:
COVID-19: [2%]++
Cold: [8%]++++++++
Flu: [8%]++++++++
Other illness:[82%]+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
+++++++++++++++++++
    */
    string covidMarks(covidCases, '+');
    string coldMarks(coldCases, '+');
    string fluMarks(fluCases, '+');
    string otherMarks(otherCases, '+');
    cout << "Symptoms Checker...." << endl;
    cout << covidCases << " patients have symptoms of COVID-19" << endl;
    cout << coldCases << " patients have symptoms of Cold" << endl;
    cout << fluCases << " patients have symptoms of Flu" << endl;
    cout << otherCases << " patients may have some other illness" << endl;
    cout << "========================================" << endl;
    cout << "Percentage of each illness:" << endl;
    cout << "COVID-19: [" << percentCovid << "%]" << covidMarks << endl;
    cout << "Cold: [" << percentCold << "%]" << coldMarks << endl;
    cout << "Flu: [" << percentFlu << "%]" << fluMarks << endl;
    cout << "Other illness:[" << percentOther << "%]" << otherMarks << endl;

    // patients[0].printSymptoms();
    
    return 0;
}

