#include <Windows.h>
#include <filesystem>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>

namespace fs = std::filesystem;
void printObjectsInList(std::vector<std::string> objectList);
void printObjectPathsInList(std::vector<std::string> objectPaths);

int main() 
{
    std::vector<std::string> objectList;
    std::vector<std::string> objectPaths;

    const char* p_path = "C:\\Users\\apoll\\OneDrive\\repos\\glproc\\models";

    for (const fs::directory_entry& _entry : fs::directory_iterator(p_path)) 
    {
        if (fs::is_directory(_entry)) 
        {
            std::string sceneFileLoc = _entry.path().string() + "\\scene.gltf";
            std::string object;

            if (fs::exists(sceneFileLoc)) 
            {
                object = _entry.path().filename().string(); 
                objectList.push_back(object);
                // fprintf(stdout, "found scene.gltf in %s\n", object.c_str());

                objectPaths.push_back(sceneFileLoc.c_str());
                // fprintf(stdout, "file location: %s\n", sceneFileLoc.c_str());
                // putchar('\n');
            } 
            else 
            { 
                object = _entry.path().filename().string(); 
                fprintf(stdout, "no scene.gltf in %s\n", object.c_str()); 
            }
        }
    }

    // debugging    
    // printObjectsInList(objectList);
    // putchar('\n');
    // printObjectPathsInList(objectPaths);

    const char* target = "grass";

    for (const auto& path : objectPaths)
    {
        if (path.find(target) != std::string::npos)
        {
            std::cout << target << " path found: " << path << std::endl;
            break;
        }
    }

    return 0;
}

void printObjectsInList(std::vector<std::string> objectList)
{
    fputs("Object List\n\n", stdout);
    for (const auto& object : objectList)
    { fprintf(stdout, "%s\n", object.c_str()); }
}

void printObjectPathsInList(std::vector<std::string> objectPaths)
{
    fputs("Object Paths\n\n", stdout);
    for (const auto& paths : objectPaths)
    { fprintf(stdout, "%s\n", paths.c_str()); }
}
