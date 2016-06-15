#include <iostream>
#include <cstring>
#include <SFML/Network.hpp>

using namespace std;
using namespace sf;

int main()
{
    UdpSocket skt;
    skt.bind(Socket::AnyPort);
    
    char data[24];
    const size_t amt = 24;
    
    IpAddress recipient = "127.0.0.1";
    unsigned short port = 8888;
    
    float coords[6] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    for (int i = 0; i < 6; i++)
    {
        memcpy(data+4*i, coords+i, 4);
    }
    skt.send(data, 24, recipient, port);
}
