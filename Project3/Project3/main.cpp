// Info Header
/*
Jeremy Davis
Project 3
SNHU CS-210
June 19, 2022

Item-Tracking Program
Takes a list of items purchased during a day (file)
Counts the number of items and provides an itemized list 

This program uses C++ and Python functions for data calculations

Program will produce different reports until user press 4
*/

#include <Python.h>
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

/*
Description:
To call this function, simply pass the function name in Python that you wish to call.
*/
void CallProcedure(string pName)
{
    char* procname = new char[pName.length() + 1];
    strcpy(procname, pName.c_str());

    Py_Initialize();
    PyObject* my_module = PyImport_ImportModule("PythonCode");
    PyErr_Print();

    PyObject* my_function = PyObject_GetAttrString(my_module, procname);
    PyObject* my_result = PyObject_CallObject(my_function, NULL);
    Py_Finalize();

    delete[] procname;
}

/*
Description:
    To call this function, pass the name of the Python function you wish to call and the string parameter you want to send
*/
int callIntFunc(string proc, string param)
{
    char* procname = new char[proc.length() + 1];
    strcpy(procname, proc.c_str());

    char* paramval = new char[param.length() + 1];
    strcpy(paramval, param.c_str());

    PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;

    // Initialize the Python Interpreter
    Py_Initialize();

    // Build the name object
    pName = PyUnicode_FromString((char*)"PythonCode");

    // Load the module object
    pModule = PyImport_Import(pName);

    // pDict is a borrowed reference 
    pDict = PyModule_GetDict(pModule);

    // pFunc is also a borrowed reference 
    pFunc = PyDict_GetItemString(pDict, procname);

    if (PyCallable_Check(pFunc)) {
        pValue = Py_BuildValue("(z)", paramval);
        PyErr_Print();
        presult = PyObject_CallObject(pFunc, pValue);
        PyErr_Print();
    } else {
        PyErr_Print();
    }

    //printf("Result is %d\n", _PyLong_AsInt(presult));
    Py_DECREF(pValue);

    // Clean up
    Py_DECREF(pModule);
    Py_DECREF(pName);

    // Finish the Python Interpreter
    Py_Finalize();

    // clean 
    delete[] procname;
    delete[] paramval;

    return _PyLong_AsInt(presult);
}

// Returns a string for the n number of times
string nCharString(int n, char c) {

    int i = 0;
    string userCharStr;

    // append character to string
    while (i < n) {
        userCharStr.push_back(c);
        i++;
    }
    // return the n character string
    return userCharStr;
}

// Returns a string for with capital letter rest lowercase
void toUpper(string& str) {
    if (str.length() == 0) {
        return;
    }

    transform(begin(str), end(str), begin(str), [](char const& c) {
        return tolower(c);
        });

    str[0] = toupper(str[0]);
}

// Prints application opening message
void printOpenTitle() {

    cout << "================================================================" << endl;
    cout << "=                                                              =" << endl;
    cout << "================================================================" << endl;
    cout << "------ > > > > > > >   CORNER    GROCER  < < < < < < < <  ------" << endl;
    cout << "================================================================" << endl;
    cout << "=                                                              =" << endl;
    cout << "=                                                              =" << endl;
    cout << "================================================================" << endl;
    cout << "=                                                              =" << endl;
    cout << "- - - - - - - -   ITEM - TRACKING   PROGRAM   - - - - - - - - - " << endl;
    cout << "=                                                              =" << endl;
    cout << "================================================================" << endl;
    cout << "=                                                              =" << endl;
    cout << "=                                                              =" << endl;
    cout << "=                                                              =" << endl;
    cout << "-/-/-/-/-/-/-/-         Jeremy   Davis         -/-/-/-/-/-/-/-/-" << endl;
    cout << "-------------------      SNHU CS-210        --------------------" << endl;
    cout << "=                                                              =" << endl;
    cout << "================================================================" << endl;

    cout << " " << endl;
    system("pause");
}

