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
	auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
	for (ll i = 0; i < N; ++i)
	{
		a += b;
	}
	auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
	auto dur = end - start;        // 要した時間を計算
	auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
	// 要した時間をミリ秒（1/1000秒）に変換して表示
	std::cout << msec << " milli sec \n";
	return 0;
}