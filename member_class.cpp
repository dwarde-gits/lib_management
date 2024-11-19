#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

// class definition of Member
class Member
{
public:
    int memberID;
    string name;
    string address;
    string phoneNumber;

public:
    // Method to display member details
    void displayMemberInfo()
    {
        cout << "Member ID: " << memberID << endl;
        cout << "Member name: " << name << endl;
        cout << "Memeber address: " << address << endl;
        cout << "Member phone number: " << phoneNumber << endl;
        cout << "-------------------------" << endl;
    }

    // Method to update the name of the member
    void updateName(string newName)
    {
        name = newName;
        cout << "Status updated to: " << name << endl;
    }

    // Getter for memberID
    int getMemberID() const
    {
        return memberID;
    }
    // const means that the function isn't modifying variables
    string getMemberName() const
    {
        return name;
    }
    string getMemberAddress() const
    {
        return address;
    }
    string getMemeberPhoneNumber() const
    {
        return phoneNumber;
    }
};
// function to check if a file is empty.
bool is_file_empty(std::ifstream &pFile)
{
    if (pFile.tellg() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// create and return a new member object
Member createMember()
{
    int memberID = 0;
    string memberName = "";
    string memberAddress = "";
    string memberPhoneNumber = "";

    std::cout << "\n==== Add New Member Menu ====\n";
    std::cout << "1. enter member id: ";
    std::cin >> memberID;
    std::cin.ignore();

    std::cout << "2. enter member name: ";
    std::cin >> memberName;
    std::cin.ignore(); // Clear newline from input buffer

    std::cout << "3. enter member address: ";
    std::cin >> memberAddress;
    std::cin.ignore();

    std::cout << "4. enter member phone number: ";
    std::cin >> memberPhoneNumber;
    std::cin.ignore();

    Member member;
    member.memberID = memberID;
    member.name = memberName;
    member.address = memberAddress;
    member.phoneNumber = memberPhoneNumber;

    return member;
}

// Function to read CSV file into vector of Members.
std::vector<Member> readCSV(const std::string &filename)
{
    std::vector<Member> memberList;
    std::ifstream file(filename);
    std::string line;
    bool header = true; // Skip the header line

    if (!file.is_open())
    {
        std::cerr << "Could not open file: " << filename << std::endl;
        return memberList;
    }

    while (std::getline(file, line))
    {
        // Skip the header line. first line is the header line.
        if (header)
        {
            header = false;
            continue;
        }

        std::stringstream ss(line);
        std::string item;
        Member member;

        // Parse each field separated by comma
        std::getline(ss, item, ',');
        member.memberID = std::stoi(item);

        std::getline(ss, item, ',');
        member.name = item;

        std::getline(ss, item, ',');
        member.address = item;

        std::getline(ss, item, ',');
        member.phoneNumber = item;
        std::getline(ss, item, ',');

        memberList.push_back(member);
    }

    file.close();
    return memberList;
}

// Function to display the main menu
void displayMenu()
{
    std::cout << "\n==== Library Menu ====\n";
    std::cout << "1. Add Member\n";
    std::cout << "2. List Members\n";
    std::cout << "3. Delete Member\n";
    std::cout << "4. Edit Member\n";
    std::cout << "5. Exit\n";
    std::cout << "Select an option: ";
}

void listMembers(vector<Member> memberList)
{
    if (memberList.empty())
    {
        std::cout << "No members available.\n";
        return;
    }

    std::cout << "\nList of Members:\n";
    for (const auto &member : memberList)
    {
        std::cout << "memberID: " << std::to_string(member.getMemberID())
                  << ", Name: " << member.getMemberName()
                  << ", Address: " << member.getMemberAddress()
                  << ", Phone Number: " << member.getMemeberPhoneNumber()
                  << "\n";
    }
}
// Function to delete a member
vector<Member> deleteMember(vector<Member> memberList)
{
    int id;
    std::cout << "Enter Member ID to delete: ";
    std::cin >> id;
    std::cin.ignore(); // Clear newline from input buffer

    auto it = std::remove_if(memberList.begin(), memberList.end(), [id](const Member &member)
                             { return member.getMemberID() == id; });

    if (it != memberList.end())
    {
        memberList.erase(it, memberList.end());
        std::cout << "Member deleted successfully!\n";
    }
    else
    {
        std::cout << "Member with ID " << id << " not found.\n";
    }
    return memberList;
}
// function to search for a specific member.
Member *findMemberByID(std::vector<Member> &members, int id)
{
    auto it = std::find_if(members.begin(), members.end(), [id](Member &b)
                           { return b.getMemberID() == id; });

    // If the member is found, return a pointer to it
    if (it != members.end())
    {
        return &(*it);
    }
    return nullptr; // Member not found
}

int main()
{

    vector<Member> memberList2 = readCSV("members.csv");
    int choice;
    do
    {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(); // Clear newline from input buffer

        switch (choice)
        {
        case 1:
            // using extra braces since the the member object is created here.
            // because https://stackoverflow.com/questions/5136295/switch-transfer-of-control-bypasses-initialization-of-when-calling-a-function
            {

                Member member = createMember();
                memberList2.push_back(member);
            }
            break;
        case 2:
            listMembers(memberList2);
            break;
        case 3:
            // new memberList after a deletion is done.
            memberList2 = deleteMember(memberList2);
            break;
        case 4:
        {
            // modify/edit a member.
            int id;
            int memberID;
            string memberName;
            string memberAddress;
            string memberPhoneNumber;

            std::cout << "Enter member ID to edit: ";
            std::cin >> id;
            std::cin.ignore(); // Clear newline from input buffer
            Member *memberToModify = findMemberByID(memberList2, id);
            if (memberToModify)
            {
                std::cout << "Modifying member with ID: " << memberToModify->getMemberID() << "\n";
                // Modify member details
                // std::cout << "1. enter new member id: ";
                // std::cin >> memberID;
                // std::cin.ignore();

                std::cout << "2. enter new member name (enter to keep as is): ";
                std::cin >> memberName;
                std::cin.ignore(); // Clear newline from input buffer
                if (!memberName.empty())
                {
                    memberToModify->name = memberName;
                }

                std::cout << "3. enter new member address  (enter to keep as is ): ";
                std::cin >> memberAddress;
                std::cin.ignore();

                std::cout << "4. enter new member phone number (enter to keep as is ): ";
                std::cin >> memberPhoneNumber;
                std::cin.ignore();

                if (!memberName.empty())
                {
                    memberToModify->name = memberName;
                }
                if (!memberAddress.empty())
                {
                    memberToModify->address = memberAddress;
                }
                if (!memberPhoneNumber.empty())
                {
                    memberToModify->phoneNumber = memberPhoneNumber;
                }
            }
            else
            {
                std::cout << "Member with ID " << id << " not found.\n";
            }
        }
        break;
        case 5:
            // before existing. write the records to file.
            // if the file was previously empty will need to write header first,
            // otherwise just proceed to write actual record content.
            {
                std::ofstream myfile;
                std::ifstream file("members.csv");
                myfile.open("members.csv");
                bool header_set = false;
                for (const auto &member : memberList2)
                {
                    // todo. continue modifying from here
                    std::cout << "ID: " << std::to_string(member.getMemberID())
                              << ", Name: " << member.getMemberName()
                              << ", Address: " << member.getMemberAddress() << "\n";

                    string record1 = std::to_string(member.getMemberID()) + "," +
                                     member.getMemberName() + "," +
                                     member.getMemberAddress() + "," +
                                     member.getMemeberPhoneNumber() + ",";
                    if (is_file_empty(file) && header_set == false)
                    {
                        // the header only needs to be written once.
                        myfile << "MemberId, name, address, phone_number\n";
                        header_set = true;
                    }
                    myfile << record1;
                }
                myfile.close();
                file.close();
                std::cout << "Exiting...\n";
            }
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
