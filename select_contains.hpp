#include "select.hpp"
#include "spreadsheet.hpp"
#include <string>

using namespace std;

class Select_Contains : public Select{
	
	public:
		 Select_Contains(const Spreadsheet* sheet, string& column, string& name){
			column_num = sheet->get_column_by_name(column);
			this->name = name;
			}

		  bool select(const Spreadsheet* sheet, int row) const{
				if (column_num != -1){
					dataa = cell_data(row,column_num)
					//if(dataa.find(name) != std::string::npos){
					if (dataa.contains(name){
						return true;
					}
					else{
						return false;
				}
				else {return false;}
			}
		}


	protected:

    		int column_num;
		string dataa;
		string name;	
	

}; 
