#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Base class for pet
class Pet {
protected:
    string name;
    int hungerLevel;
    int sleepinessLevel;
    int boredomLevel;
public:
    Pet(string n) {
        name = n;
        hungerLevel = 0;
        sleepinessLevel = 0;
        boredomLevel = 0;
    }
    virtual void play() = 0;
    virtual void feed() = 0;
    virtual void sleep() = 0;
    virtual void display() = 0;
    void saveToFile(string filename) {
        ofstream outfile;
        outfile.open(filename);
        outfile << name << " " << hungerLevel << " " << sleepinessLevel << " " << boredomLevel << endl;
        outfile.close();
    }
    void loadFromFile(string filename) {
        ifstream infile;
        infile.open(filename);
        if (infile.is_open()) {
            infile >> name >> hungerLevel >> sleepinessLevel >> boredomLevel;
            infile.close();
        }
        else {
            cout << "Error: Unable to open file." << endl;
        }
    }
};

// Derived class for dog
class Dog : public Pet {
public:
    Dog(string n) : Pet(n) {}
    void play() override {
        boredomLevel -= 5;
        if (boredomLevel < 0) boredomLevel = 0;
        hungerLevel += 3;
        if (hungerLevel > 10) hungerLevel = 10;
    }
    void feed() override {
        hungerLevel -= 3;
        if (hungerLevel < 0) hungerLevel = 0;
        boredomLevel += 2;
        if (boredomLevel > 10) boredomLevel = 10;
    }
    void sleep() override {
        sleepinessLevel -= 5;
        if (sleepinessLevel < 0) sleepinessLevel = 0;
        hungerLevel += 2;
        if (hungerLevel > 10) hungerLevel = 10;
    }
    void display() override {
        cout << "--<>--<>--<>--<>--<>--<>--" << endl;
        cout << "Dog: " << name << endl;
        cout << "Hunger Level: " << hungerLevel << endl;
        cout << "Sleepiness Level: " << sleepinessLevel << endl;
        cout << "Boredom Level: " << boredomLevel << endl;
        cout << "--<>--<>--<>--<>--<>--<>--" << endl;
    }
};

// Derived class for cat
class Cat : public Pet {
public:
    Cat(string n) : Pet(n) {}
    void play() override {
        boredomLevel -= 6;
        if (boredomLevel < 0) boredomLevel = 0;
        hungerLevel += 2;
        if (hungerLevel > 10) hungerLevel = 10;
    }
    void feed() override {
        hungerLevel -= 2;
        if (hungerLevel < 0) hungerLevel = 0;
        boredomLevel += 1;
        if (boredomLevel > 10) boredomLevel = 10;
    }
    void sleep() override {
        sleepinessLevel -= 6;
        if (sleepinessLevel < 0) sleepinessLevel = 0;
        hungerLevel += 1;
        if (hungerLevel > 10) hungerLevel = 10;
    }
    void display() override {
        cout << "--<>--<>--<>--<>--<>--<>--" << endl;
        cout << "Cat: " << name << endl;
        cout << "Hunger Level: " << hungerLevel << endl;
        cout << "Sleepiness Level: " << sleepinessLevel << endl;
        cout << "Boredom Level: " << boredomLevel << endl;
        cout << "--<>--<>--<>--<>--<>--<>--" << endl;
    }
};

// Derived class for bunny
class Bunny : public Pet {
public:
    Bunny(string n) : Pet(n) {}
    void play() override {
        boredomLevel -= 4;
        if (boredomLevel < 0) boredomLevel = 0;
        hungerLevel += 1;
        if (hungerLevel > 10) hungerLevel = 10;
    }
    void feed() override {
        hungerLevel -= 1;
        if (hungerLevel < 0) hungerLevel = 0;
        boredomLevel += 3;
        if (boredomLevel > 10) boredomLevel = 10;
    }
    void sleep() override {
        sleepinessLevel -= 4;
        if (sleepinessLevel < 0) sleepinessLevel = 0;
        hungerLevel += 1;
        if (hungerLevel > 10) hungerLevel = 10;
    }
    void display() override {
        cout << "--<>--<>--<>--<>--<>--<>--" << endl;
        cout << "Bunny: " << name << endl;
        cout << "Hunger Level: " << hungerLevel << endl;
        cout << "Sleepiness Level: " << sleepinessLevel << endl;
        cout << "Boredom Level: " << boredomLevel << endl;
        cout << "--<>--<>--<>--<>--<>--<>--" << endl;
    }
};

