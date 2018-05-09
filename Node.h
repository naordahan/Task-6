#include <iostream>
using namespace std;

class Node{
  
    char data;
  
 public:
    Node();
    Node(char d);
    Node(const Node& n);
    char getNode() const;
    Node& operator=(char d);
    bool operator==(char c) const;
    bool operator==(const Node& o) const;
    bool operator!=(char c) const;
    bool operator!=(const Node& n) const;
    friend ostream& operator<< (ostream& os, Node& n);
};

//operator <<
inline ostream& operator<< (ostream& os, Node& n)
{
    os << n.getNode();
    return os;
}
