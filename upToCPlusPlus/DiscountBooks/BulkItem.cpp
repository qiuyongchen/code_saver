#include "BookItem.h"
#include "BulkItem.h"
BulkItem::BulkItem(const string& bookName, double salesPrice,
	  int qty, double salesDisc):BookItem(bookName, salesPrice) {
   minQty_ = qty;
   discount_ = salesDisc;
 }

double BulkItem::netPrice(int cnt) const {

  if (cnt > minQty_) {
    return discount_ * BookItem::netPrice(cnt);
  } else {
    return BookItem::netPrice(cnt);
  }

}

