#ifndef  _MAIN_HANDLER_H_
#define _MAIN_HANDLER_H_

#include "Tufao/HttpServer"
#include "Tufao/AbstractHttpServerRequestHandler"

#include <QObject>

class MainHandler : public QObject,
	public Tufao::AbstractHttpServerRequestHandler
{
	Q_OBJECT

public:
	MainHandler(QObject *parent = 0);
	~MainHandler();

public slots:
bool handleRequest(Tufao::HttpServerRequest &request,
	Tufao::HttpServerResponse &response) override;
};

#endif