int main() {
    int selection;
    cout << ".'`'. .'`'. .'`'. .'`'." << endl;
    cout << "`    `     `     `     `" << endl;
    cout << "       " << "Tamagotchi" << "       " << endl;
    cout << ".     .     .     .     ." << endl;
    cout << " `._.` `._.` `._.` `._.`" << endl;
    cout << "0: Load a saved game" << endl;
    cout << "1: Start a new game" << endl;
        cout << "--<>--<>--<>--<>--<>--<>--" << endl;
    cout << "Enter selection: ";
    cin >> selection;
    if (selection == 0) {
        string filename;
        cout << "Enter the name of the saved game file: ";
        cin >> filename;
        Pet *pet = nullptr;
        if (ifstream(filename)) {
            pet = new Dog("");
            pet->loadFromFile(filename);
            pet->display();
            cout << endl;
            int option;
            do {
                cout << "1: Play" << endl;
                cout << "2: Feed" << endl;
                cout << "3: Sleep" << endl;
                cout << "4: Save and Exit" << endl;
                cout << "--<>--<>--<>--<>--<>--<>--" << endl;
                cout << "Enter selection: ";
                cin >> option;
                switch (option) {
                    case 1:
                        pet->play();
                        pet->display();
                        break;
                    case 2:
                        pet->feed();
                        pet->display();
                        break;
                    case 3:
                        pet->sleep();
                        pet->display();
                        break;
                    case 4:
                        pet->saveToFile(filename);
                        delete pet;
                        return 0;
                    default:
                        cout << "Invalid selection" << endl;
                        break;
                }
            } while (option != 4);
        }
        else {
            cout << "Error: Unable to open file." << endl;
        }
    }
    else if (selection == 1) {
        int petType;
        string name;
        cout << "Select pet type:" << endl;
        cout << "1: Dog" << endl;
        cout << "  __      _" << endl; 
        cout << "o'')}____//" << endl; 
        cout << " `_/      )" << endl; 
        cout << " (_(_/-(_/" << endl; 
        cout << endl;
        cout << "2: Cat" << endl;
        cout << endl;
        cout << "  _^_^_    )" << endl; 
        cout << " ( ^.^ )  )" << endl; 
        cout << "   \"/    (" << endl;
        cout << " ( | | ) )" << endl; 
        cout << "(__d b__)" << endl; 
        cout << endl;
        cout << "3: Bunny" << endl;
        cout << endl;
        cout << "   \\" << endl;
        cout << "    \\_" << endl;
        cout << "    ( _) " << endl;
        cout << "    / /_" << endl;
        cout << "   / _/``" << endl;
        cout << " */   )_" << endl;
        cout << endl;
        cout << "--<>--<>--<>--<>--<>--<>--" << endl;
        cout << "Enter selection: ";
        cin >> petType;
        cout << "Enter pet name: ";
        cin >> name;
        Pet *pet = nullptr;
        switch (petType) {
            case 1:
                pet = new Dog(name);
                break;
            case 2:
                pet = new Cat(name);
                break;
            case 3:
                pet = new Bunny(name);
                break;
            default:
                cout << "Invalid selection" << endl;
                break;
        }
        if (pet != nullptr) {
            int option;
            do {
                cout << "1: Play" << endl;
                cout << "2: Feed" << endl;
                cout << "3: Sleep" << endl;
                cout << "4: Save and Exit" << endl;
                cout << "--<>--<>--<>--<>--<>--<>--" << endl;
                cout << "Enter selection: ";
                cin >> option;
                switch (option) {
                    case 1:
                        pet->play();
                        pet->display();
                        break;
                    case 2:
                        pet->feed();
                        pet->display();
                        break;
                    case 3:
                        pet->sleep();
                        pet->display();
                        break;
                    case 4:
                    {
                        string filename;
                        cout << "Enter the name of the save file: ";
                        cin >> filename;
                        bool success = false;
                        if (pet != nullptr) {
                            pet->saveToFile(filename);
                            delete pet;
                            success = true;
                        }
                        if (success) {
                            return 0;
                        }
                        else {
                            cout << "Error: Unable to save file." << endl;
                            break;
                        }
                    }
                    default:
                        cout << "Invalid selection" << endl;
                        break;
                }
            } while (option != 4);
        }
    }
}