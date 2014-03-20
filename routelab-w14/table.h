#ifndef _table
#define _table


#include <iostream>
#include <map>
#include "limits"

using namespace std;

//test

#if defined(GENERIC)
class Table {
 public:
  ostream & Print(ostream &os) const;
};
#endif


#if defined(LINKSTATE)
class Table {
  // Students should write this class

 public:
  ostream & Print(ostream &os) const;
};
#endif

#if defined(DISTANCEVECTOR)

#include <deque>

struct Row {
  unsigned dest_node;
  unsigned next_node;
  double cost;
  ostream &Print(ostream &os) const;

  Row(unsigned dest, unsigned next, double cost);
};

inline ostream & operator<<(ostream &os, const Row &r) { return r.Print(os);}

class Table {
  deque<Row> m;
 public:

    //first int is source, second dest. double is cost
    map<pair<int,int>,double> costTable;
	double findCost(int srcNode,int destNode);
	void updateCost(int srcNode, int destNode, double newCost);
	void insertCost(int src, int dest, double newCost);
	
  deque<Row>::iterator FindMatching(const unsigned dest);
  Row *GetNext(const unsigned dest);
  void SetNext(const unsigned dest, const Row &r);
  ostream & Print(ostream &os) const;
};
#endif

inline ostream & operator<<(ostream &os, const Table &t) { return t.Print(os);}

#endif
