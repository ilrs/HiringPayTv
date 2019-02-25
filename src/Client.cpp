#include "Client.h"

Client::Client()
{

}

Client::~Client()
{
	
}

void Client::Request(string search_term, string search_type)
{
	auto fileBuffer = std::make_shared<streambuf<uint8_t>>();
    file_buffer<uint8_t>::open(kJsonLocation.c_str(), std::ios::out)
        .then([=](streambuf<uint8_t> outFile) -> pplx::task<http_response> {
            *fileBuffer = outFile;

            // Create an HTTP request.
            // Encode the URI query since it could contain special characters like spaces.
            http_client client(U(kDomain.c_str()), ClientConfigForProxy());
            return client.request(methods::GET, uri_builder(U(""))
            	.append_query(U(kApiKeyKeyword.c_str()), kApiKey.c_str())
            	.append_query(U(kReturnTypeKeyword.c_str()), kReturnType.c_str())
            	.append_query(U(kSearchTermKeyword.c_str()), search_term.c_str())
            	.append_query(U(kTypeKeyword.c_str()), search_type.c_str())
            	.to_string());
        })

        // Write the response body into the file buffer.
        .then([=](http_response response) -> pplx::task<size_t> {
            //printf("Response status code %u returned.\n", response.status_code());

            return response.body().read_to_end(*fileBuffer);
        })

        // Close the file buffer.
        .then([=](size_t) { return fileBuffer->close(); })

        // Wait for the entire response body to be written into the file.
        .wait();
}

web::http::client::http_client_config Client::ClientConfigForProxy()
{
	web::http::client::http_client_config client_config;
    if (const char* env_http_proxy = std::getenv("http_proxy"))
    {
        std::string env_http_proxy_string(env_http_proxy);

        if (env_http_proxy_string == U("auto"))
            client_config.set_proxy(web::web_proxy::use_auto_discovery);
        else
            client_config.set_proxy(web::web_proxy(env_http_proxy_string));
    }

    return client_config;
}