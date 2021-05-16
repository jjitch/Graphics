#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/type_ptr.hpp>

using ll = long long;

int main()
{
	const ll N = (ll)100000000;
	float a = 0.;
	float b = 0.0001;
	auto start = std::chrono::system_clock::now();      // �v���X�^�[�g������ۑ�
	for (ll i = 0; i < N; ++i)
	{
		a += b;
	}
	auto end = std::chrono::system_clock::now();       // �v���I��������ۑ�
	auto dur = end - start;        // �v�������Ԃ��v�Z
	auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
	// �v�������Ԃ��~���b�i1/1000�b�j�ɕϊ����ĕ\��
	std::cout << msec << " milli sec \n";
	return 0;
}