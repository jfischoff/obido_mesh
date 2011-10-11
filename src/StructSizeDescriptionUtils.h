#ifndef STRUCTSIZEDESCRIPTIONUTILS_H
#define STRUCTSIZEDESCRIPTIONUTILS_H


class StructSizeDescription;

void setupAsPosition(StructSizeDescription* ssd);
void setupAsNormal(StructSizeDescription* ssd);
void setupAsBinormal(StructSizeDescription* ssd);
void setupAsTangent(StructSizeDescription* ssd);
void setupAsColors(StructSizeDescription* ssd, unsigned int index);
void setupAsUV(StructSizeDescription* ssd, unsigned int index = 0);
void setupAsBoneIndices(StructSizeDescription* ssd);
void setupAsBoneWeight(StructSizeDescription* ssd);



#endif //STRUCTSIZEDESCRIPTIONUTILS_H
