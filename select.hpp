#ifndef __SELECT_HPP__
#define __SELECT_HPP__

#include <cstring>
#include <string>

#include <iostream>

#include "spreadsheet.hpp"


using namespace std;

class Select
{
public:
    virtual ~Select() = default;

    // Return true if the specified row should be selected.
    virtual bool select(const Spreadsheet* sheet, int row) const = 0;
};

// A common type of criterion for selection is to perform a comparison based on
// the contents of one column.  This class contains contains the logic needed
// for dealing with columns. Note that this class is also an abstract base
// class, derived from Select.  It introduces a new select function (taking just
// a string) and implements the original interface in terms of this.  Derived
// classes need only implement the new select function.  You may choose to
// derive from Select or Select_Column at your convenience.
class Select_Column: public Select
{
protected:
    int column;
public:
    Select_Column(const Spreadsheet* sheet, const std::string& name)
    {
        column = sheet->get_column_by_name(name);
    }

    virtual bool select(const Spreadsheet* sheet, int row) const
    {
        return select(sheet->cell_data(row, column));
    }

    // Derived classes can instead implement this simpler interface.
    virtual bool select(const std::string& s) const = 0;
};


class Select_Contains : public Select{
	
	private:
		int column_num;
		//string dataa;
		string name;
	
	public:
			Select_Contains(const Spreadsheet* sheet, const string& column, const string& name){
			column_num = sheet->get_column_by_name(column);
			this->name = name;
			}

		  bool select(const Spreadsheet* sheet, int row) const{
				if (column_num != -1){
					//dataa = cell_data(row,column_num)
					if((sheet->cell_data(row,column_num)).find(name) != std::string::npos){
						//if (dataa.contains(name){
							return true;
					}
					else{}
				}
				return false;
}};


class Select_And : public Select{

        public:
                 Select_And(Select* leftside, Select* rightside){
                        lhs = leftside;
			rhs = rightside;
                        }

                  bool select(const Spreadsheet* sheet, int row) const{
			if(lhs->select(sheet, row) && rhs->select(sheet, row)){return true;}
			else {return false;}
			}

		~Select_And(){
			delete rhs;
			delete lhs;
			}

        private:
                Select* lhs;
		Select* rhs;
};


class Select_Or : public Select {
  private:
        Select* left;
        Select* right;
  public:
        Select_Or(Select* inLeft, Select* inRight) {
            left = inLeft;
            right = inRight;
        }

        ~Select_Or() {
            delete left;
            delete right;
        }

        bool select(const Spreadsheet* sheet, int row) const {
            bool leftSel = left->select(sheet, row);
            bool rightSel = right->select(sheet,row);

            if (leftSel || rightSel)
                return true;
            else
                return false;

	}
};


class Select_Not : public Select {
  private:
        Select* chosen;

  public:
        Select_Not (Select* input) {
            chosen = input;
        }

        ~Select_Not() {
            delete chosen;
        }

        bool select(const Spreadsheet* sheet, int row) const {
            if (chosen->select(sheet,row)) {
                return false;
            }
            else {
                return true;
            }
        }
};


#endif //__SELECT_HPP__
