//
//  main.cpp
//  RegexMatcher
//
//  Created by Yating Sheng on 9/13/12.
//  Copyright 2012 University of Michigan . All rights reserved.
//

#include <iostream>
#include "RegexMatcher.h"

void testStringMatch() {
	struct TestCase {
		std::string a;
		std::string b;
		bool match;
	} testCases[] = {
		/*
		 { "a?c", "ad" },
		 { "ab?c", "adc" },
		 { "a*b*c", "d" },
		 { "a*b*c", "d" },
		 { "a+c", "c" }, // No Match
		 { "a+c", "d" }, // No Match
		 { "a?c", "aaaaa" }, // No Match
		 { "ab?cd*de+f", "acdddddf" }, // No Match
		 
		 { "a*+c", "c" }, // Input RegexResultInvalid
		 { "*a", "a" }, // Input RegexResultInvalid
		 
		 { "abc", "abc" }, // Match
		 { "ab*", "abbbb" }, // Match
		 { "a*b", "b" }, // Match
		 { "ab*", "a" }, // Match
		 { "a*b*c", "c" }, // Match
		 { "a+c", "ac" }, // Match
		 { "a+", "a" }, // Match
		 { "a+", "aaaaaa" }, // Match
		 { "a?c", "c" }, // Match
		 { "a?c", "ac" }, // Match
		 { "a?cd", "cd" }, // Match
		 { "a?cd", "acd" }, // Match
		 { "ab?c", "ac" }, // Match
		 { "ab?cdd", "acdd" }, // Match
		 { "ab?cd*de+f", "acdddddef" }, // Match
		 { "a*cd+d", "acddddd" }, // Match
		 { "a.c", "abc" }, // Match
		 { "a.*c", "adsdewrzc" }, // Match \\
		 { "a*.e", "ze" }, // Match
		 { "abcd", "abcd" }, // Match
		 */
		//{ "a(sc)d", "ascd", true },
		//{ "abc", "ab", false },
		//{ "ab", "abc", false },
		//{ "a(sb)*d", "asbsbd", true },
		//{ "(ab)*cd", "ababcd", true },
		{ "(a)*cd", "cd", true }
	};
	
	
	for (int i = 0; i < sizeof(testCases)/sizeof(TestCase); ++i) {
		std::string atest = testCases[i].a;
		std::string btest = testCases[i].b;
		RegexMatcher regMatcher;
		regMatcher.regexMatcherMachineBuild(atest);
		RegexMatcher::RegexMatchResult result = regMatcher.regexMatch(btest);
		if (result == regMatcher.RegexMatcherMatch && testCases[i].match == true)
			std::cout << "Match!" << std::endl;
		else if (result == regMatcher.RegexMatcherNotMatch && testCases[i].match == false)
			std::cout << "Match!" << std::endl;
		else if (result == regMatcher.RegexMatcherInvalid)
			std::cout << "Invalid!" << std::endl;
		else
			std::cout << "Correct!" << std::endl;
	}
}

int main (int argc, const char * argv[])
{
/*	
	regMatcher.regexMatcherMachineBuild(a);
	RegexMatcher::RegexMatchResult result = regMatcher.regexMatch(b);
	if (result == regMatcher.RegexMatcherMatch)
		std::cout << "Match!" << std::endl;
	else if (result == regMatcher.RegexMatcherNotMatch)
		std::cout << "Not Match!" << std::endl;
	else if (result == regMatcher.RegexMatcherInvalid)
		std::cout << "Invalid!" << std::endl;
	else
		std::cout << "Huh?" << std::endl;
	*/
	testStringMatch();
	return 0;
}

