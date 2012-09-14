//
//  RegexMatcher.h
//  RegexMatcher
//
//  Created by Yating Sheng on 9/14/12.
//  Copyright 2012 University of Michigan . All rights reserved.
//

#ifndef RegexMatcher_RegexMatcher_h
#define RegexMatcher_RegexMatcher_h

class RegexMatcher {
public:
	RegexMatcher() : root(new Node(0)) {}
	~RegexMatcher() {
		deleteAll();
	}
	
	void stateMachineBuild(std::string a);
	
private:
	struct Node{
		Node() : next(NULL), numNext(0) {};
		Node(char val) : value(val), next(NULL), numNext(0) {};
		char value;
		Node** next;
		unsigned int numNext;
	};
	
	Node* root;
	
	void addNode(Node* curNode, char val);
	void deleteAll();
	
};



#endif
