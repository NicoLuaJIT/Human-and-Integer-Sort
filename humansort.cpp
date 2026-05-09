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

int main() {
    std::vector<Human> human = {};

    while (true) {
        int choice;
        std::cout << "0. Exit\n1. Create Human\n2. Remove Human\n3. Show Human\n4. Sort by Name\n5. Sort by Age\nChoice: ";
        std::cin >> choice;

        switch (choice) {
            case 0: return 0;
            case 1: {
                std::string name;
                int age;
                inputHuman(age, name);
                human.push_back({name, age});
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
                for (const auto &h : human) {
                    std::cout << "Name: " << h.name << ", Age: " << h.age << "\n";
                }
                break;
            }
            case 4: {
                std::sort(human.begin(), human.end(), [](const Human& a, const Human& b) {
                   return a.name < b.name;
                });

                std::cout << "Successfully sorted!\n";
                break;
            }
            case 5: {
                std::sort(human.begin(), human.end(), [](const Human& a, const Human& b) {
                   return a.age < b.age;
                });

                std::cout << "Successfully sorted!\n";
                break;
            }
            default: continue;
        }
    }
}
