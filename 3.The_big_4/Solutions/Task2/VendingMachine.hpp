
struct Inventory {
    unsigned int salty;
    unsigned int sweet;
    unsigned int drinks;

    void changeSalty(int quantity);
    void changeSweets(int quantity);
    void changeDrinks(int quantity);
    void print();
};

class VendingMachine {
    int id;
    char* address;
    Inventory inventory;
    char** warningMessages;
    int numWarningMsgs;
    int capacity;

public:
    VendingMachine(); //default constructor
    VendingMachine(char* address, Inventory inventory); //default constructor
    VendingMachine(VendingMachine const& other); // copy constructor
    VendingMachine(VendingMachine && other); // move constructor
    VendingMachine& operator=(VendingMachine const& other);
    ~VendingMachine();

    int getId();
    char* getAddress();
    Inventory getInventory();
    
    void addMsg(char* msg);

};


class VendingController {
    VendingMachine* vendingMachineList;
    int numMachines;
    int capacity;

public:
    //include big 4-5-6 
    void addVendingMachine(VendingMachine machine);
    void getAddressOfMachine(int machineID);
    void getInventoryOfMachine(int machineID);
    void sellProductInMachine(int machineID, char* product);
    void restockProductInMachine(int machineID, char* product);
    void seeWarningMsgForMachine(int machineID);
};