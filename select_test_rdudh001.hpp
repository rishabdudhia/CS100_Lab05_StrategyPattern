#ifndef __SELECT_TEST_RDUDH001_HPP__
#define __SELECT_TEST_RDUDH001_HPP__

#include "gtest/gtest.h"

#include "select.hpp"
#include "spreadsheet.hpp"
#include "spreadsheet.cpp"

using namespace std;

TEST(SelectTest, TestNormalOr){
    Spreadsheet sheet;
    sheet.set_column_names({"First","Second","Third"});
    sheet.add_row({"one", "two", "three"});
    sheet.add_row({"four", "five", "six"});
    sheet.add_row({"seven", "eight", "nine"});

    stringstream out;
    sheet.set_selection(new Select_Or(new Select_Contains(&sheet, "First", "e"), new Select_Contains(&sheet, "First", "v")));
    sheet.print_selection(out);

    string expected = "one two three \nfour five six \nseven eight nine \n";

    EXPECT_EQ(out.str(), expected);
}

TEST(SelectTest, TestCaptialOr) {
    Spreadsheet sheet;
    sheet.set_coloumn_names({"Front", "Last"});
    sheet.add_row({"Rishab", "Dudhia"});
    sheet.add_row({"Fadi", "Zaki"});

    stringstream out;
    sheet.set_selection(new Select_Or(new Select_Contains(&sheet, "Last", "Z"), new Select_Contains(&sheet, "Last", "D")));
    sheet.print_selection(out);

    string expected = "Rishab Dudhia \nFadi Zaki \n";
  
    EXPECT_EQ(out.str(), expected);
}
    
TEST(SelectTest, WrongColumn){
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    sheet.add_row({"Carol","Conners","21","computer science"});
    sheet.add_row({"Joe","Jackson","21","mathematics"});
    sheet.add_row({"Sarah","Summers","21","computer science"});
    sheet.add_row({"Diane","DOLE","20","computer engineering"});
    sheet.add_row({"David","Dole","22","electrical engineering"});
    sheet.add_row({"Dominick","DOLE","22","communications"});
    sheet.add_row({"George","Genius","9","astrophysics"});

    stringstream out;
    sheet.set_selection(new Select_Or(new Select_Contains(&sheet, "age", "2"), new Select_Contains(&sheet, "age", "1")));
    sheet.print_selection(out);
    
    string expected = "";

    EXPECT_EQ(out.str(), expected);
}


#endif

