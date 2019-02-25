#include <cstdio>
#include <cstdlib>

#include <cpprest/filestream.h>
#include <cpprest/http_client.h>

#include <string>

using namespace utility;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;

#include "Client.h"
#include "JsonReader.h"

int main (int argc, char* argv[])
{
    int search_index = 0;
    int type_index = argc;
    bool can_search = false;

    for (int i = 1; i < argc; i++) {
        if (0 == strcmp(argv[i], "-h") || 0 == strcmp(argv[i], "--help")) {
            printf("-h\t\t--help\n\t\tImprime a lista de opcoes da aplicacao\n");
            printf("-s\t\t--search\n\t\tBusca pelo tipo da media\n");
            printf("-t\t\t--type\n\t\tRetorna o tipo de media selecionado. (movie, series, episode)\n");
            return 0;
        }
        if (0 == strcmp(argv[i], "-s") || 0 == strcmp(argv[i], "--search")) {
            search_index = i + 1;
            can_search = true;
        }
        if (0 == strcmp(argv[i], "-t") || 0 == strcmp(argv[i], "--type")) {
            type_index = i;
        }
    }

    if (!can_search)
        return 0;

    std::string search_item;
    for (int i = search_index; i < type_index; i++) {
        search_item.append(argv[i]);
        search_item.append(" ");
    }

    std::string search_type;
    for (int i = type_index; i < argc; i++) {
        search_type.append(argv[i]);
        search_type.append(" ");
    }

	Client client;
	client.Request(search_item, search_type);
    JsonReader reader;
    reader.LoadFile(kJsonLocation.c_str());
	reader.PrintContent();
    return 0;
}