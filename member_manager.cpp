#include "member_manager.h"

// Method definitions for Member class
void Member::displayMemberInfo()
{
    cout << "Member ID: " << memberID << endl;
    cout << "Member name: " << name << endl;
    cout << "Member address: " << address << endl;
    cout << "Member phone number: " << phoneNumber << endl;
    cout << "-------------------------" << endl;
}

void Member::updateName(string newName)
{
    name = newName;
    cout << "Name updated to: " << name << endl;
}

int Member::getMemberID() const { return memberID; }
string Member::getMemberName() const { return name; }
string Member::getMemberAddress() const { return address; }
string Member::getMemberPhoneNumber() const { return phoneNumber; }

// Other function implementations...
bool is_member_file_empty(std::ifstream &pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

Member createMember()
{
    Member member;
    cout << "\n==== Add New Member Menu ====\n";
    cout << "1. Enter member ID: ";
    cin >> member.memberID;
    cin.ignore();
    cout << "2. Enter member name: ";
    getline(cin, member.name);
    cout << "3. Enter member address: ";
    getline(cin, member.address);
    cout << "4. Enter member phone number: ";
    getline(cin, member.phoneNumber);
    return member;
}

std::vector<Member> readCSVMembers(const std::string &filename)
{
    std::vector<Member> memberList;
    std::ifstream file(filename);
    std::string line;
    bool header = true;

    if (!file.is_open())
    {
        cerr << "Could not open file: " << filename << endl;
        return memberList;
    }

    while (getline(file, line))
    {
        if (header)
        {
            header = false;
            continue;
        }
        std::stringstream ss(line);
        Member member;
        string item;

        getline(ss, item, ',');
        member.memberID = stoi(item);

        getline(ss, item, ',');
        member.name = item;

        getline(ss, item, ',');
        member.address = item;

        getline(ss, item, ',');
        member.phoneNumber = item;

        memberList.push_back(member);
    }

    return memberList;
}

// Function to display the main menu
void displayMenuMember()
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
                  << ", Phone Number: " << member.getMemberPhoneNumber()
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