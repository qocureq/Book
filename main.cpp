#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <climits>
#include "book.h"

int main()
{
    std::vector<book> collection;
    int choice;
    do
    {

        std::cout << "Menu : " << std::endl;
        std::cout << "1. Add a book" << std::endl;
        std::cout << "2. Delete a book" << std::endl;
        std::cout << "3. Reports" << std::endl;
        std::cout << "5. Save collection to file" << std::endl;
        std::cout << "6. Load collection from file" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cin >> choice;
        if (choice == 1)
        {
            book::addbook(collection);
        }
        else if (choice == 2)
        {
            book::deletebook(collection);
        }
        else if (choice == 3)
        {
            int report;
            do
            {
                std::cout << "Choose report : " << std::endl;
                std::cout << "1. Show all books by the same author" << std::endl;
                std::cout << "2. Show all books of a given genre" << std::endl;
                std::cout << "3. Show all books of a given genre and publisher" << std::endl;
                std::cout << "4. Show the name of the publisher with the maximum quantity of the books" << std::endl;
                std::cout << "5. Show TOP-3 genres (popularity is determined by the number of books in the genre)" << std::endl;
                std::cout << "6. Show all books" << std::endl;
                std::cout << "7. Back to menu" << std::endl;
                std::cin >> report;
                if (report == 1)
                {
                    book::showbooksbyauthor(collection);
                }
                else if (report == 2)
                {
                    book::showbooksbygenre(collection);
                }
                else if (report == 3)
                {
                    book::showbooksbygenreandpublisher(collection);
                }
                else if (report == 4)
                {
                    book::showpublisherwithmaxbooks(collection);
                }
                else if (report == 5)
                {
                    book::showtop3genres(collection);
                }
                else if (report == 6)
                {
                    book::printbooks(collection);
                }
                else if (report == 7)
                {
                    break;
                }
                else
                {
                    std::cout << "Invalid input" << std::endl;
                }
            } while (report != 8);
        }
        else if (choice == 5)
        {
            book::savecollectiontofile(collection);
        }
        else if (choice == 6)
        {
            book::loadcollectionfromfile(collection);
        }
        else if (choice == 7)
        {
            break;
        }
        else
        {
            std::cout << "Invalid input" << std::endl;
        }
    } while (choice != 7);
    return 0;
}
