#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <string>
#include <vector>

#include <cpprest/filestream.h>
#include <cpprest/http_client.h>
#include <cpprest/containerstream.h>

using std::string;

using namespace utility;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;

const static string kDomain("http://www.omdbapi.com/");
const static string kApiKey("8c71a1db");
const static string kApiKeyKeyword("apikey");
const static string kReturnType("json");
const static string kReturnTypeKeyword("r");
const static string kSearchTermKeyword("t");
const static string kTypeKeyword("t");

const static string kJsonLocation("/tmp/result.json");

/**
 * Classe responsável pela conexão com o WebService.
 */
class Client {
public:
	/**
	 * Construtor da classe.
	 */
	Client();
	/**
	 * Destrutor da classe.
	 */
	~Client();
	/**
	 * Realiza uma requisição.
	 * \param search_item Nome do filme a ser pesquisado.
	 * \param search_type Tipo de midia a ser pesquisada.
	 */
	void Request(string search_term, string search_type);
	
private:
	/**
	 * Realiza a configuração do proxy.
	 * \return A configuração do proxy.
	 */
	static web::http::client::http_client_config ClientConfigForProxy();
};
#endif //_CLIENT_H_