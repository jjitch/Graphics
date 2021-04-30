#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>

bool readShaderSource1(const char* name, std::vector<char>& buffer)
{
	if (name == NULL) return false;
	std::ifstream file(name, std::ios_base::in | std::ios_base::out | std::ios_base::binary);
	if (file.fail())
	{
		std::cerr << "Error: Can't open source file: " << name << std::endl;
		return false;
	}
	file.seekg(0L, std::ios::end);
	size_t length = static_cast<size_t>(file.tellg());
	buffer.resize(length + 1);

	file.seekg(0L, std::ios::beg);
	file.read(buffer.data(), length);
	buffer[length] = '\0';

	if (file.fail())
	{
		std::cerr << "Error: Couldn't read source file: " << name << std::endl;
		file.close();
		return false;
	}
	file.close();
	return true;
}

int readShaderSource(std::string fileName)
{
	//ファイルの読み込み
	std::ifstream ifs(fileName, std::ios::binary);
	if (!ifs)
	{
		std::cout << "error" << std::endl;
		return -1;
	}

	std::string source;
	std::string line;
	while (getline(ifs, line))
	{
		source += line + "\n";
	}

	// シェーダのソースプログラムをシェーダオブジェクトへ読み込む
	const char* sourcePtr = (const char*)source.c_str();
	size_t length = source.length();
	//glShaderSource(shaderObj, 1, &sourcePtr, &length);
	std::cout << sourcePtr << std::endl;
	return 0;
}

int main()
{
	using namespace std;
	vector<char> str;
	if (readShaderSource1("test.vert", str)) cout << str.data() << endl;
	readShaderSource("test.vert");
}