#ifndef ARA_COM_IPC_SOCKET_H_
#define ARA_COM_IPC_SOCKET_H_

#include "Isocket.h"

namespace mz {
namespace ipc {

class Socket : public ISocket
{
public:
    Socket() {}
    ~Socket() override {}

    int socket(int domain, int type, int protocol) const override;
    int close(int fd) const override;
    int remove(char const* path) const override;
    int bind(int fd, const sockaddr* addr, socklen_t len) const override;
    int listen(int fd, int backlog) const override;
    int accept(int fd, sockaddr* addr, socklen_t* len) const override;
    int connect(int fd, sockaddr* addr, socklen_t len) const override;
};

}
}

#endif  // !ARA_COM_IPC_SOCKET_H_