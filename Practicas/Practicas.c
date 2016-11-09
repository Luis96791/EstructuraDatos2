
_nodoPersona* pasarDataALista(char* data, int seek, char delimitador)
{
	_nodoPersona* NP = malloc(sizeof(_nodoPersona));
	int posInicial = seek;
	seek = buscarDelimitador(data, seek, delimitador);

	strcpy(&(NP->nombre), &(data[posInicial]), (seek - posInicial));
	seek += (seek - posInicial) + 1;
	posInicial = seek;
	seek = buscarDelimitador(data, seek, delimitador);
	strcpy(&(NP->apellido), &(data[posInicial]), (seek - posInicial));
	seek += (seek - posInicial) + 1;
	posInicial = seek;
	seek = buscarDelimitador(data, seek, delimitador);
	strcpy(&(NP->edad), &(data[posInicial]), (seek - posInicial));
	seek += (seek - posInicial) + 1;

	return NP;
} 

int buscarDelimitador(char* data, int seek, char delimitador)
{
	while( 1 )
	{
		if(data[seek] != delimitador)
			seek++;
		else
			break;
	}
	return seek;
}

char* pasarDeListaAData(char* data, _nodoPersona* NP, char delimitador, int seek)
{
	int sizeNombre = strlen(NP->nombre);
	int sizeApellido = strlen(NP->apellido);
	int sizeEdad = strlen(NP->edad);

	memcpy(&(data[seek]), &(NP->nombre), sizeNombre);
	seek += sizeNombre;
	memcpy(&(data[seek]), delimitador, 1);
	seek += 1;
	memcpy(&(data[seek]), &(NP->apellido), sizeApellido);
	seek += sizeApellido;
	memcpy(&(data[seek]), delimitador, 1);
	seek += 1;
	memcpy(&(data[seek]), &(NP->edad), sizeEdad);
	seek += edad;
	memcpy(&(data[seek]), delimitador, 1);
	seek += 1;

	return data;
}