#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// Class definition of Member
class Member
{
public:
    int memberID;
    string name;
    string address;
    string phoneNumber;

    // Method to display member details
    void displayMemberInfo();

    // Method to update the name of the member
    void updateName(string newName);

    // Getter methods
    int getMemberID() const;
    string getMemberName() const;
    string getMemberAddress() const;
    string getMemberPhoneNumber() const;
};

// Function declarations
bool is_member_file_empty(std::ifstream &pFile);
Member createMember();
std::vector<Member> readCSVMembers(const std::string &filename);
void displayMenuMember();
void listMembers(std::vector<Member> memberList);
std::vector<Member> deleteMember(std::vector<Member> memberList);
Member *findMemberByID(std::vector<Member> &members, int id);

#endif // MEMBER_H
