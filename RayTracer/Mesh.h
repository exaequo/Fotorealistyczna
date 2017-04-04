#pragma once
#include "Vector3.h"
#include "Primitive.h"
#include "Triangle.h"

class Mesh :
	public Primitive
{
public:
	Mesh();
	Mesh(const std::string &fileName);
	Mesh(const std::string &fileName, const Color &material);
	~Mesh();

	void LoadMesh(const std::string &fileName);

	std::vector<Triangle *> Polygons() const { return polygons; }
	void Polygons(std::vector<Triangle *> val) { polygons = val; }
	std::vector<Vector3> Vertices() const { return vertices; }
	void Vertices(std::vector<Vector3> val) { vertices = val; }
	std::vector<Vector3> TextureCoord() const { return textureCoord; }
	void TextureCoord(std::vector<Vector3> val) { textureCoord = val; }
	std::vector<Vector3> Normals() const { return normals; }
	void Normals(std::vector<Vector3> val) { normals = val; }

	virtual bool Intersect(Ray &ray) override;
	virtual void IntersectionOutput(const Ray &ray) override;

private:
	std::vector<Triangle *> polygons;
	std::vector<Vector3> vertices;
	std::vector<Vector3> textureCoord;
	std::vector<Vector3> normals;
	std::vector<Material> materials;
};

