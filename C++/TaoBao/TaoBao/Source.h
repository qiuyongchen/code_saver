#include "Taobao.h"

class SortByPrice : public SortInterface {
 public:
    virtual void DoSort(TaoBaoItem item[], int size);
};

void SortByPrice::DoSort(TaoBaoItem item[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i; j < size; j++) {
            // 1. meet a big fool, prepare to kill(swap) him.
            // 2. if the price is the same, then we have no need to swap
            // they two big fool if the sales of the first one is larger
            // than the that of the second, or we have to swap them so that
            // the one whose sale is larger can be located to the front and
            // the smaller one will be downed to be located to the front at
            // the next loop.
            if ((item[j].price > item[i].price) ||
                (item[j].price == item[i].price) &&
                (item[j].volume_of_sales > item[i].volume_of_sales)) {
                // swap the price.
                int priceTemp = item[j].price;
                item[j].price = item[i].price;
                item[i].price = priceTemp;
                // swap the sale.
                int saleItem = item[j].volume_of_sales;
                item[j].volume_of_sales = item[i].volume_of_sales;
                item[i].volume_of_sales = saleItem;
            }
        }
    }
}

class SortBySales : public SortInterface {
 public:
    virtual void DoSort(TaoBaoItem item[], int size);
};

void SortBySales::DoSort(TaoBaoItem item[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i; j < size; j++) {
            if ((item[j].volume_of_sales > item[i].volume_of_sales) ||
                (item[j].price > item[i].price) &&
                (item[j].volume_of_sales == item[i].volume_of_sales)) {
                // swap the price.
                int priceTemp = item[j].price;
                item[j].price = item[i].price;
                item[i].price = priceTemp;
                // swap the sale.
                int saleItem = item[j].volume_of_sales;
                item[j].volume_of_sales = item[i].volume_of_sales;
                item[i].volume_of_sales = saleItem;
            }
        }
    }
}

class TaoBao {
 public:
    explicit TaoBao(SortInterface *strategy);
    void SetSortStrategy(SortInterface *strategy_);
    void sort(TaoBaoItem item[], int size);
 private:
    SortInterface *strategy;
};

TaoBao::TaoBao(SortInterface* strategy_) {
    strategy = strategy_;
}

void TaoBao::SetSortStrategy(SortInterface* strategy_) {
    strategy = strategy_;
}

void TaoBao::sort(TaoBaoItem item[], int size) {
    strategy->DoSort(item, size);
}
