#include "Polygon.h"
#include "Vertex.h"
#include <vector>
#include <assert.h>

void* Polygon::Constructor()
{
  return new Polygon();
}
Polygon::Polygon()
{
  m_Vertices.reinit(sizeof(Vertex*), 0);
}

Polygon::Polygon(const Polygon& other)
{
  copy(other);
}

Polygon& Polygon::operator=(const Polygon& other)
{
  copy(other);
  return *this;
}

void Polygon::copy(const Polygon& other)
{
  m_Vertices = other.m_Vertices;
}

Polygon::~Polygon()
{
}

Polygon::Polygon(DynamicArray* vertices)
{
  if(vertices != NULL){m_Vertices.deepCopy(vertices);}
}

DynamicArray& Polygon::getVertices()
{
  return m_Vertices;
}

const DynamicArray& Polygon::getVertices() const
{
  return m_Vertices;
}

const Vertex* Polygon::getVerticesElement(unsigned int index) const
{
  return *(Vertex**)m_Vertices.get(index);
}

Vertex* Polygon::getVerticesElement(unsigned int index)
{
  return *(Vertex**)m_Vertices.get(index);
}

unsigned int Polygon::getVerticesCount() const
{
  return m_Vertices.getCount();
}
void Polygon::setVertices(const DynamicArray& array)
{
  m_Vertices.deepCopy(&array);
}

void Polygon::setVerticesElement(unsigned int index, Vertex* element)
{
  m_Vertices.safeSet(index, &element);
}
void Polygon::appendVertices(Vertex* element)
{
  m_Vertices.append(&element);
}
void Polygon::merge(const Polygon& other)
{
  mergeVertices(other.m_Vertices);
}

void Polygon::clear()
{
  clearVertices();
}

void Polygon::mergeVertices(const DynamicArray& otherVertices)
{
  m_Vertices.merge(otherVertices);
}

void Polygon::clearVertices()
{
  m_Vertices.clearData();
}

void Polygon::deepCopy(const Polygon* copyable)
{
  m_Vertices.deepCopy(&copyable->m_Vertices);
}

void Polygon::destroy()
{
  assert(0);
}

void Polygon::reverseWindingOrder()
{
  //this should really be a static
  //get the two spots as temp variables and switch them
  int count = getVerticesCount();

  int halfCount = count / 2;

  for(int index = 0; index < halfCount; index++)
    {
      int endIndex = count - index;
      
      Vertex* startVertex = getVerticesElement(index);
      Vertex* endVertex = getVerticesElement(endIndex);

      setVerticesElement(index, endVertex);
      setVerticesElement(endIndex, startVertex);
    }
}

void Polygon::reinit(int count)
{
  m_Vertices.setCount(count);
}

void Polygon::findVerticesWithIndex(int streamIndex,
				     int vertIndex,
				     vector<Vertex*>&
				     foundVertices)
{
  for(int polygonVertIndex = 0; 
      polygonVertIndex < getVerticesCount();
      polygonVertIndex++)
    {
      Vertex* currentVertex = 
	getVerticesElement(polygonVertIndex);
      if(currentVertex->hasIndex(streamIndex, vertIndex))
	{
	  foundVertices.push_back(currentVertex);
	}
    }
}

void Polygon::appendStreamIndexToVertices(int streamIndex)
{
  int vertCount = getVerticesCount();
  for(int polygonIndex = 0; polygonIndex < vertCount; 
      polygonIndex++)
    {
      Vertex* vertex = getVerticesElement(polygonIndex);
      vertex->appendStreamIndices(streamIndex);
    }
}

