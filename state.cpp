
/************************************************** Description *******************************************************/
/*
    File : State.cpp
    Programmer : Mohammad Lotfi
    Used : Sample used State
    Design Pattern : State
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
class State {
	public:
		virtual ~State() {}
		virtual void handle() = 0;
};
/*--------------------------------------------------------------------------------------------------------------------*/
class ConcreteStateA : public State {
	public:
		void handle() override {
			cout << "ConcreteStateA::handle() called" << endl;
		}
};
/*--------------------------------------------------------------------------------------------------------------------*/
class ConcreteStateB : public State {
	public:
		void handle() override {
			cout << "ConcreteStateB::handle() called" << endl;
		}
};
/*--------------------------------------------------------------------------------------------------------------------*/
class Context {
	public:
		Context(State* initialState) {
			this->state = initialState;
		}
		~Context() {
			delete state;
		}
		void setState(State* state) {
			delete this->state;
			this->state = state;
		}
		void request() {
			state->handle();
		}
	private:
		State* state;
};
/************************************************** Functions *********************************************************/
/* The main function start of program in cpp language */
int main() {

    ConcreteStateA stateA;
    ConcreteStateB stateB;
    Context context(&stateA);
    context.request();
    context.setState(&stateB);
    context.request();

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