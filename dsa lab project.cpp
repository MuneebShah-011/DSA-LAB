#include<iostream>
#include<string>
using namespace std;

class Appliance {
public:
    string name;
    string powerStatus;
    Appliance* next;

    Appliance(string applianceName) {
        name = applianceName;
        powerStatus = "OFF";
        next = NULL;
    }

    void turnOn() {
        powerStatus = "ON";
        cout<<"The "<<name<<" has been turned ON"<<endl;
    }

    void turnOff() {
        powerStatus = "OFF";
        cout<<"The "<<name<<" has been turned OFF"<<endl;
    }

    void rename(string newName) {
        name = newName;
    }
};

class SmartHome{
private:
    Appliance* head;

public:
    SmartHome() {
        head = NULL;
    }

    void addAppliance(string name) {
        Appliance* newAppliance = new Appliance(name);
        if(head == NULL) {
            head = newAppliance;
        } else {
            Appliance* temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newAppliance;
        }
    }

    void viewAllDevices() {
        if(head == NULL) {
            cout<<"No devices added."<<endl;
            return;
        }
        int i = 1;
        Appliance* temp = head;
        while(temp != NULL) {
            cout<<i<<". "<<temp->name<<" (Status: "<<temp->powerStatus<<")"<<endl;
            temp = temp->next;
            i++;
        }
    }

    Appliance* findDevice(string name) {
        Appliance* temp = head;
        while(temp != NULL) {
            if(temp->name == name)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }

    void turnOnByName(string name) {
        Appliance* device = findDevice(name);
        if(device)
            device->turnOn();
        else
            cout<<"Appliance not found!"<<endl;
    }

    void turnOffByName(string name) {
        Appliance* device = findDevice(name);
        if(device)
            device->turnOff();
        else
            cout<<"Appliance not found!"<<endl;
    }

    void changeSettingsByName(string name) {
        Appliance* device = findDevice(name);
        if(device) {
            string newName;
            cout<<"Enter new name: ";
            cin>>newName;
            device->rename(newName);
            cout<<"Device renamed successfully."<<endl;
            
        } else {
            cout<<"Appliance not found!"<<endl;
        }
    }

   

    void displayMenu() {
        int choice = 0;
        while(choice != 7) {
            cout<<"\nSmart Home Control Menu"<<endl;
            cout<<"1. View all devices"<<endl;
            cout<<"2. Add a new device"<<endl;
            cout<<"3. Turn ON a device"<<endl;
            cout<<"4. Turn OFF a device"<<endl;
            cout<<"5. Change device name"<<endl;
            cout<<"7. Exit"<<endl;
            cout<<"Enter your choice: ";
            cin>>choice;

            string deviceName;

            switch(choice) {
                case 1:
                    viewAllDevices();
                    break;
                case 2:
                    cout<<"Enter device name: ";
                    cin>>deviceName;
                    addAppliance(deviceName);
                    break;
                case 3:
                    cout<<"Enter device name to turn ON: ";
                    cin>>deviceName;
                    turnOnByName(deviceName);
                    break;
                case 4:
                    cout<<"Enter device name to turn OFF: ";
                    cin>>deviceName;
                    turnOffByName(deviceName);
                    break;
                case 5:
                    cout<<"Enter device name to change settings: ";
                    cin>>deviceName;
                    changeSettingsByName(deviceName);
                    break;
                
                case 7:
                    cout<<"Exiting Smart Home..."<<endl;
                    break;
                default:
                    cout<<"Invalid choice!"<<endl;
            }
        }
    }
};

int main() {
    SmartHome obj;
    obj.addAppliance("Fan");
	obj.addAppliance("Light");
    obj.addAppliance("Heater");
    obj.addAppliance("AC");
    obj.displayMenu();
    return 0;
}

