#include "../TC/Dispatcher.h"
#include "../TC/SPTrader.h"
#include "../TC/ComboTrader.h"
#include "../TC/SwingTrader.h"
#include "../TC/TradeCube.h"
#include "../TC/DispatcherFactory.h"

int traderId = 1;
const char * PROGRAM_NAME = "TradeCube";

void testComboTrader() 
{
	PlatformInfo platformInfo;
	platformInfo.platformName = SPTRADER;
	platformInfo.server = "127.0.0.1";
	platformInfo.accountNo = "DEMO258";
	platformInfo.password = "12341234";
	platformInfo.orderPort = 8092;
	platformInfo.pricePort = 8089; 
	platformInfo.tickPort = 8090;

	Dispatcher* disp = DispatcherFactory::createDispatcher(platformInfo);

	ComboTrader* cmb_trader =  new ComboTrader(traderId++);

	// 应该在启动线程前设置
	cmb_trader->setIntraBarTrading(true);
	cmb_trader->setDispatcher(disp);
	DWORD tbtid = cmb_trader->startTraderThread();  // 交易线程启动，等待消息

	QuoteItem* qi1 = new QuoteItem();
	qi1->setTradePlatform(SPTRADER);
	qi1->setQuoteId("NQZ3");
	qi1->setExchange("CBOT");
	qi1->setMinContractQty(1);
	qi1->setPriceScale(1);	
	TradeUnit* tu1 = new TradeUnit(qi1);

	// 在这里会添加品种，进而开启价格线程和订单线程
	cmb_trader->addTradeUnit(tu1);

	disp->addPriceThreadId(qi1->getTradePlatform(), qi1->getQuoteId(),tbtid);

	disp->addOrderThreadId(cmb_trader->getTraderId(), tbtid);
	//Todo: add ui thread id

	QuoteItem* qi2 = new QuoteItem();
	qi2->setTradePlatform(SPTRADER);
	qi2->setQuoteId("YMZ3");
	qi2->setExchange("CBOT");
	qi2->setMinContractQty(1);
	qi2->setPriceScale(1);
	TradeUnit* tu2 =  new TradeUnit(qi2);
	cmb_trader->addTradeUnit(tu2);

	disp->addPriceThreadId(qi2->getTradePlatform(), qi2->getQuoteId(),tbtid);

	//cmb_trader->setOptimizeOrderFlow(NO_OPTIMIZE_OFP);
	cmb_trader->setOptimizeOrderFlow(OPTIMIZE_OFP);

	int quoteNO[2] = {1,2};
	double qty[2] = {1,1};
	char buysell[2]={'B', 'S'};
	int rankId[2]={1,2};

	// 在这里创建orderunit 
	cmb_trader->createOrderTemplate(2,quoteNO,qty,buysell,rankId);

	//cmb_trader->setSpread(2700);

	//cmb_trader->setIntraBarTrading(false);
	//cmb_trader->setStrategy(stgy);
	Sleep(10);// Check price data is more than maxRefBarNum
	cmb_trader->turnOnStrategy();
	Sleep(10000000);
}

void testSwingTrader() 
{
	PlatformInfo platformInfo;
	platformInfo.platformName = SPTRADER;
	platformInfo.server = "127.0.0.1";
	platformInfo.accountNo = "DEMO258";
	platformInfo.password = "12341234";
	platformInfo.orderPort = 8092;
	platformInfo.pricePort = 8089; 
	platformInfo.tickPort = 8090;

	Dispatcher* disp = DispatcherFactory::createDispatcher(platformInfo);

    SwingTrader* swingTrader =  new SwingTrader(traderId++, NULL, NULL);

	// 应该在启动线程前设置
	swingTrader->setIntraBarTrading(true);
	swingTrader->setDispatcher(disp);
	DWORD tbtid = swingTrader->startTraderThread();  // 交易线程启动，等待消息

	QuoteItem* qi1 = new QuoteItem();
	qi1->setTradePlatform(SPTRADER);
	qi1->setQuoteId("NQZ3");
	qi1->setExchange("CBOT");
	qi1->setMinContractQty(1);
	qi1->setPriceScale(1);	
	TradeUnit* tu1 = new TradeUnit(qi1);

	// 在这里会添加品种，进而开启价格线程和订单线程
	swingTrader->setTradeUnit(tu1);

	disp->addPriceThreadId(qi1->getTradePlatform(), qi1->getQuoteId(),tbtid);
	disp->addOrderThreadId(swingTrader->getTraderId(), tbtid);

	swingTrader->turnOnStrategy();
	Sleep(10000000);
}

void main()
{
	//testComboTrader();
	testSwingTrader();
}
