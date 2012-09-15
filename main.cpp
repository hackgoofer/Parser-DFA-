//
//  main.cpp
//  RegexMatcher
//
//  Created by Yating Sheng on 9/13/12.
//  Copyright 2012 University of Michigan . All rights reserved.
//

#include <iostream>
#include "RegexMatcher.h"

int main (int argc, const char * argv[])
{
	RegexMatcher regMatcher;
	std::string a = "(ab)*c";
	std::string b = "abc";
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
	
	return 0;
}

