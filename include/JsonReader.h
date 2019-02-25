#ifndef _JSON_READER_H_
#define _JSON_READER_H_

#include <fstream>
#include <unistd.h>

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>
#include <rapidjson/reader.h>
#include <rapidjson/filereadstream.h>

using rapidjson::BaseReaderHandler;
using rapidjson::Document;
using rapidjson::FileReadStream;
using rapidjson::Value;

class JsonReader {
public:
	/**
	 * Construtor da classe.
	 */
	JsonReader();
	/**
	 * Destrutor da classe.
	 */
	~JsonReader();
	/**
	 * Carrega o arquivo JSON.
	 * \param filename Nome do arquivo.
	 * \return True caso o arquivo seja carregado com sucesso, senão False.
	 */
	bool LoadFile(const char* filename);
	/**
	 * Imprime o conteúdo do JSON lido.
	 */
	void PrintContent();

private:
	Document document_;
};
#endif //_JSON_READER_H_