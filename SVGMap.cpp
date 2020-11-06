// SVGMap.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "tinyxml2.h"

using namespace tinyxml2;

int main()
{
    //Cargar info de path
    XMLDocument doc;
    doc.LoadFile("world.svg");
    XMLElement* svg = doc.FirstChildElement();
    XMLElement * path = svg->FirstChildElement("path");
    int counter = 0;
    while (path != NULL) {
        counter++;
        std::cout << path->Attribute("id")<<std::endl;
        path = path->NextSiblingElement();
    }
    std::cout << counter;
    //K-Means?(Encontrar k como el codo de la funcion)Reduccion en variacion
    //Se usa como entrada de datos el x,y del punto de origen?
    //Que es el k? (Encontrar el k para el problema de colindancia)
    //Que se logra con la distribucion?
    //Como representarlo con el problema
    //La matriz se le aplica el algoritmo de k means
    //Que valores estan junto a otros
    //Las marcas de k son los paises?
    //Nos da como resultado la distribucion
    //Se itera n veces y se toma el mejor resultado
    //Da como resultado k clusters de datos
    //Reducir el k means en cada etapa para 
    //Usar distancias absolutas?
    //Se pueden normalizar los datos


    //Los datos en un cluster van a ser los utilizados por los algoritmos?
    //El resultado de los datos puede ser el punto
    //Se puede sacar un punto central de los paises y aplicar el k means en esos?
    //Puede ser el punto central el k
    //Distancia euclidiana
    return 0;
}
