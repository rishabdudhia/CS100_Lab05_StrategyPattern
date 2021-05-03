#include "select.hpp"
#include "spreadsheet.hpp"
#include <string>

using namespace std;

class Select_Contains{
	
	public:
		vector<T> Select_Contains(const Spreadsheet* sheet, string& column, string& name){
			column_num = sheet->get_column_by_name(column);
			if (column_num != -1){
				for(unisgned int i = 0; i < data.size(); i++){
					dataa = cell_data(i,column_num)
					//if(dataa.find(name) != std::string::npos){
					if (dataa.contains(name){
						rows_selected.pushback(i);
					}
					else{}
				}
			}
		return rows_slected;


	protected:
		vector<int> rows_selected;	
    		int column_num;
		string dataa;	
	

}; 
