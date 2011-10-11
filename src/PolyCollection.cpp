#include "PolyCollection.h"
#include "Polygon.h"
//__HEADERS__
//__HEADERS__
void* PolyCollection::Constructor()
{
  return new PolyCollection();
}
PolyCollection::PolyCollection()
{
m_Polygons.reinit(sizeof(Polygon*), 0);
//__CUSTOM_INIT__
//__CUSTOM_INIT__

}

PolyCollection::PolyCollection(const PolyCollection& other)
{
  copy(other);
}

PolyCollection& PolyCollection::operator=(const PolyCollection& other)
{
  copy(other);
  return *this;
}

void PolyCollection::copy(const PolyCollection& other)
{
  m_Name = other.m_Name;
  m_Polygons = other.m_Polygons;
}

PolyCollection::~PolyCollection()
{
}

PolyCollection::PolyCollection(string name, DynamicArray* polygons)
{
m_Name = name;
if(polygons != NULL){m_Polygons.deepCopy(polygons);}
}
string PolyCollection::getName()
{
  return m_Name;
}

const string PolyCollection::getName() const
{
  return m_Name;
}

void PolyCollection::setName(string value)
{
  m_Name = value;
}
DynamicArray& PolyCollection::getPolygons()
{
  return m_Polygons;
}

const DynamicArray& PolyCollection::getPolygons() const
{
  return m_Polygons;
}

const Polygon* PolyCollection::getPolygonsElement(unsigned int index) const
{
return *(Polygon**)m_Polygons.get(index);
}

Polygon* PolyCollection::getPolygonsElement(unsigned int index)
{
return *(Polygon**)m_Polygons.get(index);
}

unsigned int PolyCollection::getPolygonsCount() const
{
  return m_Polygons.getCount();
}
void PolyCollection::setPolygons(const DynamicArray& array)
{
  m_Polygons.deepCopy(&array);
}

void PolyCollection::setPolygonsElement(unsigned int index, Polygon* element)
{
  m_Polygons.safeSet(index, &element);
}
void PolyCollection::appendPolygons(Polygon* element)
{
  m_Polygons.append(&element);
}
void PolyCollection::merge(const PolyCollection& other)
{
    mergeName(other.m_Name);
    mergePolygons(other.m_Polygons);
}

void PolyCollection::clear()
{
    clearName();
    clearPolygons();
}
void PolyCollection::mergeName(const string& otherName)
{
}
void PolyCollection::mergePolygons(const DynamicArray& otherPolygons)
{
  m_Polygons.merge(otherPolygons);
}
void PolyCollection::clearName()
{
}
void PolyCollection::clearPolygons()
{
  m_Polygons.clearData();
}
//__CUSTOM_METHODS__
void PolyCollection::reverseWindingOrder()
{
  unsigned int count = getPolygonsCount();
  for(unsigned int polyIndex = 0; polyIndex < count; polyIndex++)
    {
      Polygon* currentPolygon = getPolygonsElement(polyIndex);
      currentPolygon->reverseWindingOrder();
    }
}

void PolyCollection::deepCopy(const PolyCollection* copyable)
{
  PolyCollection* otherPolyCollection2 = (PolyCollection*)copyable;
  
  m_Name = otherPolyCollection2->m_Name;
  m_Polygons.deepCopy(&otherPolyCollection2->m_Polygons);
}
void PolyCollection::destroy()
{

}

void PolyCollection::cache()
{
  
}

void PolyCollection::uncache()
{
  
}

void PolyCollection::reinitPolygons(unsigned int polyCount)
{
  m_Polygons.setCount(polyCount);
}

void PolyCollection::findVerticesWithIndex(unsigned int streamIndex, 
				       unsigned int vertIndex, 
			  vector<Vertex*>& foundVertices)
{
  //assuming pos is at zero
  unsigned int polygonCount = getPolygonsCount();
  for(unsigned int polygonIndex = 0; 
      polygonIndex < polygonCount; 
      polygonIndex++)
    {
      Polygon* currentPolygon = 
	getPolygonsElement(polygonIndex);
      
      currentPolygon->findVerticesWithIndex(streamIndex,
						   vertIndex, 
						   foundVertices);
      
    }
}

void PolyCollection::appendStreamIndexToVertices(unsigned int streamIndex)
{
  unsigned int polygonCount = getPolygonsCount();
  for(unsigned int index = 0; index < polygonCount; index++)
    {
      Polygon* polygon = getPolygonsElement(index);
      polygon->appendStreamIndexToVertices(streamIndex);
    }
}
//__CUSTOM_METHODS__
