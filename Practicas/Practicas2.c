
_nodoPersona* pasarDataALista(char* data, int seek)
{
	int sizeNombre, sizeApellido, sizeEdad;
	_nodoPersona* NP = malloc(sizeof(_nodoPersona));

	memcpy(&(sizeNombre), &(data[seek]), 4);
	seek += 4;
	memcpy(&(NP->nombre), &(data[seek]), sizeNombre);
	seek += sizeNombre;
	memcpy(&(sizeApellido), &(data[seek]), 4);
	seek += 4;
	memcpy(&(NP->apellido), &(data[seek]), sizeApellido);
	seek += sizeApellido;
	memcpy(&(sizeEdad), &(data[seek]), 4);
	seek += 4;
	memcpy(&(NP->Edad), &(data[seek]), sizeEdad);
	seek += sizeEdad;
}