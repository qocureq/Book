#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#pragma once

class book
{
public:
    book(std::string name, std::string author, std::string genre, int year, std::string publisher, int pages);
    book();
    std::string name;
    std::string author;
    std::string genre;
    int year;
    std::string publisher;
    int pages;

    static void addbook(std::vector<book>& collection);
    static void deletebook(std::vector<book>& collection);
    static void printbooks(std::vector<book> collection);
    static void showbooksbyauthor(std::vector<book> collection);
    static void showbooksbygenre(std::vector<book> collection);
    static void showbooksbygenreandpublisher(std::vector<book> collection);
    static void showpublisherwithmaxbooks(std::vector<book> collection);
    static void showtop3genres(std::vector<book> collection);
    static void savecollectiontofile(std::vector<book> collection);
    static void loadcollectionfromfile(std::vector<book>& collection);
};

