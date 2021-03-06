﻿/**
 * The component that handles communication with the device controlling the
 * Leap Motion sensor, through a UDP socket.
 * 
 * @author thenaesh
 */

using System.Collections;
using System.Net;
using System.Net.Sockets;
using System;

public class LeapMotionInput
{
	// port the Leap Motion input device should send data to
	public const int recvPort = 10000;

	private UdpClient recv;
	private IPEndPoint ep;


	void Start()
	{
		recv = new UdpClient(recvPort);
		ep = new IPEndPoint(IPAddress.Any, recvPort);
	}

	void Update()
	{
		try
		{
			byte[] recvBytes = recv.Receive(ref ep);
			modifyTransformProperties(recvBytes);
		}
		catch (Exception e)
		{
            recv.Close();
		}
	}

	void modifyTransformProperties(byte[] data)
	{
		// the byte array should be 24 bytes, as it contains 6 floats
		// 0-3		xPos
		// 4-7		yPos
		// 8-11		zpos
		// 12-15	xRot
		// 16-19	yRot
		// 20-23	zRot

		float xPos = extractFourByteRange(data, 0);
		float yPos = extractFourByteRange(data, 4);
		float zPos = extractFourByteRange(data, 8);
		float xRot = extractFourByteRange(data, 12);
		float yRot = extractFourByteRange(data, 16);
		float zRot = extractFourByteRange(data, 20);
        
        Console.WriteLine(xPos);
        Console.WriteLine(yPos);
        Console.WriteLine(zPos);
        Console.WriteLine(xRot);
        Console.WriteLine(yRot);
        Console.WriteLine(zRot);
	}

	static float extractFourByteRange(byte[] data, int start)
	{
		// ASSUMPTION: data is little-endian
		byte[] range = new byte[4];

		for (int i = start; i < start + 4; i++)
			range[i - start] = data[i];

		return BitConverter.ToSingle(range, 0);
	}

}

