/*
 *  This program reads the input data from the Leap Motion sensor
 *  and writes it out as a packet of 6 floats (24-byte payload).
 *  The packets so generated may be read at the client side by
 *  converting the 24-byte payload back to 6 floats using bit operations.
 *
 *  WARNING: We assume here that the endianness of the source and target are the same.
 *
 *  @author thenaesh
 */

#include <cstdio>
#include <cstring>
#include <SFML/Network.hpp>
#include "Leap.h"

using namespace std;
using namespace sf;
using namespace Leap;



class TrackerListener : public Listener
{
public:
    virtual void onConnect(Controller const&);
    virtual void onFrame(Controller const&);
};


class SocketHandler
{
    UdpSocket skt;
    IpAddress addr;
    unsigned short port;
public:
    SocketHandler();
    virtual void sendTransformData(float, float, float, float, float, float);
private:
    virtual void init(IpAddress, unsigned short);
    virtual void sendPacket(char*, unsigned int);
public:
    static SocketHandler* sktHandler;
};

#define SKTHANDLER SocketHandler::sktHandler



int main()
{
    SKTHANDLER = new SocketHandler();

    Controller controller;
    TrackerListener listener;
    controller.addListener(listener);

    while (true) {}
    return 0;
}



SocketHandler* SocketHandler::sktHandler;

SocketHandler::SocketHandler()
{
    this->init("127.0.0.1", 10000);
}

void SocketHandler::init(IpAddress addr, unsigned short port)
{
    this->addr = addr;
    this->port = port;
    this->skt.bind(Socket::AnyPort);
}

void SocketHandler::sendPacket(char* packet, unsigned int length)
{
    this->skt.send(packet, length, this->addr, this->port);
}

void SocketHandler::sendTransformData(float xPos, float yPos, float zPos, float xRot, float yRot, float zRot)
{
    char packet[24];
    float coords[] = {xPos, yPos, zPos, xRot, yRot, zRot};

    for (int i = 0; i < 6; i++)
        memcpy(packet+4*i, coords+i, 4);

    this->sendPacket(packet, 24);
}


void TrackerListener::onConnect(Controller const& controller)
{
    printf("controller is connected\n");
}

void TrackerListener::onFrame(Controller const& controller)
{
    const Frame frame = controller.frame();
    HandList hands = frame.hands();
    Hand hand = hands[0];

    Vector pos = hand.palmPosition();
    float pitch = hand.direction().pitch();
    float yaw = hand.direction().yaw();
    float roll = hand.palmNormal().roll();

    SKTHANDLER->sendTransformData(pos.x, pos.y, pos.z, pitch, yaw, roll);
}
