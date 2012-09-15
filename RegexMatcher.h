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
	
	RegexMatcher() : start(new Edge(0)) {}
	~RegexMatcher() {
		deleteAll();
	}
	
	enum RegexMatchResult {
		RegexMatcherPlaceHolder = 0,
		RegexMatcherInvalid,
		RegexMatcherNotMatch,
		RegexMatcherMatch
	};
	
	void regexMatcherMachineBuild(std::string a);
	RegexMatchResult regexMatch(std::string b);
private:
	struct Edge {
		Edge() : next(NULL), numNext(0) {};
		Edge(char val) : value(val), next(NULL), numNext(0) {};
		
		char value;
		Edge **next;
		unsigned int numNext;
	};
	
	Edge *start;
	
	Edge* makeEdge(char val);
	int addNumNext(Edge *curEdge);
	void linkEdge(Edge *curEdge, Edge *nextEdge);
	bool isNewEdge(Edge *t, char a, Edge *newEdge);
	
	RegexMatchResult regexMatchEdge(Edge *edge, std::string b, RegexMatchResult re);

	void deleteAll();
	void escapeCharacterMatch();
};



#endif