// Displays a list of options to user
void displayMenu() {

    cout << "============================================================================" << endl;
    cout << "=                                                                          =" << endl;
    cout << "=                                                                          =" << endl;
    cout << "=  1: Produce a list of all items purchased in a day                       =" << endl;
    cout << "=                                                                          =" << endl;
    cout << "=  2: Produce a number respresenting how many times an item was purchased  =" << endl;
    cout << "=                                                                          =" << endl;
    cout << "=  3: Produce a histogram listing all items purchased in a day             =" << endl;
    cout << "=                                                                          =" << endl;
    cout << "=  4: Exit the program                                                     =" << endl;
    cout << "=                                                                          =" << endl;
    cout << "=  Enter your selection as a number 1, 2, 3, 4.                            =" << endl;
    cout << "=                                                                          =" << endl;
    cout << "=                                                                          =" << endl;
    cout << "=                                                                          =" << endl;
    cout << "=                                                                          =" << endl;
    cout << "=                                                                          =" << endl;
    cout << "=                                                                          =" << endl;
    cout << "============================================================================" << endl;

}

// Function that executes the user's selections
void menuSelection() {
    int option = 0;
    string item;
    string item_qty;
    ifstream inFS;                          // declares input file stream
    string str1;                            // represents item
    int num1;                               // represents item qty
    vector<string> vec1(0);                 // declares empty vector
    vector<int> vec2(0);                    // declares empty vector
    int i = 0;
    int j = 0;

    do {
        system("CLS");
        displayMenu();

        // error checking and assigns integer to variable
        while (!(cin >> option))
        {
            cin.clear();
            while (cin.get() != '\n') continue;
            cout << "Invalid Value!  Try Again. " << endl;
        }


        switch (option) {
            // case 1 executes "Produce a list of all items purchased in a day"
            case 1:
            CallProcedure("ListItemsPurchased");                    // Calls function from Python file
            cout << " " << endl;
            system("pause");
            system("CLS");
            break;

            // case 2 executes "Produce a number respresenting how many times an item was purchased"
            case 2:
            system("CLS");
            cout << "Enter item name you are seeking... " << endl;
            cin >> item;
            toUpper(item);
            system("CLS");

            // calls Python function and C++ outputs the return value
            cout << item << " - purchased " << callIntFunc("FrequencyOfItem", item) << " times." << endl;
            cout << " " << endl;
            system("pause");
            system("CLS");
            break;

            // case 3 executes "Produce a histogram listing all items purchased in a day"
            case 3:
            system("CLS");

            CallProcedure("ItemHistogram");                         // Calls function from Python file

            inFS.open("frequency.dat");                             // opens an input stream to frequency.dat (reading from file)

            // sets error flag if unable to open input file
            if (!inFS.is_open()) {
                cout << "Could not open file." << endl;
            }

            vec1.clear();
            vec2.clear();

            // read file while end of input file is not true
            while (!inFS.eof() && inFS.good()) {
                inFS >> str1;                              // read first input as string
                inFS >> num1;                              // read next content as integer

                if (!inFS.fail()) {
                    vec1.push_back(str1);                  // appends str1 to vector 1
                    vec2.push_back(num1);                  // appends num1 to vector 2
                }
            }

            inFS.close();                                          // done reading file.  closing file    

            cout << "   Item Histogram \n" << endl;

            // prints a histogram for all the purchased items
            for (i = 0; i < vec1.size(); i++) {
                cout << setw(12) << left << vec1.at(i) << "|" << nCharString(vec2.at(i), '#') << endl;
            }

            cout << " " << endl;
            system("pause");
            system("CLS");
            break;
            }

    } while (option != 4);                                          // do - while loop to continue the actions inside while variable option is not 4

    system("CLS");
    cout << "You have exited the application." << endl;

}

// main to execute / trigger the program
void main() {

    printOpenTitle();

    menuSelection();
}