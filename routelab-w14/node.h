#ifndef _node
#define _node

#include <new>
#include <iostream>
#include <deque>
#include "table.h"

class RoutingMessage;
//class Table;
class Link;
class SimulationContext;

using namespace std;

class Node {
 private:
  unsigned number;
  struct SimulationContext    *context; //added
  //Table table;

  double   bw;
  double   lat;

#if defined(LINKSTATE)
  static const unsigned maxttl;
  unsigned seqno;
#endif

#if defined(DISTANCEVECTOR)
  Table table;
 

  // students will add protocol-specific data here

 public:
  
  friend class Table;
 
  Node(const unsigned n, SimulationContext *c, double b, double l);
  Node();
  Node(const Node &rhs);
  Node & operator=(const Node &rhs);
  virtual ~Node();

  virtual bool Matches(const Node &rhs) const;

  virtual void SetNumber(const unsigned n);
  virtual unsigned GetNumber() const;

  virtual void SetLatency(const double l);
  virtual double GetLatency() const;
  virtual void SetBW(const double b);
  virtual double GetBW() const;

  virtual void SendToNeighbors(const RoutingMessage *m);
  virtual void SendToNeighbor(const Node *n, const RoutingMessage *m);
  virtual deque<Node*> *GetNeighbors();
  virtual void SetTimeOut(const double timefromnow);

  //
  // Students will WRITE THESE
  //
  virtual void LinkUpdate(const Link *l);
  virtual void ProcessIncomingRoutingMessage(const RoutingMessage *m);
  virtual void TimeOut();
  virtual Node *GetNextHop(const Node *destination) const;
  virtual Table *GetRoutingTable() const;

  virtual ostream & Print(ostream &os) const;

};
#endif
inline ostream & operator<<(ostream &os, const Node &n) { return n.Print(os);}


#endif
