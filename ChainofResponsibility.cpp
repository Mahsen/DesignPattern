
/************************************************** Description *******************************************************/
/*
    File : ChainofResponsibility.cpp
    Programmer : Mohammad Lotfi
    Used : Sample used Chain of Responsibility
    Design Pattern : Chain of Responsibility
    Types of memory : Heap & Stack
    Total Tread : Nothing
    Site : https://www.mahsen.ir
    Tel : +989124662703
    Email : info@mahsen.ir
    Last Update : 2023/6/6
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
class Handler {
private:
    Handler* successor;
public:
    Handler() {
        successor = nullptr;
    }
    void setSuccessor(Handler* successor) {
        this->successor = successor;
    }
    virtual void handleRequest(int request) {
        if (successor != nullptr) {
            successor->handleRequest(request);
        }
    }
};
/*--------------------------------------------------------------------------------------------------------------------*/
class ConcreteHandler1 : public Handler {
public:
    void handleRequest(int request) override {
        if (request >= 0 && request < 10) {
            std::cout << "ConcreteHandler1 handled the request." << std::endl;
        } else {
            Handler::handleRequest(request);
        }
    }
};
/*--------------------------------------------------------------------------------------------------------------------*/
class ConcreteHandler2 : public Handler {
public:
    void handleRequest(int request) override {
        if (request >= 10 && request < 20) {
            std::cout << "ConcreteHandler2 handled the request." << std::endl;
        } else {
            Handler::handleRequest(request);
        }
    }
};
/*--------------------------------------------------------------------------------------------------------------------*/
class ConcreteHandler3 : public Handler {
public:
    void handleRequest(int request) override {
        if (request >= 20 && request < 30) {
            std::cout << "ConcreteHandler3 handled the request." << std::endl;
        } else {
            Handler::handleRequest(request);
        }
    }
};
/************************************************** Functions *********************************************************/
/* The main function start of program in cpp language */
int main() {
    
    ConcreteHandler1 concrete_handler1;
    ConcreteHandler2 concrete_handler2;
    ConcreteHandler3 concrete_handler3;

    concrete_handler1.setSuccessor(&concrete_handler2);
    concrete_handler2.setSuccessor(&concrete_handler3);

    concrete_handler1.handleRequest(5);
    concrete_handler1.handleRequest(15);
    concrete_handler1.handleRequest(25);
    concrete_handler1.handleRequest(35);

    /* Return successful*/
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
