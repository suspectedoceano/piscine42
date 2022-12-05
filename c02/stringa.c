#include<stdio.h>
#include<unistd.h>

int main()
{
	char	*s = "hello";
	char	s1[] = "world";

	printf("\nWhere is \"hello\" literal?     ~%p\n\n", s);
	printf("Where is the ptr--->\"hello\"?  ~%p\n\n", &s);
	printf("Where is [\"world\"]?           ~%p\n\n", s1);
	//To check vmmap, if (!sleep) OS will kill immediately the process
	sleep(30);
}
