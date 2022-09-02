#include "book.h"
#include<iostream>
#include<string>
book::book(std::string name, std::string author, std::string genre, int year, std::string publisher, int pages)
{
    this->name = name;
    this->author = author;
    this->genre = genre;
    this->year = year;
    this->publisher = publisher;
    this->pages = pages;
}

void book::addbook(std::vector<book>& collection)
{
    std::string name;
    std::string author;
    std::string genre;
    int year;
    std::string publisher;
    int pages;
    std::cin.ignore();
    std::cout << "Enter book name : "<< std::endl;
    std::getline(std::cin, name);
    std::cout << "Enter author's name : " << std::endl;
    std::getline(std::cin, author);
    std::cout << "Enter genre : " << std::endl;
    std::getline(std::cin, genre);
    std::cout << "Enter year : " << std::endl;
    std::cin >> year;
    std::cin.ignore();
    std::cout << "Enter publisher : " << std::endl;
    std::getline(std::cin, publisher);
    std::cout << "Enter number of pages : " << std::endl;
    std::cin >> pages;
    book newbook(name, author, genre, year, publisher, pages);
    collection.push_back(newbook);
}

void book::deletebook(std::vector<book>&collection)
{
    std::string name;
    std::cout << "Enter the name of the book you want to delete : " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, name);
    int i = 0;
    for (auto it = collection.begin(); it != collection.end(); it++)
    {
        if ((*it).name == name)
        {
            collection.erase(it);
            std::cout << "Book deleted" << std::endl;
            break;
        }
        i++;
    }
    if (i == collection.size())
    {
        std::cout << "Book not found" << std::endl;
    }
}


void book::printbooks(std::vector<book> collection)
{
    std::cout << "Name | Author | Genre | Year | Publisher | Pages" << std::endl;
    for (auto it = collection.begin(); it != collection.end(); it++)
    {
        std::cout << (*it).name << " | " << (*it).author << " | " << (*it).genre << " | " << (*it).year << " | " << (*it).publisher << " | " << (*it).pages << std::endl;
    }
}

void book::showbooksbyauthor(std::vector<book> collection)
{
    bool flag;
    std::string name;
    std::cout << "Enter author's name : " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, name);
    int i = 0;
    for (auto it = collection.begin(); it != collection.end(); it++)
    {
        if ((*it).author == name)
        {
            std::cout << (*it).name << " | " << (*it).author << " | " << (*it).genre << " | " << (*it).year << " | " << (*it).publisher << " | " << (*it).pages << std::endl;
            flag = true;
        }
    }
    if (!flag)
    {
        std::cout << "Books not found" << std::endl;
    }
}

void book::showbooksbygenre(std::vector<book> collection)
{
    bool flag;
    std::string name;
    std::cout << "Enter genre : " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, name);
    int i = 0;
    for (auto it = collection.begin(); it != collection.end(); it++)
    {
        if ((*it).genre == name)
        {
            std::cout << (*it).name << " | " << (*it).author << " | " << (*it).genre << " | " << (*it).year << " | " << (*it).publisher << " | " << (*it).pages << std::endl;
        }
        flag = true;
    }
    if (!flag)
    {
        std::cout << "Books not found" << std::endl;
    }
}

void book::showbooksbygenreandpublisher(std::vector<book> collection)
{
    bool flag;
    std::string name;
    std::string publisher;
    std::cout << "Enter genre : " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter publisher : " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, publisher);
    int i = 0;
    for (auto it = collection.begin(); it != collection.end(); it++)
    {
        if ((*it).genre == name && (*it).publisher == publisher)
        {
            std::cout << (*it).name << " | " << (*it).author << " | " << (*it).genre << " | " << (*it).year << " | " << (*it).publisher << " | " << (*it).pages << std::endl;
        }
        flag = true;
    }
    if (!flag)
    {
        std::cout << "Books not found" << std::endl;
    }
}

void book::showpublisherwithmaxbooks(std::vector<book> collection)
{
    if(collection.empty())
    {
        std::cout << "Books not found" << std::endl;
        return;
    }

    std::vector<int> count;
    std::vector<std::string> publisher;
    for (auto it = collection.begin(); it != collection.end(); it++)
    {
        if (find(publisher.begin(), publisher.end(), (*it).publisher) == publisher.end())
        {
            publisher.push_back((*it).publisher);
            count.push_back(1);
        }
        else
        {
            int i = 0;
            for (auto itr = publisher.begin(); itr != publisher.end(); itr++)
            {
                if ((*it).publisher == (*itr))
                {
                    count[i]++;
                    break;
                }
                i++;
            }
        }
    }
    int max = INT_MIN;
    int index;
    int i = 0;
    for (auto it = count.begin(); it != count.end(); it++)
    {
        if ((*it) > max)
        {
            max = (*it);
            index = i;
        }
        i++;
    }
    std::cout << "Publisher : " << publisher[index] << " | Number of books : " << max << std::endl;
}

void book::showtop3genres(std::vector<book> collection)
{
    if(collection.empty())
    {
        std::cout << "Books not found" << std::endl;
        return;
    }
    std::vector<int> count;
    std::vector<std::string> genre;
    for (auto it = collection.begin(); it != collection.end(); it++)
    {
        if (find(genre.begin(), genre.end(), (*it).genre) == genre.end())
        {
            genre.push_back((*it).genre);
            count.push_back(1);
        }
        else
        {
            int i = 0;
            for (auto itr = genre.begin(); itr != genre.end(); itr++)
            {
                if ((*it).genre == (*itr))
                {
                    count[i]++;
                    break;
                }
                i++;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        int max = INT_MIN;
        int index;
        int j = 0;
        for (auto it = count.begin(); it != count.end(); it++)
        {
            if ((*it) > max)
            {
                max = (*it);
                index = j;
            }
            j++;
        }
        std::cout << "Genre : " << genre[index] << " | Number of books : " << max << std::endl;
        count.erase(count.begin() + index);
        genre.erase(genre.begin() + index);
    }
}

void book::savecollectiontofile(std::vector<book> collection)
{
    std::ofstream fout;
    fout.open("bookcollection.txt", std::ios::out);
    for (auto it = collection.begin(); it != collection.end(); it++)
    {
        fout << (*it).name << "|" << (*it).author << "|" << (*it).genre << "|" << (*it).year << "|" << (*it).publisher << "|" << (*it).pages << std::endl;
    }
    fout.close();
}


void book::loadcollectionfromfile(std::vector<book>&collection)
{
    std::ifstream fin;
    fin.open("bookcollection.txt", std::ios::in);
    std::string name;
    std::string author;
    std::string genre;
    std::string year;
    int i_year;
    std::string publisher;
    std::string pages;
    int i_pages;
    while (!fin.eof())
    {
        if(fin.peek() == EOF) { break; };
        std::getline(fin, name, '|');
        std::getline(fin, author, '|');
        std::getline(fin, genre, '|');
        std::getline(fin, year, '|');
        std::getline(fin, publisher, '|');
        std::getline(fin, pages, '\n');
        i_year = std::stoi(year);
        i_pages = std::stoi(pages);
        book newbook(name, author, genre, i_year, publisher, i_pages);
        collection.push_back(newbook);

    }
    fin.close();
}
