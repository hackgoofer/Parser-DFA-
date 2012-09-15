//
//  RegexMatcher.cpp
//  RegexMatcher
//
//  Created by Yating Sheng on 9/13/12.
//  Copyright 2012 University of Michigan . All rights reserved.
//

#include <iostream>
#include <cassert>
#include "RegexMatcher.h"

void RegexMatcher::regexMatcherMachineBuild(std::string a) {
	// (ab)*c for now:  ababc
	Edge *thisEdge = start;
	Edge *futureDest;
	int prevOpenParen = 0;
	for (int i = 0; i < a.length(); ++i) {
		Edge *newEdge;
		if (a[i] == '(') {
			++prevOpenParen;
			continue;
		} else if (a[i] <= 'z' && a[i] >= 'a') {			
			newEdge = makeEdge(a[i]);
			linkEdge(thisEdge, newEdge);			
			thisEdge = newEdge;
			
			if (prevOpenParen > 0) {
				futureDest = thisEdge;
				prevOpenParen = 0;
			}
		} else if (a[i] == ')') {
			continue;
		} else if (a[i] == '*') {
			linkEdge(thisEdge, futureDest);
		} else if (a[i] == '+') { // one or more
			
		} else if (a[i] == '?') { // zero or one
			
		
		} else { // a[i] == '\0'
			return;
		}
	}
}

RegexMatcher::RegexMatchResult RegexMatcher::regexMatchEdge(Edge *startEdge, std::string b, RegexMatchResult re) {
	if (b.length() == 0 && re == RegexMatcherPlaceHolder) {
		return RegexMatcherMatch; 
	}
	Edge *thisEdge = startEdge;
	for (int i = 0; i < b.length(); ++i) {
		for (int j = 0; j < thisEdge->numNext; ++j) {
			if (b[i] == thisEdge->next[j]->value) {
				return regexMatchEdge(thisEdge->next[j], b.substr(1, b.length()), re);
			}
		}
	}
	
	if (re == RegexMatcherPlaceHolder) {
		return RegexMatcherNotMatch;
	}
	return RegexMatcherInvalid;
}

RegexMatcher::RegexMatchResult RegexMatcher::regexMatch(std::string b) {
	RegexMatchResult result = RegexMatcherPlaceHolder;
	return regexMatchEdge(start, b, result);
}


RegexMatcher::Edge* RegexMatcher::makeEdge(char val) {
	// Create an Edge, make curEdge's next the edge returned.
	// the newEdge should have value val
	Edge *result = new Edge(val);
	return result;
}

void RegexMatcher::deleteAll() {
	
}

void RegexMatcher::escapeCharacterMatch() {
	
}

void RegexMatcher::linkEdge(Edge *curEdge, Edge *nextEdge) {
	int num = curEdge->numNext;
	if (num == 0)
		curEdge->next = new Edge*;
	curEdge->next[num] = new Edge;
	curEdge->next[num] = nextEdge;
	addNumNext(curEdge);
	// involves adding numNext;
}

int RegexMatcher::addNumNext(Edge *curEdge) {
	++(curEdge->numNext);
	return curEdge->numNext;
}



