#include "mainhandler.h"
#include "Tufao/HttpServerRequest"

MainHandler::MainHandler(QObject *parent)
	: QObject(parent)
{
}

MainHandler::~MainHandler()
{
}

bool MainHandler::handleRequest(Tufao::HttpServerRequest& request, Tufao::HttpServerResponse& response)
{
	
	response.end();

	return true;
}
