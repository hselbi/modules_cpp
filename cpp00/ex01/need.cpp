#include <iostream>
#include <string>

#define MAX_CONTACTS 10

class Contact {
public:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
};

class PhoneBook {
public:
    Contact contacts[MAX_CONTACTS];
    int num_contacts;

    PhoneBook() : num_contacts(0) {}

    void add_contact(Contact contact) {
        if (num_contacts >= MAX_CONTACTS) {
            std::cout << "Phonebook is full." << std::endl;
            return;
        }
        contacts[num_contacts++] = contact;
    }

    void search_contact(int index) {
        if (index < 0 || index >= num_contacts) {
            std::cout << "Invalid index." << std::endl;
            return;
        }

        Contact contact = contacts[index];
        std::cout << "First Name: " << contact.first_name << std::endl;
        std::cout << "Last Name: " << contact.last_name << std::endl;
        std::cout << "Nickname: " << contact.nickname << std::endl;
        std::cout << "Phone Number: " << contact.phone_number << std::endl;
        std::cout << "Darkest Secret: " << contact.darkest_secret << std::endl;
    }

    void display_contacts() {
        for (int i = 0; i < num_contacts; i++) {
            Contact contact = contacts[i];
            std::string first_name = contact.first_name;
            first_name.resize(10, '.');
            std::string last_name = contact.last_name;
            last_name.resize(10, '.');
            std::string nickname = contact.nickname;
            nickname.resize(10, '.');
            std::cout << i << " | " << first_name << " | " << last_name << " | " << nickname << std::endl;
        }
    }
};

int main() {
    PhoneBook phonebook;

    while (true) {
        std::string command;
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::cin >> command;

        if (command == "ADD") {
            Contact contact;
            std::cout << "Enter first name: ";
            std::cin >> contact.first_name;
            std::cout << "Enter last name: ";
            std::cin >> contact.last_name;
            std::cout << "Enter nickname: ";
            std::cin >> contact.nickname;
            std::cout << "Enter phone number: ";
            std::cin >> contact.phone_number;
            std::cout << "Enter darkest secret: ";
            std::cin >> contact.darkest_secret;

            phonebook.add_contact(contact);
        } else if (command == "SEARCH") {
            phonebook.display_contacts();
            int index;
            std::cout << "Enter the index of the contact to display: ";
            std::cin >> index;
            phonebook.search_contact(index);
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command." << std::endl;
        }
    }

    return 0;
}
