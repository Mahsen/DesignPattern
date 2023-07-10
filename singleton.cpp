
/************************************************** Description *******************************************************/
/*
    File : singleton.cpp
    Programmer : Mohammad Lotfi
    Used : Sample used Chain of Responsibility
    Design Pattern : Chain of Responsibility
    Types of memory : Heap & Stack
    Total Tread : Nothing
    Site : https://www.mahsen.ir
    Tel : +989124662703
    Email : info@mahsen.ir
    Last Update : 2023/7/10
*/
/************************************************** Warnings **********************************************************/
/*
    Only for learning
*/
/************************************************** Wizards ***********************************************************/
/*
    Nothing
*/
/************************************************** Includes **********************************************************/
/* Include standard input-output stream head */
#include "iostream"
/* Vector of everything head */
#include "vector"
/************************************************** Defineds **********************************************************/
/*
    Nothing
*/
/************************************************** Names *************************************************************/
/* Using std */
using namespace std;
/************************************************** Variables *********************************************************/
/*
    Nothing
*/
/************************************************** Opjects ***********************************************************/
class PrinterManager {
    private: static PrinterManager *Instance;
    private: int Used;
    private: PrinterManager() {
        Used = 1;
    }
    public: static PrinterManager* getInstance() {
        if(Instance == nullptr) {
            Instance = new PrinterManager();
            cout << "Create Instance" << endl;
        }
        else {
            cout << "Get Instance" << endl;
        }
        
        return Instance;
    }
    void Print(auto Value) {
        cout << "Used=" << Used++ << " -> " << Value << endl;
    }    
};
PrinterManager* PrinterManager::Instance = nullptr;
/************************************************** Functions *********************************************************/
/* The main function start of program in cpp language */
int main() {

    PrinterManager *Obj_1 = PrinterManager::getInstance();
    Obj_1->Print("Hi Printer");

    PrinterManager *Obj_2 = PrinterManager::getInstance();
    Obj_2->Print(1.25);

    PrinterManager *Obj_3 = PrinterManager::getInstance();
    Obj_3->Print("Bye Printer");

    return 0;
}
/************************************************** Tasks *************************************************************/
/*
    Nothing
*/
/************************************************** Vectors ***********************************************************/
/*
    Nothing
*/
/**********************************************************************************************************************/
