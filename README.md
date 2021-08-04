# C++ assignment 1 ex1
An assignment challenge completed using C++.

Note that some of these operators have been declared as member functions whereas others have been declared as friends of the class; this has been done arbitrarily to require you to implement both kinds of function. You must not make any changes to the header file.

The six comparison operators should return boolean results (i.e. either true or false). A time t1 should be regarded as being smaller than another time t2 if it occurs earlier in the day.

It is recommended that you implement the == operator and one of the < and > operators directly and use those two in the implementation of the other operators.
The -, -= and -- operators should behave in a similar way to the +, += and ++ operators (but t-n should be the time n seconds before t instead of n seconds after t). If you choose to implement operator- directly and call it in the other operators the code for the other three will be similar to those in the lecture slides.

In the addition function it was necessary to check for seconds and minutes values greater than or equal to 60 and hours values greater than or equal to 24. In the subtraction you will need to check for values that have become less than 0. Note that when the first operand of the / operator is negative and the second is positive the result is rounded towards 0, and when the first operand of the % operator is negative and the second is positive the result is either 0 or negative; for example (-97)/60 gives -1 and (-97)%60 gives -37.

The operator% function with return the elapsed time in seconds between its 2 arguments, i.e. the length of the period from a start time to an end time. The first operand denotes the start time and the second operand the end time, so if the second argument is earlier in the day than the first you should assume that it refers to the following day (e.g. the elapsed time from 11.30pm to 1am is 90 (5400 seconds)).
