
/************************************************** Description *******************************************************/
/*
    File : flyweight.cpp
    Programmer : Mohammad Lotfi
    Used : Sample used observer
    Design Pattern : FlyWeight
    Types of memory : Heap & Stack
    Total Tread : Nothing
    Site : https://www.mahsen.ir
    Tel : +989124662703
    Email : info@mahsen.ir
    Last Update : 2023/5/24
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
#include <map>
#include <string>
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
// Instances of Tenant will be the Flyweights
class Tenant {
public:
    Tenant(const int& number = 0) : m_number(number) {}

    int number() const {
        return m_number;
    }

private:
    int m_number;
};
/*--------------------------------------------------------------------------------------------------------------------*/
// Registry acts as a factory and cache for Tenant flyweight objects
class Registry {
public:
    Tenant& findBynumber(const int& number) {
        if (!tenants.count(number)) {
            tenants[number] = Tenant{number};
        }
        return tenants[number];
    }

map<int, Tenant> tenants;
private:
    
};
/*--------------------------------------------------------------------------------------------------------------------*/
// Apartment maps a unique tenant to their name number.
class Apartment {
public:
    void addOccupant(const string& name, const int& number) {
        m_occupants[name] = &m_registry.findBynumber(number);
    }

    void printTenants() {
        for (const auto& entry : m_occupants) {
            const auto name = entry.first;
            const auto* tenant = entry.second;
            cout << name  << " was " << tenant->number() << endl;
        }
    }

    map<const string, const Tenant*> m_occupants;
    Registry m_registry;
private:
    
};
/************************************************** Functions *********************************************************/
/* The main function start of program in cpp language */
int main() {
    
    Apartment apartment;

    apartment.addOccupant("Mohammad", 20);
    apartment.addOccupant("Ali", 5);
    apartment.addOccupant("Sara", 2);
    apartment.addOccupant("Davood", 20);
    apartment.addOccupant("Mahdi", 10);
    apartment.addOccupant("Mojtaba", 4);
    apartment.addOccupant("Abbas", 9);
    apartment.addOccupant("Zohre", 4);
    apartment.addOccupant("Tina", 2);
    apartment.addOccupant("Arman", 10);
    apartment.printTenants();

    cout << endl << "Size of memory = " << apartment.m_registry.tenants.size() << endl;

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
