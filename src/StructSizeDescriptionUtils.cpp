#include "StructSizeDescriptionUtils.h"
#include <StructSizeDescription.h>
#include <sstream>
#include <assert.h>

void setupAsPosition(StructSizeDescription* ssd)
{  
  ssd->destroy();

  ssd->setIsPrimitive(false);
  ssd->setPrimitiveType(INT);
  ssd->setName("Position");

  StructSizeDescription* ssdX = new StructSizeDescription();
  ssdX->setName("x");
  ssdX->setIsPrimitive(true);
  ssdX->setPrimitiveType(FLOAT);
  ssdX->cache();

  StructSizeDescription* ssdY = new StructSizeDescription();
  ssdY->setName("y");
  ssdY->setIsPrimitive(true);
  ssdY->setPrimitiveType(FLOAT);
  ssdY->cache();

  StructSizeDescription* ssdZ = new StructSizeDescription();
  ssdZ->setName("z");
  ssdZ->setIsPrimitive(true);
  ssdZ->setPrimitiveType(FLOAT);
  ssdZ->cache();

  ssd->appendChildren(ssdX);
  ssd->appendChildren(ssdY);
  ssd->appendChildren(ssdZ);

  ssd->cache();
}

void setupAsNormal(StructSizeDescription* ssd)
{
  ssd->destroy();


  ssd->setIsPrimitive(false);
  ssd->setPrimitiveType(INT);
  ssd->setName("Normal");

  StructSizeDescription* ssdX = new StructSizeDescription();
  ssdX->setName("x");
  ssdX->setIsPrimitive(true);
  ssdX->setPrimitiveType(FLOAT);
  ssdX->cache();

  StructSizeDescription* ssdY = new StructSizeDescription();
  ssdY->setName("y");
  ssdY->setIsPrimitive(true);
  ssdY->setPrimitiveType(FLOAT);
  ssdY->cache();

  StructSizeDescription* ssdZ = new StructSizeDescription();
  ssdZ->setName("z");
  ssdZ->setIsPrimitive(true);
  ssdZ->setPrimitiveType(FLOAT);
  ssdZ->cache();

  ssd->appendChildren(ssdX);
  ssd->appendChildren(ssdY);
  ssd->appendChildren(ssdZ);

  ssd->cache();
}

void setupAsBinormal(StructSizeDescription* ssd)
{
  ssd->destroy();


  ssd->setIsPrimitive(false);
  ssd->setPrimitiveType(INT);
  ssd->setName("Binormal");

  StructSizeDescription* ssdX = new StructSizeDescription();
  ssdX->setName("x");
  ssdX->setIsPrimitive(true);
  ssdX->setPrimitiveType(FLOAT);
  ssdX->cache();

  StructSizeDescription* ssdY = new StructSizeDescription();
  ssdY->setName("y");
  ssdY->setIsPrimitive(true);
  ssdY->setPrimitiveType(FLOAT);
  ssdY->cache();

  StructSizeDescription* ssdZ = new StructSizeDescription();
  ssdZ->setName("z");
  ssdZ->setIsPrimitive(true);
  ssdZ->setPrimitiveType(FLOAT);
  ssdZ->cache();

  ssd->appendChildren(ssdX);
  ssd->appendChildren(ssdY);
  ssd->appendChildren(ssdZ);

  ssd->cache();
}

void setupAsColors(StructSizeDescription* ssd, unsigned int index)
{
  assert(0);
}

void setupAsTangent(StructSizeDescription* ssd)
{
  ssd->destroy();


  ssd->setIsPrimitive(false);
  ssd->setPrimitiveType(INT);
  ssd->setName("Tangent");

  StructSizeDescription* ssdX = new StructSizeDescription();
  ssdX->setName("x");
  ssdX->setIsPrimitive(true);
  ssdX->setPrimitiveType(FLOAT);
  ssdX->cache();

  StructSizeDescription* ssdY = new StructSizeDescription();
  ssdY->setName("y");
  ssdY->setIsPrimitive(true);
  ssdY->setPrimitiveType(FLOAT);
  ssdY->cache();

  StructSizeDescription* ssdZ = new StructSizeDescription();
  ssdZ->setName("z");
  ssdZ->setIsPrimitive(true);
  ssdZ->setPrimitiveType(FLOAT);
  ssdZ->cache();

  ssd->appendChildren(ssdX);
  ssd->appendChildren(ssdY);
  ssd->appendChildren(ssdZ);

  ssd->cache();
}

void setupAsUV(StructSizeDescription* ssd, unsigned int index)
{
  stringstream ss;
  ss << "UV" << index;
  string name = ss.str();

  ssd->setIsPrimitive(false);
  ssd->setPrimitiveType(INT);
  ssd->setName(name);

  StructSizeDescription* ssdX = new StructSizeDescription();
  ssdX->setName("u");
  ssdX->setIsPrimitive(true);
  ssdX->setPrimitiveType(FLOAT);
  ssdX->cache();

  StructSizeDescription* ssdY = new StructSizeDescription();
  ssdY->setName("v");
  ssdY->setIsPrimitive(true);
  ssdY->setPrimitiveType(FLOAT);
  ssdY->cache();

  ssd->appendChildren(ssdX);
  ssd->appendChildren(ssdY);

  ssd->cache();
  int a = 0;
}

void setupAsBoneIndices(StructSizeDescription* ssd)
{
  ssd->destroy();

  ssd->setIsPrimitive(false);
  ssd->setPrimitiveType(INT);
  ssd->setName("BoneIndices");

  StructSizeDescription* ssdX = new StructSizeDescription();
  ssdX->setName("boneIndex0");
  ssdX->setIsPrimitive(true);
  ssdX->setPrimitiveType(UINT);
  ssdX->cache();

  StructSizeDescription* ssdY = new StructSizeDescription();
  ssdY->setName("boneIndex1");
  ssdY->setIsPrimitive(true);
  ssdY->setPrimitiveType(UINT);
  ssdY->cache();

  StructSizeDescription* ssdZ = new StructSizeDescription();
  ssdZ->setName("boneIndex2");
  ssdZ->setIsPrimitive(true);
  ssdZ->setPrimitiveType(UINT);
  ssdZ->cache();

  ssd->appendChildren(ssdX);
  ssd->appendChildren(ssdY);
  ssd->appendChildren(ssdZ);

  ssd->cache();
}

void setupAsBoneWeight(StructSizeDescription* ssd)
{
  ssd->destroy();

  ssd->setIsPrimitive(false);
  ssd->setPrimitiveType(INT);
  ssd->setName("BoneWeights");

  StructSizeDescription* ssdX = new StructSizeDescription();
  ssdX->setName("boneWeight0");
  ssdX->setIsPrimitive(true);
  ssdX->setPrimitiveType(FLOAT);
  ssdX->cache();

  StructSizeDescription* ssdY = new StructSizeDescription();
  ssdY->setName("boneWeight1");
  ssdY->setIsPrimitive(true);
  ssdY->setPrimitiveType(FLOAT);
  ssdY->cache();

  StructSizeDescription* ssdZ = new StructSizeDescription();
  ssdZ->setName("boneWeight2");
  ssdZ->setIsPrimitive(true);
  ssdZ->setPrimitiveType(FLOAT);
  ssdZ->cache();

  ssd->appendChildren(ssdX);
  ssd->appendChildren(ssdY);
  ssd->appendChildren(ssdZ);

  ssd->cache();
}

