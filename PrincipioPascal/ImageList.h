#ifndef IMAGELIST_H
#define IMAGELIST_H
#include <iostream>
#include "Imaage.h"

using namespace std;

class ImageList
{
    public:
        Imaage* inicio = NULL;
        Imaage* fin = NULL;
        ImageList();
        void addImage(Imaage* image);
        Imaage* getImageInPosition(int position);
        int sizeImageList();
        virtual ~ImageList();

    protected:

    private:
};

#endif // IMAGELIST_H
