#include "Mesh.h"
#include "NamedStream.h"
#include "PolyCollection.h"
#include "Stream.h"
#include "StructSizeDescription.h"
#include "StructSizeDescriptionUtils.h"
#include <sstream>
#include <assert.h>

void* Mesh::Constructor()
{
  return new Mesh();
}

Mesh::Mesh()
{
  m_Streams.reinit(sizeof(NamedStream*), 0);
  m_PolyCollection = NULL;
}

Mesh::Mesh(const Mesh& other)
{
  copy(other);
}

Mesh& Mesh::operator=(const Mesh& other)
{
  copy(other);
  return *this;
}

void Mesh::copy(const Mesh& other)
{
  m_Streams = other.m_Streams;
  m_PolyCollection = other.m_PolyCollection;
}

Mesh::~Mesh()
{
}

Mesh::Mesh(DynamicArray* streams, 
	     PolyCollection* polyCollection)
{
  if(streams != NULL){m_Streams.deepCopy(streams);}
  m_PolyCollection = polyCollection;
}

DynamicArray& Mesh::getStreams()
{
  return m_Streams;
}

const DynamicArray& Mesh::getStreams() const
{
  return m_Streams;
}

const NamedStream* Mesh::getStreamsElement(unsigned int index) const
{
  return *(NamedStream**)m_Streams.get(index);
}

NamedStream* Mesh::getStreamsElement(unsigned int index)
{
  return *(NamedStream**)m_Streams.get(index);
}

unsigned int Mesh::getStreamsCount() const
{
  return m_Streams.getCount();
}
void Mesh::setStreams(const DynamicArray& array)
{
  m_Streams.deepCopy(&array);
}

void Mesh::setStreamsElement(unsigned int index, NamedStream* element)
{
  m_Streams.safeSet(index, &element);
}
void Mesh::appendStreams(NamedStream* element)
{
  m_Streams.append(&element);
}
PolyCollection* Mesh::getPolyCollection()
{
  return m_PolyCollection;
}

const PolyCollection* Mesh::getPolyCollection() const
{
  return m_PolyCollection;
}

void Mesh::setPolyCollection(PolyCollection* value)
{
  m_PolyCollection = value;
}
void Mesh::merge(const Mesh& other)
{
  mergeStreams(other.m_Streams);
  mergePolyCollection(other.m_PolyCollection);
}

void Mesh::clear()
{
  clearName();
  clearStreams();
  clearPolyCollection();
}

void Mesh::mergeStreams(const DynamicArray& otherStreams)
{
  m_Streams.merge(otherStreams);
}
void Mesh::mergePolyCollection(PolyCollection* const otherPolyCollection)
{
  m_PolyCollection->merge(*otherPolyCollection);
}

void Mesh::clearStreams()
{
  m_Streams.clearData();
}
void Mesh::clearPolyCollection()
{
  m_PolyCollection->clear();
}

void Mesh::deepCopy(const Mesh* copyable)
{
  Mesh* otherMesh = (Mesh*)copyable;
  
  m_Streams.deepCopy(&otherMesh->m_Streams);;
  m_PolyCollection->deepCopy(otherMesh->m_PolyCollection);
}

void Mesh::destroy()
{
  //
}

void Mesh::reverseWindingOrder()
{
  m_PolyCollection->reverseWindingOrder();
}

const Stream* Mesh::getStreamsElement(string name) const
{
  const NamedStream* currentStream = NULL;
  unsigned int count = getStreamsCount();
  for(unsigned int index = 0; index < count; index++)
    {
      currentStream = getStreamsElement(index);
      if(currentStream->getName() == name)
	{
	  return currentStream->getStream();
	}
    }

  assert(0);
  return NULL;
}

Stream* Mesh::getStreamsElement(string name)
{
  NamedStream* currentStream = NULL;
  unsigned int count = getStreamsCount();
  assert(count < 100); //not a hard limit just doesn't make sense other wise
  for(unsigned int index = 0; index < count; index++)
    {
      currentStream = getStreamsElement(index);
      string currentName = currentStream->getName();
      if(currentName == name)
	{
	  return currentStream->getStream();
	}
    }

  assert(0);
  return NULL;
}



bool Mesh::hasStream(string name) const
{
  unsigned int count = getStreamsCount();
  for(unsigned int index = 0; index < count; index++)
    {
      const NamedStream* currentStream = getStreamsElement(index);
      if(currentStream->getName() == name)
	{
	  return true;
	}
    }

  return false;
}

void Mesh::addStream(string name, StructSizeDescription* ssd)
{
  Stream* newStream = new Stream(ssd);
  unsigned int size = ssd->getSize();
  newStream->reinit(size, 0);
  
  NamedStream* newNamedStream = new NamedStream(newStream, name);
  m_Streams.append(&newNamedStream); 
}

void Mesh::reinitPolyCount(unsigned int polyCount)
{
  m_PolyCollection->reinitPolygons(polyCount);
}

Polygon* Mesh::getPolygon(unsigned int polyIndex)
{
  return m_PolyCollection->getPolygonsElement(polyIndex);
}

void Mesh::setPolygon(unsigned int index, Polygon* polygon)
{
  m_PolyCollection->setPolygonsElement(index, polygon);
}

void Mesh::findVerticesWithPositionIndex(unsigned int vertIndex, 
					  vector<Vertex*>& foundVertices)
{
  
  m_PolyCollection->findVerticesWithIndex(0, vertIndex, 
					  foundVertices);

}

void Mesh::appendStreamIndexToVertices(unsigned int streamIndex)
{
  m_PolyCollection->appendStreamIndexToVertices(streamIndex);
}

