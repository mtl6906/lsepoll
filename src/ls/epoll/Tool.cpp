#include "ls/epoll/Tool.h"
#include "fcntl.h"

using namespace std;

namespace ls
{
	namespace epoll
	{
		Tool::Tool(int n) : events(n), epollfd(epoll_create(5))
		{
		}
		int Tool::add(int fd, int type)
		{
			epoll_event event = {};
			event.data.fd = fd;
			event.events |= type;
			if(epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event) < 0)
				return -1;
			return 0;
		}
		int Tool::mod(int fd, int type)
		{
			epoll_event event = {};
			event.data.fd = fd;
			event.events |= type;
			if(epoll_ctl(epollfd, EPOLL_CTL_MOD, fd, &event) < 0)
				return -1;
			return 0;
		}
		int Tool::del(int fd)
		{
			if(epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, NULL) < 0)
				return 0;
			return -1;
		}
		int Tool::wait(int timeout)
		{
			return epoll_wait(epollfd, events.data(), events.size(), timeout);
		}
		epoll_event& Tool::event(int i)
		{
			return events[i];
		}
	}
}