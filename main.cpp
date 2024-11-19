#include "book_manager.h"
#include "member_manager.h"

int main()
{
    // vector<Book> bookList = readCSVBooks("books.csv");
    // int choice;

    // do
    // {
    //     displayMenuBook();
    //     cin >> choice;
    //     cin.ignore();

    //     switch (choice)
    //     {
    //     case 1:
    //     {
    //         Book book = createBook();
    //         bookList.push_back(book);
    //         break;
    //     }
    //     case 2:
    //         listBooks(bookList);
    //         break;
    //     case 3:
    //         bookList = deleteBook(bookList);
    //         break;
    //     case 4:
    //     {
    //         int id;
    //         cout << "Enter book ID to edit: ";
    //         cin >> id;
    //         cin.ignore();

    //         Book *bookToModify = findBookByID(bookList, id);
    //         if (bookToModify)
    //         {
    //             cout << "Modifying book with ID: " << bookToModify->getBookID() << "\n";
    //             string newTitle, newAuthor, newGenre, newStatus;

    //             cout << "New title (leave empty to keep unchanged): ";
    //             getline(cin, newTitle);

    //             cout << "New author (leave empty to keep unchanged): ";
    //             getline(cin, newAuthor);

    //             cout << "New genre (leave empty to keep unchanged): ";
    //             getline(cin, newGenre);

    //             cout << "New status (leave empty to keep unchanged): ";
    //             getline(cin, newStatus);

    //             if (!newTitle.empty())
    //                 bookToModify->title = newTitle;
    //             if (!newAuthor.empty())
    //                 bookToModify->author = newAuthor;
    //             if (!newGenre.empty())
    //                 bookToModify->genre = newGenre;
    //             if (!newStatus.empty())
    //                 bookToModify->status = newStatus;
    //         }
    //         else
    //         {
    //             cout << "Book with ID " << id << " not found.\n";
    //         }
    //         break;
    //     }
    //     case 5:
    //         cout << "Exiting...\n";
    //         break;
    //     default:
    //         cout << "Invalid choice. Please try again.\n";
    //     }
    // } while (choice != 5);

    // vector<Member> memberList2 = readCSVMembers("members.csv");
    // int choice;
    // do
    // {
    //     displayMenuMember();
    //     std::cin >> choice;
    //     std::cin.ignore(); // Clear newline from input buffer

    //     switch (choice)
    //     {
    //     case 1:
    //         // using extra braces since the the member object is created here.
    //         // because https://stackoverflow.com/questions/5136295/switch-transfer-of-control-bypasses-initialization-of-when-calling-a-function
    //         {

    //             Member member = createMember();
    //             memberList2.push_back(member);
    //         }
    //         break;
    //     case 2:
    //         listMembers(memberList2);
    //         break;
    //     case 3:
    //         // new memberList after a deletion is done.
    //         memberList2 = deleteMember(memberList2);
    //         break;
    //     case 4:
    //     {
    //         // modify/edit a member.
    //         int id;
    //         int memberID;
    //         string memberName;
    //         string memberAddress;
    //         string memberPhoneNumber;

    //         std::cout << "Enter member ID to edit: ";
    //         std::cin >> id;
    //         std::cin.ignore(); // Clear newline from input buffer
    //         Member *memberToModify = findMemberByID(memberList2, id);
    //         if (memberToModify)
    //         {
    //             std::cout << "Modifying member with ID: " << memberToModify->getMemberID() << "\n";
    //             // Modify member details
    //             // std::cout << "1. enter new member id: ";
    //             // std::cin >> memberID;
    //             // std::cin.ignore();

    //             std::cout << "2. enter new member name (enter to keep as is): ";
    //             std::cin >> memberName;
    //             std::cin.ignore(); // Clear newline from input buffer
    //             if (!memberName.empty())
    //             {
    //                 memberToModify->name = memberName;
    //             }

    //             std::cout << "3. enter new member address  (enter to keep as is ): ";
    //             std::cin >> memberAddress;
    //             std::cin.ignore();

    //             std::cout << "4. enter new member phone number (enter to keep as is ): ";
    //             std::cin >> memberPhoneNumber;
    //             std::cin.ignore();

    //             if (!memberName.empty())
    //             {
    //                 memberToModify->name = memberName;
    //             }
    //             if (!memberAddress.empty())
    //             {
    //                 memberToModify->address = memberAddress;
    //             }
    //             if (!memberPhoneNumber.empty())
    //             {
    //                 memberToModify->phoneNumber = memberPhoneNumber;
    //             }
    //         }
    //         else
    //         {
    //             std::cout << "Member with ID " << id << " not found.\n";
    //         }
    //     }
    //     break;
    //     case 5:
    //         // before existing. write the records to file.
    //         // if the file was previously empty will need to write header first,
    //         // otherwise just proceed to write actual record content.
    //         {
    //             std::ofstream myfile;
    //             std::ifstream file("members.csv");
    //             myfile.open("members.csv");
    //             bool header_set = false;
    //             for (const auto &member : memberList2)
    //             {
    //                 // todo. continue modifying from here
    //                 std::cout << "ID: " << std::to_string(member.getMemberID())
    //                           << ", Name: " << member.getMemberName()
    //                           << ", Address: " << member.getMemberAddress() << "\n";

    //                 string record1 = std::to_string(member.getMemberID()) + "," +
    //                                  member.getMemberName() + "," +
    //                                  member.getMemberAddress() + "," +
    //                                  member.getMemberPhoneNumber() + ",";
    //                 if (is_member_file_empty(file) && header_set == false)
    //                 {
    //                     // the header only needs to be written once.
    //                     myfile << "MemberId, name, address, phone_number\n";
    //                     header_set = true;
    //                 }
    //                 myfile << record1;
    //             }
    //             myfile.close();
    //             file.close();
    //             std::cout << "Exiting...\n";
    //         }
    //         break;
    //     default:
    //         std::cout << "Invalid choice. Please try again.\n";
    //     }
    // } while (choice != 5);

    

    return 0;
}
