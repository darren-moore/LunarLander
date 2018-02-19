#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <string> 
#include <sstream>
#include <fstream>

class Shader {
public:
	unsigned int ID;

	Shader(GLchar const* vertexPath, GLchar const* fragmentPath);

	void use();

	void setBool(std::string const &name, bool value) const;
	void setInt(std::string const &name, int value) const;
	void setFloat(std::string const &name, float value) const;
	void setVec3(std::string const &name, glm::vec3 value) const;
	void setMat4(std::string const &name, glm::mat4 value) const;

};

#endif //SHADER_H