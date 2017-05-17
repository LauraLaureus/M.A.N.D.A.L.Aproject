#pragma once
#include "SystemHeader.h"
#include "GraphicsHeader.h"
#include "glm\glm.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

class Renderizable
{
protected:
	std::string filename;
	std::vector<glm::vec4> vertices;
	std::vector<glm::vec3> normals;
	std::vector<GLshort> elements;

public:
	virtual void render();
	void loadObj(std::string filename, std::vector<glm::vec4>& vertices, std::vector<glm::vec3>& normals, std::vector<GLshort> ) {
	
		using namespace std;
		ifstream in(filename, ios::in);
		if (!in)
		{
			cerr << "Cannot open " << filename << endl; exit(1);
		}

    string line;
    while (getline(in, line))
    {
        if (line.substr(0,2) == "v ")
        {
            istringstream s(line.substr(2));
            glm::vec4 v; s >> v.x; s >> v.y; s >> v.z; v.w = 1.0f;
            vertices.push_back(v);
        }
        else if (line.substr(0,2) == "f ")
        {
            istringstream s(line.substr(2));
            GLushort a,b,c;
            s >> a; s >> b; s >> c;
            a--; b--; c--;
           elements.push_back(a); elements.push_back(b); elements.push_back(c);
        }
        else if (line[0] == '#')
        {
            /* ignoring this line */
        }
        else
        {
            /* ignoring this line */
        }
    }

    normals.resize(vertices.size(), glm::vec3(0.0, 0.0, 0.0));
	for (int i = 0; i < elements.size(); i += 3)
	{
		GLushort ia = elements[i];
		GLushort ib = elements[i + 1];
		GLushort ic = elements[i + 2];
		glm::vec3 normal = glm::normalize(glm::cross(
			glm::vec3(vertices[ib]) - glm::vec3(vertices[ia]),
			glm::vec3(vertices[ic]) - glm::vec3(vertices[ia])));
		normals[ia] = normals[ib] = normals[ic] = normal;
	}
};

		
private:

};

