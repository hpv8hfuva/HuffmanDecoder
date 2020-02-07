// This program is the skeleton code for the lab 10 in-lab.  It uses
// C++ streams for the file input, and just prints out the data when
// read in from the file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "huffNode.h"
#include <stdlib.h>
using namespace std;

// main(): we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file; must be opened in binary
    // mode, as otherwise whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    // read in the first section of the file: the prefix codes
    huffNode* placement = new huffNode();
    huffNode* root  = placement;
    while ( true ) {
        string character, prefix;
        // read in the first token on the line
        file >> character;
	
        // did we hit the separator?
        if ( (character[0] == '-') && (character.length() > 1) )
            break;
        // check for space
        if ( character == "space" )
            character = " ";
        // read in the prefix code
        file >> prefix;
	string holderofprefix = prefix;
	while(prefix.length() > 1){
	  string temp = prefix.substr(0,1);
	  if(temp == "0"){
	    if(placement->left != NULL){
	      placement = placement -> left;
	    }
	    else if(placement->left == NULL){
	      huffNode* mover = new huffNode();
	      placement -> left = mover;
	      placement = placement -> left;
	    }
	  }
	  else if(temp == "1"){
	    if(placement->right != NULL){
	      placement = placement -> right;
	    }
	    else if(placement->right == NULL){
	      huffNode* mover = new huffNode();
	      placement -> right = mover;
	      placement = placement -> right;
	    }
	  }
	  prefix = prefix.substr(1);
	}
	if(prefix == "1"){
	  huffNode* answ = new huffNode(character);
	  placement -> right = answ;
	  placement = root;
	}
	if(prefix == "0"){
          huffNode* answ = new huffNode(character);
	  placement -> left = answ;
	  placement = root;
	}
        // do something with the prefix code
	// cout << "character '" << character << "' has prefix code '"
	//   << holderofprefix << "'" << endl;
    }
    // read in the second section of the file: the encoded message
    stringstream sstm;
    while ( true ) {
        string bits;
        // read in the next set of 1's and 0's
	file >> bits;
	string zap = bits;
	string tracker = "";
	while(zap.length() >0){
	  string zap1 = zap.substr(0,1);
	  if(zap1 == "1"){
	    placement = placement -> right;
	  }
	  if(zap1 == "0"){
	    placement = placement -> left;
	  }
	  if(placement->left == NULL && placement->right ==NULL){
	    tracker = placement->hold;
	    placement = root;
	  }
	  zap=zap.substr(1);
	}
        // check for the separator
        if ( bits[0] == '-' )
            break;
        // add it to the stringstream
	   sstm << tracker;
    }
     string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    cout  << allbits << endl;
    // close the file before exiting
    file.close();
}
