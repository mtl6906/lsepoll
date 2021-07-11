#include "ls/epoll/Tool.h"
#include "iostream"
#include "unistd.h"

using namespace std;
using ls::epoll::Tool;

int main()
{
	Tool tool(128);
	tool.add(fileno(stdin), EPOLLIN | EPOLLET);	
	char buffer[4096] = {};
	for(;;)
	{
		int ret = tool.wait(-1);
		for(int i=0;i<ret;++i)
		{
			buffer[read(fileno(stdin), buffer, sizeof(buffer))] = '\0';
			cout << buffer;
		}
	}
	return 0;
}
