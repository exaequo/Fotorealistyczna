#include "stdafx.h"
#include "Mesh.h"

Mesh::Mesh()
{
}


Mesh::Mesh(const std::string &fileName)
{
	LoadMesh(fileName);
}

Mesh::Mesh(const std::string &fileName, const Color &material) :
	Primitive(material)
{
	LoadMesh(fileName);
}

Mesh::~Mesh()
{
}

void Mesh::LoadMesh(const std::string &fileName)
{
	string token;
	string stringValue;
	ifstream objFile(fileName + ".obj");
	ifstream mtlFile(fileName + ".mtl");

	Vector3 vectorValue;
	char delimeter = ' ';
	vector<string> objFileTokens;
	vector<string> mtlFileTokens;

	if (mtlFile.is_open())
	{
		while (mtlFile >> token)
		{
			mtlFileTokens.push_back(token);
		}

		mtlFile.close();
	}
	else
	{
		cout << "Unable to open file: " << fileName << ".mtl" << endl;
	}

	if (objFile.is_open())
	{
		while (objFile >> token)
		{
			objFileTokens.push_back(token);
		}

		objFile.close();
	}
	else
	{
		cout << "Unable to open file: " << fileName << ".obj" << endl;
	}

	Material *currentMat = new Material();
	int count = mtlFileTokens.size();
	int i = 0;
	while (i < count)
	{
		if (mtlFileTokens[i] == "newmtl")
		{
			materials.push_back(Material(mtlFileTokens[i + 1]));
			currentMat = &materials[materials.size() - 1];
			i += 2;
			continue;
		}

		if (mtlFileTokens[i] == "Ns")
		{
			currentMat->Ns(stof(mtlFileTokens[i + 1]));
			i += 2;
			continue;
		}
		if (mtlFileTokens[i] == "Ni")
		{
			currentMat->Ni(stof(mtlFileTokens[i + 1]));
			i += 2;
			continue;
		}
		if (mtlFileTokens[i] == "d")
		{
			currentMat->D(stof(mtlFileTokens[i + 1]));
			i += 2;
			continue;
		}
		if (mtlFileTokens[i] == "Tr")
		{
			currentMat->Tr(stof(mtlFileTokens[i + 1]));
			i += 2;
			continue;
		}
		if (mtlFileTokens[i] == "Tf")
		{
			currentMat->Tf(Vector3(stof(mtlFileTokens[i + 1]), stof(mtlFileTokens[i + 2]), stof(mtlFileTokens[i + 3])));
			i += 4;
			continue;
		}
		if (mtlFileTokens[i] == "illum")
		{
			currentMat->Illum(stof(mtlFileTokens[i + 1]));
			i += 2;
			continue;
		}
		if (mtlFileTokens[i] == "Ka")
		{
			currentMat->ColorAmbient(Color(stof(mtlFileTokens[i + 1]), stof(mtlFileTokens[i + 2]), stof(mtlFileTokens[i + 3])));
			i += 4;
			continue;
		}
		if (mtlFileTokens[i] == "Kd")
		{
			currentMat->ColorDiffuse(Color(stof(mtlFileTokens[i + 1]), stof(mtlFileTokens[i + 2]), stof(mtlFileTokens[i + 3])));
			i += 4;
			continue;
		}
		if (mtlFileTokens[i] == "Ks")
		{
			currentMat->ColorSpecular(Color(stof(mtlFileTokens[i + 1]), stof(mtlFileTokens[i + 2]), stof(mtlFileTokens[i + 3])));
			i += 4;
			continue;
		}
		if (mtlFileTokens[i] == "Ke")
		{
			currentMat->ColorEmissive(Color(stof(mtlFileTokens[i + 1]), stof(mtlFileTokens[i + 2]), stof(mtlFileTokens[i + 3])));
			i += 4;
			continue;
		}

		++i;
	}


	count = objFileTokens.size();
	i = 0;

	while (i < count)
	{
		if (objFileTokens[i] == "v")
		{
			vertices.push_back(Vector3(stof(objFileTokens[i + 1]), stof(objFileTokens[i + 2]), stof(objFileTokens[i + 3])));
			i += 4;
			continue;
		}

		if (objFileTokens[i] == "vn")
		{
			normals.push_back(Vector3(stof(objFileTokens[i + 1]), stof(objFileTokens[i + 2]), stof(objFileTokens[i + 3])));
			i += 4;
			continue;
		}

		if (objFileTokens[i] == "vt")
		{
			textureCoord.push_back(Vector3(stof(objFileTokens[i + 1]), stof(objFileTokens[i + 2]), stof(objFileTokens[i + 3])));
			i += 4;
			continue;
		}

		if (objFileTokens[i] == "usemtl")
		{
			for (Material &mat : materials)
			{
				if (mat.Name() == objFileTokens[i + 1])
				{
					currentMat = &mat;
				}
			}
		}

		if (objFileTokens[i] == "f")
		{
			size_t first = objFileTokens[i + 1].find_first_of('/');
			size_t last = objFileTokens[i + 1].find_last_of('/');

			string sub = objFileTokens[i + 1].substr(0, first);
			int index1 = stoi(sub) - 1;

			first = objFileTokens[i + 2].find_first_of('/');
			sub = objFileTokens[i + 2].substr(0, first);
			int index2 = stoi(sub) - 1;

			first = objFileTokens[i + 3].find_first_of('/');
			sub = objFileTokens[i + 3].substr(0, first);
			int index3 = stoi(sub) - 1;

			sub = objFileTokens[i + 1].substr(++last, objFileTokens[i + 1].size());
			int index4 = stoi(sub) - 1;

			polygons.push_back(new Triangle(vertices[index1], vertices[index2], vertices[index3], normals[index4], *currentMat));
			i += 4;
			continue;
		}

		++i;
	}
}

bool Mesh::Intersect(Ray &ray)
{
	for (auto &triangle : polygons)
	{
		if (triangle->Intersect(ray))
		{
			return true;
		}
	}
	return false;
}

void Mesh::IntersectionOutput(const Ray &ray)
{
	throw std::logic_error("The method or operation is not implemented.");
}
