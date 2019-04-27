/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
//#include "calculate.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=10, true);  // smarty should always win in at most 10 turns!
		}
		//my tests.
		 testcase.setname("Play with smart guesser ,should not work")
		.CHECK_OUTPUT(calculateBullAndPgia("9999","9991"), "3,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1122","2200"), "0,2")
		.CHECK_OUTPUT(calculateBullAndPgia("0000","0000"), "4,0")
		//.CHECK_OUTPUT(calculateBullAndPgia("010101","111111"), "3,0")
		.CHECK_OUTPUT(calculateBullAndPgia("4567","7654"), "0,4")
		.CHECK_OUTPUT(calculateBullAndPgia("9797","9000"), "1,0")
	  .CHECK_OUTPUT(calculateBullAndPgia("8000","2000"), "3,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1322","1437"), "1,1")
	  .CHECK_OUTPUT(calculateBullAndPgia("7777","4444"), "0,0")
		.CHECK_OUTPUT(calculateBullAndPgia("7878","1818"), "2,0")
	  .CHECK_OUTPUT(calculateBullAndPgia("8787","1818"), "0,2")
		.CHECK_OUTPUT(calculateBullAndPgia("123457","231888"), "0,3")

		; 
    // RandomChooser rand;
		// SmartGuesser smarty1;
		// for (uint i=0; i<100; ++i) {
		// 	testcase.CHECK_EQUAL(play(rand, smarty1, 4, 100)>10, false);  // smarty should always win in at most 10 turns!
		// }
    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}

