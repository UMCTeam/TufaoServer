#include <QCoreApplication>
#include <Tufao/HttpServer>
#include <Tufao/HttpServerRequestRouter>

#include "mainhandler.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	MainHandler mainHandler;

	Tufao::HttpServer server;
	Tufao::HttpServerRequestRouter router {
		{ QRegularExpression{ "^/hello$" },  mainHandler },
	};

	QObject::connect(&server, &Tufao::HttpServer::requestReady, 
		&router, &Tufao::HttpServerRequestRouter::handleRequest);

	server.listen(QHostAddress::Any, 8080);

	return a.exec();
}