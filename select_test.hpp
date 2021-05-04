#ifndef __SELECT_TEST_HPP__
#define __SELECT_TEST_HPP__

#include "gtest/gtest.h"

#include "select.hpp"
#include "spreadsheet.hpp"
#include "spreadsheet.cpp"

using namespace std;

TEST(SelectTest, ContainsOneLetter){
Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    sheet.add_row({"Carol","Conners","21","computer science"});
    sheet.add_row({"Joe","Jackson","21","mathematics"});
    sheet.add_row({"Sarah","Summers","21","computer science"});
    sheet.add_row({"Diane","Dole","20","computer engineering"});
    sheet.add_row({"David","Dole","22","electrical engineering"});
    sheet.add_row({"Dominick","Dole","22","communications"});
    sheet.add_row({"George","Genius","9","astrophysics"});

	string one = "Brian Becker 21 computer science \n";
	string two = "Joe Jackson 21 mathematics \n";
	string printed = one +two;

	stringstream ss;
	sheet.set_selection(new Select_Contains(&sheet, "Last", "c"));
	sheet.print_selection(ss);
	
	EXPECT_EQ(ss.str(), printed);
}

TEST(SelectTest, ContainsCapital){
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

        string one = "Brian Becker 21 computer science \n";
        string two = "Joe Jackson 21 mathematics \n";
        string printed = one +two;

        stringstream ss;
        sheet.set_selection(new Select_Contains(&sheet, "Last", "c"));
        sheet.print_selection(ss);

        EXPECT_EQ(ss.str(), printed);
}


#endif
