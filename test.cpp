#include "spreadsheet.hpp"
#include "spreadsheet.cpp"
#include "select.hpp"
#include "gtest/gtest.h"

using namespace std;

TEST(SampleTests, testing_Not) {
    Spreadsheet sheet;
    sheet.set_column_names({"First", "Second", "Third"});
    sheet.add_row({"one", "two", "three"});
    sheet.add_row({"four", "five", "six"});
    sheet.add_row({"seven", "eight", "nine"});

    string expected = "four five six \n";
    stringstream out;
    sheet.set_selection(new Select_Not(new Select_Contains(&sheet, "First", "e")));
    EXPECT_EQ(out.str(), expected);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
