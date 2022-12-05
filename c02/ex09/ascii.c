#include <stdio.h>

int main()
{
	/* Good website -> https://theasciicode.com.ar/

	  These are the ascii control chars for space formatting
	  like the function isspace() 
	  Tab - NewLine(lineFeed) -Space ...we all know them
	  ``\t''   ``\n''    ``\v''    ``\f''    ``\r''    `` ''
	     ' '    (0x20)	space (SPC)
		'\t'	(0x09)	horizontal tab (TAB)
		'\n'	(0x0a)	newline (LF)
		'\v'	(0x0b)	vertical tab (VT) Go slot down, not on the right
		'\f'	(0x0c)	feed (FF)
		'\r'	(0x0d)	carriage return (CR) Carriage return (is used to point to the start of a line and can replace the text from there)
	*/
	for (int i = 9; i<=13; ++i)
		printf("%d->%c\"$$$\"\n", i, i);	
	
	//Must read StackOverflow
	//https://stackoverflow.com/questions/15433188/what-is-the-difference-between-r-n-r-and-n
	/*
	ONCE UPON A TIME THE TERMINAL WAS A TELETYPEWRITER (Google it)
		these control chars were mechanical commands.

	linefeed \n moves the paper up one line, its horizontal placement stays the same.

	carriage return \r returns the platen to the start of the line. It does not move the paper. 
	In a teletype to start a new line both a linefeed and carriage return had to be sent. 
	This standard continued on with Windows line endings but was dropped in Unix.

	formfeed \f a form feed told the teletype to move to the start of the next piece of paper (form). 
	This was for continuous perforated fan-fold paper reams.

	Vertical tab \v this moves the paper up one tab amount while keeping the same horizontal placement. 
	Basically the same as an old linefeed but I believe there was a mechanical difference in how they were handled by the machines.
		*/
}	
