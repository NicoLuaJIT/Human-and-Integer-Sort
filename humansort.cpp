#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Human {
    std::string name;
    int age;
};

void inputHuman(int &age, std::string &name) {
    std::cout << "Name: ";
    std::getline(std::cin >> std::ws, name);
    std::cout << "Age: ";
    std::cin >> age;
}

void insertHumanIntoVector(int &age, std::string &name, std::vector<Human> &v) {
    v.push_back({name, age});
}

bool removeHuman(int &age, std::string &name, std::vector<Human> &v) {
    Human h = {name, age};
    auto it = std::find_if(v.begin(), v.end(), [&](const Human &a) {
        return a.name == h.name && a.age == h.age; 
    });
    if (it != v.end()) {
        v.erase(it);
        return true;
    }

    return false;
}

void showHumans(std::vector<Human> &v) {
    for (const auto &h : v) {
        std::cout << "Name: " << h.name << " | Age: " << h.age << "\n";
    }
}

void sortAtoZ(std::vector<Human> &vec) {
    std::sort(vec.begin(), vec.end(), [](const Human &a, const Human &b) {
        return a.name < b.name; 
    });
}

void sortZtoA(std::vector<Human> &vec) {
    std::sort(vec.begin(), vec.end(), [](const Human &a, const Human &b) {
        return a.name > b.name; 
    });
}

void sortByName(std::vector<Human> &v) {
    bool isRunning = true;
    while (isRunning) {
        int choice;
        std::cout << "Choose how you want to sort.\n0. Exit\n1. A to Z\n2. Z to A\nChoice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 0: isRunning = false; break;
            case 1: sortAtoZ(v); std::cout << "Successfully sorted!\n"; isRunning = false; break;
            case 2: sortZtoA(v); std::cout << "Successfully sorted!\n"; isRunning = false; break;
        }
    }
}

void sortYoungestToOldest(std::vector<Human> &vec) {
    std::sort(vec.begin(), vec.end(), [](const Human &a, const Human &b) {
       return a.age < b.age; 
    });
}

void sortOldestToYoungest(std::vector<Human> &vec) {
    std::sort(vec.begin(), vec.end(), [](const Human &a, const Human &b) {
       return a.age > b.age; 
    });
}

void sortByAge(std::vector<Human> &v) {
    bool isRunning = true;
    while (isRunning) {
        int choice;
        std::cout << "Choose how you want to sort.\n0. Exit\n1. Youngest to Oldest\n2. Oldest to Youngest\nChoice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 0: isRunning = false; break;
            case 1: sortYoungestToOldest(v); std::cout << "Successfully sorted!\n"; isRunning = false; break;
            case 2: sortOldestToYoungest(v); std::cout << "Successfully sorted!\n"; isRunning = false; break;
        }
    }
}


int main() {
    std::vector<Human> human = {};

    while (true) {
        int choice;
        std::cout << "0. Exit\n1. Create Human\n2. Remove Human\n3. Show Human\n4. Sort by Name (Alphabetical)\n5. Sort By Age\nChoice: ";
        std::cin >> choice;

        switch (choice) {
            case 0: return 0;
            case 1: {
                std::string name;
                int age;
                inputHuman(age, name);
                insertHumanIntoVector(age, name, human);
                std::cout << "Human successfully added!\n";
                break;
            }
            case 2: {
                std::string name;
                int age;
                inputHuman(age, name);
                if (removeHuman(age, name, human)) {
                    std::cout << "Human successfully removed!\n";
                } else {
                    std::cout << "Human not found!\n";
                }
                break;
            }
            case 3: {
                std::cout << "Humans:\n";
                showHumans(human);
                break;
            }
            case 4: {
                sortByName(human);
                break;
            }
            case 5: {
                sortByAge(human);
                break;
            }
            default: continue;
        }
    }
}
