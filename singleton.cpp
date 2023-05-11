#include <iostream>

using namespace std;

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

int main() {

    PrinterManager *Obj_1 = PrinterManager::getInstance();
    Obj_1->Print("Hi Printer");

    PrinterManager *Obj_2 = PrinterManager::getInstance();
    Obj_2->Print(1.25);

    PrinterManager *Obj_3 = PrinterManager::getInstance();
    Obj_3->Print("Bye Printer");

    return 0;
}
