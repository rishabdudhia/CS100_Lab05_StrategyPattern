#ifndef __SELECT_NOT__
#define __SELECT_NOT__
#include "select.hpp"

using namespace std;

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

#endif __SELECT_NOT__
