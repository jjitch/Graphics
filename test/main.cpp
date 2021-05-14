#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/type_ptr.hpp>


template<class T> void p(T v) { std::cout << glm::to_string(v) << std::endl; }

int main()
{
	using namespace std;
	using namespace glm;
	const double size[2] = { 640., 480. };
	const double scale(200.);
	const double location[2] = { 0.,0. };

	const glm::dvec3 eye(0., 0., 0.);
	const glm::dvec3 center(0., 0., -1.);
	const glm::dvec3 up(0., 1., 0.);
	const glm::dmat4 view = glm::lookAt(eye, center, up);
	const double w(scale / size[0]), h(scale / size[1]);
	const glm::dvec3 translating(location[0], location[1], 0.);
	const glm::dvec3 scaling(scale / size[0], scale / size[1], 1.);
	const glm::dmat4 model = glm::translate(glm::dmat4(1.), translating);
	const glm::dmat4 projection = glm::ortho(-w, w, -h, h, 1., 10.);
	const glm::dmat4 viewModel = view * model;
	p(model);
	p(view);
	p(projection);
	p(projection*view*model);

	mat4 a = {};
	mat4 b = {};
	p(a);
}