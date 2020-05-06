#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#include "socket.h"

namespace mz {
namespace ipc {

int Socket::socket(int domain, int type, int protocol) const
{
    return ::socket(domain, type, protocol);
}

int Socket::close(int fd) const
{
    return ::close(fd);
}

int Socket::remove(char const* path) const
{
    return ::remove(path);
}

int Socket::bind(int fd, const sockaddr* addr, socklen_t len) const
{
    return ::bind(fd, addr, len);
}

int Socket::listen(int fd, int backlog) const
{
    return ::listen(fd, backlog);
}

int Socket::accept(int fd, sockaddr* addr, socklen_t* len) const
{
    return ::accept(fd, addr, len);
}

int Socket::connect(int fd, sockaddr* addr, socklen_t len) const
{
    return ::connect(fd, addr, len);
}

}  // namespace ipc
}  // namespace mz