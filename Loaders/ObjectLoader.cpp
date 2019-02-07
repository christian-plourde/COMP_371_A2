#include "ObjectLoader.h"
#include <iostream>
#include <fstream>

/*
 * This is the implementation of the function to load an obj file into three different vectors
 */
bool LoadOBJ(const char* filepath, std::vector<glm::vec3>& out_vertices, std::vector<glm::vec3>& out_normals, std::vector<glm::vec2>& out_uvs)
{
    //these vectors will hold our data temporarily until we are ready to return it
    std::vector<int> vertexIndices, normalIndices, uvIndices;
    std::vector<glm::vec3> tempVertices;
    std::vector<glm::vec3> tempNormals;
    std::vector<glm::vec2> tempUVS;

    //we should first attempt to open the obj file at the specified path
    std::ifstream OBJStream(filepath);
    std::string line;

    if(OBJStream.is_open())
    {
        //if we were successful in opening the file, we need to begin reading it line by line
        //we will go case by case

        while(std::getline(OBJStream, line))
        {
            //check if the line contains a "#". If it does , this means that the line is simply a comment
            //and we should skip it
            if(line.find("#") != std::string::npos)
            {
                continue;
            }

            else
            {
                //if the line is not a comment, then we should check what type it is
                //if the line contains a v followed by a space and that line is not empty, then we should process it
                //as a vertex
                if(line.find("v ") != std::string::npos && line.length() != 0)
                {
                    //create a vec3 that will hold the x, y, and z positions of our new vertex
                    glm::vec3 vertex;
                    //get the data from the vertex line and add it to our vector of vertices
                    sscanf(line.c_str(), "v %f %f %f", &vertex.x, &vertex.y, &vertex.z);
                    tempVertices.push_back(vertex);
                }

                //if the line contains a texture coordinate
                if(line.find("vt ") != std::string::npos && line.length() != 0)
                {
                    glm::vec2 uv; //this is the new UV coordinate that we will add to our vector
                    //get the data from the next uv line and add it to the uv vertex
                    sscanf(line.c_str(), "vt %f %f", &uv.x, &uv.y);
                    tempUVS.push_back(uv);
                }

                //if the line contains a vector normal
                if(line.find("vn ") != std::string::npos && line.length() != 0)
                {
                    glm::vec3 normal; //this will hold the new vertex normal that we will add to our vector
                    //get the data from the next vertex normal line and add it to our normal vector
                    sscanf(line.c_str(), "vn %f %f %f", &normal.x, &normal.y, &normal.z);
                    tempNormals.push_back(normal);
                }

                //now we need to parse each face in our object
                if(line.find("f ") != std::string::npos && line.length() != 0)
                {
                    /*if the line contains a face then we need to parse it appropriately
                     * there are different cases for the face definition
                    */
                    int vertexIndex[3], normalIndex[3], uvIndex[3]; //for each face, there should be three of each attribute
                    bool haveNormal, haveUV;
                    haveNormal = true;
                    haveUV = true;
                    //these will let us know if we have normals and UVs. We dont have a bool for vertex
                    //because without that nothing can be drawn and the parsing has failed
                    //lets first check to see if all three of the attributes are defined (this is the first case and the layout is:)
                    //vertex/uv/normal
                    int nbMatches = sscanf(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d",
                            &vertexIndex[0], &uvIndex[0], &normalIndex[0],
                            &vertexIndex[1], &uvIndex[1], &normalIndex[1],
                            &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
                    if(nbMatches != 9)
                    {
                        /*if we attempted to parse using this layout and we did not get 9 matches, then this means that we have
                        a different schema for defining the faces and we should deal with it appropriately
                        if the schema is vertex and normal only, then these should be defined as follows:
                        vertex//normal
                        */
                        nbMatches = sscanf(line.c_str(), "f %d//%d %d//%d %d//%d",
                                &vertexIndex[0], &normalIndex[0],
                                &vertexIndex[1], &normalIndex[1],
                                &vertexIndex[2], &normalIndex[2]);

                        //if the number of matches for this format was not 6, then this means that we are using another
                        //format for the layout of the faces
                        if(nbMatches != 6)
                        {
                            //if we did not get a match for this format, we may have just vertices and texture coords
                            //if we did have this, it would be shown in the following format
                            // vertex/UV
                            nbMatches = sscanf(line.c_str(), "f %d/%d %d/%d %d/%d",
                                    &vertexIndex[0], &uvIndex[0],
                                    &vertexIndex[1], &uvIndex[0],
                                    &vertexIndex[2], &uvIndex[2]);
                            if(nbMatches != 6)
                            {
                                //if we did not find a match for this layout, then this may mean that we only have vertices
                                //if this is the case, then the format would simply be three vertices separated by spaces
                                nbMatches = sscanf(line.c_str(), "f %d %d %d",
                                        &vertexIndex[0], &vertexIndex[1], &vertexIndex[2]);

                                //if this format fails, then the file format is not valid and we should return
                                //false and an error message.
                                if(nbMatches != 3)
                                {
                                    std::cout << "The file format for the faces is not valid." << std::endl;
                                    return false;
                                }

                                //if we had this format however, then this means that we only have vertices
                                haveNormal = false;
                                haveUV = false;
                            }

                            else
                            {
                                //if we got a match for the vertex/uv format, then this means that we dont have normals
                                haveNormal = false;
                            }
                        }

                        //if the number of matches for this format (vertex and normal only) was 6, then we don't have uv
                        else
                        {
                            //since we dont have any uv coordinates, then we should set the haveUV to false
                            haveUV = false;
                        }

                    }

                    //now that we know the format of the faces (based on the booleans haveNormal and haveUV, we need
                    //to add those indices to our list
                    //since we know that to define a valid face we need at least a vertex array, lets do that first
                    vertexIndices.push_back(vertexIndex[0]);
                    vertexIndices.push_back(vertexIndex[1]);
                    vertexIndices.push_back(vertexIndex[2]);

                    //if we have UV coordinates then we should add those to our list
                    if(haveUV)
                    {
                        uvIndices.push_back(uvIndex[0]);
                        uvIndices.push_back(uvIndex[1]);
                        uvIndices.push_back(uvIndex[2]);
                    }

                    //if we have normals we should add their indices as well
                    if(haveNormal)
                    {
                        normalIndices.push_back(normalIndex[0]);
                        normalIndices.push_back(normalIndex[1]);
                        normalIndices.push_back(normalIndex[2]);
                    }

                }
            }
        }

        OBJStream.close();
    }
    else
    {
        //if the file is not open, we should print an error message and return false
        OBJStream.close();
        printf("Unable to open the file at %s", filepath);
        return false;
    }

    //now that we have all the data we need, we need to update the values in the out vectors passed by reference
    //with the indices vectors and the data vectors (the temp vectors)

    //for each vertex

    for(int i = 0; i < vertexIndices.size(); i++)
    {
        //for each vertex, if the size of the uvIndices is not zero (meaning we have some)
        if(uvIndices.size() != 0)
            if(i < uvIndices.size()) //this line is necessary because for some reason the convention
                                     //for obj files is for the first vertex or attribute to be assigned the index of 1
                                     //obviously in our vector the starting index is one so we need to make sure that it's
                                     //less than the size or we will go out of bounds
            {
                unsigned int uvIndex = abs(uvIndices[i]); //OpenGL uses unsigned ints for its indices and so we need
                                                          //to mae sure that our new uvindex is an unsigned int
                glm::vec2 uvVec = tempUVS[uvIndex - 1]; //here we subtract one from the index to make sure that it
                //matches the convention in the opengl language where the indices start at 1
                out_uvs.push_back(uvVec); //add this uvVector to the out_uvs
            }

        //now we need to handle the normals in the same way (if we have some)
        if(normalIndices.size() != 0)
            if(i < normalIndices.size())
            {
                unsigned int normalIndex = abs(normalIndices[i]);
                glm::vec3 normalVec = tempNormals[normalIndex - 1];
                out_normals.push_back(normalVec);
            }

        //finally we need to handle the vertices, which we should have if we are at this point
        unsigned int vertexIndex = abs(vertexIndices[i]);
            glm::vec3 vertVec = tempVertices[vertexIndex - 1];
            out_vertices.push_back(vertVec);
    }
    return true;
}

