#include "Vertex.h"
//__HEADERS__
//__HEADERS__
void* Vertex::Constructor()
{
  return new Vertex();
}
Vertex::Vertex()
{
m_StreamIndices.reinit(sizeof(unsigned int), 0);
//__CUSTOM_INIT__
//__CUSTOM_INIT__

}

Vertex::Vertex(const Vertex& other)
{
  copy(other);
}

Vertex& Vertex::operator=(const Vertex& other)
{
  copy(other);
  return *this;
}

void Vertex::copy(const Vertex& other)
{
  m_Name = other.m_Name;
  m_DebugName = other.m_DebugName;
  m_StreamIndices = other.m_StreamIndices;
}

Vertex::~Vertex()
{
}

Vertex::Vertex(string name, string debugName, DynamicArray* streamIndices)
{
m_Name = name;
m_DebugName = debugName;
if(streamIndices != NULL){m_StreamIndices.deepCopy(streamIndices);}
}
string Vertex::getName()
{
  return m_Name;
}

const string Vertex::getName() const
{
  return m_Name;
}

void Vertex::setName(string value)
{
  m_Name = value;
}
string Vertex::getDebugName()
{
  return m_DebugName;
}

const string Vertex::getDebugName() const
{
  return m_DebugName;
}

void Vertex::setDebugName(string value)
{
  m_DebugName = value;
}
DynamicArray& Vertex::getStreamIndices()
{
  return m_StreamIndices;
}

const DynamicArray& Vertex::getStreamIndices() const
{
  return m_StreamIndices;
}

const unsigned int Vertex::getStreamIndicesElement(unsigned int index) const
{
return *(unsigned int*)m_StreamIndices.get(index);
}

unsigned int Vertex::getStreamIndicesElement(unsigned int index)
{
return *(unsigned int*)m_StreamIndices.get(index);
}

unsigned int Vertex::getStreamIndicesCount() const
{
  return m_StreamIndices.getCount();
}
void Vertex::setStreamIndices(const DynamicArray& array)
{
  m_StreamIndices.deepCopy(&array);
}

void Vertex::setStreamIndicesElement(unsigned int index, unsigned int element)
{
  m_StreamIndices.safeSet(index, &element);
}
void Vertex::appendStreamIndices(unsigned int element)
{
  m_StreamIndices.append(&element);
}
void Vertex::merge(const Vertex& other)
{
    mergeName(other.m_Name);
    mergeDebugName(other.m_DebugName);
    mergeStreamIndices(other.m_StreamIndices);
}

void Vertex::clear()
{
    clearName();
    clearDebugName();
    clearStreamIndices();
}
void Vertex::mergeName(const string& otherName)
{
}
void Vertex::mergeDebugName(const string& otherDebugName)
{
}
void Vertex::mergeStreamIndices(const DynamicArray& otherStreamIndices)
{
}
void Vertex::clearName()
{
}
void Vertex::clearDebugName()
{
}
void Vertex::clearStreamIndices()
{
  m_StreamIndices.clearData();
}
//__CUSTOM_METHODS__
void Vertex::addMultiple(int count, int index)
{
  for(int index = 0; index < count; index++)
    {
      appendStreamIndices(index);
    }
}
void Vertex::deepCopy(const Vertex* copyable)
{
  Vertex* otherVertex = (Vertex*)copyable;
  
  m_Name = otherVertex->m_Name;
  m_DebugName = otherVertex->m_DebugName;
  m_StreamIndices.deepCopy(&otherVertex->m_StreamIndices);
}

void Vertex::destroy()
{

}

void Vertex::cache()
{

}

void Vertex::uncache()
{

}

bool Vertex::hasIndex(int streamIndex, int vertIndex)
{

  int currentVertIndex = getStreamIndicesElement(
			       streamIndex);
  
  if(currentVertIndex == vertIndex)
    {
      return true;
    }
    
  
  return false;
}
//__CUSTOM_METHODS__
