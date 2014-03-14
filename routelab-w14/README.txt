Project 3: Routing Lab

Team members: Jordan Geltner(jge920) and Leesha Maliakal (lvm908)

Work completed by Jordan:
 - table.h: implement costTable design
 - table.cc: implement helper functions findCost, updateCost, and insertCost. These functions make the costTable work for nodes.
 - Node.cc: implement linkUpdate for DISTANCE_VECTOR, getting source and destination addresses and new cost from link. Sends a message to neighbors if routing table changes.
 - Node.cc: processIncomingRoutingMessages implemented; gets source and destination addresses and new cost from link, checks to see if changes affect our table, change them if they do, send message to neighbors if they do.


Work completed by Leesha:
 - table.h: modified to define table.cc functions
 - table.cc: implemented the distance vector algorithm
 - Node.h: modified to define variables, etc for Node.cc functions
 - Node.cc: modified GetNextHop(), GetRoutingTable()
 
 Additional notes: