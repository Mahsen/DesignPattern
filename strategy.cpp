#include "iostream"

using namespace std;

class Status {

    public:

        enum class Messege {
            Success,
            Fault,
            Fault_Media
        };

        void SetMessege(Messege _Messege) {
            this->_Messege = _Messege;
        }

        Messege GetMessege() {
            return _Messege;
        }

        void ShowMessege() {
            cout << "Messege : " << Messege2String[(int)this->_Messege] << endl;
        }

    private:
        const string Messege2String[3] = {"Success", "Fault", "Fault_Media"};
        Messege _Messege;
};

class Media {    
    public: 
        virtual Status* Send(string Messege, uint32_t Length) = 0;
        virtual Status* Receive(string *Messege, uint32_t *Length) = 0;
};

class RS485 : public Media {    
    private: 
        static RS485 *Instance;
        private: RS485() {};

    public: 
        static RS485 *getInstance() {
            if(Instance == nullptr) {
                Instance = new RS485();
            }

            return Instance;
        }

        Status* Send(string Messege, uint32_t Length) override {
            static Status status;
            status.SetMessege(Status::Messege::Fault);

            cout << "RS485 : Send()" << endl;
            status.SetMessege(Status::Messege::Success);

            return &status;
        }

        Status* Receive(string *Messege, uint32_t *Length) override {
            static Status status;
            status.SetMessege(Status::Messege::Fault);    

            cout << "RS485 : Receive()" << endl;
            status.SetMessege(Status::Messege::Success);

            return &status;
        }
};
RS485 *RS485::Instance = nullptr;

class LAN : public Media {    
    private: 
        static LAN *Instance;
        private: LAN() {};
        
    public: 
        static LAN *getInstance() {
            if(Instance == nullptr) {
                Instance = new LAN();
            }

            return Instance;
        }

        Status* Send(string Messege, uint32_t Length) override {
            static Status status;
            status.SetMessege(Status::Messege::Fault);

            cout << "LAN : Send()" << endl;
            status.SetMessege(Status::Messege::Success);

            return &status;
        }

        Status* Receive(string *Messege, uint32_t *Length) override {
            static Status status;
            status.SetMessege(Status::Messege::Fault);    

            cout << "LAN : Receive()" << endl;
            status.SetMessege(Status::Messege::Success);

            return &status;
        }
};
LAN *LAN::Instance = nullptr;

class IEC {
    public:
        IEC() : _Media(nullptr) {};
        Status* setMedia(Media *_Media) {
            static Status status;
            status.SetMessege(Status::Messege::Fault); 

            this->_Media = _Media; 
            status.SetMessege(Status::Messege::Success);

            return &status;
        }
        Status* Handle(void) {
            static Status status;
            status.SetMessege(Status::Messege::Fault);

            if(_Media == nullptr) {
                status.SetMessege(Status::Messege::Fault_Media);
                return &status;
            }            

            string Messege;
            uint32_t Length;
            
            Messege = "Data";
            Length = 4;
            _Media->Send(Messege, Length);

            Messege = "";
            Length = 0;
            _Media->Receive(&Messege, &Length);

            status.SetMessege(Status::Messege::Success);

            return &status;
        }
    private:
        Media *_Media;
};

int main() {
    
    Status *status;

    RS485 *rs485 = RS485::getInstance();
    LAN *lan = LAN::getInstance();

    IEC *iec = new IEC();
    status = iec->Handle();
    status->ShowMessege();

    status = iec->setMedia(rs485);
    status = iec->Handle();

    status = iec->setMedia(lan);
    status = iec->Handle();

    return 0;
}