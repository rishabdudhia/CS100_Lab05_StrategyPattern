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

        string one = "Diane DOLE 20 computer engineering \n";
        string two = "Dominick DOLE 22 communications \n";
        string printed = one +two;

        stringstream ss;
        sheet.set_selection(new Select_Contains(&sheet, "Last", "DOLE"));
        sheet.print_selection(ss);

        EXPECT_EQ(ss.str(), printed);
}

TEST(SelectTest, ContainsNULL){
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

    string printed = "Amanda Andrews 22 business \nBrian Becker 21 computer science \nCarol Conners 21 computer science \nJoe Jackson 21 mathematics \nSarah Summers 21 computer science \nDiane DOLE 20 computer engineering \nDavid Dole 22 electrical engineering \nDominick DOLE 22 communications \nGeorge Genius 9 astrophysics \n";
        stringstream ss;
        sheet.set_selection(new Select_Contains(&sheet, "Last", ""));
        sheet.print_selection(ss);

        EXPECT_EQ(ss.str(), printed);
}

TEST(SelectTest, CapandNotMixed){
 Spreadsheet sheet;
 sheet.set_column_names({"Name","Pet"});
 sheet.add_row({"Frank", "Dog"});
 sheet.add_row({"Roxie", "dog"});
 sheet.add_row({"Rex", "ddogs"});

stringstream ss; 
string printed = "Roxie dog \nRex ddogs \n";
sheet.set_selection(new Select_Contains(&sheet, "Pet", "do"));
        sheet.print_selection(ss);

        EXPECT_EQ(ss.str(), printed);
}


TEST(SelectTest, DoubbleAND){
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

        string printed = "Amanda Andrews 22 business \n";

        stringstream ss;
       sheet.set_selection(
         new Select_And(
               new Select_Contains(&sheet,"First","Amanda"),
                         new Select_And(
                                new Select_Contains(&sheet,"Last","r"),
       			                 new Select_Contains(&sheet,"Age","2"))));
        sheet.print_selection(ss);

        EXPECT_EQ(ss.str(), printed);
}

TEST(SelectTest, AndWithNoResult){
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

        string printed = "";

        stringstream ss;
       sheet.set_selection(
         new Select_And(
               new Select_Contains(&sheet,"First","Amanda"),
                         new Select_And(
                                new Select_Contains(&sheet,"Last","r"),
                                         new Select_Contains(&sheet,"Age","9"))));
        sheet.print_selection(ss);

        EXPECT_EQ(ss.str(), printed);
}

TEST(SelectTest, AndWrongColumn){
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

        string printed = "";

        stringstream ss;
       sheet.set_selection(
         new Select_And(
               new Select_Contains(&sheet,"first","Amanda"),
                         new Select_And(
                                new Select_Contains(&sheet,"Last","r"),
                                         new Select_Contains(&sheet,"Age","2"))));
        sheet.print_selection(ss);

        EXPECT_EQ(ss.str(), printed);
}

TEST(SelectTest, And_Not_Or){
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

        string printed = "Amanda Andrews 22 business \nBrian Becker 21 computer science \nCarol Conners 21 computer science \nSarah Summers 21 computer science \n";

        stringstream ss;
       sheet.set_selection(
         new Select_Or(
               new Select_Contains(&sheet,"First","A"),
                         new Select_And(
                                new Select_Contains(&sheet,"Last","r"),
                                         new Select_Not(new Select_Contains(&sheet,"Age","0")))));
        sheet.print_selection(ss);

        EXPECT_EQ(ss.str(), printed);
}


#endif
