#ifndef _TRADECUBE_H
#define _TRADECUBE_H

#define ORDER_SEND_MSG WM_USER+1
#define ORDER_ACCEPT_MSG WM_USER+2
#define TRADE_DONE_MSG WM_USER+3
#define PRICE_MSG WM_USER+4
#define ORDER_UNIT_TRADED WM_USER+5
#define STRATEGY_MSG WM_USER+6

#define LINK_STATE_MSG WM_USER+7
#define TICK_PRICE WM_USER+8
#define LOSE_CONN_MSG WM_USER+9

#define CHECK_LINK_TIMER_ID 1
#define UPDATE_BAR_TIMER_ID 2
#define LOAD_ORDER_AND_TRADE_TIMER_ID 3
//#define QUIT_MSG WM_USER+3

extern const char *PROGRAM_NAME;

const int LMT=0;
const int MKT=1;
const int STP=2;
const int MIT=3;


const int ADD_ACTION=1;
const int CHG_ACTION=2;
const int DEL_ACTION=3;

const int DAY=0;
const int FAK=1;
const int FOK=2;
const int GTC=3;
const int GTD=4;

const int SA=1;
const int AA=2;

const char OPEN='O';
const char CLOSE='C';

const int WAITING = 0;
const int WORKING=1;
const int INACTIVE=2;
const int PENDING=3;
const int ADDING=4;
const int CHANGING=5;
const int DELETING=6;
const int DEACTIVATING=7;
const int PARTIALTRADED=8;
const int ALLTRADED=9;
const int DELETED=10;

const char BUY='B';
const char SELL='S';

const int RADIX = 10;

const int SPTRADER=1;
const int CTP=2;

const int NO_OPTIMIZE_OFP=0;
const int OPTIMIZE_OFP=1;

const int NO_RANK=0;
const int ORDINAL_RANK=1;
const int REVERSE_RNAK=-1;

const int SUCCESS=1;
const int MY_ERROR=0;

const int STRATEGY_SUBMITTER=0;
const int MANUAL_SUBMITTER=1;

const int MULTIPLIER = 1000;

// by xie
enum LinkID {
	TRANSACTION_CLIENT_LINK = 80, 
	TRANSACTION_ADMIN_LINK = 81, 
	PRICE_LINK = 83, 
	LONG_DEPTH_LINK = 87,
	INFORMATION_LINK = 88,
	MARGIN_CHECK_LINK = 85
};

#include <stdio.h>
#include <iostream>
#include <string> 
#include <windows.h>
#include<sstream>
#include <time.h>

using namespace std; 

#include "Bar.h"
#include "PlatformInfo.h"
#include "QuoteItem.h"
#include "PriceItem.h"
#include "OrderItem.h"
#include "TradeItem.h"
#include "Position.h"
#include "ComboOrder.h"
#include "LogHandler.h"


#endif  