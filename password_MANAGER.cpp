#include <bits/stdc++.h>
using namespace std;

// Define a PasswordEntry class
class PasswordEntry
{
public:
    PasswordEntry(const std::string &website, const std::string &username, const std::string &password)
        : website(website), username(username), password(password) {}

    std::string getWebsite() const { return website; }
    std::string getUsername() const { return username; }
    std::string getPassword() const { return password; }

private:
    std::string website;
    std::string username;
    std::string password;
};

// Function to encrypt a string (dummy implementation)
std::string encrypt(const std::string &input)
{
    return input; // Replace with actual encryption logic
}

// Function to decrypt a string (dummy implementation)
std::string decrypt(const std::string &encrypted)
{
    return encrypted; // Replace with actual decryption logic
}

// Function to save password entries to a file
void saveToFile(const std::vector<PasswordEntry> &entries)
{
    std::ofstream file("passwords.txt");
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file for writing." << std::endl;
        return;
    }

    for (const auto &entry : entries)
    {
        file << entry.getWebsite() << ',' << entry.getUsername() << ',' << encrypt(entry.getPassword()) << '\n';
    }

    file.close();
}

// Function to load password entries from a file
std::vector<PasswordEntry> loadFromFile()
{
    std::vector<PasswordEntry> entries;
    std::ifstream file("passwords.txt");
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file for reading." << std::endl;
        return entries;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string website, username, password;
        std::getline(ss, website, ',');
        std::getline(ss, username, ',');
        std::getline(ss, password);

        entries.emplace_back(website, username, decrypt(password));
    }

    file.close();
    return entries;
}

int main()
{
    std::vector<PasswordEntry> passwordEntries;

    while (true)
    {
        std::cout << "Password Manager\n";
        std::cout << "1. Add Password Entry\n";
        std::cout << "2. List Password Entries\n";
        std::cout << "3. Exit\n";
        std::cout << "Select an option: ";

        int choice;
        std::cin >> choice;

        if (choice == 1)
        {
            std::string website, username, password;
            std::cout << "Website: ";
            std::cin >> website;
            std::cout << "Username: ";
            std::cin >> username;
            std::cout << "Password: ";
            std::cin >> password;

            passwordEntries.emplace_back(website, username, password);
            saveToFile(passwordEntries);
        }
        else if (choice == 2)
        {
            passwordEntries = loadFromFile();
            std::cout << "Password Entries:\n";
            for (const auto &entry : passwordEntries)
            {
                std::cout << "Website: " << entry.getWebsite() << '\n';
                std::cout << "Username: " << entry.getUsername() << '\n';
                std::cout << "Password: " << entry.getPassword() << '\n';
                std::cout << "------------------------\n";
            }
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            std::cout << "Invalid choice. Please select a valid option.\n";
        }
    }

    return 0;
}
// Mehedi Hasan
// Green University Of Bangladesh
// https://www.facebook.com/mohammad.mahedi.100(facebook LINK)