#include "ImageList.h"

ImageList::ImageList()
{
    //ctor
}

void ImageList::addImage(Imaage* image)
{
    Imaage* imageTemp = image;

    if(inicio == NULL)
        inicio =  fin = imageTemp;
    else{
        fin->siguiente = imageTemp;
        fin = imageTemp;
    }
}

int ImageList::sizeImageList()
{
    int _size = 0;
    Imaage* temp = inicio;

    while(temp != NULL)
    {
        _size++;
        temp = temp->siguiente;
    }
    return _size;
}

Imaage* ImageList::getImageInPosition(int position)
{
    int _position = 0;
    Imaage* temp = inicio;

    while(temp != NULL)
    {
        if(_position == position)
        {
            return temp;
        }
        temp = temp->siguiente;
        _position++;
    }
    return NULL;
}

ImageList::~ImageList()
{
    //dtor
}
