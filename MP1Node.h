/**********************************
 * FILE NAME: MP1Node.cpp
 *
 * DESCRIPTION: Membership protocol run by this Node.
 * 				Header file of MP1Node class.
 **********************************/

#ifndef _MP1NODE_H_
#define _MP1NODE_H_

#include "stdincludes.h"
#include "Log.h"
#include "Params.h"
#include "Member.h"
#include "EmulNet.h"
#include "Queue.h"

/**
 * Macros
 */
#define TREMOVE 20
#define TFAIL 5
#define MEMBER_LIST_SIZE 10

/*
 * Note: You can change/add any functions in MP1Node.{h,cpp}
 */

/**
 * Message Types
 */
enum MsgTypes{
    JOINREQ,
    JOINREP,
    PING,
    ACK,
    PING_FWD,
    ACK_FWD,
    DUMMYLASTMSGTYPE
};

typedef struct MembershipList {
	int num_members;
	Address member_list[MEMBER_LIST_SIZE];
} MembershipList;

typedef struct JoinReq {
	Address sender_addr;
	long heartbeat;
} JoinReq;


typedef struct JoinRep {
	Address sender_addr;
	MembershipList list;
} JoinRep;

typedef struct Ping {
	Address sender_addr;
	MembershipList list;
} Ping;

typedef struct PingFwd {
	Address sender_addr;
	Address mediator_addr;
	Address dest_addr;
	MembershipList list;
} PingFwd;

/**
 * STRUCT NAME: MessageHdr
 *
 * DESCRIPTION: Header and content of a message
 */
typedef struct MessageHdr {
	enum MsgTypes msgType;
	union {
		JoinReq join_req;
		JoinRep join_rep;
		Ping ping;
		PingFwd ping_fwd;
	} data;
}MessageHdr;

/**
 * CLASS NAME: MP1Node
 *
 * DESCRIPTION: Class implementing Membership protocol functionalities for failure detection
 */
class MP1Node {
private:
	EmulNet *emulNet;
	Log *log;
	Params *par;
	Member *memberNode;
	char NULLADDR[6];

public:
	MP1Node(Member *, Params *, EmulNet *, Log *, Address *);
	Member * getMemberNode() {
		return memberNode;
	}
	int recvLoop();
	static int enqueueWrapper(void *env, char *buff, int size);
	void nodeStart(char *servaddrstr, short serverport);
	int initThisNode(Address *joinaddr);
	int introduceSelfToGroup(Address *joinAddress);
	int finishUpThisNode();
	void nodeLoop();
	void checkMessages();
	bool recvCallBack(void *env, char *data, int size);
	void nodeLoopOps();
	int isNullAddress(Address *addr);
	Address getJoinAddress();
	void initMemberListTable(Member *memberNode);
	void printAddress(Address *addr);
	string AddressStr(Address *addr);
	virtual ~MP1Node();
};

#endif /* _MP1NODE_H_ */
