#include "TextBook.h"


int main()
{
	ArgumentText<int> xd("LMAO WTF",2, 2, 2, 2, 10);
	ArgumentText<int> xd2 = xd;

	char key[2][15] = { "sadasddas" };
	char text[200] = "sadasddas";
	
	//TextBook book(2);		(delete error)
	//book.addText(xd);		(crash)
	//Poem poem("asdasd", 1 , key);		(error)		

	return 0;
}