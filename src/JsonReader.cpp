#include "JsonReader.h"

#include <string>

JsonReader::JsonReader()
{

}

JsonReader::~JsonReader()
{

}

bool JsonReader::LoadFile(const char* filename)
{
	    std::ifstream is (filename, std::ifstream::in);

    if (!is) {
        printf("Arquivo de configuracao inexistente\n");
        return false;
    }

    std::string json;

    while (is.good()) {
        std::string line;
        std::getline(is, line);
        json.append(line);
    }

    is.close();

    if (document_.Parse(json.c_str()).HasParseError()) {
        fprintf(stderr, "\nError(offset %u): %s\n", 
            (unsigned)document_.GetErrorOffset(),
            GetParseError_En(document_.GetParseError()));

        printf("\n\n%s\n\n", json.c_str());

    }

    if (!document_.IsObject()) {
        printf("Arquivo de config invalido\n");
        return false;
    }

    unlink(filename);

    return true;
}

void JsonReader::PrintContent()
{
	for (Value::ConstMemberIterator itr = document_.MemberBegin();
	    itr != document_.MemberEnd(); ++itr)
	{
	    printf("%s - %s\n", itr->name.GetString(), itr->value.GetString());
	}
}