#ifndef __SPREADSHEET_HPP__
#define __SPREADSHEET_HPP__

#include <string>
#include <initializer_list>
#include <vector>
#include <iosfwd>

class Select;

class Spreadsheet
{
    std::vector<std::string> column_names;
    std::vector<std::vector<std::string> > data;
    Select* select = nullptr;

public:
    ~Spreadsheet();

    const std::string& cell_data(int row, int column) const
    {
        return data.at(row).at(column);
    }

    std::string& cell_data(int row, int column)
    {
        return data.at(row).at(column);
    }

    void set_selection(Select* new_select);

    // TODO: Implement print_selection.
    void print_selection(std::ostream& out) const{
	
	if (select == null){
		for (unsigned int i = 0; i<column_names.size(); i++){
			for (unsigned int j = 0; j < column_names.size(); j++){
				out << data.at(i).at(j) << " "; //i=row j=column
				}
			out << endl;
			}
		}
	else {
		select->data;
		

    void clear();
    void set_column_names(const std::vector<std::string>& names);
    void add_row(const std::vector<std::string>& row_data);
    int get_column_by_name(const std::string& name) const;
};

#endif //__SPREADSHEET_HPP__
