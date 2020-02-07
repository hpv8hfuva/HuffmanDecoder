//Hunter Vaccaro
//hpv8hf
//9/8/2019
//heapNode.cpp

#include <iostream>
#include <string>
#include "huffNode.h"


using namespace std;

huffNode::huffNode(){
  hold = "-1";
  left = NULL;
  right = NULL;
}
huffNode::huffNode(string a){
  hold = a;
  left = NULL;
  right = NULL;
}

