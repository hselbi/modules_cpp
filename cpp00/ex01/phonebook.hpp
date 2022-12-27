

class phonebook
{
    private:
        static const int MAX_CON = 10;
        
    public:
        Contact contacts[MAX_CON];
        int index_contact;
        
        PhoneBook() : num_contacts(0) {}

        void adding_contact(Contact new_contact)
        {
            if (index_contact >= MAX_CON)
                index_contact = 0;
            contacts[index_contact++] = new_contact;
        }
        contact searching_contact(int index)
        {
            if (index < 0 || index >= MAX_CON)
            {
                std::cerr << "Error: Index out of range." << std::endl;
                return (NULL);
            }
            return (contacts[index]);
        }
};

