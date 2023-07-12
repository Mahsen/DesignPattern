
/************************************************** Description *******************************************************/
/*
    File : visitor.cpp
    Programmer : Mohammad Lotfi
    Used : Sample used visitor
    Design Pattern : visitor
    Types of memory : Heap & Stack
    Total Tread : Nothing
    Site : https://www.mahsen.ir
    Tel : +989124662703
    Email : info@mahsen.ir
    Last Update : 2023/7/12
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
#include <vector>
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
class Visitor;
/*--------------------------------------------------------------------------------------------------------------------*/
class Element {
	public:
		virtual ~Element() {}
		virtual void accept(Visitor& visitor) = 0;
};
/*--------------------------------------------------------------------------------------------------------------------*/
class ConcreteElementA : public Element {
	public:
		void accept(Visitor& visitor) override;
		void operationA() { cout << "ConcreteElementA::operationA() called" << endl; }
};
/*--------------------------------------------------------------------------------------------------------------------*/
class ConcreteElementB : public Element {
	public:
		void accept(Visitor& visitor) override;
		void operationB() { cout << "ConcreteElementB::operationB() called" << endl; }
};
/*--------------------------------------------------------------------------------------------------------------------*/
class Visitor {
	public:
		virtual ~Visitor() {}
		virtual void visitConcreteElementA(ConcreteElementA& element) = 0;
		virtual void visitConcreteElementB(ConcreteElementB& element) = 0;
};
/*--------------------------------------------------------------------------------------------------------------------*/
class ConcreteVisitor1 : public Visitor {
	public:
		void visitConcreteElementA(ConcreteElementA& element) override {
			cout << "ConcreteVisitor1 visited ConcreteElementA" << endl;
			element.operationA();
		}
		void visitConcreteElementB(ConcreteElementB& element) override {
			cout << "ConcreteVisitor1 visited ConcreteElementB" << endl;
			element.operationB();
		}
};
/*--------------------------------------------------------------------------------------------------------------------*/
class ConcreteVisitor2 : public Visitor {
	public:
		void visitConcreteElementA(ConcreteElementA& element) override {
			cout << "ConcreteVisitor2 visited ConcreteElementA" << endl;
			element.operationA();
		}
		void visitConcreteElementB(ConcreteElementB& element) override {
			cout << "ConcreteVisitor2 visited ConcreteElementB" << endl;
			element.operationB();
		}
};
/*--------------------------------------------------------------------------------------------------------------------*/
class ObjectStructure {
	public:
		void attach(Element* element) {
			elements.push_back(element);
		}
		void detach(Element* element) {
			elements.erase(remove(elements.begin(), elements.end(), element), elements.end());
		}
		void accept(Visitor& visitor) {
			for (Element* element : elements) {
				element->accept(visitor);
			}
		}
	private:
		vector<Element*> elements;
};
/*--------------------------------------------------------------------------------------------------------------------*/
void ConcreteElementA::accept(Visitor& visitor) {
    visitor.visitConcreteElementA(*this);
}
/*--------------------------------------------------------------------------------------------------------------------*/
void ConcreteElementB::accept(Visitor& visitor) {
    visitor.visitConcreteElementB(*this);
}
/************************************************** Functions *********************************************************/
/* The main function start of program in cpp language */
int main() {
	
    ObjectStructure objectStructure;
    objectStructure.attach(new ConcreteElementA());
    objectStructure.attach(new ConcreteElementB());

    ConcreteVisitor1 concreteVisitor1;
    objectStructure.accept(concreteVisitor1);

    ConcreteVisitor2 concreteVisitor2;
    objectStructure.accept(concreteVisitor2);

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