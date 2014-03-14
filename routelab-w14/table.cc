#include "table.h"
using namespace std;

#if defined(GENERIC)
ostream & Table::Print(ostream &os) const
{
  // WRITE THIS
  // for each row, call row.print
 os << "Table()";
  return os;
}
#endif

#if defined(LINKSTATE)

#endif

#if defined(DISTANCEVECTOR)

/*deque<Row>::iterator Table::FindMatching(const unsigned dest)
{
}

Row *Table::GetNext(const unsigned dest)
{
}

void Table::SetNext(const unsigned dest, const Row &r)
{
}
*/


//Our Function Implementations here:
//returns the estimated cost from src to destination
double Table::findCost(int src, int dest){
    pair<int,int> tmp(src,dest);
	if(costTable.find(tmp)==costTable.end()){
		cerr << "Couldn't find path " << src << " to " << dest << " in costTable.\n";
		return 9999999999;
	} else {
		return costTable.at(tmp);
	}

}

//updates the cost from src to dest to newCost
void Table::updateCost(int src, int dest, double newCost){
    pair<int,int> tmp(src,dest);
	if(costTable.find(tmp)==costTable.end()){
		cerr << "Couldn't find path " << src << " to " << dest << " in costTable.\n";
	} else if (findCost(src,dest)!=newCost){
		costTable[tmp]=newCost;
	}
}

void Table::insertCost(int src, int dest, double newCost){
    pair<int,int> tmp(src,dest);
    costTable[tmp] = newCost;
}

/*
Row::Row(const unsigned dest, const unsigned next, const double c) :
  dest_node(dest), next_node(next), cost(c)
{}

ostream & Row::Print(ostream &os) const
{
  os <<"Row(dest="<<dest_node<<", next="<<next_node<<", cost="<<cost<<")";
  return os;
}

ostream & Table::Print(ostream &os) const
{
  os<<"Table(rows={";
  for (deque<Row>::const_iterator i=m.begin();i!=m.end();++i) {
    os <<(*i)<<", ";
  }
  os<<"})";
  return os;
}
*/

#endif
