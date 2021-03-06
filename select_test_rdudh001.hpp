#ifndef __SELECT_TEST_RDUDH001_HPP__
#define __SELECT_TEST_RDUDH001_HPP__

#include "gtest/gtest.h"

#include "select.hpp"
#include "spreadsheet.hpp"

using namespace std;


//OR tests
TEST(SelectTest, TestNormalOr){
    Spreadsheet sheet;
    sheet.set_column_names({"First","Second","Third"});
    sheet.add_row({"one", "two", "three"});
    sheet.add_row({"four", "five", "six"});
    sheet.add_row({"seven", "eight", "nine"});

    stringstream out;
    sheet.set_selection(new Select_Or(new Select_Contains(&sheet, "First", "e"), new Select_Contains(&sheet, "First", "r")));
    sheet.print_selection(out);

    string expected = "one two three \nfour five six \nseven eight nine \n";

    EXPECT_EQ(out.str(), expected);
}

TEST(SelectTest, TestCaptialOr) {
    Spreadsheet sheet;
    sheet.set_column_names({"Front", "Last"});
    sheet.add_row({"Rishab", "Dudhia"});
    sheet.add_row({"Fadi", "Zaki"});

    stringstream out;
    sheet.set_selection(new Select_Or(new Select_Contains(&sheet, "Last", "Z"), new Select_Contains(&sheet, "Last", "D")));
    sheet.print_selection(out);

    string expected = "Rishab Dudhia \nFadi Zaki \n";
  
    EXPECT_EQ(out.str(), expected);
}
    
TEST(SelectTest, OrWrongColumn){
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

TEST (SelectTest, ORandAND) {
    Spreadsheet sheet;
    sheet.set_column_names({"First", "Last", "Position"});
    sheet.add_row({"Lebron", "James", "Power Forward"});
    sheet.add_row({"Steph", "Curry", "Point Guard"});
    sheet.add_row({"Dame", "Lillard", "Point Guard"});
    sheet.add_row({"Joel", "Embiid", "Center"});
    sheet.add_row({"Anthony", "Davis", "Center"});
    sheet.add_row({"Kobe", "Bryant", "Shooting Guard"});

    stringstream out;
    sheet.set_selection(new Select_Or(
      new Select_And(
	new Select_Contains(&sheet, "Position", "Center"),
	new Select_Contains(&sheet, "Position", "Davis")),
      new Select_Contains(&sheet, "Position", "Guard")));
    sheet.print_selection(out);

    string expected = "Steph Curry Point Guard \nDame Lillard Point Guard \nKobe Bryant Shooting Guard \n";

    EXPECT_EQ(out.str(), expected);
}

TEST (SelectTest, OrNotFound) {
    Spreadsheet sheet;
    sheet.set_column_names({"First", "Last", "Position"});
    sheet.add_row({"Lebron", "James", "Power Forward"});
    sheet.add_row({"Steph", "Curry", "Point Guard"});
    sheet.add_row({"Dame", "Lillard", "Point Guard"});
    sheet.add_row({"Joel", "Embiid", "Center"});
    sheet.add_row({"Anthony", "Davis", "Center"});
    sheet.add_row({"Kobe", "Bryant", "Shooting Guard"});

    stringstream out;
    sheet.set_selection(new Select_Or(new Select_Contains(&sheet, "Last", "james"), new Select_Contains(&sheet, "Last", "davis")));
    sheet.print_selection(out);

    string expected = "";

    EXPECT_EQ(out.str(), expected);
}

TEST (SelectTest, OrAllCaps) {
    Spreadsheet sheet;
    sheet.set_column_names({"FIRST", "SECOND", "THIRD"});
    sheet.add_row({"ONE", "TWO", "THREE"});
    sheet.add_row({"FOUR", "FIVE", "SIX"});
    sheet.add_row({"SEVEN", "EIGHT", "NINE"});

    stringstream out;
    sheet.set_selection(new Select_Or(new Select_Contains(&sheet, "SECOND", "FIVE"), new Select_Contains(&sheet, "THIRD", "FOUR")));
    sheet.print_selection(out);

    string expected = "FOUR FIVE SIX \n";

    EXPECT_EQ(out.str(), expected);
}



//NOT tests
TEST (SelectTest, NormalNot) {
    Spreadsheet sheet;
    sheet.set_column_names({"First", "Last", "Position"});
    sheet.add_row({"Lebron", "James", "Power Forward"});
    sheet.add_row({"Steph", "Curry", "Point Guard"});
    sheet.add_row({"Dame", "Lillard", "Point Guard"});
    sheet.add_row({"Joel", "Embiid", "Center"});
    sheet.add_row({"Anthony", "Davis", "Center"});
    sheet.add_row({"Kobe", "Bryant", "Shooting Guard"});

    stringstream out;
    sheet.set_selection(new Select_Not(new Select_Contains(&sheet, "First", "e")));
    sheet.print_selection(out);

    string expected = "Anthony Davis Center \n";

    EXPECT_EQ(out.str(), expected);
}

TEST (SelectTest, CapitalNot) {
    Spreadsheet sheet;
    sheet.set_column_names({"First", "Last", "Position"});
    sheet.add_row({"Lebron", "James", "Power Forward"});
    sheet.add_row({"Steph", "Curry", "Point Guard"});
    sheet.add_row({"Dame", "Lillard", "Point Guard"});
    sheet.add_row({"Joel", "Embiid", "Center"});
    sheet.add_row({"Anthony", "Davis", "Center"});
    sheet.add_row({"Kobe", "Bryant", "Shooting Guard"});

    stringstream out;
    sheet.set_selection(new Select_Not(
      new Select_Or(
	new Select_Contains(&sheet, "First", "L"),
	new Select_Contains(&sheet, "Last", "L"))));
    sheet.print_selection(out);

    string expected = "Steph Curry Point Guard \nJoel Embiid Center \nAnthony Davis Center \nKobe Bryant Shooting Guard \n";

    EXPECT_EQ(out.str(), expected);
}

TEST (SelectTest, NotWrongColumn) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Second","Third"});
    sheet.add_row({"one", "two", "three"});
    sheet.add_row({"four", "five", "six"});
    sheet.add_row({"seven", "eight", "nine"});

    stringstream out;
    sheet.set_selection(new Select_Not(new Select_Contains(&sheet, "apple", "x")));
    sheet.print_selection(out);

    string expected = "one two three \nfour five six \nseven eight nine \n";;

    EXPECT_EQ(out.str(), expected);
}

TEST (SelectTest, NotNoReturn) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Second","Third"});
    sheet.add_row({"one", "two", "three"});
    sheet.add_row({"foure", "five", "sixe"});
    sheet.add_row({"seven", "eight", "nine"});

    stringstream out;
    sheet.set_selection(new Select_Not(new Select_Contains(&sheet, "First", "e")));
    sheet.print_selection(out);

    string expected = "";

    EXPECT_EQ(out.str(), expected);
}

TEST (SelectTest, NotAllCaps) {
    Spreadsheet sheet;
    sheet.set_column_names({"FIRST", "SECOND", "THIRD"});
    sheet.add_row({"ONE", "TWO", "THREE"});
    sheet.add_row({"FOUR", "FIVE", "SIX"});
    sheet.add_row({"SEVEN", "EIGHT", "NINE"});

    stringstream out;
    sheet.set_selection(new Select_Not(new Select_Contains(&sheet, "SECOND", "FIVE")));
    sheet.print_selection(out);

    string expected = "ONE TWO THREE \nSEVEN EIGHT NINE \n";

    EXPECT_EQ(out.str(), expected);
}


#endif


