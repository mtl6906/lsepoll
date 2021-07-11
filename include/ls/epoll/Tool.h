#ifndef LS_EPOLL_TOOL_H
#define LS_EPOLL_TOOL_H

#include "vector"
#include "sys/epoll.h"

namespace ls
{
	namespace epoll
	{
		class Tool
		{
			int epollfd;
			std::vector<epoll_event> events;
			public:
				Tool() = default;
				Tool(int n);
				int add(int fd, int type);
				int mod(int fd, int type);
				int del(int fd);
				int wait(int timeout);
				epoll_event& event(int i);
		};
	}
}

#endif
