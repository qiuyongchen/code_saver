/***********************************************************
/* Kruskal Algorithm.
/*
/* main.cpp
/*
/* implemented by SomebodyWho
/*
***********************************************************/
#include "graphMatrix.h"
#include <iostream>
using namespace std;

int main() {
    graphMatrix m;
    cin >> m;
    cout << m;
    m.repeat();
    m.showEdge();
    return 0;
}
