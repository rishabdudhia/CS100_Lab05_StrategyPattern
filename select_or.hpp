#ifndef __SELECT_OR__
#define __SELECT_OR__

#include "select.hpp"

using namespace std;

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

#endif __SELECT_OR__
