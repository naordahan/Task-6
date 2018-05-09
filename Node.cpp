
#include "Board.h"

//constructors
Node::Node(){}

Node::Node(char d)
{
    if(d=='X' || d== 'O' || d=='.')
        this->data = d;
    else{
        IllegalCharException e;
        e.setInput(data);
        throw e;
    }
}
Node::Node(const Node& n)
{
    this->data = n.getNode();
}


char Node::getNode() const
{
    return this->data;
}

Node& Node::operator=(char d)
{
   if(d=='X' || d=='O' || d=='.'){
        this->data = d;
        return *this;
   }
    else
    {
        IllegalCharException e;
        e.setInput(data);
        throw e;
    }
    return *this;
}

bool Node::operator==(char c) const
{
    return data == c;
}

bool Node::operator==(const Node& o) const
{
    return data== o.data;
}

bool Node::operator!=(char c) const {
    return data != c;
}

bool Node::operator!=(const Node& o) const {
    return data!= o.data;
}
