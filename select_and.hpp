#ifndef __SELECT_AND_HPP__
#define __SELECT_AND_HPP__

#include "select.hpp"
#include "spreadsheet.hpp"
#include <string>

using namespace std;

class Selec_And : public Select{

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

#endif	
