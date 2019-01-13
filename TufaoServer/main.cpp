#include <QCoreApplication>
#include <Tufao/HttpServer>
#include <QtCore/QUrl>
#include <Tufao/HttpServerRequest>
#include <Tufao/Headers>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	Tufao::HttpServer server;

	QObject::connect(&server, &Tufao::HttpServer::requestReady,
		[](Tufao::HttpServerRequest &request,
			Tufao::HttpServerResponse &response) {
		response.writeHead(Tufao::HttpResponseStatus::OK);
		response.headers().replace("Content-Type", "text/plain");
		response.end("Hello " + request.url().path().toUtf8());
	});

	server.listen(QHostAddress::Any, 8080);

	return a.exec();
}