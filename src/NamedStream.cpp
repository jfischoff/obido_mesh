#include "NamedStream.h"
#include "Stream.h"


void* NamedStream::Constructor()
{
  return new NamedStream();
}
NamedStream::NamedStream()
{
  m_Stream = NULL;

}

NamedStream::NamedStream(const NamedStream& other)
{
  copy(other);
}

NamedStream& NamedStream::operator=(const NamedStream& other)
{
  copy(other);
  return *this;
}

void NamedStream::copy(const NamedStream& other)
{
  m_Stream = other.m_Stream;
  m_Name = other.m_Name;
}

NamedStream::~NamedStream()
{
}

NamedStream::NamedStream(Stream* stream, string name)
{
  m_Stream = stream;
  m_Name = name;
}
Stream* NamedStream::getStream()
{
  return m_Stream;
}

const Stream* NamedStream::getStream() const
{
  return m_Stream;
}

void NamedStream::setStream(Stream* value)
{
  m_Stream = value;
}
string NamedStream::getName()
{
  return m_Name;
}

const string NamedStream::getName() const
{
  return m_Name;
}

void NamedStream::setName(string value)
{
  m_Name = value;
}
void NamedStream::merge(const NamedStream& other)
{
  mergeStream(other.m_Stream);
  mergeName(other.m_Name);
}

void NamedStream::clear()
{
  clearStream();
  clearName();
}
void NamedStream::mergeStream(Stream* const otherStream)
{
  m_Stream->merge(*otherStream);
}
void NamedStream::mergeName(const string& otherName)
{
}
void NamedStream::clearStream()
{
  m_Stream->clear();
}
void NamedStream::clearName()
{
}
